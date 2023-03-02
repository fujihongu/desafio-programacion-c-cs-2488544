#include <stdio.h>
#include <string.h>
#include "../../lib/del_log.h"

void del_log(t_info info)
{
  char *logname;

  logname = strcat(info.current_date, ".log");
  if (remove(logname) == 0)
  {
    printf("Log file deleted successfully.\n");
  }
  else
  {
    printf("ERROR: File could not be deleted.\n");
  }
}