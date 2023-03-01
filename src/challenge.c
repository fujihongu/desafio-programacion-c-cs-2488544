/*Author: Flaviu E. Hongu (Noriel Sylvire)
Platform: LinkedIn Learning, thanks to Fujitsu*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Sout: show date on the standard output. Fout: use date for file output.
enum t_datemode
{
  sout,
  fout
};

static const char version_text[50] = "Error Logger C Challenge Version 0";
char current_date[15];
unsigned short int op_id;

void init_text(void);
void get_id(void);
void logger(void);
void show_info(void);
void show_menu(void);
void show_end_info(void);
int get_date(enum t_datemode dmode);
int grab_command(void);
int execute_command(int cmd_nbr);
int generate_log(void);

int main(void)
{
  init_text();
  logger();
  return (0);
}

void init_text(void)
{
  system("clear");
  printf("Initializing logging manager.\nDetecting current date...\n");
  get_date(sout);
  get_id();
  printf("Press enter to start.\n");
  getchar();
  system("clear");
}

void get_id(void)
{
  printf("Please input your operator ID: ");
  scanf("%d", (int *)&op_id);
  getchar();
  printf("Operator Flaviu Emanuel Hongu with ID %d identified.\nProceeding with the initialization.\n", (int)op_id);
}

int get_date(enum t_datemode dmode)
{
  FILE *logfile;
  int file_created;
  time_t current_time;
  struct tm local_time;

  file_created = 0;
  current_time = time(NULL);
  local_time = *localtime(&current_time);
  if (strftime(current_date, sizeof(current_date), "%Y-%m-%d", &local_time) != 0)
  {
    if (dmode == sout)
    {
      printf("Current date: %s\n", current_date);
      return (1);
    }
    else
    {
      char *logname = strcat(current_date, ".log");
      printf("Creating log file %s...\n", logname);
      logfile = fopen(logname, "a");
      // Fill it in with stuff
      fclose(logfile);
      file_created = 1;
    }
  }
  else
    printf("Date Error.\n");
  return (file_created);
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
  printf("\n");
  if (strlen(command) == 1 && *command == '0')
    return (execute_command(0));
  else if (cmd_nbr != 0)
  {
    return (execute_command(cmd_nbr));
  }
  else
    printf("Invalid action number or command.\nPlease, input a valid action.\n");
  printf("Press enter to continue.\n");
  getchar();
  system("clear");
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
    if (generate_log())
      printf("Log generated successfully.\n");
    else
      printf("Ran into an error while attempting to create logfile.\n");
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
  printf("Press enter to exit program.\n");
  getchar();
  system("clear");
}

int generate_log(void)
{
  printf("Logging today's error history...\n");
  return (get_date(fout));
}
