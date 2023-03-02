#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../../lib/log_error.h"

/// @brief Adds a user generated error log to today's logfile
/// @param op_id current user's operator ID
/// @param info the t_info struct containing today's date and other info
void log_error(int op_id, t_info info)
{
  char error[100];
  char *logname;
  char time_of_day[50];
  FILE *logfile;
  time_t current_time;
  struct tm local_time;

  // Get current local time
  current_time = time(NULL);
  local_time = *localtime(&current_time);
  // Format time_of_day to contain the hour, minute an second of the local time
  strftime(time_of_day, sizeof(time_of_day), "%H:%M:%S", &local_time);
  printf("Introduce error summary. Max summary length: 100\nPrompt: ");
  fgets(error, sizeof(error), stdin);
  // Open today's logfile, and add the error logged by the operator, formatted with ID, name, and hour
  logname = strcat(info.current_date, ".log");
  logfile = fopen(logname, "a");
  fprintf(logfile, "\nFlaviu Emanuel Hongu - %d", op_id);
  fprintf(logfile, "\n%s; %s\n", time_of_day, error);
  fclose(logfile);
  // After successfully adding an error to the error log, let the user know
  printf("\nYour error was logged successfully.\n");
}