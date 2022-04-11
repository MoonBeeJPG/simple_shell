#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lsh_exit(char **args);
int lsh_launch(char **args);
int lsh_execute(char **args);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
void lsh_loop(void);
int lsh_num_builtins(void);
int compare(char *str1, char *str2);

#endif
