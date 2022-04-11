#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int exit(char **args);
int main(char **args);
int match(char **args);
char *readline(void);
char **tokenize_input(char *line);
void infiniteloop(void);
int countbuiltins(void);
int compare(char *str1, char *str2);
int runloop(void);

#endif
