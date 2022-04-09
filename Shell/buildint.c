#include "main.h"
/**
* buildint_name - Names of the buildints
*/
char *buidint_name[] = {
					{"exit"}
};
/**
* buildint_func - functions that corresponds with the buildint_name
*/
int (*buildint_func[])(char **) = {
				{&sh_exit}
};
/**
* buildint_size - chech the size of rthe buildint_name for lately compare it
* with the input line
*/
int buildint_size() 
{
	return (sizeof(builtin_name) / sizeof(char *));
}
/**
* exit - leaves the current program or if you write in the terminal exit it
*/
int exit(char **tok)
{
	return (0);
}
