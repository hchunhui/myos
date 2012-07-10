#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mathopr.h"
#include <iostream>

void * operator new(size_t size)
{
	void *p = malloc(size);
	return (p);
}

void operator delete(void *p)
{
	free(p);
}  

int main()
{
	char buffer[NMAX]="x^2/4+y^2/3-1";//"a/6/3-1";//"a^4";
	//char buffer[NMAX]="a*3+a/(3+4/5)+a+3+a-3";//"3+6+a*a+a*a+a*a+3";
	fnptr fn;
	mo_letter dletter;
	mathopr test;
	//scanf("%s",buffer);
	test.input(buffer,&dletter);
	fn=test.compiler();
	//scanf("%lf",&dletter.table[(int)'a']);
	dletter.table[(int)'a']=0;
	dletter.table[(int)'x']=0;
	dletter.table[(int)'y']=0;
	double j=pow(0,-2);
	double t1,t2;
	//printf("%lf %lf",pow(0,0),0*log(0));for(;;);
	for(int i=0;i<100000000;i++)
	{

		//t2=test.calc();
		t1=fn();
		//t1=M_PI_2;
		//t2=t1+1e-15;
		//t1/=t2;
		//printf("%lf %lf %d %d",tan(t1),tan(t2),isnan(t1),finite(t1));for(;;);
		//j=test.calc();
		//j=pow(t1,t2);
		//j=(*fn)();
		//j=dletter.table[(int)'a']*3;
		//j++;
		//printf("%lf %lf\n",t1,t2);system("pause");
		//if(t1!=t2)printf("%lf  %lf\n",t1,t2);//system("pause");
		//dletter.table[(int)'a']+=0.1;
		dletter.table[(int)'x']+=0.1;
		dletter.table[(int)'y']+=0.1;
	}

	return 0;
}
