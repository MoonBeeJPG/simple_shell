#include "main.h"
/**
* checkinput - inputcheck
*
* @line: Line previously read
*
* Return: returning
*/
int checkinput(char *line)
{
	int i = 0, retu = -1;

	while (line[i])
	{
		if (line[i] != '\t' && line[i] != 32 && line[i] != 10)
		{
			retu = 0;
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
