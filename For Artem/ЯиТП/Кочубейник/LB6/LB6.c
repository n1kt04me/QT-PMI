/* 
  LB6.c
  --------------------------
  (c)оздал: Кочубейник Д.Д.
  группа  : 1БПМИ-УДМО
  дата    : 24/03/23
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 6. Циклы с известным числом повторений.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctime>


int main(){
  int k, number, number1 = 0, number2 = 0, i = 0;
  // Programm A
  //Ввод числа k 
  printf("Введите K число: ");
  scanf("%d", &k);
  //Вывод элементов, где кратные k заменяются на нуль
  printf("Вывод чисел A(20), если они кратны k, то заменяются на 0:\n");
  while(i < 20)
  {
    number = rand() % 1001;
    //Условие для определения числа кратного К
    if(number % k == 0 )
    {
      printf("0\n"); 
    }
    else
    {
    printf("%d\n", number);
    }
    i++; 
  }
  printf("\nМатрица\n");
  // Programm B
  int line, forLine = 0, numberLine = 0;
  srand((unsigned)time(0)); //чтобы при каждом запуске программы были разные элементы матрицы 
  //Матрица N(6,5) со случайными элементами в диапазоне [1, 1001)
  for(size_t i = 0; i < 6; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      number1 = rand() % 1001;
      printf("%d\t", number1);
      number2 += number1;
    }
    //Вывод суммы элементов строк
    printf(" =  %d\n", number2);
    forLine++;
    //Условие для определения макимальной строки
    if (numberLine <= number2)
    {
        line = forLine;
        numberLine = number2;
    }
    number2 = 0;
  }
  //Вывод строки с максимальной суммой элементов
  printf("Строка №%d с макимальной суммой элементов равна: %d\n", line, numberLine);
}
  
