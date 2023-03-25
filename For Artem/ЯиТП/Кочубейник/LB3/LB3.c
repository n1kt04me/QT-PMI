/* 
  LB3.c
  --------------------------
  (c)оздал: Кочубейник Д.Д.
  группа  : 1БПМИ-УДМО
  дата    : 19/03/23
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 3. Функции ввода-вывода. 
*/

// ’P’; ’Меня зовут <фамилия и имя>’; 963, –785; 426.37, –653.871; 643.

#include <stdio.h>
#include <string.h>

 int main() {
    int symbol = ' ' , FirstNum = 0, SecondNum = 0; 
    unsigned int number = 0;
    char firstname[15], lastname[15];
    float firstNumber = 0.000;
    float secondNumber = 0.000;
    // Ввод и вывод символа
    printf("\nВведите символ: ");
    scanf("%c", &symbol);
    printf("Вывод: %c ", symbol);
    printf("и в виде кода: %u\n", symbol);
    // Ввод и вывод текста, вывод длины текста
    printf("\nВведите фамилию и имя: ");
    scanf("%s %s", &lastname, &firstname);
    printf("Меня зовут %s %s\n", lastname, firstname);
    printf("Длина строки: %zu\n", 12 + strlen(firstname) + strlen(lastname));
    // Ввод и вывод двух целых чисел(положительного и отрицательного)
    printf("\nВведите первое число: ");
    scanf("%d", &FirstNum);
    printf("Введите второе число: ");
    scanf("%d", &SecondNum);
    printf("Вывод первого целого числа: %d ", FirstNum);
    printf("и в шестнадцатеричном  виде: %x\n", FirstNum);
    printf("Вывод второго целого числа: %d ", SecondNum);
    printf("и в шестнадцатеричном виде: %x\n", SecondNum);
    // Ввод и вывод двух чисел(положительного и отрицательного) с плавающей точкой
    printf("\nВведите первый число: ");
    scanf("%f", &firstNumber);
    printf("Введите второй число: ");
    scanf("%f", &secondNumber);
    printf("Ваше первое число с плавающей точкой: %.3f ", firstNumber);
    printf("и экспоненциальная форма: %.3e\n", firstNumber);
    printf("Ваше второе число с плавающей точкой: %.3f ", secondNumber);
    printf("и экспоненциальная форма: %.3e\n", secondNumber);
    // Ввод и вывод целого безнакового числа
    printf("\nВведите число: ");
    scanf("%u", &number);
    printf("Ваше число в десятичном формате: %u ", number);
    printf("и без знака: %o ", number);
    printf("и шестнадцатерично целое: %x\n", number);
 }