#include <stdio.h>
FILE* fp;
char table[256];
char table2[256];
int main()
{
	int i,j;
	int tmp;
	fp=fopen("out.txt","w");
	for(i=32 ;i<=126;i++)
	{
		printf("%c:",i);
		scanf("%x",&tmp);
		if(tmp==-100)break;
		if(tmp!=0)
			table[tmp]=i;
	}
	for(i=0;i<256;i++)
	{
		if(table[i]!=0)
			fprintf(fp,"'%c',",table[i]);
		else fprintf(fp,"0,");
		if((i)%16==0)fprintf(fp,"\n");
	}
	fclose(fp);
	return 0;
}
