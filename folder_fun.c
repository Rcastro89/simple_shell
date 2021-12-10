#include "main.h"
/**
 * ctr_c - add new line by pressing ctr + c
 * @ctr1_c: SIGINT
 */
void ctr_c(int ctr1_c)
{
	char waiting[] = "prompt$ ";

	if (ctr1_c == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, waiting, _strlen(waiting));
	}
}
/**
 * select_command - check the command or path entered
 * @comand: command entered by user
 * @array: parameter array (not interective)
 * @ctr_error_isaty: check interactive or non-interactive input
 * Return: NULL
 */
int select_command(char *comand, char *array, int ctr_error_isaty)
{
	int dir, com_exit = 0;
	char *delim = " \n\t\"";
	char *exe;
	char *copycom = NULL, **get_path = NULL, *str1;

	copycom = strdup(comand);
	get_path = search_path("PATH=", ctr_error_isaty, array, copycom);
	dir = comp_comand(comand, '/');
	if (dir == 0)
	{
		if (get_path)
		{
			str1 = *get_path;
			com_exit = only_comand(copycom, str1, comand, array, ctr_error_isaty);
		}
		else
			com_exit = 127;
		if (get_path)
		{
			free(get_path[0]);
			free(get_path);
		}
		free(copycom);
	}
	else
	{
		exe = strtok(copycom, delim);
		argv_exec(comand, exe, ctr_error_isaty);
		free(get_path[0]);
		free(get_path);
		free(copycom);
	}
	return (com_exit);
}
/**
 * search_path - Find the location of the PATH in the environment
 * @path: searched string "PATH ="
 * @ctr_error_isaty: check interactive or non-interactive input
 * @array: parameter array (not interective)
 * @copycom: check interactive or non-interactive input
 * Return: PATH
 */
char **search_path(char *path, int ctr_error_isaty, char *array, char *copycom)
{
	char **ret = environ, comp[5] = {0}, **fill = NULL;
	int j = 0, i = 0, k = 0;

	while (*ret)
	{
		for (i = 0; i < 5; i++)
		{
			comp[i] = ret[j][i];
		}
		k = _strcmp(comp, path);
		if (k == 0)
		{
			k = _strlen(ret[j]);
			fill = malloc(sizeof(char) * k + 1);
			if (fill == NULL)
				return (NULL);
			*fill = _strdup(*ret);
			fill[0][4] = ':';
			break;
		}
		ret++;
	}
	if (fill == NULL)
	{
		if (ctr_error_isaty == -1)
		{
			write(STDERR_FILENO, array, _strlen(array));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, copycom, _strlen(copycom) - 1);
			write(STDERR_FILENO, ": not found\n", 12);
			return (fill);
		}
		perror("./shell");
	}
	return (fill);
}

/**
 * comp_comand - look for special symbols
 * @command: command entered by user
 * @simbol: character to evaluate
 * Return: Symbol count
 */
int comp_comand(char *command, char simbol)
{
	int ret = 0, i;
	char stop = ' ';

	for (i = 0; command[i] != simbol && command[i] != '\0'; i++)
		;
	for (; command[i] != stop && command[i] != '\0'; i++)
	{
		if (command[i] == simbol)
		{
			ret++;
		}
	}
	return (ret);
}
/**
 * _EOF - eof funtions
 * @comand: command entered by user
 */
void _EOF(char *comand)
{
	free(comand);
	if (isatty(fileno(stdin)))
		write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}
