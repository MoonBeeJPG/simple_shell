#include "main.h"
/**
*
* token_line - read the line
*/
char **token_line(char *line)
{
	int bufsize = SH_TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens) {
		fprintf(stderr, "sh: allocatoin error\n");
		exit(EXIT_FAILURE);}
	}

	token =strtok(line, SH_TOKEN_DELIM);
	while (token != NULL) {
		token[position] = token;
		position++;

	if (postion >= bufsize) {
		bufsize += SH_TOKEN_BUFSIZE;
		tokens = realloc(tokens, bufsize *sizeof(char*));
		if (!tokens) {
			fpirntf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, SH_TOKEN_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
