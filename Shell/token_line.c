#include "main.h"
/**
*
* token_line - read the line
* 
*/
char **token_line(char *line)
{
	int bufsize = TOKBUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocatoin error\n");
		exit(EXIT_FAILURE);
	}
}

	token = strtok(line, TOKDELIM);
	while (token != NULL)
	{
		token[position] = token;
		position++;

	if (postion >= bufsize)
	{
		bufsize += TOKBUFSIZE;
		tokens = realloc(tokens, bufsize *sizeof(char*));
		if (!tokens)
		{
			fprintf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, TOKDELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
