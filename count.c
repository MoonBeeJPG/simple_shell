#include "main.h"
/**
* counter - Function that count line arguments
*
* @line: previous line read
*
* Return: counter of arguments
*/
int counter(char *line)
{
	size_t counter = 0;
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] == 32)
		{
			if (line[i + 1] == 32)
			{
				i++;
				continue;
			}
			else
			{
				counter++;
				i++;
			}
		}
		else
			i++;
	}
	counter += 2;
	return (counter);
}
