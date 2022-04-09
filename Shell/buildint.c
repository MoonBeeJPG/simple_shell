#include "main.h"
/**
* buildint_arr - array with the names of every buildint
*
* @buildint_arr: hola
*/
char (*buildint_arr[]) = {
			{"exit"}
};
/**
* buildint_func - array with the functions of every buildint
*
* @buildint_func: hola
*/
int (*buildint_func[])(char **) = {
			{&exit}
};
/**
* buildint_num - a
*
* Return: quantity of arguments in the array
*/
int buildint_num(void)
{
	return (sizeof(buildint_arr) / sizeof(char *));
}
/**
* exit - leaves the current program or if you write in the terminal exit it
*
* @tok: previous tokenized line
*
* Return: 0 (Success)
*/
int exit(char **tok)
{
	return (0);
}
