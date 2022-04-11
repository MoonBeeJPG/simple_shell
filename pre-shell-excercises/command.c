#include "main.h"

/**
*commandexe - looks for the command and executes it
*@path: full PATH
*@command: command given
*Return: stat
*/
int commandexe(char **path, char **command)
{
	pid_t pid;
	int stat = 0;
/** int i;*/
/** printf("Starting %u\n", getpid());*/

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
/** printf("Child %u n*[%d], father[%u]\n", getpid(), i, getpid());*/
		stat = execve(path, command, NULL);
		exit(stat);
	}
	else
	{
		wait(NULL);
	}

/** printf("Ended\n");*/
	return (stat);
}
