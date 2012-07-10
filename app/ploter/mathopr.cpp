#include "mathopr.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
mo_err mathopr::stage1(char *buffer,_mo_stage1 *result)
{
	result->length=0;
	int len=strlen(buffer);
	int i,j;
	int tlen=0;
	int ttype=0;
	int ntype[NMAX];
	bool fushu=false;
	bool bdot=false;
	for(i=0;i<len;i++)
	{
		if((buffer[i]>='0' && buffer[i]<='9') || buffer[i]=='.')
		{
			ntype[i]=1;
			ttype=1;
			if(buffer[i]=='.')
			{
				if(bdot)
					return MO_ERR_DOT;	//小数点使用错误
				else
					bdot=true;
			}
			if(ttype==2)
				return MO_ERR_NUM_BEFORE_ALPHA;//数字前面不能有字母
			if(ttype==4)
				return MO_ERR_NUM_BEFORE_BRACKET;//数字前面不能有括号
		}else if(buffer[i]>='a' && buffer[i]<='z')
		{
			ntype[i]=2;
			ttype=2;
			bdot=false;
		}else if(buffer[i]=='(')
		{
			ntype[i]=3;
			ttype=3;
			bdot=false;
		}else if(buffer[i]==')')
		{
			ntype[i]=4;
			ttype=4;
			bdot=false;
			if(ttype==3)
				return MO_ERR_NO_CONTENT_IN_BRACKET;//括号内无内容
			if(ttype==5)
				return MO_ERR_BRACKET_BEFORE_OPR;//括号前面不能是运算符
		}else
		{
			ntype[i]=5;
			bdot=false;
			if(i==0 && buffer[i]!='-')
				return MO_ERR_OPR_BEGIN;//运算符不能放在开头
			if(ttype==5 || ttype==3)
			{
				if(i<(len-1) && buffer[i]=='-')
				{
					if((buffer[i+1]>='0' && buffer[i+1]<='9') || (buffer[i+1]>='a' && buffer[i+1]<='z'))
						continue;
				}
				return MO_ERR_OPR;//运算符使用错误
			}
			if(ttype==3)
				return MO_ERR_BRACKET;//括号使用错误
			ttype=5;
		}
	}
	for(i=0;i<len;i++)
	{
		if(ntype[i]==1 || ntype[i]==2)
		{
			tlen++;
			if(i>0)
			{
				if(ntype[i]==2 && (ntype[i-1]==1 || ntype[i-1]==4))
				{
					result->len[result->length]=1;
					result->type[result->length]=5;
					result->str[result->length]='*';
					result->length++;
				}
			}
			if(fushu)
			{
				if(ntype[i]==1)
				{
					result->type[result->length]=6;
				}
				else
				{
					result->len[result->length]=1;
					result->type[result->length]=6;
					result->str[result->length]='1';
					result->length++;
					result->len[result->length]=1;
					result->type[result->length]=5;
					result->str[result->length]='*';
					result->length++;
					fushu=false;
					result->type[result->length]=2;
				}
			}
			else
			{
				result->type[result->length]=ntype[i];
			}
			result->str[result->length]=buffer[i];
			if(i<(len-1))
			{
				if(ntype[i+1]!=ntype[i])
				{
					result->len[result->length]=tlen;
					fushu=false;
					for(j=1;j<tlen;j++)
						result->len[result->length-j]=tlen;
					tlen=0;
				}
			}else{
				result->len[result->length]=tlen;
				fushu=false;
				for(j=1;j<tlen;j++)
					result->len[result->length-j]=tlen;
				tlen=0;
			}
			result->length++;
		}else if(ntype[i]==5)
		{
			if(i==0 && buffer[i]=='-')
			{
				fushu=true;
				continue;
			}
			if(i>0)
				if(buffer[i-1]=='(')
				{
					fushu=true;
					continue;
				}
			if(i>0)
			{
				if(buffer[i]=='-' && ntype[i-1]==5)
				{
					fushu=true;
				}
				else
				{
					result->type[result->length]=ntype[i];
					result->str[result->length]=buffer[i];
					result->len[result->length]=1;
					result->length++;
				}
			}else{
				result->type[result->length]=ntype[i];
				result->str[result->length]=buffer[i];
				result->len[result->length]=1;
				result->length++;
			}
		}else{
			if(buffer[i]=='(' && i>0)
			{
				if(buffer[i-1]!='(' && ntype[i-1]!=5 && (ntype[i-1]!=2 || result->len[result->length-1]==1))
				{
					result->type[result->length]=5;
					result->str[result->length]='*';
					result->len[result->length]=1;
					result->length++;
				}
			}
			result->type[result->length]=ntype[i];
			result->str[result->length]=buffer[i];
			result->len[result->length]=1;
			result->length++;
		}
	}
	return MO_ERR_OK;
}
//1-4分别代表加、减、乘、除5指数6对数7正弦8余弦9正切10反正弦11反余弦12反正切13绝对值
static inline int GetAdvance(int index)
{
	int table[]={0,1,1,2,2,3,4,4,4,4,4,4,4,4};
	if(index>13 || index<0)
		return -1;
	return table[index];
}

static inline int GetOperator(char *buf,int index)
{
	if(buf[index]=='+')
		return 1;
	else if(buf[index]=='-')
		return 2;
	else if(buf[index]=='*')
		return 3;
	else if(buf[index]=='/')
		return 4;
	else if(buf[index]=='^')
		return 5;
	else if(buf[index]=='l' && buf[index+1]=='o' && buf[index+2]=='g')
		return 6;
	else if(buf[index]=='s' && buf[index+1]=='i' && buf[index+2]=='n')
		return 7;
	else if(buf[index]=='c' && buf[index+1]=='o' && buf[index+2]=='s')
		return 8;
	else if(buf[index]=='t' && buf[index+1]=='a' && buf[index+2]=='n')
		return 9;
	else if(buf[index]=='a' && buf[index+1]=='r' && buf[index+2]=='c' && buf[index+3]=='s' && buf[index+4]=='i' && buf[index+5]=='n')
		return 10;
	else if(buf[index]=='a' && buf[index+1]=='r' && buf[index+2]=='c' && buf[index+3]=='c' && buf[index+4]=='o' && buf[index+5]=='s')
		return 11;
	else if(buf[index]=='a' && buf[index+1]=='r' && buf[index+2]=='c' && buf[index+3]=='t' && buf[index+4]=='a' && buf[index+5]=='n')
		return 12;
	else if(buf[index]=='a' && buf[index+1]=='b' && buf[index+2]=='s')
		return 13;
	return 0;
}

mo_err mathopr::stage2(_mo_stage1 *obj,_mo_stage2 *result)
{
	int i,j,index,tlen;
	int base=0;
	int &ncount=result->ncount;
	bool add=false;
	char buffer[NMAX];
	ncount=0;
	for(i=0;i<obj->length;i++)
	{
		if(obj->type[i]==1 || obj->type[i]==6)
		{
			tlen=obj->len[i];
			for(j=0;j<tlen && i<obj->length;j++,i++)
			{
				buffer[j]=obj->str[i];
				add=true;
			}
			if(add)
			{
				i--;
				add=false;
			}
			buffer[tlen]='\0';
			result->advance[ncount]=0;
			result->data[ncount]=0;
			result->type[ncount]=1;
			result->fdata[ncount]=atof(buffer);
			if(obj->type[i]==6)
				result->fdata[ncount]*=-1;
			ncount++;
		}else if(obj->type[i]==2)
		{
			tlen=obj->len[i];
			if(tlen>1)//运算符
			{
				index=GetOperator(obj->str,i);
				if(index==0)
					return MO_ERR_UNKOWN_FUNCTION;//未知函数
				result->advance[ncount]=0;
				result->data[ncount]=0;
				result->type[ncount]=1;
				result->fdata[ncount]=1;
				ncount++;//添加一个假想的数字
				result->advance[ncount]=GetAdvance(index)+base;
				result->data[ncount]=index;
				result->type[ncount]=3;
				result->fdata[ncount]=0;
				ncount++;
				i+=(tlen-1);
			}else//字母
			{
				result->advance[ncount]=0;
				result->data[ncount]=int(obj->str[i]);
				result->type[ncount]=2;
				result->fdata[ncount]=0;
				ncount++;
			}
		}else if(obj->type[i]==3)
		{
			base+=ADV;
		}else if(obj->type[i]==4)
		{
			base-=ADV;
			if(base<0)
				return MO_ERR_BRACKET_NO_MATCH;//括号不匹配
		}else if(obj->type[i]==5)
		{
			index=GetOperator(obj->str,i);
			if(index==0)
				return MO_ERR_UNKOWN_OPR;//未知运算符
			result->advance[ncount]=GetAdvance(index)+base;
			result->data[ncount]=index;
			result->type[ncount]=3;
			result->fdata[ncount]=0;
			ncount++;
		}
	}
	if(base>0)
		return MO_ERR_BRACKET_NO_MATCH;//括号不匹配
	return MO_ERR_OK;
}

mo_err mathopr::stage3(_mo_stage2 *obj,_mo_stage3 *des)
{
	des->head=new _mo_stage3_chain;
	des->head->opr_type=OPR_NUL;
	des->head->next=NULL;
	_mo_stage3_chain *now=des->head,*pre=NULL;
	int ncount=0;
	int rcount=0;
	int i;
	int* advance=new int[obj->ncount+1];
	double* dstack=new double[obj->ncount+1];
	int* stack=new int[obj->ncount+1];
	int* tstack=new int[obj->ncount+1];
	int npos=0;

	for(i=0;i<obj->ncount;i++)
	{
		if(obj->type[i]==1)
		{
			dstack[npos]=obj->fdata[i];
			stack[npos]=0;
			advance[npos]=0;
			tstack[npos]=1;
			npos++;
		}else if(obj->type[i]==2)
		{
			stack[npos]=obj->data[i];
			dstack[npos]=0;
			tstack[npos]=2;
			advance[npos]=0;
			npos++;
		}else if(obj->type[i]==3)
		{
			if(npos>=2)
			{
				if(tstack[npos-2]!=3)
				{
					delete[] advance;
					delete[] dstack;
					delete[] stack;
					delete[] tstack;
					return MO_ERR_UNKOWN;
				}
				while(advance[npos-2]>=obj->advance[i])				/*heihei*/
				{
					npos--;

					pre=now;
					now=new _mo_stage3_chain;
					now->next=NULL;
					pre->next=now;

					if(tstack[npos]==1)
					{

						now->type[1]=TYPE_NUM;
						now->data[1].num=dstack[npos];
					}else if(tstack[npos]==2)
					{
						now->type[1]=TYPE_VAR;
						now->data[1].chr=stack[npos];
					}else{
						now->type[1]=TYPE_REG;
						now->data[1].chr=stack[npos];	//??
					}
					npos--;
					if(tstack[npos]!=3)
						return MO_ERR_UNKOWN;
					now->opr_type=(enum _opr)stack[npos];

					npos--;
					if(tstack[npos]==1)
					{
						now->type[0]=TYPE_NUM;
						now->data[0].num=dstack[npos];
					}else if(tstack[npos]==2)
					{
						now->type[0]=TYPE_VAR;
						now->data[0].chr=stack[npos];
					}else{
						now->type[0]=TYPE_REG;
						now->data[0].chr=stack[npos];	//??
					}
					now->reg_num=rcount;

					stack[npos]=rcount;
					tstack[npos]=4;
					dstack[npos]=0;
					advance[npos]=0;
					npos++;
					rcount++;
					ncount++;
					if(npos<2)
						break;
				}
			}
			stack[npos]=obj->data[i];
			dstack[npos]=0;
			tstack[npos]=3;
			advance[npos]=obj->advance[i];
			npos++;
		}
	}
	while(npos>1)
	{
		npos--;

		pre=now;
		now=new _mo_stage3_chain;
		now->next=NULL;
		pre->next=now;

		if(tstack[npos]==1)
		{
			now->type[1]=TYPE_NUM;
			now->data[1].num=dstack[npos];
		}else if(tstack[npos]==2)
		{
			now->type[1]=TYPE_VAR;
			now->data[1].chr=stack[npos];
		}else{
			now->type[1]=TYPE_REG;
			now->data[1].chr=stack[npos];	//??
		}
		npos--;
		if(tstack[npos]!=3)
		{
			delete[] advance;
			delete[] dstack;
			delete[] stack;
			delete[] tstack;
			return MO_ERR_UNKOWN;
		}
		now->opr_type=(enum _opr)stack[npos];

		npos--;
		if(tstack[npos]==1)
		{
			now->type[0]=TYPE_NUM;
			now->data[0].num=dstack[npos];
		}else if(tstack[npos]==2)
		{
			now->type[0]=TYPE_VAR;
			now->data[0].chr=stack[npos];
		}else{
			now->type[0]=TYPE_REG;
			now->data[0].chr=stack[npos];	//??
		}

		now->reg_num=rcount;
		stack[npos]=rcount;
		tstack[npos]=4;
		dstack[npos]=0;
		npos++;
		rcount++;
		ncount++;
	}
	des->count=ncount;
	/*printf("rcount:%d  nconut:%d\n",rcount,ncount);

	if(rcount!=ncount)
	{
		printf("oh!\n");
		system("pause");
	}*/
	delete[] advance;
	delete[] dstack;
	delete[] stack;
	delete[] tstack;
	return MO_ERR_OK;
}

void mathopr::go_faster(_mo_stage3 *obj)
{

}

mo_base mathopr::calc()
{
	_mo_stage3 *obj=&r3;
	_mo_stage3_chain *now;
	int j;
	double a,b;
	if(!factor)factor=new double[r3.count];
	for(j=0;j<obj->count;j++)
		factor[j]=0;
	for(now=obj->head->next;now;now=now->next)
	{
		if(now->type[0]==TYPE_NUM)
		{
			a=now->data[0].num;
		}else if(now->type[0]==TYPE_VAR)
		{
			a=letter->table[now->data[0].chr];
		}else{
			a=factor[now->data[0].chr];
		}
		if(now->type[1]==TYPE_NUM)
		{
			b=now->data[1].num;
		}else if(now->type[1]==TYPE_VAR)
		{
			b=letter->table[now->data[1].chr];
		}else{
			b=factor[now->data[1].chr];
		}
		j=now->reg_num;
		switch(now->opr_type)
		{
		case OPR_ADD:
			factor[j]=a+b;
			break;
		case OPR_SUB:
			factor[j]=a-b;
			break;
		case OPR_MUL:
			factor[j]=a*b;
			break;
		case OPR_DIV:
			if(b==0)
				return 0;
			factor[j]=a/b;
			break;
		case OPR_EXP:
			//if(a==0)
				//return 0;
			factor[j]=pow(a,b);
			break;
		case OPR_LOG:
			factor[j]=log(b);
			break;
		case OPR_SIN:
			factor[j]=sin(b);
			break;
		case OPR_COS:
			factor[j]=cos(b);
			break;
		case OPR_TAN:
			factor[j]=tan(b);
			break;
		case OPR_ASI:
			factor[j]=asin(b);
			break;
		case OPR_ACO:
			factor[j]=acos(b);
			break;
		case OPR_ATA:
			factor[j]=atan(b);
			break;
		case OPR_ABS:
			factor[j]=fabs(b);
			break;
		case OPR_NUL:;
		}
	}
	return factor[obj->count-1];
}

