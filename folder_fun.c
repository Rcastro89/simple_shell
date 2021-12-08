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
 * no_isatty - non-interactive mode
 * @comand: command entered by user
 * @memory: memory used by getline
 * @array: parameter array (not interective)
 */
void no_isatty(char *comand, size_t memory, char *array[])
{
	ctr_error_isaty = -1;
	getline(&comand, &memory, stdin);
	select_command(comand, array[0]);
	if (com_exit == 0)
	{
		free(comand);
		return;
	}
}
/**
 * select_command - check the command or path entered
 * @comand: command entered by user
 * @array: parameter array (not interective)
 * Return: NULL
 */
void **select_command(char *comand, char *array)
{
	int dir;
	char *delim = " \n\t\"";
	char *exe;
	char *copycom = NULL, **get_path = NULL, *str1;

	get_path = search_path("PATH=");
	str1 = *get_path;
	copycom = _strdup(comand);
	dir = comp_comand(comand, '/');
	if (dir == 0)
	{
		only_comand(copycom, str1, comand, array);
	}
	else
	{
		exe = strtok(copycom, delim);
		argv_exec(comand, exe);
	}
	free(fill[0]);
	free(fill);
	free(copycom);
	return (NULL);
}
/**
 * search_path - Find the location of the PATH in the environment
 * @path: searched string "PATH ="
 * Return: PATH
 */
char **search_path(char *path)
{
	char **ret = environ, comp[5] = {0};
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
		perror("./shell");
		if (ctr_error_isaty == -1)
			_exit(127);
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

	for (i = 0; command[i] != simbol && command[i] != '\0' ; i++)
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
