#include "main.h"
/**
* time - replace a sleep
*/
struct timeval tv;
tv.tv_sec = 1;
tv.tv_usec = 500000;
select(0, NULL, NULL, NULL, &tv);

/**
*
*
*
*/
void signalofc(int sig)
{
	printf("press Ctrl-c");
	(void)signal(SIGINT, SIG_DFL);
}
/**
*
*
*/
int main()
{
	(void)signal(SIGINT, signalofc);

	while(1) {
		printf("hi");
	tv(1);
	}

	return (0);
}
