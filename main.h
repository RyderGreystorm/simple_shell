#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
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
int _strcmp(const char *str1, const char *str2);
int fork_exe(char **argv);
char *get_path(char *cmd);
char *_strcat(char *des, char *src);
char *_strdup(char *str);
extern char **environ;
char *get_input(void);
void exit_func(char **args);
void chdirectory(char **argv);
void env_builtin(char **args);
void setEnv(char **args);
void unsetEnv(char **args);
int executeBuiltIn(char **argv);
char **tokenization(char *buffer);
int fork_exe(char **argv);
int _strtok(void);
#endif /**MAIN_H*/
