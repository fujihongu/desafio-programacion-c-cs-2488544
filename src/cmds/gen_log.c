#include <stdio.h>
#include "../../lib/info.h"
#include "../../lib/gen_log.h"

int generate_log(t_info info)
{
  printf("Logging today's error history...\n");
  return (get_date(info, fout));
}
