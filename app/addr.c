#include <libc/libc.h>
#define WIN 1
#define UNIX 2
#define URL 3
int t;
char buf[256];

void judge()
{
	int mode;
	int flag=0;
	int i,len=strlen(buf);
	if(buf[0]=='/' || buf[0]=='\\')mode=UNIX;
	else
	{
		if(buf[1]==':' && buf[3]!='/' && buf[3]!='\\')mode=WIN;
		else mode=URL;
	}
	if(mode==UNIX || mode==URL)
	{
		for(i=0;i<len;i++)
		{
			if(buf[i]=='\\')
			{
				flag=1;
				buf[i]='/';
			}
		}
	}
	else
	{
		for(i=0;i<len;i++)
		{
			if(buf[i]=='/')
			{
				flag=1;
				buf[i]='\\';
			}
		}
	}
	
	switch(mode)
	{
		case WIN:printf("It's a path in Windows system!\n");break;
		case URL:printf("It's a URL!\n");break;
		case UNIX:printf("It's a path in Unix-like systems!\n");break;
	}
	printf("%s\n",buf);
}

int main()
{
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		judge();
	}
	//system("pause");
	return 0;
}
