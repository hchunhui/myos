#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "mathopr.h"
#define DO_CONST_OPT
#define DO_DIV_OPT
#define DO_LOAD_OPT		//没有把握，慎用
#define DO_CHECK

#ifdef DO_CHECK
#define check(len)
#else
#endif

#define BPUT(_byte) cb->buf[cb->ptr++]=_byte
#define WPUT(_word) {*((u16*)&cb->buf[cb->ptr])=_word;cb->ptr+=2;}
#define LPUT(_long) {*((u32*)&cb->buf[cb->ptr])=_long;cb->ptr+=4;}

#define fldl_32(off32)		{BPUT(0xdd);BPUT(0x5);LPUT((u32)off32);}
#define fldl_edx()			{BPUT(0xdd);BPUT(0x2);}
#define faddl_edx8(off8)	{BPUT(0xdc);BPUT(0x42);BPUT(off8);}
#define faddl_32(off32)		{BPUT(0xdc);BPUT(0x5);LPUT(off32);}
#define fsubl_edx8(off8)	{BPUT(0xdc);BPUT(0x62);BPUT(off8);}
#define fsubl_32(off32)		{BPUT(0xdc);BPUT(0x25);LPUT(off32);}
#define fmull_edx8(off8)	{BPUT(0xdc);BPUT(0x4a);BPUT(off8);}
#define fmull_32(off32)		{BPUT(0xdc);BPUT(0x0d);LPUT(off32);}
#define fdivl_edx8(off8)	{BPUT(0xdc);BPUT(0x72);BPUT(off8);}
#define fdivl_32(off32)		{BPUT(0xdc);BPUT(0x35);LPUT(off32);}
#define fyl2x()				{BPUT(0xd9);BPUT(0xf1);}
#define fstpl_32(off32)		{BPUT(0xdd);BPUT(0x1d);LPUT((u32)off32);}
#define fstl_32(off32)		{}
#define sub_esp8(imm8)		{BPUT(0x83);BPUT(0xec);BPUT(imm8);}
#define add_esp8(imm8)		{BPUT(0x83);BPUT(0xc4);BPUT(imm8);}
#define movl_a32_eax(addr)	{BPUT(0xa1);LPUT(addr);}
#define movl_eax_esp8(imm8)	{BPUT(0x89);BPUT(0x44);BPUT(0x24);BPUT(imm8);}
#define movl_32_ecx(imm32)	{BPUT(0xb9);LPUT(imm32);}
#define call_a_ecx()		{BPUT(0xff);BPUT(0xd1);}
#define fstpl_esp8(imm8)	{BPUT(0xdd);BPUT(0x5c);BPUT(0x24);BPUT(imm8);}
#define fstpl_esp()			{BPUT(0xdd);BPUT(0x1c);BPUT(0x24);}
#define fsin()				{BPUT(0xd9);BPUT(0xfe);}
#define fcos()				{BPUT(0xd9);BPUT(0xff);}
#define fptan()				{BPUT(0xd9);BPUT(0xf2);}
#define fpatan()			{BPUT(0xd9);BPUT(0xf3);}
#define fld1()				{BPUT(0xd9);BPUT(0xe8);}
#define fldz()				{BPUT(0xd9);BPUT(0xee);}
#define fldlg2()			{BPUT(0xd9);BPUT(0xec);}
#define fldln2()			{BPUT(0xd9);BPUT(0xed);}
#define fldpi()				{BPUT(0xd9);BPUT(0xeb);}
#define fincstp()			{BPUT(0xd9);BPUT(0xf7);}
#define fstp_st(i)			{BPUT(0xdd);BPUT(0xd8+i);}
#define fld_st(i)			{BPUT(0xd9);BPUT(0xc0+i);}
#define fmul_st(i)			{BPUT(0xd8);BPUT(0xc8+i);}
#define fsubp()				{BPUT(0xde);BPUT(0xe1);}
#define fsqrt()				{BPUT(0xd9);BPUT(0xfa);}
#define f_abs()				{BPUT(0xd9);BPUT(0xe1);}
#define fxch(i)				{BPUT(0xd9);BPUT(0xc8+i);}
#define fsubr_st_st1()		{BPUT(0xdc);BPUT(0xe9);}
#define frndint()			{BPUT(0xd9);BPUT(0xfc);}
#define f2xm1()				{BPUT(0xd9);BPUT(0xf0);}
#define faddp_st_st1()		{BPUT(0xde);BPUT(0xc1);}
#define fscale()			{BPUT(0xd9);BPUT(0xfd);}
#define ftst()				{BPUT(0xd9);BPUT(0xe4);}
#define fnstsw_ax()			{BPUT(0xdf);BPUT(0xe0);}
#define fdivr_st_st1()		{BPUT(0xdc);BPUT(0xf9);}
#define jnz_rel8(rel8)		{BPUT(0x75);BPUT(rel8);}
#define jmp_rel8(rel8)		{BPUT(0xeb);BPUT(rel8);}
#define andw_16_ax(imm16)		{BPUT(0x66);BPUT(0x25);WPUT(imm16);}
void say_hello(double a,double b)
{
	printf("hi! a=%lf,b=%lf\n",a,b);
	for(;;);
}

void panic(const char* buf)
{
	printf("%s\n",buf);
	for(;;);
}
#ifdef DO_LOAD_OPT
#define smart_load(nr)	if(should_load)fldl_32(off[nr])
#else
#define smart_load(nr)	fldl_32(off[nr])
#endif

/* x87 FPU Status Word
15:Busy
14:C3
13,12,11:Stack Top
10:C2
 9:C1
 8:C0
 7:Error Summary Status
 6:Stack Fault Exception Flags
 5:Precision
 4:Underflow
 3:Overflow
 2:Zero Divide
 1:Denormalized Operand
 0:Invaild Operation
*/

void * operator new(size_t size)
{
void *p = malloc(size);
return (p);
}
void operator delete(void *p);
{
free(p);
}  

fnptr mathopr::compiler()
{
	_mo_stage3 *obj=&r3;
	_mo_stage3_chain *now;
	int k;
	u32 off[2];
	int isconst[2];
	double tmp;
	//#ifdef DO_LOAD_OPT
	int should_load=1;
	//#endif
	struct codebuf* cb=new struct codebuf;
	if(!factor)factor=new double[r3.count];
	#ifdef DO_CONST_OPT
	if(!fac_con)fac_con=new int[r3.count];
	memset(fac_con,0,sizeof(int)*r3.count);
	#endif
	cb->ptr=0;
	for(now=obj->head->next;now;now=now->next)
	{
		for(k=0;k<2;k++)
		{
			if(now->type[k]==TYPE_NUM)
			{
				off[k]=(u32)(&(now->data[k].num));
				isconst[k]=1;
			}else if(now->type[k]==TYPE_VAR)
			{
				off[k]=(u32)(&(letter->table[now->data[k].chr]));
				isconst[k]=0;
			}else{
				off[k]=(u32)(&(factor[now->data[k].chr]));
				#ifdef DO_CONST_OPT
				if(fac_con[now->data[k].chr])isconst[k]=1;
				else isconst[k]=0;
				#else
				isconst[k]=0;
				#endif
			}
		}
		#ifdef DO_CONST_OPT
		if(isconst[0] && isconst[1])		//算符两边都是常数,就先计算好
		{
			double a=*(double*)off[0];
			double b=*(double*)off[1];
			int j=now->reg_num;
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
				factor[j]=a/b;
				break;
			case OPR_EXP:
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
			fac_con[j]=1;		//说明起寄存器也是常数
			//#ifdef DO_LOAD_OPT	//到底要不要加!!!???
			//should_load=1;
			//#endif
			continue;
		}
		#endif
		#ifdef DO_DIV_OPT		//对于除以常数的情况,以乘代除
		if(isconst[1] && now->opr_type==OPR_DIV)
		{
			now->opr_type=OPR_MUL;
			if(now->type[1]==TYPE_NUM)
			{
				//printf("enter1\n");
				now->data[1].num=1/(now->data[1].num);
			}
			else if(now->type[1]==TYPE_REG)
			{
				//printf("enter2\n");
				now->type[1]=TYPE_NUM;
				now->data[1].num=factor[now->data[1].chr];
			}
		}
		#endif
		switch(now->opr_type)
		{
		case OPR_ADD:
			//factor[j]=a+b;
			smart_load(0);
			faddl_32(off[1]);//faddl  0x1234567
			break;
		case OPR_SUB:
			//factor[j]=a-b;
			//fldl_32(off[0]);
			smart_load(0);
			fsubl_32(off[1]);//fsubl  0x1234567
			break;
		case OPR_MUL:
			//factor[j]=a*b;
			//fldl_32(off[0]);
			smart_load(0);
			fmull_32(off[1]);//fmull  0x1234567
			break;
		case OPR_DIV:
			//fldl_32(off[0]);
			smart_load(0);
			fdivl_32(off[1]);//fdivl  0x1234567
			break;
		case OPR_EXP:
			/*sub_esp8(16);
			fldl_32(off[1]);
			fstpl_esp8(8);
			fldl_32(off[0]);
			fstpl_esp();*/
			//movl_a32_eax(off[0]);
			//movl_eax_esp8(0);
			//movl_a32_eax(off[0]+4);
			//movl_eax_esp8(4);
			/*movl_a32_eax(off[1]);
			movl_eax_esp8(8);
			movl_a32_eax(off[1]+4);
			movl_eax_esp8(12);*/
			//movl_32_ecx((u32)&pow);
			//call_a_ecx();
			//add_esp8(16);

			//factor[j]=pow(a,b);
			if(!should_load)panic("error at exp!");
			tmp=*((double*)off[1]);
			if(isconst[1] && tmp<=4.0 && tmp>=-4.0)		//b is const
			{
				if(tmp==(int)tmp)		//确实可以用==
				{
					int ex=(int)tmp;
					if(ex==0)			//严格说0^0无定义!!
					{
						fldl_32(off[0]);
						ftst();
						fnstsw_ax();
						andw_16_ax(0x4500);			//0100000000000000b:C3
						jnz_rel8(6);
						fstp_st(0);//2bytes
						fld1();//2bytes
						jmp_rel8(10);//2bytes
						fstp_st(0);		//pop 2bytes
						fldz();			//2bytes
						fldz();			//2bytes
						fdivr_st_st1();	//2bytes
						fstp_st(0);		//2bytes
						break;
					}
					if(ex<0)
					{
						fld1();
						fdivl_32(off[0]);
						fldl_32(off[0]);
						ftst();
						fnstsw_ax();
						andw_16_ax(0x4500);			//0100000000000000b:C3
						jnz_rel8(4);
						/* a!=0 */
						fstp_st(0);//2bytes
						jmp_rel8(6);//2bytes
						/* a==0 */
						fstp_st(0);//2bytes
						fstp_st(0);//2bytes
						fldz();//2bytes
					}
					else
					{
						fldl_32(off[0]);
					}
					switch(abs(ex))
					{
						case 1:break;
						case 2:
							fmul_st(0);
							break;
						case 3:
							fld_st(0);
							fmul_st(0);
							fmul_st(1);
							fstp_st(1);
							break;
						case 4:
							fmul_st(0);
							fmul_st(0);
							break;
					}
					break;
				}
			}

			sub_esp8(16);
			fldl_32(off[1]);
			fstpl_esp8(8);
			//fldl_32(off[0]);
			//fstpl_esp();
			movl_a32_eax(off[0]);
			movl_eax_esp8(0);
			movl_a32_eax(off[0]+4);
			movl_eax_esp8(4);
			movl_32_ecx((u32)&pow);
			call_a_ecx();
			add_esp8(16);

			//fldl_32(off[1]);
			//fldl_32(off[0]);
			//fyl2x();
			//fld_st(0);
			//frndint();							/* int(x) */
			//fsubr_st_st1();						/* fract(x) */
			//fxch(1);
			//f2xm1();							/* 2^(fract(x)) - 1 */
			//fld1();
			//faddp_st_st1();						/* 2^(fract(x)) */
			//fscale();							/* 2^x */
			//fstp_st(1);
			break;
		case OPR_LOG:
			if(!should_load)panic("error at log!");
			//factor[j]=log(b);
			//fldlg2();//log(10,x)
			fldln2();//ln(x)
			fldl_32(off[1]);
			fyl2x();
			break;
		case OPR_SIN:
			smart_load(1);
			//fldl_32(off[1]);
			fsin();
			//factor[j]=sin(b);
			break;
		case OPR_COS:
			smart_load(1);
			//fldl_32(off[1]);
			fcos();
			//factor[j]=cos(b);
			break;
		case OPR_TAN:
			smart_load(1);
			//fldl_32(off[1]);
			fptan();
			fstp_st(0);
			//factor[j]=tan(b);
			break;
		case OPR_ASI:
			//factor[j]=asin(b);
			//arcsin(x)=arctan(x / sqrt(1 - x^2))
			smart_load(1);
			//fldl_32(off[1]);
			fld_st(0);
			fmul_st(0);
			fld1();
			fsubp();
			fsqrt();
			fpatan();
			break;
		case OPR_ACO:
			//factor[j]=acos(b);
			smart_load(1);
			//fldl_32(off[1]);
			fld_st(0);
			fmul_st(0);
			fld1();
			fsubp();
			fsqrt();
			fxch(1);
			fpatan();
			break;
		case OPR_ATA:
			//factor[j]=atan(b);
			smart_load(1);
			//fldl_32(off[1]);
			fld1();
			fpatan();
			break;
		case OPR_ABS:
			smart_load(1);
			//fldl_32(off[1]);
			f_abs();
			break;
		case OPR_NUL:;
		}
		#ifdef DO_LOAD_OPT
		if(now->next)
		{
			_mo_stage3_chain* pnext=now->next;
			if(pnext->type[0]==TYPE_REG && pnext->data[0].chr==now->reg_num)
			{
				should_load=0;
				goto quit;
			}
			if(
			pnext->opr_type==OPR_SIN || pnext->opr_type==OPR_COS ||
			pnext->opr_type==OPR_TAN || pnext->opr_type==OPR_ASI || pnext->opr_type==OPR_ACO ||
			pnext->opr_type==OPR_ATA || pnext->opr_type==OPR_ABS
				)
			{
				if(pnext->data[1].chr==now->reg_num)
				{
					should_load=0;
					goto quit;
				}
			}
			fstpl_32(&(factor[now->reg_num]));//fstpl  0x1234567
			should_load=1;
			quit:;
		}
		else		//now reach the end,so there is no need to store and reload it.
			should_load=0;
		#else
		fstpl_32(&(factor[now->reg_num]));//fstpl  0x1234567
		#endif

	}
	//return factor[obj->count-1];
	#ifndef DO_LOAD_OPT
	BPUT(0xdd);BPUT(0x5);LPUT((u32)&(factor[obj->count-1]));
	#else
	if(should_load)
	{
		BPUT(0xdd);BPUT(0x5);LPUT((u32)&(factor[obj->count-1]));
	}
	#endif
	BPUT(0xc3);//ret
	if(cb->ptr>=2000)printf("oh!no");
	FILE *fp=fopen("out.bin","wb");
	fwrite((void*)cb,cb->ptr,1,fp);
	fclose(fp);
	return (fnptr)cb;
}

