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
	size_t size; //st can be a 64 bits
	size_t len = 0;
	char args[] = "/bin/ls l /usr/";
	char *token = strtok(args, " /");
	struct stat st_size;

	while (1)
	{
		getline(&file, &len, stdin);
		//is a stat
		if (stat(file, len) == 0)
		{
			size = len->st_size;
			printf("size of \"%s\" is %ld bytes.\n", file, size);
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
			execve(args, 0);
			if (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, " /");
			}
		}
	}
	free(file);
	return (0);
}
