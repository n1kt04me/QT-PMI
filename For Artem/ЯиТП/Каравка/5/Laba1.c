/* 
  Laba5.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 05/04/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 5. Условный оператор. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция ввода значения a,b,c,d и нахождения пар*/
void solveFunction();
void compareAndFindPairs(int a, int b, int c, int d);
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
  int a, b, c, d;
  printf("Input 'a' value: ");
  scanf("%d", &a);
  printf("Input 'b' value: ");
  scanf("%d", &b);
  printf("Input 'c' value: ");
  scanf("%d", &c);
  printf("Input 'd' value: ");
  scanf("%d", &d);
  waitAnimate();
  compareAndFindPairs(a, b, c, d);
}
void compareAndFindPairs(int a, int b, int c, int d){
  if(a<0 && b<0 && c<0 && d<0){
    printf("(%d) and (%d)\n", a, b);
    printf("(%d) and (%d)\n", a, c);
    printf("(%d) and (%d)\n", a, d);
    printf("(%d) and (%d)\n", b, c);
    printf("(%d) and (%d)\n", b, d);
    printf("(%d) and (%d)\n", c, d);
    return;
  }
  if(a<0 && b<0) 
    printf("(%d) and (%d)\n", a, b);
  if(a<0 && c<0) 
    printf("(%d) and (%d)\n", a, c);
  if(a<0 && d<0) 
    printf("(%d) and (%d)\n", a, d);
  if(b<0 && c<0) 
    printf("(%d) and (%d)\n", b, c);
  if(b<0 && d<0) 
    printf("(%d) and (%d)\n", b, d);
  if(c<0 && d<0) 
    printf("(%d) and (%d)\n", c, d); 
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
  printf("Type '1' to input and perform main operation of this program\n");
  printf("Type '2' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion