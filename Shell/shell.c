#include "main.h"
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
int main(char **tokenized)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        if (execvp(tokenized[0], tokenized) == -1)
        {
            perror("Program error");
        }
        exit(EXIT_FAILURE);
    }
    else if (child < 0)
    {
        perror("Fork error");
    }
    else
    {
        do {
            waitpid(child, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}
