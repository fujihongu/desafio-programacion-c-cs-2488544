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
  char *decision = malloc(sizeof(char) * 5);
  switch (cmd_nbr)
  {
  case 1:
    log_error(info.op_id, info);
    break;
  case 2:
    if (generate_log(info))
      printf("Error log generated successfully.\n");
    else
      printf("Ran into an error while attempting to create logfile.\n");
    break;
  case 3:
    printf("This action is irreversible. Please, confirm. (y/n) ");
    while (1)
    {
      scanf("%s", decision);
      decision = strlwr(decision);
      if (*decision == 'y')
      {
        del_log(info);
        break;
      }
      else if (*decision == 'n')
      {
        break;
      }
      else
      {
        printf("Please, either type (y)es or (n)o.\n");
        printf("Deleting today's log is irreversible. Please, confirm (y/n) ");
      }
    }
    getchar();
    free(decision);
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