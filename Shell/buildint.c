#include "main.h"
/**
*
*
*/
int sh_exit(char **args);
//list arguments with thier functions
char *builtin_string[] = {
	"exit"
};

int (*builtin_functions[]) (char **) = {
	&sh_exit
};

int sh_num_bulitins() {
	return sizeof(builtin_string) / sizeof(char *);
}

//create functions
int sh_exit(char **args)
{
	return (0);
}
