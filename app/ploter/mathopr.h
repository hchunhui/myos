#ifndef _MATH_OPR_HEADER
#define _MATH_OPR_HEADER
#define NMAX 1000
#define ADV 4
#include <stddef.h>
typedef double mo_base;
typedef double (*fnptr)();
enum _opr
{
	OPR_ADD=1,
	OPR_SUB,
	OPR_MUL,
	OPR_DIV,
	OPR_EXP,
	OPR_LOG,
	OPR_SIN,
	OPR_COS,
	OPR_TAN,
	OPR_ASI,
	OPR_ACO,
	OPR_ATA,
	OPR_ABS,
	OPR_NUL
};
enum _type
{
	TYPE_NUM=1,
	TYPE_VAR,
	TYPE_REG,
	TYPE_NUL
};

enum _err
{
	MO_ERR_OK,
	MO_ERR_DOT,						//小数点使用错误
	MO_ERR_NUM_BEFORE_ALPHA,		//数字前面不能有字母
	MO_ERR_NUM_BEFORE_BRACKET,		//数字前面不能有括号
	MO_ERR_NO_CONTENT_IN_BRACKET,		//括号内无内容
	MO_ERR_BRACKET_BEFORE_OPR,		//括号前面不能是运算符
	MO_ERR_OPR_BEGIN,				//运算符不能放在开头
	MO_ERR_OPR,					//运算符使用错误
	MO_ERR_BRACKET,				//括号使用错误
	MO_ERR_UNKOWN_FUNCTION,			//未知函数
	MO_ERR_BRACKET_NO_MATCH,	//括号不匹配
	MO_ERR_UNKOWN_OPR,			//未知运算符
	MO_ERR_UNKOWN,
};
typedef enum _err mo_err;

struct _mo_stage1//字符串型计算式的初步分析结果
{
	char str[NMAX];
	int length;
	int type[NMAX];
	int len[NMAX];
};

struct _mo_stage2 //字符串型计算式的进一步分析结果
{
	double fdata[NMAX];
	int data[NMAX];//运算符时为种类，变量时为该字母的ASCII码
	int type[NMAX];//1为数字,2为变量，3为运算符，4为无效位
	int advance[NMAX];//0为非运算符，否则为运算符优先级
	int ncount;
};

struct _mo_stage3_chain
{
	enum _opr opr_type;
	enum _type type[2];
	union
	{
		double num;
		int chr;
	}data[2];
	int reg_num;
	_mo_stage3_chain* next;
};
struct _mo_stage3
{
	int count;
	_mo_stage3_chain* head;
	void sweep(_mo_stage3_chain* now)
	{
		if(now)
		{
			sweep(now->next);
			delete now;
		}
	}
	_mo_stage3()
	{
		head=NULL;
	}
	~_mo_stage3()
	{
		sweep(head);
		head=NULL;
	}
};

struct mo_letter
{
	mo_base table[256];
};

class mathopr
{
private:
	mo_err stage1(char *buffer,_mo_stage1 *result);
	mo_err stage2(_mo_stage1 *obj,_mo_stage2 *result);
	mo_err stage3(_mo_stage2 *obj,_mo_stage3 *des);
	void go_faster(_mo_stage3 *obj);
	_mo_stage3 r3;
	mo_letter* letter;
	double* factor;		//给stage3使用
	int* fac_con;
public:
	mathopr()
	{
		letter=NULL;
		factor=NULL;
		fac_con=NULL;
	}
	~mathopr()
	{
		delete[] factor;
		delete[] fac_con;
		factor=NULL;
		fac_con=NULL;
	}
	mo_err input(char* text,mo_letter* obj)
	{
		mo_err err;
		_mo_stage1 r1;
		_mo_stage2 r2;
		r3.~_mo_stage3();
		letter=obj;
		err=stage1(text,&r1);
		if(err)return err;
		err=stage2(&r1,&r2);
		if(err)return err;
		err=stage3(&r2,&r3);
		go_faster(&r3);
		return err;
	}
	mo_err import(_mo_stage2* pr2,mo_letter* obj)
	{
		mo_err err;
		r3.~_mo_stage3();
		letter=obj;
		err=stage3(pr2,&r3);
		go_faster(&r3);
		return err;
	}
	mo_base calc();
	fnptr compiler();
};

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct codebuf
{
	u8 buf[2000];
	int ptr;
};

void * operator new(size_t);
void operator delete(void *p);
#endif
