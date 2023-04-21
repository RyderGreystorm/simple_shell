#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcpy(char *des, char *src);
int _strlen(char *str);
void _printf(char *str);
int _putchar(char c);
void exec(char **argv);
int fork_exe(char **argv);
char *get_path(char *cmd);
char *_strcat(char *des, char *src);
char *_strdup(char *str);
extern char **environ;
char *get_input(void);
void exit_func(char **args);
void _cd(char **args);
void env_builtin(void);
#endif /**MAIN_H*/
