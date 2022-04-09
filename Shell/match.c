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
	int i;

	if (tok[0] == NULL) 
	{
    	return 1;
	}

	for (i = 0; i < buildint(); i++)
	{
		if (strcmp(tok[0], buildint_name[i]) == 0) 
		{
      		return (*buidint_func[i])(tok);
    	}
	}

	return shell(tok);
}
