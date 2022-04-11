#include "main.h"

/**
 * sighand - handles signals
 * @sighandv: sighandv
 */

void sighand(__attribute__((unused)) int sighandv)
{
	write(STDIN_FILENO, "\n$ ", 4);
}
