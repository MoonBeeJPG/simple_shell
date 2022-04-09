#include "main.h"
/**
*
* shell: init the shell launcher
* child process in first if for
* else if, error in forking
* else do, parent process
*/
int shell(char **tok)
{
	pid_t pid, wpid;
	int status;

		pid = fork();
		if (pid == 0)
		{
			if (execvp(tok[0], tok) == -1)
			{
				perror("shell");
			}
				exit(EXIT_FAILURE);
			}
		else if (pid < 0) 
		{
			perror("shell");
		}
		else
		{
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
			} 
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}

		return 1;
}
