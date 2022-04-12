#include "main.h"
/**
* builtin - An array that stores all the built in names
*
* @builtin: For betty checking
*/
char (*builtin[]) = {
	"exit",
	"env",
	"cd"
};

/**
* builtin_func - An array that stores all the built in functions that
* corresponds with every built in name
*
* @builtin_func: For betty checking
*/
int (*builtin_func[]) (char **) = {
	&builtin_exit,
	&builtin_env,
	&builtin_cd
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
int builtin_exit(char **tokenized __attribute__((unused)))
{
	return (0);
}

/**
* builtin_cd - Built in for the command cd
*
* @tokenized: Previous tokenized input
*
* Return: 1 if its success, perror if the directory is missing
* or no specify
*/
int builtin_cd(char **tokenized)
{
	if (tokenized[1] == NULL)
	{
		perror("Missing directory\n");
	}
	else
	{
		if (chdir(tokenized[1]) != 0)
		{
			perror("No directory specify\n");
		}
	}
	return (1);
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
/**
* builtin_env - to get variables of environment
* Return: Success
*/
int builtin_env(void)
{
	unsigned int c = 0, i = 0;

	for (; environ[i] != NULL; i++)
	{
		write(1, environ[c], _strlen(environ[c]));
		_putchar('\n');
		c++;
	}
	return (0);
}
