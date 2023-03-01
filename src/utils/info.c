#include "info.h"

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

void show_end_info(void)
{
  printf("Exiting session 'Flaviu Emanuel Hongu'...\n\n");
  printf(version_text);
  printf("\n");
  printf("Press enter to exit program.\n");
  getchar();
  system("clear");
}
