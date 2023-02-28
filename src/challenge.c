/*Author: Flaviu E. Hongu (Noriel Sylvire)
Platform: LinkedIn Learning, thanks to Fujitsu*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char current_date[15];
unsigned short int op_id;

void get_id(void);
void get_date(void);
void logger(void);
void show_info(void);
void show_menu(void);

int main(void)
{
  system("clear");
  printf("Initializing logging manager.\nDetecting current date...\n");
  get_date();
  get_id();
  printf("Hit a key to start.\n");
  getchar();
  system("clear");
  logger();
  return (0);
}

void get_id(void)
{
  printf("Please input your operator ID:\n");
  scanf("%d", (int *)&op_id);
  getchar();
  printf("Operator Flaviu Emanuel Hongu with ID %d identified.\nProceeding with the initialization.\n", (int)op_id);
}

void get_date(void)
{
  time_t current_time;
  struct tm local_time;

  current_time = time(NULL);
  local_time = *localtime(&current_time);
  if (strftime(current_date, sizeof(current_date), "%Y-%m-%d", &local_time) != 0)
  {
    printf("Current date: %s\n", current_date);
  }
  else
    printf("Error.\n");
}

void logger(void)
{
  int exit;

  exit = 0;
  while (!exit)
  {
    show_info();
    show_menu();
    system("clear");
  }
}

void show_menu(void)
{
  printf("\nActions:\n");
  printf("1. Log an error\n");
  printf("2. Show today's error history\n");
  printf("3. Delete today's error history\n");
  printf("0. Exit\n");
  printf("\nPrompt: ");
  getchar();
  printf("\n");
}

void show_info(void)
{
  printf("Error Logger C Challenge Version 0.\n");
  printf("Operator ID: %d\nDate: %s\n", op_id, current_date);
}
