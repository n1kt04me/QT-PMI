/* 
  Laba12.c
  --------------------------
  (c)оздал: Каравка Д.И.
  группа  : 1БПМИ-УДМО
  дата    : 13/06/22
  для     : VSCode GCC
  -------------------------------------------------------
  Лабораторная работа 12. Структуры
*/
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*Структура "Вокзал"*/
typedef struct Date {
    int day;
    int mouth;
    int year;
} Date;
typedef struct Break_Time{
    int hours;
    int minutes;
} Break_Time;
typedef struct Station_List{
  int number;
  char destination[20]; 
  Date date;
  Break_Time break_time;
  int days;
} Station;

/*Функция ввода данных в структуру*/
void input(Station stat[], int index);
/*Функция вывода данных из структуры*/
void output(Station stat[], int amount_to_output);
/*Функция сортировки данных в структуре*/
void sort_data(Station stat[], int amount);
/*Функция поиска данных из структуры*/
void find(Station stat[], int amount);
/*Функция анимации ожидания*/
void waitAnimate();
/*Функция вывода справки*/
void printHelp();
/*Выделение памяти для String*/
char* mallocStr(const char *str);

/*Главная функция main*/
int main(){
    int amount = 0;
    int amount_to_output = 0;
    printHelp();
    Station station_list[30];
    int i = -1;
    while(i != 0){
      scanf("%d", &i);
      switch (i)
      {
        case 1:
          printf("input amount to input: \n");
          scanf("%d",&amount);
          for (size_t i = 0; i < amount; i++)
          {
            input(station_list, i);
          }
          printf("Done.\n");
          break;
        case 2:
          printf("input amount to output: \n");
          scanf("%d", &amount_to_output);
          output(station_list, amount_to_output);
          break;
        case 3:
          sort_data(station_list, amount);
          break;
        case 4:
          find(station_list, amount);
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
char* mallocByString(const char *str) {
    char* p = (char*) malloc(strlen(str) + 1);
    strcpy(p, str);
    return p;
}
void input(Station stat[], int index){
  printf("input train number: ");
  scanf("%d", &stat[index].number);
  printf("input destination: ");
  scanf("%s", &stat[index].destination);
  printf("input days: ");
  scanf("%d", &stat[index].days);
  printf("input breaktime minutes: ");
  scanf("%d", &stat[index].break_time.minutes);
  printf("input breaktime hours: ");
  scanf("%d", &stat[index].break_time.hours);
  printf("input date day: ");
  scanf("%d", &stat[index].date.day);
  printf("input date mouth: ");
  scanf("%d", &stat[index].date.mouth);
  printf("input date year: ");
  scanf("%d", &stat[index].date.year);
}

void output(Station stat[], int amount_to_output){
  int i = 0;
  while(i < amount_to_output){
    printf("train number: %d\n", stat[i].number);
    printf("train destination: %s\n", stat[i].destination);
    printf("train days: %d\n", stat[i].days);
    printf("train breaktime: %d:%d\n", stat[i].break_time.hours, stat[i].break_time.minutes);
    printf("train date: %d:%d:%d\n", stat[i].date.day, stat[i].date.mouth, stat[i].date.year);
    i++;
  }
}

int destination_cmp(const void * a, const void *b){
  return strcmp(((Station*)a)->destination, ((Station*)b)->destination);
}

int days_cmp(const void * a, const void *b){
  return ((Station*)a)->days - ((Station*)b)->days;
}

int number_cmp(const void * a, const void *b){
  return ((Station*)a)->number - ((Station*)b)->number;
}

void sort_data(Station stat[],  int amount){
  int count = 10;
  int choice = -1;
  while(choice != 0)
  {
    printf("type '1' to sort by destination;\ntype '2' to sort by days;\ntype '3' to sort by number;\ntype '0' to exit;\n");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
        qsort(stat, amount, sizeof(Station), destination_cmp);
        printf("Sorted by destination: \n");
        break;
      case 2:
        qsort(stat, amount, sizeof(Station), days_cmp);
        printf("Sorted by days: \n");
        break;
      case 3:
        qsort(stat, amount, sizeof(Station), number_cmp);
        printf("Sorted by train number: \n");
        break;
      case 0:
        return;
      default:
        break;
    }
    int i = 0;
    printf("======================\n");
    while(i < amount){
      printf("train number: %d\n", stat[i].number);
      printf("train destination: %s\n", stat[i].destination);
      printf("train days: %d\n", stat[i].days);
      printf("train breaktime: %d:%d\n", stat[i].break_time.hours, stat[i].break_time.minutes);
      printf("train date: %d:%d:%d\n", stat[i].date.day, stat[i].date.mouth, stat[i].date.year);
      i++;
    }
    printf("======================\n");
  }
}

void find(Station stat[],  int amount){
  int choice = -1;
  int i = 0;
  char destination[20];
  int days = 0;
  int number = 0;
  while(choice != 0)
  {
    printf("type '1' to find by destination;\ntype '2' to find by days;\ntype '3' to find by number;\ntype '0' to exit;\n");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
        printf("Input destination: \n");
        scanf("%s", &destination);
        printf("Found by destination: \n");
        i = 0;
        while(i < amount){
          if(!strcmp(stat[i].destination, destination)){
            printf("=====destination======\n");
            printf("train number: %d\n", stat[i].number);
            printf("train destination: %s\n", stat[i].destination);
            printf("train days: %d\n", stat[i].days);
            printf("train breaktime: %d:%d\n", stat[i].break_time.hours, stat[i].break_time.minutes);
            printf("train date: %d:%d:%d\n", stat[i].date.day, stat[i].date.mouth, stat[i].date.year);
            printf("======================\n");
            break;
          }
          i++;
        }
        break;
      case 2:
        printf("Input days: \n");
        scanf("%d", &days);
        printf("Found by days: \n");
        i = 0;
        while(i < amount){
          if(stat[i].days == days){
            printf("========days=========\n");
            printf("train number: %d\n", stat[i].number);
            printf("train destination: %s\n", stat[i].destination);
            printf("train days: %d\n", stat[i].days);
            printf("train breaktime: %d:%d\n", stat[i].break_time.hours, stat[i].break_time.minutes);
            printf("train date: %d:%d:%d\n", stat[i].date.day, stat[i].date.mouth, stat[i].date.year);
            printf("======================\n");
            break;
          }
          i++;
        }
        break;
      case 3:
        printf("Input train number: \n");
        scanf("%d", &number);
        printf("Found by train number: \n");
        i = 0;
        while(i < amount){
          if(stat[i].number == number){
            printf("=========number======\n");
            printf("train number: %d\n", stat[i].number);
            printf("train destination: %s\n", stat[i].destination);
            printf("train days: %d\n", stat[i].days);
            printf("train breaktime: %d:%d\n", stat[i].break_time.hours, stat[i].break_time.minutes);
            printf("train date: %d:%d:%d\n", stat[i].date.day, stat[i].date.mouth, stat[i].date.year);
            printf("======================\n");
            break;
          }
          i++;
        }
        break;
      case 0:
        return;
      default:
        break;
    }
  }
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
  printf("This programm add, print, sort and find of station info\n");
  printf("Type '1' to add data\n");
  printf("Type '2' to output data\n");
  printf("Type '3' to sort data\n");
  printf("Type '4' to find data\n");
  printf("Type '0' to quit\n");
  printf("Type anything else to show help\n");
}
#pragma endregion