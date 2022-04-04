#include <stdio.h>
/**
* main - AV
*
* Return: 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	while (*av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}

/** __attribute__((unused)) **/
