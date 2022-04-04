#include <stdio.h>
#include <unistd.h>
/**
* main - PID
*
* Return: 0
*/
int main(void)
{
	printf("%u\n", getppid());
	return(0);
}
