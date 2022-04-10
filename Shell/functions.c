#include "main.h"
#define TOKBUFSIZE 64
#define TOKDELIM "/t/r/n/a"
/**
* loop - Infinite loop that are always on when the shell runs
*
* line: the input, when the person writes something this is the line reading
* tok: the previous line tokenized
* func: the program corresponding to the input read and tokenized
*
*/
void loop(void)
{
    char *line;
    char **tok;
    int func;

    do {
        printf("#cisfun$ ");
        line = readline();
        tok = token_line(line);
        func = match(tok);

        free(line);
        free(tok);
    } while (func);
}

/**
* read_line - function that read the input line
*
* line: input line
* bufsize: size of the malloc that getline automatically creates
*
* Return: the input line already read
*/
char *read_line(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        perror("readline");
        exit(EXIT_FAILURE);
    }

    return (line);
}

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
char **token_line(char *line)
{
    int bufsize = TOKBUFSIZE, position = 0;
    char **buff = malloc(bufsize * sizeof(char *));
    char *token;

    if (!buff)
    {
        perror(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKDELIM);

    while (token != NULL)
    {
        token[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += TOKBUFSIZE;
            buff = realloc(buff, bufsize * sizeof(char *));

            if (!buff)
            {
                perror(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOKDELIM);
    }

    buff[position] = NULL;
    return (buff);
}

/**
* shell - matches the tokenized line to the corresponding program
* through a child
*
* @tok: previous line tokenized
*
* child: child created by the father
* waitchild: the father wait for the child dead
*
* Return: 1 (Shell on, Success)
*/
int shell(char **tok)
{
    pid_t child, waitchild;
    int status;

        child = fork();
        if (child == 0)
        {
            if (execvp(tok[0], tok) == -1)
            {
                perror("shell");
            }
                exit(EXIT_FAILURE);
        }
        else if (child < 0)
        {
            perror("shell");
        }
        else
        {
            do {
                waitchild = waitpid(child, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return (1);
}

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
    int i;

    if (tok[0] == NULL)
    {
        return (1);
    }

    for (i = 0; i < buildint_num(); i++)
    {
        if (strcmp(tok[0], buildint_arr[i]) == 0)
        {
            return (*buidint_func[i](tok));
        }
    }

    return (shell(tok));
}
