#include "main.h"
/**
* builtin - An array that stores all the built in names
*
* @builtin: For betty checking
*/
char (*builtin[]) = {
	"exit"
};

/**
* builtin_func - An array that stores all the built in functions that
* corresponds with every built in name
*
* @builtin_func: For betty checking
*/
int (*builtin_func[]) (char **) = {
	&builtin_exit
};

/**
* countbuiltins - Returns the size of the built in name and lately
* compares it with the size of tokenized input
*
* Return: Size of the built in name
*/
int countbuiltins(void)
{
	return (sizeof(builtin) / sizeof(char *));
}

/**
* builtin_exit - Built in for the command exit
*
* @tokenized: previous tokenized input
*
* Return: Always zero at the end of the execution
 */
int builtin_exit(char **tokenized)
{
	return (0);
}

/**
* match - compares the size of the built int name and the size of the tokenized
* input
*
* @tokenized: previous tokenized line
*
* Return: If the tokenized input are not any of the buildint the
* shell go to the system programs and work with pid and ppid
*/
int match(char **tokenized)
{
	int i;

	if (tokenized[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < countbuiltins(); i++)
	{
		if (compare(tokenized[0], builtin[i]) == 0)
		{
			return ((*builtin_func[i])(tokenized));
		}
	}

	return (shell(tokenized));
}
