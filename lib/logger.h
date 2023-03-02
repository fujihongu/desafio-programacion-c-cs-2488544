#ifndef LOGGER_H
#define LOGGER_H

#include "gen_log.h"
#include "log_error.h"
#include "del_log.h"

void logger(t_info info);
int grab_command(t_info info);
int execute_command(t_info info, int cmd_nbr);

#endif