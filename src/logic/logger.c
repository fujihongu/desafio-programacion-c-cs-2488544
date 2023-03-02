#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/logger.h"

void logger(t_info info)
{
  int exit;

  exit = 0;
  while (!exit)
  {
    show_info(info);
    show_menu();
    exit = grab_command(info);
  }
  system("clear");
  show_end_info(info);
}

int grab_command(t_info info)
{
  char command[15];
  int cmd_nbr;

  scanf("%s", command);
  getchar();
  cmd_nbr = atoi(command);
  printf("\n");
  if (strlen(command) == 1 && *command == '0')
    return (execute_command(info, 0));
  else if (cmd_nbr != 0)
  {
    return (execute_command(info, cmd_nbr));
  }
  else
    printf("Invalid action number or command.\nPlease, input a valid action.\n");
  printf("Press enter to continue.\n");
  getchar();
  system("clear");
  return (0);
}

int execute_command(t_info info, int cmd_nbr)
{
  switch (cmd_nbr)
  {
  case 1:
    printf("You logged an error.\n");
    break;
  case 2:
    if (generate_log(info))
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