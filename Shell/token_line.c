#include "main.h"
#define TOKBUFSIZE 64
#define TOKDELIM "/t/r/n/a"
/**
* token_line - function for the tokenization of the input line
*
* @line: previus input line
*
* bufsize: capacity of the buffer
* position: always positioned in the beginning of the buffer at startup
* buff: capacity for the tokenized line memory allocation
* token: tokenization of the input line
*
* Return: buff with the tokenized line successfuly allocated
*/
char **token_line(char *line)
{
	int bufsize = TOKBUFSIZE, position = 0;
	char **buff = malloc(bufsize * sizeof(char *));
	char *token;

	if (!buff)
	{
		perror(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKDELIM);

	while (token != NULL)
	{
		token[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOKBUFSIZE;
			buff = realloc(buff, bufsize * sizeof(char *));

			if (!buff)
			{
				perror(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKDELIM);
	}

	buff[position] = NULL;
	return (buff);
}
