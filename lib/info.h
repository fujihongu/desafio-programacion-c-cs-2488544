#ifndef INFO_H
#define INFO_H

typedef struct s_info
{
  char *version_text;
  char current_date[15];
  unsigned short int op_id;
} t_info;

// Sout: show date on the standard output. Fout: use date for file output.
enum t_datemode
{
  sout,
  fout
};

void init_text(t_info *info);
int get_date(t_info *info, enum t_datemode dmode);
void get_id(t_info *info);
void show_info(t_info info);
void show_menu(void);
void show_end_info(t_info info);
char *strlwr(char *str);

#endif