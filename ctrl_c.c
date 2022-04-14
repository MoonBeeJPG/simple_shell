#include "main.h"

/**
 * _ctrl_c - function that ignores ctrl + c input from keybord and prints a
 * break line with $ symbol.
 * @signal: signal to ignore
 **/

void signalctrl_c(int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
