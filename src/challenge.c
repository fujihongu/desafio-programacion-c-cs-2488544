/*Author: Flaviu E. Hongu (Noriel Sylvire)
Platform: LinkedIn Learning, thanks to Fujitsu*/

#include <stdio.h>
#include "../lib/logger.h"

int main(void)
{
  t_info info;
  info.version_text = "Error Logger C Challenge Version 0.1\n";
  init_text(&info);
  logger(info);
  return (0);
}
