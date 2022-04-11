#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
*main - program that prints "$ ", wait for the user to enter a command
*prints it on the next line.
*function that splits a string and returns an array of each word of the string.
*/
int main(void)
{
	size_t buffersize = 0;
	char *buffer = 0;
	const char sp[3] = " ";
    char *tok;
	int prompt();

	while (1)
	{
        prompt();
        getline(&buffer, &buffersize, stdin);
        tok = strtok(buffer, "\n");
        tok = strtok(buffer, sp);
		if (tok[0] == '\n')
			continue;
        while(tok != NULL)
        {
            printf("%s\n", tok);
            tok = strtok(NULL, sp);
		}
		free(tok);
	}
	free(tok);
	free(buffer);
	return (buffersize);
}
