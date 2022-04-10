#include "main.h"
/**
* lsh_loop - Infinite loop that are always on when the shell runs
*
* line: the input, when the person writes something this is the line reading
* args: the previous line tokenized
* status: the program corresponding to the input read and tokenized
*
*/
void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("#cisfun$ ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
}

/**
* lsh_read_line - function that read the input line
*
* line: input line
* bufsize: size of the malloc that getline automatically creates
*
* Return: the input line already read
*/
char *lsh_read_line(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

    return (line);
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
* token_line - function for the tokenization of the input line
*
* @line: previus input line
*
* bufsize: capacity of the buffer
* position: always positioned in the beginning of the buffer at startup
* buff: capacity for the tokenized line memory allocation
* token: tokenization of the input line
*
* Return: buff with the tokenized line successfuly allocated
*/
char **lsh_split_line(char *line)
{
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!token)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, LSH_TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
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
                wpid = waitpid(child, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return (1);
}

/**
* match - function that matches the tokenized line input with the
* corresponding program or buildint
*
* @args: previous tokenized line
*
* Return: If the tokenized input are not any of the buildint the
* shell go to the system programs and work with pid and ppid
*/
int match(char **tok)
{
    int i;

    if (args[0] == NULL)
    {
        return (1);
    }

    for (i = 0; i < lsh_num_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    return lsh_launch(args);
}
