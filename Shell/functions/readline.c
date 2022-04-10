#include <stdio.h>
/**
* readline - function that read the input line
*
* line: input line
* bufsize: size of the malloc that getline automatically creates
*
* Return: the input line already read
*/
char *readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);

	return (line);
}
