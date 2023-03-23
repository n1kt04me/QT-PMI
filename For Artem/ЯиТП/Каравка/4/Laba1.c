/* 
  Laba4.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 12/03/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 4. Линейная программа. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция ввода значения х и вычисления уравнения*/
void solveFunction();

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
  double number;
  printf("Input 'x' value: ");
  scanf("%lf", &number);
  printf("A function with value:\n");
  printf("y = fabs(%lf-1/", number);
  printf("%lf^2) - (",number);
  printf("cos(%lf)/", number);
  printf("log(tan(%lf)", number);
  printf("-%lf)\n", number);
  waitAnimate();
  double result = fabs(number-1/(number*number)) - cos(number)/log(tan(number)-number);
  printf("Answer is: %lf", result);
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
  printf("This programm solve  this function:\n");
  printf("===================================\n");
  printf("  |   1 |    cosx  \n");
  printf("y=|x-___|-_________\n");
  printf("  |  x^2| ln|tgx-x|\n");
  printf("Type '1' to solve\n");
  printf("Type '0' to exit \n");
  printf("===================================\n");
}
#pragma endregion