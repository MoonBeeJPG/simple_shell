#include "main.h"
/**
* _strlen - to environment
* Return: i
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
