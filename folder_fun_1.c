#include "main.h"
/**
 * comp_comand_1 - look for special symbols
 * @command: command entered by user
 * @simbol: character to evaluate
 * Return: Symbol count
 */
int comp_comand_1(char *command, char simbol)
{
	int ret = 0, i;

	for (i = 0; command[i] == ' ' || command[i] == '\0'; i++)
		;
	for (; command[i] != '\0'; i++)
	{
		if (command[i] == simbol)
		{
			ret++;
		}
	}
	return (ret);
}
/**
 * only_comand - evaluate command
 * @copycom: copy of command entered by user
 * @str1: PATH
 * @comand: command entered by user
 * @array:  parameter array (not interective)
 */
void only_comand(char *copycom, char *str1, char *comand, char *array)
{
	char *token1;
	int ctr_error = -1, k = 0;
	char *delim = " \n\t\"", **built = NULL;

	token1 = strtok(copycom, delim);
	k = _strlen(token1);
	token1[k + 1] = '\0';
	ctr_error = loop_token(str1, token1, comand);
	if (ctr_error == -1 && ctr_error_isaty != -1)
	{
		built = malloc(sizeof(char) * _strlen(copycom));
		*built = _strdup(copycom);
		built_in(copycom)(built);
		free(built[0]);
		free(built);
		return;
	}
	else if (ctr_error == -1 && ctr_error_isaty == -1)
	{
		write(STDOUT_FILENO, array, _strlen(array));
		write(STDOUT_FILENO, ": 1: ", 5);
		write(STDOUT_FILENO, copycom, _strlen(copycom));
		write(STDOUT_FILENO, ": not found\n", 12);
		exit(127);
	}
}

/**
 * loop_token - concatenate the PATH
 * @token1: copy of command entered by user
 * @str1: PATH
 * @comand: command entered by user
 * Return: (0) success (-1) Error
 */
int loop_token(char *str1, char *token1, __attribute__((unused))char *comand)
{
	int j, ctr_error = -1;
	char *token = NULL, *exe = NULL, *sim = "/\0";
	struct stat buf;

	for (j = 1; ; j++, str1 = NULL)
	{
		token = strtok(str1, ":");
		if (token == NULL)
			break;
		exe = malloc(sizeof(char) * (_strlen(token1) + _strlen(token)) + 2);
		if (exe == NULL)
			return (-1);
		exe[0] = '\0';
		exe = _strcat(exe, token);
		exe = _strcat(exe, sim);
		exe = _strcat(exe, token1);
		if (stat(exe, &buf) == 0)
		{
			ctr_error = 0;
			argv_exec(comand, exe);
			free(exe);
			break;
		}
		free(exe);
	}
return (ctr_error);
}
/**
 * argv_exec - build the argument for the execv command
 * @comand: command entered by user
 * @exe: PATH complete
 */
void argv_exec(char *comand, char *exe)
{
	char *delim = " \n\t\"", *argv[1024], *token1;
	int count_comands, j;
	struct stat buf;

	count_comands = comp_comand_1(comand, ' ');
	if (count_comands != 0)
	{
		for (j = 0; ; j++, comand = NULL)
		{
			token1 = strtok(comand, delim);
			if (token1 == NULL)
				break;
			argv[j] = token1;
		}
		argv[j] = NULL;
	}
	else
		argv[0] = exe, argv[1] = NULL;
	if (stat(exe, &buf) == 0)
		proccess_fork(exe, argv);
	else
	{
		perror("./shell");
		if (ctr_error_isaty == -1)
			_exit(127);
	}
}
/**
 * proccess_fork - spawn the child process to run the program
 * @exe: path complete
 * @argv: execv parameters
 * Return: (0) success
 */
int proccess_fork(char *exe, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		perror("./shell");
	else if (pid > 0)
		wait(NULL);
	else
	{
		execv(exe, argv);
		exit(1);
	}
	return (0);
}
