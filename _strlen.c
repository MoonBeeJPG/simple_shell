#include "main.h"
/**
* _strlen - calculate the length of a string
*
* @s: string
*
* Return: length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}