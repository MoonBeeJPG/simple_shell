#include <stdio.h>
#include <unistd.h>
/**
* type_prompt - terminal
* @first_display: muestra la terminal en apagado encendido
*/
void type_prompt ()
{
	static int first_display = 1;
	if (first_display)
	{
	const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	first_display = 0;
	}
	printf("#");
}
