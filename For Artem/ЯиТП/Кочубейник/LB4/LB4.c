/* 
  LB4.c
  --------------------------
  (c)оздал: Кочубейник Д.Д.
  группа  : 1БПМИ-УДМО
  дата    : 24/03/23
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 4. Линейная программа. 
*/

// y = (tan(sqrt(pow(e, (x+2)))))/(sin(7 * x / (4 - 0.001)) - математическая формула
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main(){
    printf("Пример: y = tan(sqrt(pow(e, (x + 2)))) / (sin(7 * x / (4 - 0.001))");
    //Объявление перемнной 
    double variable;
    printf("\nВведите X переменную: ");
    //Ввод переменной
    scanf("%lf", &variable);
    //Вывод ответа примера
    printf("Ваш ответ: %f\n", tan(sqrt(exp(variable + 2))) / (sin(7 * variable / (4 - 0.001))));
    // printf("\ntan = %f", tan(sqrt(exp(variable + 2))));
    // printf("\nsin = %f", sin(7 * variable / (4 - 0.001)));
}