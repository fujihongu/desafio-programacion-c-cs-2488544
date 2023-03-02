/*Author: Flaviu E. Hongu (Noriel Sylvire)
Platform: LinkedIn Learning, thanks to Fujitsu*/

#include <stdio.h>
#include "../lib/logger.h"

int main(void)
{
  t_info info;
  info.version_text = "Error Logger C Challenge Version 0";
  init_text(&info);
  printf("\n\ntest\n\n");
  printf("\n\ntest    %d\n\n", info.op_id);
  logger(info);
  return (0);
}
