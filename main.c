#include "main.h"
/**
 * main - main function of the program
 * @argc: number of parameters (not interective)
 * @array: parameter array (not interective)
 * Return: (0) success
 */
int main(__attribute__((unused))int argc, char *array[])
{
	size_t memory = 0;
	ssize_t ending = 0;
	char *comand, waiting[] = "prompt$ ";
	int com_exit = 0, ctr_error_isaty = -1;

	laps = 0;
	signal(SIGINT, ctr_c);
		while (com_exit != 2 && com_exit != 127)
		{
			if (isatty(fileno(stdin)))
			{
				ctr_error_isaty = 0;
				write(STDOUT_FILENO, waiting, _strlen(waiting));
			}
			else
				laps++;
			comand = NULL;
			ending = getline(&comand, &memory, stdin);
			if (ending == EOF)
				_EOF(comand);
			else if (ending == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				perror("./shell");
			}
			else if (*comand != 10)
			{
				com_exit = select_command(comand, array[0], ctr_error_isaty);
				free(comand);
			}
			else
				free(comand);
		}
	if (laps == 2)
		return (2);
	if (com_exit == 127)
		return (127);
	return (0);
}
