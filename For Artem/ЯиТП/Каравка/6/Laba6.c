/* 
  Laba6.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 6. Циклы с известным числом повторений. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция подсчета первого задания*/
void solveFirstTask();
/*Функция ввода и подсчета чисел в массиве*/
void countElements();
/*Функция подсчета второго задания*/
void solveSecondTask();
/*Функция нахождения максимального числа*/
void findingMaxElement();
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
          solveFirstTask();
          break;
        case 2:
          solveSecondTask();
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
void solveFirstTask(){
  countElements();
}

void countElements(){
  int i = 0;
  int massive[20];
  int number = 0;
  int k_number = 0;
  int amount = 0;
  printf("Input k-value: ", k_number);
  scanf("%d", &k_number);
  while(i < 20)
  {
    number = rand()%1000;
    if(number > 0 && number % k_number == 0){
      amount ++;
    }
    i++;
  }
  waitAnimate();
  printf("Amount positive elements divined by (%d): (%d)\n", k_number, amount);
}

void solveSecondTask(){
  
  findingMaxElement();
}

void findingMaxElement(){
  int number = 0;
  int maxNumber = 0;
  int amount = 0;
  int result = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      number = rand()%1000;
      if(amount == 0){
        maxNumber = number;
        amount ++;
      }
      if(maxNumber < number){
        maxNumber = number;
      }
      else{
        result = i;
      }
    }
  }
  waitAnimate();
  printf("Row with Max number in massive: %d", result);    
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
  printf("This programm find negative pairs\n");
  printf("Type '1' to perfom a first task\n");
  printf("Type '2' to perfom a second task\n");
  printf("Type '0' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion