#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
* main - Strtok
*
* Return: 0
*/
int main(void)
{
	char str[] = "hola hola hola";
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
