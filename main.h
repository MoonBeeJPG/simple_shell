#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int builtin_exit(char **tokenized);
int counter(char *line);
void signalctrl_c(int signal);
int checkinput(char *line);
int _strlen(char *s);
int builtin_env(char **tokenized);
int shell(char **tokenized);
int match(char **tokenized);
char *readline(void);
char **tokenize_input(char *line);
void infiniteloop(void);
int countbuiltins(void);
int compare(char *str1, char *str2);
int main(void);
void sighand(__attribute__((unused)) int sighandv);
#endif
