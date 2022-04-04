#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
* main - Read Line
*
* Return: 0
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	printf("$ ");
	
	getline(&line, &len, stdin);
	
	printf("%s", line);
	
	free(line);
	return (0);
}
