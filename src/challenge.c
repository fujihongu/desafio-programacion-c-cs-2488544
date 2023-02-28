/*Author: Flaviu E. Hongu (Noriel Sylvire)
Platform: LinkedIn Learning, thanks to Fujitsu*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

static const char version_text[50] = "Error Logger C Challenge Version 0";
char current_date[15];
unsigned short int op_id;

void get_id(void);
void get_date(void);
void logger(void);
void show_info(void);
void show_menu(void);
void show_end_info(void);
int grab_command(void);
int execute_command(int cmd_nbr);

int main(void)
{
  system("clear");
  printf("Initializing logging manager.\nDetecting current date...\n");
  get_date();
  get_id();
  printf("Press enter to start.\n");
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
    exit = grab_command();
  }
  system("clear");
  show_end_info();
}

void show_menu(void)
{
  printf("\nActions:\n");
  printf("1. Log an error\n");
  printf("2. Show today's error history\n");
  printf("3. Delete today's error history\n");
  printf("0. Exit\n");
  printf("\nPrompt: ");
  printf("\n");
}

void show_info(void)
{
  printf(version_text);
  printf("\n");
  printf("Operator ID: %d\nDate: %s\n", op_id, current_date);
}

int grab_command(void)
{
  char command[15];
  int cmd_nbr;

  scanf("%s", command);
  getchar();
  cmd_nbr = atoi(command);
  if (strlen(command) == 1 && *command == '0')
    return (execute_command(0));
  else if (cmd_nbr != 0)
  {
    return (execute_command(cmd_nbr));
  }
  else
    printf("Invalid action number or command.\nPlease, input a valid action.\n");
  return (0);
}

int execute_command(int cmd_nbr)
{
  switch (cmd_nbr)
  {
  case 1:
    printf("You logged an error.\n");
    break;
  case 2:
    printf("This is today's error history:\nnull\n");
    break;
  case 3:
    printf("For some reason you deleted today's error history.\nMaybe I just misinterpreted the instructions?\n");
    break;
  case 0:
    return (1);
  default:
    printf("Invalid action number or command.\nPlease, input a valid action.\n");
  }
  printf("Press enter to continue.\n");
  getchar();
  system("clear");
  return (0);
}

void show_end_info(void)
{
  printf("Exiting session 'Flaviu Emanuel Hongu'...\n\n");
  printf(version_text);
  printf("\n");
  printf("Press enter to exit program.");
  getchar();
  system("clear");
}
