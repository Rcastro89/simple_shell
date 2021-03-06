#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct buily_in - Struct built
 * @comand: format
 * @f: The function associated
 */
typedef struct buily_in
{
	char *comand;
	int (*f)(char *);
} bu_in;


extern char **environ;
int laps;

int select_command(char *comand, char *array, int ctr_error_isaty);
int error(char *comand, int readcomand);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *tok(char *path, char *limit);
char *_strcat(char *dest, char *src);
int comp_comand(char *command, char simbol);
int proccess_fork(char *exe, char **argv);
int loop_token(char *str1, char *token1, char *comand, int ctr_error_isaty);
char *_strdup(char *str);
void ctr_c(int ctr1_c);
int only_comand(char *copycom, char *str1, char *comand,
char *array, int ctr_error_isaty);
void argv_exec(char *comand, char *exe, int ctr_error_isaty);
int (exit_program(__attribute__((unused))char *command));
int (*built_in(char *commad))(char *);
int fun_error(__attribute__((unused))char *command);
int comp_comand_1(char *command, char simbol);
int print_environ(__attribute__((unused))char *command);
char **search_path(char *path, int ctr_error_isaty,
char *array, char *copycom);
int _putchar(char c);
void _puts(char *str);
void _EOF(char *comand);

#endif /* MAIN_H */
