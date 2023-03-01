#include "gen_log.h"

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

int generate_log(void)
{
  printf("Logging today's error history...\n");
  return (get_date(fout));
}
