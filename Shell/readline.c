#include "main.h"
/**
* read_line - function that read the input line 
*
* line: input line
* bufsize: size of the malloc that getline automatically creates
*
* Return: the input line already read
*/
char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		perror("readline");
		exit(EXIT_FAILURE);
	}
	
	return line;
}
