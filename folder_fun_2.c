#include "main.h"
/**
 * built_in - functions built in
 * @commad: command entered by user
 * Return: (0) success
 */
int (*built_in(char *commad))(char *)
{
	int i = 0;

	bu_in function_buil[] = {
		{"exit", exit_program},
		{"env", print_environ},
		{NULL, NULL},
		{"error", fun_error}
	};

	while (function_buil[i].comand != NULL)
	{
		if (_strcmp(function_buil[i].comand, commad) == 0)
		{
			return (function_buil[i].f);
		}
		i++;
	}
	return (function_buil[i + 1].f);
}
/**
 * exit_program - exit system
 * @command: command entered by user
 * Return: (0) success
 */
int (exit_program(__attribute__((unused))char *command))
{
	return (2);
}
/**
 * fun_error - control errors
 * @command: command entered by user
 * Return: (0) success
 */
int fun_error(__attribute__((unused))char *command)
{
	return (1);
}
/**
 * print_environ - function env
 * @command: command entered by user
 * Return: (0) success
 */
int print_environ(__attribute__((unused))char *command)
{
	unsigned int j;

	for (j = 0; environ[j]; j++)
		_puts(environ[j]);
	return (3);
}
