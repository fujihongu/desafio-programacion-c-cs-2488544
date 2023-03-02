#include <stdio.h>
#include <stdlib.h>
#include "../../lib/gen_log.h"

int generate_log(t_info info)
{
  int exists;

  exists = 0;
  system("clear");
  printf("Logging today's error history...\n");
  exists = get_date(&info, fout);
  return (exists);
}
