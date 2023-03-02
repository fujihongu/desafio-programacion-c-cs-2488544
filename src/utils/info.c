#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "../../lib/info.h"

void init_text(t_info *info)
{
  system("clear");
  printf("Initializing logging manager.\n");
  get_date(info, sout);
  get_id(info);
  printf("\nInitialization successful.\nPress enter to start.\n");
  getchar();
  system("clear");
}

int get_date(t_info *info, enum t_datemode dmode)
{
  FILE *logfile;
  int file_created;
  time_t current_time;
  struct tm local_time;
  char full_date[100];

  printf("\nCalculating current date...\n");
  file_created = 0;
  current_time = time(NULL);
  local_time = *localtime(&current_time);
  if (strftime(info->current_date, sizeof(info->current_date), "%Y-%m-%d", &local_time) != 0)
  {
    if (dmode == sout)
    {
      strftime(full_date, sizeof(full_date), "%c", &local_time);
      printf("Current date: %s\n\n", full_date);
      return (1);
    }
    else
    {
      char *logname = strcat(info->current_date, ".log");
      logfile = fopen(logname, "a+");
      struct stat st;
      stat(logname, &st);
      if (st.st_size == 0)
      {
        strftime(full_date, sizeof(full_date), "%c", &local_time);
        printf("Creating log file %s...\n", logname);
        fprintf(logfile, "Error-log for %s.\n", full_date);
        fclose(logfile);
      }
      else
      {
        printf("Existing log file found: %s\nPrinting contents:\n\n", logname);
        char c = fgetc(logfile);
        while (c != EOF)
        {
          printf("%c", c);
          c = fgetc(logfile);
        }
        printf("\n\n");
        fclose(logfile);
      }
      file_created = 1;
    }
  }
  else
    printf("Date Error.\n");
  return (file_created);
}

void get_id(t_info *info)
{
  unsigned short int id;
  printf("Please input your operator ID: ");
  scanf("%hu", &id);
  info->op_id = id;
  getchar();
  printf("\nOperator Flaviu Emanuel Hongu with ID %hu identified.\nProceeding with the initialization...\n", info->op_id);
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

void show_info(t_info info)
{
  printf(info.version_text);
  printf("\n");
  printf("Operator ID: %d\nDate: %s\n", info.op_id, info.current_date);
}

void show_end_info(t_info info)
{
  printf("Exiting session 'Flaviu Emanuel Hongu'...\n\n");
  printf(info.version_text);
  printf("\n");
  printf("Press enter to exit program.\n");
  getchar();
  system("clear");
}

char *strlwr(char *str)
{
  char *copy;

  copy = str;
  while (*copy)
  {
    if (*copy >= 'A' && *copy <= 'Z')
      *copy = *copy + ('a' - 'A');
    copy++;
  }
  return (str);
}
