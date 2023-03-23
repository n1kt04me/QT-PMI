/* 
  Laba8.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 8. Указатели
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

/*Функция нахождения суммы положительных элементов, кратных введенному значению*/
void solveFunctionA();
/*Функция подсчета*/
void solveFunctionB();
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
          solveFunctionA();
          break;
        case 2:
          solveFunctionB();
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
void solveFunctionA(){
  int *mass = malloc(sizeof(int*) * 20);
  int *elem = 0;
  int i = 0;
  int kNumber = 0;
  int count = 0;
  printf("input K value: ");
  scanf("%d", &kNumber);
  while(i < 20){
    *(mass+i) = rand()%100;
    if((*(mass+i) % kNumber == 0) && (*(mass+i) > 0)){
      count++;
    }
    i++;
    elem++;
  }
  waitAnimate();
  printf("result: %d\n", count);
}

void solveFunctionB(){
  int **mass = malloc(sizeof(int) * (8));
  for (int i = 0; i < 8; i++)
  {
    mass[i] = malloc(sizeof *mass[i] * 8);
  }
  int maxNumber = 0;
  int amount = 0;
  int result = 0;
  for(int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++)
    {
      *(*(mass+i)+j) = rand()%10;
      
      if(amount == 0){
        maxNumber = (int) *(*(mass+i)+j);
        amount ++;
      }
      if(maxNumber < *(*(mass+i)+j)){
        maxNumber = (int) *(*(mass+i)+j);
      }
      else{
        result = i;
      }
      printf("%d ",*(*(mass+i)+j));
    }
    printf("\n");
  }
  waitAnimate();
  printf("Row with Max number in massive: %d\n", result); 
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
  printf("Type '1' to perfom a first task\n");
  printf("Type '2' to perfom a second task\n");
  printf("Type '0' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion