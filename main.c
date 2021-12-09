#include "main.h"
/**
 * main - main function of the program
 * @argc: number of parameters (not interective)
 * @array: parameter array (not interective)
 * Return: (0) success
 */
int main()
{
	size_t memory = 0;
	ssize_t ending = 0;
	char *comand, waiting[] = "prompt$ ";
	int com_exit = 0;

	
	/*signal(SIGINT, ctr_c);*/
		while (com_exit != 2)
		{
			if (isatty(fileno(stdin)))
				write(STDOUT_FILENO, waiting, _strlen(waiting));
			comand = NULL;
			ending = getline(&comand, &memory, stdin);
			if (ending == EOF)
			{
				free(comand);
				if (isatty(fileno(stdin)))
					write(STDOUT_FILENO, "\n", 1);
				return(0);
			}
			else if (ending == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				perror("./shell");
			}
			else if (*comand != 10)
			{
				select_command(comand);
				free(comand);
			}
			else
				free(comand);
		}
	return (0);
}
