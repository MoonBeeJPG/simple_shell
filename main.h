#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _strlen(char *s);
int _putchar(char c);
int builtin_env(void);
int builtin_exit(char **tokenized);
int builtin_cd(char **tokenized);
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
