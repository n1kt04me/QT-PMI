#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

/*Функция подсчета суммы ряда*/
void summaryRow(){
  int kNum = 0;
  float result = 0;
  printf("Type number of cycle operations: \n");
  scanf("%d", &kNum);
  if(kNum < 1){
    printf("k number cannot be above 1!\n");
    return;
  }
  for (int i = 1; i <= kNum; i++)
  {
    result += (2*i+3)/(3*i-2);
  }
  printf("Result: %.3f\n", result);
}

/*Функция подсчета суммы ряда при помощи рекурсии*/
void summaryRowRecurs(int k, float result){
  if(k == 0){
    printf("Result: %.3f \n", result);
    return;
  }
  result += (2*k+3)/(3*k-2);
  summaryRowRecurs(k-1, result);
}

/*Функция получения значений для рекурсии*/
void getVarsToPerformRecurs(){
  int kNum = 0;
  float result = 0;
  printf("Type number of cycle operations: \n");
  scanf("%d", &kNum);
  if(kNum < 1){
    printf("k number cannot be above 1!\n");
    return;
  }
  summaryRowRecurs(kNum, result);
}