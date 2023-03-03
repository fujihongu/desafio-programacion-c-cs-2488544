#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/del_log.h"

void del_log(t_info info)
{
  FILE *logfile;
  FILE *backup;
  char *logname = malloc(sizeof(info.current_date) + 5);
  char *backupname = malloc(sizeof(info.current_date) + 10);
  char cp;

  // Get file names
  logname = strcpy(logname, info.current_date);
  logname = strcat(logname, ".log");
  backupname = strcpy(backupname, info.current_date);
  backupname = strcat(backupname, ".log.bak");
  // Open backup and log files
  backup = fopen(backupname, "w+");
  logfile = fopen(logname, "a+");
  // Copy contents of logfile into backup, then close them both
  cp = fgetc(logfile);
  while (cp != EOF)
  {
    fputc(cp, backup);
    cp = fgetc(logfile);
  }
  fclose(backup);
  fclose(logfile);
  if (remove(logname) == 0)
  {
    printf("Log file deleted successfully.\n");
  }
  else
  {
    printf("ERROR: File could not be deleted.\n");
  }
}