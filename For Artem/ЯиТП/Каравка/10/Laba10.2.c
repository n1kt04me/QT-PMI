#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

/*Функция подсчета кольца*/
void squareRing(){
  float ringRadius = 0;
  float circleRadius = 0;
  float square = 0;
  printf("Type ring radius: \n");
  scanf("%f", &ringRadius);
  if(ringRadius < 1){
    printf("Ring radius cannot be above 0!\n");
    return;
  }
  printf("Type cicle radius: \n");
  scanf("%f", &circleRadius);
  if(circleRadius < 1){
    printf("Circle radius cannot be above 1!\n");
    return;
  }
  if(circleRadius < ringRadius){
    printf("Circle radius cannot be smaller than ring radius!\n");
    return;
  }
  square = M_PI*(circleRadius - ringRadius);
  printf("Result: %.3f\n", square);
}