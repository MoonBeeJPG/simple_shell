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
	long long size; //st can be a 64 bits
	size_t len = 0;
	char args[] = "/bin/ls l /usr/";
	char *token = strtok(args, " ");
	errno = 0; //always set errno in zero

	while (1)
	{
		getline(&file, &len, stdin);
		//is a stat
		if (stat(file, len) == 0)
		{
			size = len->st_size;
			printf("size of \"%s\" is %lld bytes.\n", file, size);
		}
		else
		{
			perror(file); //if stat fail
		}
		if (fork() != 0)
		{
			wait (NULL);
		}
		else
		{
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, " /");
				if (execve("./shstat", args) == -1)
					perror("could not execve");
				return (1);
			}
		}
	}
	free(file);
	return (0);
}
