#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
* main - shellcita
* 
*
* Return: zero
*/
int main(void)
{
	size_t buffersize = 0;
	char *buffer = 0;
	const char sp[3] = " ";
	char *tok;

	while (1)
	{
		printf("\033[0;31mNax$ \033[0m");
		getline(&buffer, &buffersize, stdin);
		tok = strtok(buffer, "\n");
		tok = strtok(buffer, sp);

		if (tok[0] == '\n')
			continue;

		while (tok != NULL)
		{
			printf("%s\n", tok);
			tok = strtok(NULL, sp);
		}
		free(tok);
		free(buffer);
	}
	return (buffersize);
}
