#include <sys/signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
/**
* main - Strtok Fork Getline
*
* Return: 0
*/
int main(void)
{
	char *file = NULL;
	size_t len = 0;
	char *args[] = {"/bin/ls", "-l" ,"/usr/"};
	char *token;
	int status;

	while (1)
	{
		printf("#cisfun$");
		if (getline(&file, &len, stdin) == -1);
			printf("error");
		token = strtok(file, " ");
		token = strtok(NULL, " ");

		if (fork() != 0)
		{
			wait (NULL);
		}
		if (fork() == 0)
		{
			if (execve(args[0], args, 0))
        	{
           		perror("execve");
           		exit(EXIT_FAILURE);
        	}
		}
		if (fork() > 0)
			wait(&status);
	}
	putchar('\n');
	free(file);
	exit (status);
}
