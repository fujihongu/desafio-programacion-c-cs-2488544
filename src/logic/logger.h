#ifndef LOGGER_H
#define LOGGER_H

#include "../utils/info.h"

void logger(void);
int grab_command(void);
int execute_command(int cmd_nbr);

#endif