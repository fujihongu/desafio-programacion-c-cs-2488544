#ifndef INFO_H
#define INFO_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Sout: show date on the standard output. Fout: use date for file output.
enum t_datemode
{
  sout,
  fout
};

static const char version_text[50] = "Error Logger C Challenge Version 0";
char current_date[15];
unsigned short int op_id;

void init_text(void);
void get_id(void);
void show_info(void);
void show_menu(void);
void show_end_info(void);

#endif