#include <libc/libc.h>
//#include "string.h"

#define MAX 10
int abs(int x)
{
	return x<0?-x:x;
}
class qnum
{
private:
	int gcd(int a,int b)
	{
		if(a==0 || b==0)return 1;
		if(!(a%b))return b;
		return gcd(b,a%b);
	}
	int lcm(int a,int b)
	{
		return a*b/gcd(a,b);
	}
	void reduce()
	{
		if(p==0)
		{
			q=1;
			return;
		}
		int sgn=((p<0)?-1:1)*((q<0)?-1:1);
		int x=gcd(abs(q),abs(p));
		q/=x;
		p/=x;
		p=abs(p);
		q=abs(q);
		p=sgn*p;
	}
public:
	int p,q;		//q>0
	qnum(int a,int b)
	{
		p=a;
		q=b;
	}
	qnum()
	{
		p=0;
		q=1;
	}
	void get()
	{
		char buf[32];
		char *pstr=buf;
		q=1;
		scanf("%s",buf);
		p=mystrtol(pstr,10);
		for(;*pstr && *pstr!='/';pstr++);
		if(*pstr=='/')
		{
			q=mystrtol(pstr+1,10);
		}
		//cin>>buf;
		//sscanf(buf,"%d/%d",&p,&q);
		reduce();
	}
	void show()
	{
		printf("%d/%d",p,q);
	}
	friend qnum operator+(const qnum& a,const qnum& b);
	friend qnum operator-(const qnum& a,const qnum& b);
	friend qnum operator*(const qnum& a,const qnum& b);
	friend qnum operator/(const qnum& a,const qnum& b);
	qnum& operator=(const int x)
	{
		p=x;
		q=1;
		return *this;
	}
	int operator==(const qnum& obj)
	{
		return (q==obj.q) && (p==obj.p);
	}
	int operator!=(const qnum& obj)
	{
		return !(*this==obj);
	}
	int operator==(const int x)
	{
		return (q==1) && (x==p);
	}
	int operator!=(const int x)
	{
		return !(*this==x);
	}
	qnum& operator-=(const qnum& obj)
	{
		*this=*this-obj;
		return *this;
	}
};


qnum operator+(const qnum& a,const qnum& b)
{
	//a.show();cout<<" + ";b.show();cout<<endl;
	qnum tmp;
	tmp.p=b.q*a.p+b.p*a.q;
	tmp.q=b.q*a.q;
	tmp.reduce();
	return tmp;
}

qnum operator-(const qnum& a,const qnum& b)
{
	//a.show();cout<<" - ";b.show();cout<<endl;
	qnum tmp;
	tmp.p=-b.p;
	tmp.q=b.q;
	return a+tmp;
}

qnum operator-(const int a,const qnum& b)
{
	//cout<<a<<" - ";b.show();cout<<endl;
	qnum tmp(a,1);
	return tmp-b;
}

qnum operator*(const qnum& a,const qnum& b)
{
	//a.show();cout<<" * ";b.show();cout<<endl;
	qnum tmp;
	tmp.p=a.p*b.p;
	tmp.q=a.q*b.q;
	tmp.reduce();
	return tmp;
}

qnum operator/(const qnum& a,const qnum& b)
{
	//a.show();cout<<" / ";b.show();cout<<endl;
	qnum tmp;
	if(b.p!=0)
	{
		tmp.p=b.q;
		tmp.q=b.p;
		return a*tmp;
	}
	printf("\ndiv 0!\n");
	return qnum(0,1);
}

typedef qnum num_t;

class matrix
{
public:
	int m,n;
	num_t data[MAX][MAX];
	void gauss();
	int iszero(int line)
	{
		for(int i=0;i<n-1;i++)
		{
			if(data[line][i]!=0)return 0;
		}
		return 1;
	}
	void show()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				data[i][j].show();
				printf(" ");
			}
			printf("\n");
		}
	}
	matrix(int mm,int nn)
	{
		m=mm;
		n=nn;
		//memset(data,0,sizeof(data));
	}
	matrix()
	{
		m=0;
		n=0;
		//memset(data,0,sizeof(data));
	}
};

void matrix::gauss()
{
	num_t q;
	int tmp;
	for(int i=0;i<m;i++)
	{
		for(tmp=i;tmp<m && data[i][tmp]==0;tmp++);
		if(tmp==m)continue;
		for(int j=i+1;j<m;j++)
		{
			if(data[j][tmp]==0)continue;
			q=0-(data[i][tmp]/data[j][tmp]);
			for(int k=0/*i*/;k<n;k++)
			{
				data[j][k]=data[i][k]+q*data[j][k];
			}
			show();
			printf("------------\n");
			//cout<<"------------"<<endl;system("pause");
		}
	}
	for(int i=1;i<m;i++)
	{
		for(tmp=i;tmp<m && data[i][tmp]==0;tmp++);
		if(tmp==m)continue;
		for(int j=0;j<m;j++)
		{
			if(j==i)continue;
			if(data[i][tmp]==0)continue;
			q=0-(data[j][tmp]/data[i][tmp]);
			for(int k=0;k<n;k++)
			{
				data[j][k]=q*data[i][k]+data[j][k];
			}
			show();
			printf("------------\n");
			//cout<<"------------"<<endl;system("pause");
		}
	}
	//show result
	int alpha=0;
	for(int i=m-1+1;i>=0;i--)
	{
		if(iszero(i) && data[i][n-1]!=0)
		{
			printf("no sol\n");
			return;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n-1;j++)
			if(data[i][j]!=0)
			{
				printf("x%d=",j+1);
				for(int k=j+1;k<n-1;k++)
				{
					if(data[i][k]!=0)
					{
						q=0-data[i][k];
						q=q/data[i][j];
						printf("+(");
						q.show();
						printf(")x%d ",k+1);
						alpha=1;
					}
				}
				if((data[i][n-1]!=0 && alpha) || !alpha)
				{
					q=data[i][n-1]/data[i][j];
					printf("+(");
					q.show();
					printf(")");
				}
				printf("\n");
				break;
			}
	}
}
extern "C" int gauss()
{
	int m,n;
	//printf("I am in C++\n");for(;;);
	scanf("%d %d",&m,&n);
	matrix mar(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			mar.data[i][j].get();
		}
	}
	printf("begin\n");
	mar.gauss();
	printf("end\n");
	return 0;
}

