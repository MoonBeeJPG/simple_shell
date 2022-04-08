#include "main.h"

void sh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = sh_read_line();
		args = sh_token_line(line);
		status = sh_execute(args);

		free(line);
		free(args);
	}	while (status);
}
