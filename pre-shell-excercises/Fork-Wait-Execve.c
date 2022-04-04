#include <sys/signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
/**
* main - Fork, exit and execve
*
* Return: 0
*/
int main(void)
{
	char *file = NULL;
	size_t len = 0;
	char *args[] = {"/bin/ls", "-l", "/usr/", NULL};

	while (1)
	{
		getline(&file, &len, stdin);
	
		if (fork() != 0)
		{
			wait (NULL);
		}
		else
		{
			execve(args[0], args, 0);
		}
	}
	free(file);
	return (0);
}
