#include "main.h"

int select_command(char *comand)
{
	int com_exit = 0;
	
		argv_exec(comand);

	return (com_exit);
}

void argv_exec(__attribute__((unused))char *comand)
{
	struct stat buf;
	char *argv[1024];

	argv[0] = "/bin/ls", argv[1] = NULL;
	if (stat("/bin/ls", &buf) == 0)
		proccess_fork("/bin/ls", argv);
	else
	{
		perror("./shell");
	}
}

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