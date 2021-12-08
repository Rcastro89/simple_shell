#include "main.h"
/**
 * main - main function of the program
 * @argc: number of parameters (not interective)
 * @array: parameter array (not interective)
 * Return: (0) success
 */
int main(__attribute__((unused))int argc, char *array[])
{
	size_t memory = 1;
	ssize_t ending = 0;
	char *comand = NULL, waiting[] = "prompt$ ";

	com_exit = 1;
	if (isatty(fileno(stdin)))
	{
		signal(SIGINT, ctr_c);
		while (com_exit != 0)
		{
			write(STDOUT_FILENO, waiting, _strlen(waiting));
			ending = getline(&comand, &memory, stdin);
			if (ending == -1)
			{
				free(comand);
				write(STDOUT_FILENO, "\n", 1);
				exit(127);
			}
			else if (*comand != 10)
			{
				select_command(comand, array[0]);
				if (com_exit == 0)
				{
					free(comand);
					return (0);
				}
			}
			free(comand);
			comand = NULL;
		}
	}
	else
		no_isatty(comand, memory, array);
	free(comand);
	return (0);
}
