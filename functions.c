#include "main.h"

/**
* infiniteloop - Infinite loop that are always on when the shell runs
*
* line: the input, when the person writes something this is the line reading
* args: the previous line tokenized
* status: the program corresponding to the input read and tokenized
*
*/
void infiniteloop(void)
{
	char *input;
	char **tokenized;
	int status;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		input = readline();
		if (input == NULL)
			continue;
		tokenized = tokenize_input(input);
		status = match(tokenized);

	free(input);
	free(tokenized);
	} while (status);
}

/**
* readline - function that read the input line
*
* line: input line
* bufsize: size of the malloc that getline automatically creates
*
* Return: the input line already read
*/
char *readline(void)
{
	char *line = NULL;
	size_t buffer = 0;

	if (getline(&line, &buffer, stdin) == '\n')
	{
		exit(EXIT_FAILURE);
	}
	while (line[0] == '\n')
		continue;
/**	
	while (checkinput(line) == -1)
		continue;
**/
	return (line);
}

#define DELIM " \t\r\n\a"
/**
* tokenize_input - function for the tokenization of the input line
*
* @line: previus input line
*
* buffer: capacity of the buffer
* position: always positioned in the beginning of the buffer at startup
* tokenbuff: capacity for the tokenized line memory allocation
* token: tokenization of the input line
*
* Return: buff with the tokenized line successfuly allocated
*/
char **tokenize_input(char *line)
{
	int buffer = counter(line), position = 0;
	char **tokenbuff = calloc(buffer, sizeof(char *));
	char *token;

	if (!tokenbuff)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokenbuff[position] = token;
		position++;
		token = strtok(NULL, DELIM);
	}
	tokenbuff[position] = NULL;
	return (tokenbuff);
}

/**
* shell - matches the tokenized line to the corresponding program
* through a child
*
* @tokenized: previous line tokenized
*
* child: child created by the father
*
* Return: 1 (Shell on, Success)
*/
int shell(char **tokenized)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == 0)
	{
		if (execve(tokenized[0], tokenized, environ) == -1)
		{
			perror("Program error");
		}
		exit(EXIT_FAILURE);
	}
	else if (child < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
/**
* compare - function replace of strcmp
*
* @str1: firts string to compare
* @str2: second string to compare
*
* Return: rest of both comparison
*/
int compare(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
		{
			break;
		}
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}
