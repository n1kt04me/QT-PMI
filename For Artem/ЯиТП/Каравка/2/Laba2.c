/* 
  Laba2.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 28/02/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 2. Основные свойства фундаментальных типов данных. 
*/
#include <stdio.h>
#include <limits.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
/*Функция вывода размера типа данных unsigned char*/
void printSizeOfUChar();
/*Функция вывода минимального и максимального значений signed int*/
void printMinMaxValues();
/*Функция вывода размера символа '!'*/
void printSizeOfSymbol();
/*Функция анимации ожидания*/
void waitAnimate(int taskNumber);
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
          waitAnimate(i);
          printSizeOfUChar();
          break;
        case 2:
          waitAnimate(i);
          printSizeOfSymbol();
          break;
        case 3:
          waitAnimate(i);
          printMinMaxValues();
          break;
        default:
          printHelp();
          break;
      }
    }
    return 0;
}
void printSizeOfUChar(){
  unsigned char example;
  printf("Size of UChar is %d byte(s)\n", sizeof(example));
}
void printSizeOfSymbol(){
  printf("Size of '!' symbol is %d byte(s)\n", sizeof('!'));
}
void printMinMaxValues(){
  printf("Min value of signed int: 0 \n");
  printf("Max value of signed int: %u \n", UINT_MAX);
}
void waitAnimate(int taskNumber){
  printf("Perfoming a %d task", taskNumber);
  for (int i = 0; i < 3; i++)
  {
    printf(".");
    sleep(1);
  }
  printf("\nDone.\n");
}
void printHelp(){
  printf("This programm operate next functions:\n");
  printf("===============================================\n");
  printf("Type '1' to print a size of unsigned char\n");
  printf("Type '2' to print a size of '!' symbol\n");
  printf("Type '3' to print max and min singed int values \n");
  printf("Type '0' to exit \n");
  printf("===============================================\n");
}