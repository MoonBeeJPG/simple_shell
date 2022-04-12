#include "main.h"
/**
* checkinput - inputcheck
*
* Return: returning
*/
int checkinput(char *line)
{
	int i = 0, returning = -1;

	while (line[i])
	{
		if (line[i] != '\t' && line[i] != 32 && line[i] != 10)
		{
			returning = 0;
			if (line[0] == ' ' && line[1] != ' ')
			{
				line = strtok(line, " ");
			}
			break;
		}
		i++;
	}
	return (returning);
}
