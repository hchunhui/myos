#include <libc/libc.h>
#define N 362890
int last[N];
int step[N];
char list[N][16];
char temp[16];
int bb[N];
int p,q;
const int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};

void out(int v)
{
	if(v==0)return;
	out(last[v]);
	printf("%s\n",list[v]);
}

void system(char* x)
{
	printf("press any key to continue...");
	getline(temp);
}

int hash(char* p)//, int n)
{
	const int n=9;
	int j,k;
	int result = 0;
	for (j = 1; j < n; ++j)
	{
		int count = 0;
		for (k = 0; k < j; ++k)
		{
			if (p[k] > p[j])
				++count;
    	}
		// factorials[j]±£´æ×Åj!
		result += count * fact[j];
	}
	return result;
}


int main()
{
	int i,j,hval;
	char t;
	memset(bb,0,sizeof(bb));
	memset(last,0,sizeof(last));
	memset(list,0,sizeof(list));
	memset(step,0,sizeof(step));
	p=0;
	q=0;
	q++;
	strcpy(list[q],"613824597");
	bb[hash("613824597")]=1;
	printf("pai start\n");
	for(;p<q;)
	{
		p++;
		if(strcmp(list[p],"123456789")==0)
		{
			printf("step:%d\n",step[p]);
			out(p);
			system("pause");
		}
		for(i=0;i<8;i++)
		{
			for(j=i+1;j<9;j++)
			{
				strcpy(temp,list[p]);
				t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
				hval=hash(temp);
				if(!bb[hval])
				{
					q++;
					strcpy(list[q],temp);
					step[q]=step[p]+1;
					bb[hval]=1;
					last[q]=p;
				}
			}
		}
	}
	
	system("pause");
	return 0;
}
