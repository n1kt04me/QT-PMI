/* 
  Laba10.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 10. Функции
*/
#include <stdio.h>
#include "Laba10.2.c"
#include "Laba10.3.c"
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция подсчета объема параллелипипеда*/
float volume();
/*Функция печати результата подсчета*/
void print(float result){
  printf("Cube volume: %.3f", result);
}
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
          print(volume());
          break;
        case 2:
          squareRing();
          break;
        case 3:
          summaryRow();
          break;
        case 4:
          getVarsToPerformRecurs();
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
float volume(){
  float height = 0;
  float square = 0;
  float result = 0;
  printf("Type cube height: \n");
  scanf("%f", &height);
  if(height < 1){
    printf("Height cannot be above 0!\n");
    return 0;
  }
  printf("Type cube square: \n");
  scanf("%f", &square);
  if(square < 1){
    printf("Square cannot be above 0!\n");
    return 0;
  }
  result = height * square;
  return result;
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
  printf("This programm calculate cube volume, ring square and summary of numbers row\n");
  printf("Type '1' to perfom a first task\n");
  printf("Type '2' to perfom a second task\n");
  printf("Type '3' to perfom a third task\n");
  printf("Type '4' to perfom a forth task\n");
  printf("Type '0' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion