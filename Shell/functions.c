#include "main.h"

/**
* main - running the infinite loop
*
* Return: success
*/
int runloop(void)
{

  loop();

  return EXIT_SUCCESS;
}

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
        printf("#cisfun$ ");
        input = readline();
        tokenized = tokenize_input(input);
        status = match(tokenized);

        free(line);
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
    ssize_t buffer = 0;

    if (getline(&line, &buffer, stdin) == -1)
	{
		perror("Error reading input");
		exit(EXIT_FAILURE);
	}
    return (line);
}

#define BUFFERSIZE 1024
#define DELIM "\t\n"
/**
* tokenize_line - function for the tokenization of the input line
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
    int buffer = BUFFERSIZE, position = 0;
    char **tokenbuff = malloc(buffer * sizeof(char *));
    char *token;

    if (!token)
    {
        perror("Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM);
    while (token != NULL)
    {
        tokenbuff[position] = token;
        position++;

        if (position >= buffer)
        {
            buffer += BUFFERSIZE;
            tokenbuff = realloc(tokenbuff, buffer * sizeof(char *));
            if (!tokenbuff)
            {
                perror("Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
<<<<<<< HEAD
        token = strtok(NULL, DELIM);
=======
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return (tokens);
}

/**
* shell - matches the tokenized line to the corresponding program
* through a child
*
* @args: previous line tokenized
*
* pid: child created by the father
* waitchild: the father wait for the child dead
*
* Return: 1 (Shell on, Success)
*/
int lsh_launch(char **args)
{
    pid_t pid, wpid;
    int status;
    
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("lsh");
	}
    else
    {
    	do {
        	wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
>>>>>>> d23feec2022f6b1913ae72bde54092308dc60f98
    }
    tokenbuff[position] = NULL;
    return (tokenbuff);
}

/**
* compare - function replace of strcmp
* 
* str1: firts string to compare
* str2: second string to compare
* 
* Return: rest of both comparison
*/
int compare(char *str1, char *str2)
{
	while(*str1 || *str2)
	{
		if(*str1 != *str2)
		{
			break;
		}
		++str1;
		++str2;
	}
	return *str1 - *str2;
}
