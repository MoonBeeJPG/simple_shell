#include "main.h"
/**
* match - function that matches the tokenized line input with the
* corresponding program or buildint
*
* @tok: previous tokenized line
*
* Return: If the tokenized input are not any of the buildint the
* shell go to the system programs and work with pid and ppid
*/
int match(char **tok)
{

	if (tok[0] == NULL)
	{
		return (1);
	}

	return (shell(tok));
}
