#include "main.h"
/**
* loop - Infinite loop that are always on when the shell runs
*
* line: the input, when the person writes something this is the line reading
* tok: the previous line tokenized
* func: the program corresponding to the input read and tokenized
*
*/
void loop(void)
{
	char *line;
	char **tok;
	int func;

	do {
		printf("#cisfun$ ");
		line = readline();
		tok = token_line(line);
		func = match(tok);

		free(line);
		free(tok);
	} while (func);
}
