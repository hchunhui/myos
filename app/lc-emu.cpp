#include <libc/libc.h>
//#include <stdlib.h>
void show_name(int);
void show_unit(int);
void system(char *pc)
{
	//char c;
	char buf[32];
	printf("Press Enter to continue...\n");
	//while( scanf("%c", &c), c != '\n');
	getline(buf);
	//scanf("%c", &c);
}
/*******************************************gauss*****************************/
//#include <stdio.h>
//#include <stdlib.h>
//#define mystrtol(a,b) strtol(a,0,b)
#define MAX 200
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
		printf("%+d/%d",p,q);
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
	void auto_swap();
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

void matrix::auto_swap()
{
	num_t tmp;
	for(int now = 0; now < m; now++)
	{
		int first = n + 1, firstl = m;
		for(int i = now; i < m; i++)
		{
			int j;
			for(j = 0; j < n; j++)
			{
				if(data[i][j] != 0)
					break;
			}
			if(first > j)
			{
				first = j;
				firstl = i;
			}
		}
		if(firstl == now)
			continue;
		if(firstl != m)
		{
			for(int a = 0; a < n; a++)
			{
				tmp = data[now][a];
				data[now][a] = data[firstl][a];
				data[firstl][a] = tmp;
			}
		}
	}
}

void matrix::gauss()
{
	num_t q;
	int tmp;
	for(int i=0;i<m;i++)
	{
		auto_swap();
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
			//show();
			//printf("------------\n");
			//system("pause");
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
			/*show();
			printf("------------\n");*/
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
				//printf("x%d=",j+1);
				show_name(j);
				printf("= ");
				for(int k=j+1;k<n-1;k++)
				{
					if(data[i][k]!=0)
					{
						q=0-data[i][k];
						q=q/data[i][j];
						q.show();
						//printf(")x%d ",k+1);
						show_name(k);
						alpha=1;
					}
				}
				if((data[i][n-1]!=0 && alpha) || !alpha)
				{
					q=data[i][n-1]/data[i][j];
					q.show();
					show_unit(j);
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
/*******************************************gauss*****************************/
#define NMAX  100
#define BMAX  100

#define TYPE_R 	1
#define TYPE_CS 2
#define TYPE_VS 3
#define TYPE_CCCS 4
#define TYPE_CCVS 5
#define TYPE_VCCS 6
#define TYPE_VCVS 7

matrix ma;	//(16, 17);//(7 * 2, 7 * 2 + 1);	//(2b, 2b+1)
int ma_now;

struct line_t
{
	int node[2];
	char name[16];
	int type;
	num_t args;
	int ctl;
	int enable;
};

/*2.28*/
struct line_t line[BMAX]=
{
		{{1,2},"12u",TYPE_R,qnum(2,1),0,0},
		{{1,3},"13",TYPE_VS,qnum(2,1),0,0},
		{{1,4},"14",TYPE_R,qnum(1,1),0,0},
		{{2,3},"23s",TYPE_CS,qnum(9,1),0,0},

		
		{{3,4},"34i",TYPE_R,qnum(2,1),0,0},
		{{2,5},"25",TYPE_R,qnum(1,1),0,0},
		{{3,5},"35s",TYPE_VCCS,qnum(2,1),0,0},
		{{4,5},"45s",TYPE_CCVS,qnum(3,1),4,0},
};
int n=5, b=8;

/*2.25
struct line_t line[BMAX]=
{
		{{2,1},"21",TYPE_R,qnum(3000,1),0,0},
		{{2,3},"23",TYPE_R,qnum(1000,1),0,0},
		{{3,2},"32s",TYPE_CCCS,qnum(2,1),0,0},
		{{1,4},"14s",TYPE_VS,qnum(10,1),0,0},

		
		{{2,4},"24",TYPE_R,qnum(2000,1),0,0},
		{{4,3},"43s",TYPE_CS,qnum(1,500),0,0},
		{{3,4},"34I",TYPE_R,qnum(3000,1),0,0},
};
int n=4, b=7;
*/
/*2.24
struct line_t line[BMAX]=
{
		{{1,2},"12",TYPE_CS,qnum(15,1),0,0},
		{{1,3},"13",TYPE_R,qnum(1,1),0,0},
		{{2,3},"23",TYPE_R,qnum(3,1),0,0},
		{{3,4},"34",TYPE_R,qnum(2,1),0,0},

		
		{{1,4},"14",TYPE_VS,qnum(10,1),0,0},
		{{4,2},"42",TYPE_VCCS,qnum(1,4),3,0},
};
int n=4, b=6;*/

/*struct line_t line[BMAX]=
{
		{{1,2},"12",TYPE_R,qnum(8,1),0,0},
		{{2,3},"23",TYPE_R,qnum(4,1),0,0},
		{{2,4},"24",TYPE_R,qnum(6,1),0,0},
		{{3,5},"35",TYPE_R,qnum(2,1),0,0},

		
		{{1,6},"s1",TYPE_VS,qnum(24,1),0,0},
		{{4,6},"s2",TYPE_VCVS,qnum(3,1),3,0},
		{{5,6},"s3",TYPE_VS,qnum(12,1),0,0},
};
int n=6, b=7;*/

/*struct line_t line[BMAX]=
{
		{{1,2},"12",TYPE_R,qnum(1,1),0,0},
		{{2,3},"23",TYPE_R,qnum(1,1),0,0},
		{{3,4},"34",TYPE_R,qnum(1,1),0,0},
		{{4,1},"41",TYPE_R,qnum(1,1),0,0},
		{{1,8},"18",TYPE_R,qnum(1,1),0,0},
		{{2,7},"27",TYPE_R,qnum(1,1),0,0},
		{{3,6},"36",TYPE_R,qnum(1,1),0,0},
		{{4,5},"45",TYPE_R,qnum(1,1),0,0},
		{{5,6},"56",TYPE_R,qnum(1,1),0,0},
		{{6,7},"67",TYPE_R,qnum(1,1),0,0},
		{{7,8},"78",TYPE_R,qnum(1,1),0,0},
		{{8,5},"85",TYPE_R,qnum(1,1),0,0},
		
		{{4,7},"s",TYPE_CS,qnum(1,1),0,0},
};
int n=8, b=13;*/

/*struct line_t line[BMAX]=
{
		{{1,2},"12",TYPE_R,{qnum(2,1),qnum(0,1)},0},
		{{2,1},"21",TYPE_VS,{qnum(10,1),qnum(0,1)},0},
};
int n=2, b=2;*/

/*struct line_t line[BMAX]=
{
		{{1,2},"12",TYPE_R,{qnum(1,1),qnum(0,1)},0},
		{{2,3},"23",TYPE_R,{qnum(1,2),qnum(0,1)},0},
		{{2,5},"25",TYPE_R,{qnum(1,3),qnum(0,1)},0},
		{{3,4},"34",TYPE_R,{qnum(1,4),qnum(0,1)},0},
		{{4,5},"45",TYPE_R,{qnum(1,5),qnum(0,1)},0},
		{{5,6},"56",TYPE_CS,{qnum(1,6),qnum(0,1)},0},
		{{1,6},"16",TYPE_VS,{qnum(1,7),qnum(0,1)},0},
};
int n=6, b=7;*/

int node[NMAX];

void make_tree(int now)
{
	int i;
	node[now] = 1;
	for(i = 0; i < b; i++)
	{
		if(line[i].node[0] == now)
		{
			if(node[line[i].node[1]])
				goto next;
			line[i].enable = 1;
			make_tree(line[i].node[1]);
		}
		if(line[i].node[1] == now)
		{
			if(node[line[i].node[0]])
				goto next;
			line[i].enable = 1;
			make_tree(line[i].node[0]);
		}
		next:;
	}
}

struct line_t tline[BMAX];
int count[NMAX];
int loop[BMAX];

void make_kvl_func(int start)
{
	int i, j;
	int dir;
	//printf("make_kvl_func\n");
	if(line[loop[start]].node[0] == line[start].node[0] ||
		line[loop[start]].node[1] == line[start].node[0])
	{
		dir = -1;
	}
	else
	{
		dir = 1;
	}
	struct line_t *p;
	for(j = 0; j < 2 * b + 1; j++)
		ma.data[ma_now][j] = 0;
	for(i = start; i != -1; i = loop[i])
	{
		p = line + i;
		if(dir < 0)
		{
			printf("-U%s ",p->name);
			ma.data[ma_now][i] = -1;
			if(loop[i] != -1)
			{
				if(line[i].node[0] == line[loop[i]].node[0])
				{
					dir = 1;
				}
				else
				{
					dir = -1;
				}
			}
		}
		else
		{
			printf("+U%s ",p->name);
			ma.data[ma_now][i] = +1;
			if(loop[i] != -1)
			{
				if(line[i].node[1] == line[loop[i]].node[0])
				{
					dir = 1;
				}
				else
				{
					dir = -1;
				}
			}
		}
	}
	printf("= 0\n");
	ma_now++;
}

void travel_loop(int now)
{
	int i;
	struct line_t *p = tline + now;
	struct line_t *q;
	//printf("travel_loop\n");
	for(i = 0, q = tline; i < b; i++, q++)
	{
		if(p == q)
			continue;
		if(q->enable == 0)
			continue;
		if(
			p->node[0] == q->node[0] ||
			p->node[0] == q->node[1] ||
			p->node[1] == q->node[0] ||
			p->node[1] == q->node[1]
			)
		{
			printf("%s->", p->name);
			loop[now] = i;
			p->enable = 0;
			travel_loop(i);
			return;
		}
	}
	loop[now] = -1;
	printf("%s:\n\t", tline[now].name);
}

void do_find_loop()
{
	int i, j;
	int flag;
	//printf("do_find_loop\n");
	for(;;)
	{
		memset(count, 0, sizeof(int) * NMAX);
		for(i = 0; i < b; i++)
		{
			if(tline[i].enable == 0)
				continue;
			count[tline[i].node[0]]++;
			count[tline[i].node[1]]++;
		}
		flag = 1;
		for(i = 1; i <= n ; i++)
		{
			if( count[i] == 1)
			{
				flag = 0;
				//printf("find tail (%d)\n", i);
				for(j = 0; j < b; j++)
				{
					if(tline[j].enable == 0)
						continue;
					if(tline[j].node[0] == i || tline[j].node[1] == i)
					{
						//printf("del %s (%d)\n",tline[j].name, j);
						tline[j].enable = 0;
						break;
					}
				}
			}
		}
		if(flag)break;
	}
}


void find_loop()
{
	int i;
	for( i = 0; i < b; i++)
	{
		if(line[i].enable == 0)
		{
			memcpy(tline, line, sizeof(struct line_t) * BMAX);
			tline[i].enable = 1;
			do_find_loop();
			printf("\nuse KVL for loop ");
			travel_loop(i);
			make_kvl_func(i);
		}
	}
}

void make_kcl_func()
{
	int i, j;
	for(i = 1; i <= n - 1 ; i++)
	{
		for(j = 0; j < 2 * b + 1; j++)
			ma.data[ma_now][j] = 0;
		printf("\nuse KCL for node %d:\n\t",i);
		for(j = 0; j < b; j++)
		{
			if(line[j].node[0] == i)
			{
				printf("+I%s ",line[j].name);
				ma.data[ma_now][j + b] = 1;
			}
			else if(line[j].node[1] == i)
			{
				printf("-I%s ",line[j].name);
				ma.data[ma_now][j + b] = -1;
			}
		}
		printf("= 0\n");
		ma_now++;
	}
}

void make_var_func()
{
	int j, k;
	struct line_t *p;
	for(j = 0; j < b; j++)
	{
		p = line + j;
		for(k = 0; k < 2 * b + 1; k++)
			ma.data[ma_now][k] = 0;
		printf("\nVAR for line %s:\n",p->name);
		switch(p->type)
		{
			case TYPE_R:
				printf("\tU%s = ", p->name);
				(p->args).show();
				printf("\xea * I%s\n", p->name);
				ma.data[ma_now][j] = 1;
				ma.data[ma_now][j + b] = 0 - (p->args);
				ma_now++;
				break;
			case TYPE_CS:
				printf("\tI%s = ", p->name);
				(p->args).show();
				printf("A\n");
				ma.data[ma_now][j + b] = 1;
				ma.data[ma_now][2 * b] = (p->args);
				ma_now++;
				break;
			case TYPE_VS:
				printf("\tU%s = ", p->name);
				(p->args).show();
				printf("V\n");
				ma.data[ma_now][j] = 1;
				ma.data[ma_now][2 * b] = (p->args);
				ma_now++;
				break;
			case TYPE_CCCS:
				printf("\tI%s = ", p->name);
				(p->args).show();
				printf(" * I%s\n", line[p->ctl].name);
				ma.data[ma_now][j + b] = 1;
				ma.data[ma_now][p->ctl + b] = 0 - (p->args);
				ma_now++;
				break;
			case TYPE_CCVS:
				printf("\tU%s = ", p->name);
				(p->args).show();
				printf("\xea * I%s\n", line[p->ctl].name);
				ma.data[ma_now][j] = 1;
				ma.data[ma_now][p->ctl + b] = 0 -(p->args);
				ma_now++;
				break;
			case TYPE_VCCS:
				printf("\tI%s = ", p->name);
				(p->args).show();
				printf("S * U%s\n", line[p->ctl].name);
				ma.data[ma_now][j + b] = 1;
				ma.data[ma_now][p->ctl] = 0 - (p->args);
				ma_now++;
				break;
			case TYPE_VCVS:
				printf("\tU%s = ", p->name);
				(p->args).show();
				printf(" * U%s\n", line[p->ctl].name);
				ma.data[ma_now][j] = 1;
				ma.data[ma_now][p->ctl] = 0 - (p->args); 
				ma_now++;
				break;
		}
	}
}

void show_name(int x)
{
	if(x<b)
	{
		printf("U%s ", line[x].name);
	}
	else
	{
		printf("I%s ", line[x - b].name);
	}
}

void show_unit(int x)
{
	if(x<b)
	{
		printf("V", line[x].name);
	}
	else
	{
		printf("A", line[x - b].name);
	}
}

int solve()
{
	int i;
	memset( node, 0, sizeof(node));
	make_tree(1);
	printf("tree list: ");
	for(i = 0; i < b; i++)
	{
		if(line[i].enable)
			printf("%s ", line[i].name);
	}
	printf("\n");
	ma_now = 0;
	find_loop();
	make_kcl_func();
	make_var_func();
	printf("func count: %d\n",ma_now);
	system("pause");
	ma.gauss();
	return 0;
}

void console()
{
	int c;
	
	int id, ctlid;
	char type_name[16];
	
	printf("n b: ");
	scanf("%d %d", &n, &b);
	ma.m = 2 * b;
	ma.n = 2 * b + 1;
	
	printf("enter 'h' for help.\n");
	
	while(1)
	{
		__loop:
		//while ( (c=getchar()) != '\n' && c != EOF );
		printf("\n>>");
		//c	= getchar();
		while( scanf("%c", &c), c != '\n');
		redo: scanf("%c", &c);
		if( c == '\n')goto redo;
		switch(c)
		{
			case 'h':
				printf(
					"m id node0 node1 name type arg ctlid\n"
					"l\n"
					"g\n"
					"q\n"
					);
				break;
			case 'm':
				scanf("%d", &id);
				if(id < 0 || id >= b)
				{
					printf("error");
					goto __loop;
				}
				scanf("%d %d", &line[id].node[0], &line[id].node[1]);
				scanf("%s", line[id].name);
				scanf("%s", type_name);
				if(strcmp(type_name, "CS") == 0)
					line[id].type = TYPE_CS;
				else if(strcmp(type_name, "CS") == 0)
					line[id].type = TYPE_CS;
				else if(strcmp(type_name, "VS") == 0)
					line[id].type = TYPE_VS;
				else if(strcmp(type_name, "R") == 0)
					line[id].type = TYPE_R;
				else if(strcmp(type_name, "CCCS") == 0)
					line[id].type = TYPE_CCCS;
				else if(strcmp(type_name, "CCVS") == 0)
					line[id].type = TYPE_CCVS;
				else if(strcmp(type_name, "VCCS") == 0)
					line[id].type = TYPE_VCCS;
				else if(strcmp(type_name, "VCVS") == 0)
					line[id].type = TYPE_VCVS;
				else
					{
					printf("error");
					goto __loop;
					}
				line[id].args.get();
				scanf("%d", &ctlid);
				if(id < 0 || id >= b)
				{
					printf("error");
					goto __loop;
				}
				line[id].ctl = ctlid;
				break;
			case 'l':
				printf("id  node0 node1 name       type  arg  ctlid\n");
				for(id = 0; id < b; id++)
				{
					printf("%4d %5d %5d %-10s ",
						id, line[id].node[0], line[id].node[1], line[id].name);
					switch(line[id].type)
					{
						case TYPE_R:
							printf("R    ");
							break;
						case TYPE_CS:
							printf("CS   ");
							break;
						case TYPE_VS:
							printf("VS   ");
							break;
						case TYPE_CCCS:
							printf("CCCS ");
							break;
						case TYPE_CCVS:
							printf("CCVS ");
							break;
						case TYPE_VCCS:
							printf("VCCS ");
							break;
						case TYPE_VCVS:
							printf("VCVS ");
							break;
						default:
							printf("     ");
							break;
					}
					line[id].args.show();
					printf("  %d\n",line[id].ctl);
				}
				break;
			case 'g':
				solve();
				break;
			case 'q':
				return;
				break;
			default:
				printf("error!\n");
				break;
		}
	}
}

int main()
{
	console();
	return 0;
}
