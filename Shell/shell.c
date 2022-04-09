#include "main.h"
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
