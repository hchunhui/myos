#ifndef _CLIPDEMON_H_FILE_INCLUDED_

#define _CLIPDEMON_H_FILE_INCLUDED_

#include "Object.h"

class CClipDemon:public CObject
{
public:
	CClipDemon(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual bool Block(CObject * Other);
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
private:
	int m_Action;//当前的动作状态，取值0~1
	int m_ActionTimeCount;//并非每个时钟周期都改变动作，而是要等该数器达到一定值时才改变。
	int m_UpDownTimeCount;//并非每个时钟周期都钻出来缩进去，而是要等该数器达到一定值时才出来或回去。
	int m_Top;//夹子能上升到的最高位置
};

#endif
