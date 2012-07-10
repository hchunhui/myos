#include <libc/libc.h>
extern int gauss();
char buf[10];
int main()
{
	printf("Now we enter function gauss().\n");
	gauss();
	printf("exit.\n");
	return 0;
}
