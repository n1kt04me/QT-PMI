/* 
  Laba11.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 11. Работа с файлами
*/
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция подсчета строк в файле*/
int countStringFromFile();
/*Функция чтения файла*/
char* readFileAndCountSpaces();
/*Функция подсчета*/
void writeIntoFile(char *string);
/*Функция анимации ожидания*/
void waitAnimate();
/*Функция вывода справки*/
void printHelp();

/*Главная функция main*/
int main(){
    printHelp();
    int i = -1;
    while(i != 0){
      scanf("%d", &i);
      switch (i)
      {
        case 1:
          readFileAndCountSpaces();
          break;
        case 0:
          break;
        default:
          printHelp();
          break;
      }
    }
    return 0;
}

#pragma region Main functions
int countStringFromFile(){
  FILE *fin;
  fin = fopen("data.txt","a+");
  char currChar;
  int count = 0;
  while((currChar = fgetc(fin)) != EOF){
    if(currChar == '\n' || currChar == '\0'){
      count++;
    }
  }
  return count;
}
char* readFileAndCountSpaces(){
  FILE *fin;
  fin = fopen("data.txt","a+");
  int countSpace[30];
  int i = 0;
  int count = 0;
  char currChar;
  while((currChar = fgetc(fin)) != EOF){
    if(currChar == '\n' || currChar == '\0'){
      countSpace[i] = count;
      count = 0;
      i++;
    }
    if(currChar == ' '){
      count += 1;
    }
  }
  i = 0;
  fclose(fin);
  int size = countStringFromFile();
  while(i < size)
  {
    char temp[200] = "";
    char num[2] = "";
    char count[10] = "";
    sprintf(num, "%d", i+1);
    sprintf(count, "%d", countSpace[i]);
    strcat(temp, num);
    strcat(temp, " string contains ");
    strcat(temp, count);
    strcat(temp, " space(s)\n");
    i+=2;
    writeIntoFile(temp); 
  }
}

void writeIntoFile(char* string){
  FILE *fin;
  fin = fopen("data.txt","a+");
  char *rstr;
  fputs(string, fin);
  fclose(fin);
  printf("Done.\n"); 
}
#pragma endregion

#pragma region Additional Functions
void waitAnimate(){
  printf("Solving");
  for (int i = 0; i < 3; i++)
  {
    printf(".");
    sleep(1);
  }
  printf("\nDone.\n");
}
void printHelp(){
  printf("This programm find an amount of spaces in file\n");
  printf("Type '1' to perfom a first task\n");
  printf("Type '0' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion