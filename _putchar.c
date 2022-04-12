#include "main.h"
/**
* _putchar - to use with environ
*
* @c: a paremetr
*
* Return: success
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
