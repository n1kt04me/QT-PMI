/* 
  LB5.c
  --------------------------
  (c)оздал: Кочубейник Д.Д.
  группа  : 1БПМИ-УДМО
  дата    : 24/03/23
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 5. Условный оператор.
*/

/*
С клавиатуры вводятся 4 целых числа: a, b, c, d (положительных и отрицательных).
Подсчитать количество положительных чисел, кратных k1 и не кратных k2.
Операторы цикла в программе не использовать.
*/

#include <stdio.h>
 
int main(){
    int a, b, c, d, k = 0, k0 = 0, k1, k2;
    printf("Введите переменные a, b, c, d: ");
    //Ввод 4 положительных и отрицательных целых чисел
    scanf("%d %d %d %d", &a, &b, &c, &d);
    //Подсчет количества положительных чисел
    if (a > 0)
        k0++;
    if (b > 0)
        k0++;
    if (c > 0)
        k0++;
    if (d > 0)
        k0++;
    printf("Количество положительных: %d\n", k0);
    printf("Количество отрицательных: %d\n", 4 - k0);
    //Ввод k1 и k2
    printf("Введите k1 и k2: ");
    scanf("%d %d", &k1, &k2);
    //Определение количество чисел картных k1 и не кратных k2
    if(a % k1 == 0 && a % k2 != 0) 
        k++;
    if(b % k1 == 0 && b % k2 != 0) 
        k++;
    if(c % k1 == 0 && c % k2 != 0) 
        k++;
    if(d % k1 == 0 && d % k2 != 0) 
        k++;
    //Вывод количества чисел картных k1 и не кратных k2:
    printf("Количество чисел картных k1 и не кратных k2: %d\n", k);
}
