/* 
  Laba7.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 5. Циклы с неизвестным числом повторений
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

/*Функция подсчета*/
void solveFunction();
/*Функция нахождения факториала */
int factorial(int num);
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
          solveFunction();
          break;
        default:
          printHelp();
          break;
      }
    }
    return 0;
}

#pragma region Main functions
void solveFunction(){
  int x = 0;
  float esp = 0.001;
  printf("Input x: ");
  scanf("%d", &x);
  double result = x;
  double number = x;
  int i = 2;
  while(fabs(number) > esp){
    number = (pow(x, 2*i-1)*pow(-1,i-1))/factorial(2*i-1);
    result += number;
    i++;
  } 
  waitAnimate();
  printf("result: %f\n", result);
}
int factorial(int num){
  if(num == 0)
    return 1;
  return num * factorial(num-1);
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
  printf("This programm find a sin(x)\n");
  printf("Type '1' to input and perform main operation of this program\n");
  printf("Type '2' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion