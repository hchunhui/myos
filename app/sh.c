#include <libc/libc.h>
char buf[100];

void float_test()
{
	double f, b;
	for(b = 0; ; b+=0.1)
		f = b * b + 0.9;
}

extern char **environ;
int main(int argc, char **argv)
{
	char *p;
	
	printf(
		"Alt+(1,2,3,4) : change console.\n"
		"Alt+5         : graphic mode.\n"
		"/w.bin        : a window manager.\n"
		"/task2.bin    : a window.\n"
		"/gauss.bin    : gauss elimination method.\n\n"
		);
	for(;;)
	{
		printf("#");
		//scanf("%s",buf);
		getline(buf);
		for(p=buf;*p!='\n';p++);*p='\0';
		if(strcmp(buf,"exit")==0)
		{
			exit(0);
		}
		else if(buf[0]=='\0')
		{
			//no operation
		}
		else if(buf[0]=='/')
		{
			if(vfork()==0)
			{
				exit(execle(buf, buf, 0, environ));
			}
			int status,pid;
			pid=waitpid(-1,&status,0);
			printf("\npid=%d exit code=%d\n",pid,status);
		}
		else if(strlen(buf)>2 && buf[0]=='&' && buf[1]=='/')
		{
			if(vfork()==0)
			{
				exit(execle(buf+1, buf, 0, environ));
			}
		}
		else if(buf[0] == '!')
		{
			printf("testing float\n");
			float_test();
		}
		else
		{
			printf("Unknown commmand line.\n");
		}
	}
	return 0;
}

