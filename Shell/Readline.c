#include "main.h"
/**
* sh_read_line - function that read your command
*/
char *sh_read_line(void)
{
	int bufsize = SH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buf) {
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		//read character
		c = getchar();

		//if is EOF, replace with NULL and return
		if (c = EOF) || ('c == '\n') {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		//if exceeded the buffer, realloc
		if (position >= bufsize) {
			bufsize += SH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "sh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
