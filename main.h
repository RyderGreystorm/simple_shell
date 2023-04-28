#ifndef MAIN_H
#define MAIN_H
#define CMD_LEN 100
#define E_O_F -2
#define EXIT_VAR -3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
#include <signal.h>

extern char **environ;
extern char *err_name;
extern int hist;

/**
 * struct lists_s - functions
 * @dir: path of dir.
 * @next: next node.
 */
typedef struct lists_s
{
	char *dir;
	struct lists_s *next;
} lists_t;

/**
 * struct builtins_s - functions
 * @name: builtin command.
 * @f: func ptr.
 */
typedef struct builtins_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtins_t;

/**
 * struct aliases_s - function 
 * @name: alias.
 * @value: The value
 * @next: alias_s ptr.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} aliases_t;

extern aliases_t *aliases;

int _strncmp(const char *str1, const char *str2, size_t bytes);
int _strcmp(char *str1, char *str2);
int _strspn(char *str1, char *str2);
char *_strchr(char *needle, char haystack);
int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t bytes);
char *_strdup(char *str);
int _putchar(char c);
int execute(char **args, char **bufptr);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);
void _printf(char *str);
void *my_realloc(void *ptr, unsigned int size1, unsigned int size2);
void _lineptr(char **ptr, size_t *mem, char *buffer, size_t bytes);
ssize_t _getline(char **ptr, size_t *mem, FILE *stream);
char *get_location(char *cmd);

/*Aliases*/
int my_alias(char **args, char __attribute__((__unused__)) **node);
void set_alias(char *var_name, char *value);
void display_alias(aliases_t *alias);
char **change_aliases(char **args);
/*tokenization*/
int token_length(char *token, char *delim);
int count_tokens(char *token, char *delim);
char **_strtok(char *buffer, char *delim);
/*error1*/
int num_length(int num_len);
char *_itoa(int num_len);
int handle_error(char **str_arg, int err);

/*enviroment variables*/
char **_cpyenv(void);
void free_env(void);
char **_getenv(const char *var);
void variable_replacement(char **buff, int *exe);
char *get_pid(void);
void free_args(char **args, char **ptr);
char *get_env_value(char *needle, int haystack);
/*PATH*/
char *fill_path_dir(char *path);
lists_t *get_path_dir(char *path);

/*logical operators*/
void logical_ops(char *buffer, ssize_t *_len);
ssize_t get_new_len(char *buffer);
void handle_line(char **buffer, ssize_t read);

int sh_env(char **args, char __attribute__((__unused__)) **ptr);
int sh_setenv(char **args, char __attribute__((__unused__)) **ptr);
int sh_unsetenv(char **args, char __attribute__((__unused__)) **ptr);
int (*get_builtin(char *command))(char **args, char **adv);
int sh_exit(char **args, char **adv);
int sh_cd(char **args, char __attribute__((__unused__)) **adv);
int sh_help(char **args, char __attribute__((__unused__)) **adv);
/*error handlers0*/
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/*helpcmd*/
void help_all(void);
void help_alias(void);
void help_unsetenv(void);
void help_history(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);


/*fileahndling*/
int file_not_open(char *path);
int _file_commands(char *path, int *ex);
void free_args(char **args, char **front);
char *get_pid(void);

/*args handler from input*/
int handle_args(int *exe_ret);
int check_args(char **args);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
/*linked list operations*/
aliases_t *add_alias_end(aliases_t **head, char *name, char *value);
void free_alias_list(aliases_t *head);
lists_t *add_node_end(lists_t **head, char *dir);
void free_list(lists_t *head);


#endif /*MAIN_H*/
