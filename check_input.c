#include "main.h"
/**
* checkinput - Function that check if the
* input reading some characters or not
*
* @line: Line previously read
*
* Return: -1 it its fail
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
	return (retu);
}
