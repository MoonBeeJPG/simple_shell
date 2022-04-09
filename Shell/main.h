#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char (*buildint_arr[]);
int(*buildint_func[])(char **);
int buildint_num(void);
int exit(char **tok);
void loop(void);
int match(char **tok);
char *read_line(void);
int shell(char **tok);
char **token_line(char *line);

#endif
