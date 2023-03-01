#include "logger.h"

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