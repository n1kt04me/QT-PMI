/* 
  Laba3.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 28/02/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 3. Функции ввода-вывода. 
*/
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Функция ввода символа и его вывод в символьном виде и в виде кода*/
void printCharToText();
/*Функция ввода строки символов, определение ee длины и вывод строки символов с указанием ее длины*/
void printStringAndSize();
/*Функция ввода двух целых десятичных чисел и их вывод в десятичном и шестнадцатеричном виде*/
void printIntToByte();
/*Функция ввода двух чисел с плавающей точкой и их вывод в десятичной и экспоненциальной формах*/
void printFloatToDecExp();
/*Функция ввода двух чисел с плавающей точкой и их вывод в десятичной и экспоненциальной формах*/
void printFloatToU();

/*Функция анимации ожидания*/
void waitAnimate(int taskNumber);
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
          waitAnimate(i);
          printCharToText();
          break;
        case 2:
          waitAnimate(i);
          printStringAndSize();
          break;
        case 3:
          waitAnimate(i);
          printIntToByte();
          break;
        case 4:
          waitAnimate(i);
          printFloatToDecExp();
          break;
        case 5:
          waitAnimate(i);
          printFloatToU();
          break;
        default:
          printHelp();
          break;
      }
    }
    return 0;
}

#pragma region Main functions
void printCharToText(){
  char example = ' ';
  printf("Input some symbol: ");
  scanf("%s", &example);
  printf("Output in char: %c \n", example);
  printf("Output in ASCII code: %u \n", example);
}
void printStringAndSize(){
  char string[15];
  printf("Input some text: ");
  scanf("%s", string);
  printf("Your text: %s\n", string);
  printf("Size of text is %d\n", sizeof(string)/sizeof(char));
}
void printIntToByte(){
  int firstNumber = 0;
  int secondNumber = 0;
  printf("Input first number: ");
  scanf("%d", &firstNumber);
  printf("Input second number: ");
  scanf("%d", &secondNumber);
  printf("Your first number in int: %d ", firstNumber);
  printf("and byte: %x\n", firstNumber);
  printf("Your second number in int: %d ", secondNumber);
  printf("and byte: %x\n", secondNumber);
}
void printFloatToDecExp(){
  float firstNumber = 0.000;
  float secondNumber = 0.000;
  printf("Input first number: ");
  scanf("%f", &firstNumber);
  printf("Input second number: ");
  scanf("%f", &secondNumber);
  printf("Your first number in float: %.3f ", firstNumber);
  printf("and exp: %.3e\n", firstNumber);
  printf("Your second number in float: %.3f ", secondNumber);
  printf("and exp: %.3e\n", secondNumber);
}
void printFloatToU(){
  unsigned int number = 0;
  printf("Input number: ");
  scanf("%u", &number);
  printf("Your number in int: %u ", number);
  printf("unsigned: %o ", number);
  printf("and byte: %x\n", number);
}
#pragma endregion

#pragma region Additional Functions
void waitAnimate(int taskNumber){
  printf("Perfoming a %d task", taskNumber);
  for (int i = 0; i < 3; i++)
  {
    printf(".");
    sleep(1);
  }
  printf("\nDone.\n");
}
void printHelp(){
  printf("This programm operate next functions:\n");
  printf("=================================================\n");
  printf("Type '1' to print a char and ASCII code \n");
  printf("Type '2' to print a text and size \n");
  printf("Type '3' to print int and byte values \n");
  printf("Type '4' to print float and exp values \n");
  printf("Type '5' to print int, unsigned and byte values \n");
  printf("Type '0' to exit \n");
  printf("=================================================\n");
}
#pragma endregion