#ifndef _FLYTORTOISEDEMON_H_FILE_INCLUDED_

#define _FLYTORTOISEDEMON_H_FILE_INCLUDED_

#include "Object.h"

class CFlyTortoiseDemon:public CObject
{
public:
	CFlyTortoiseDemon(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
private:
	int m_Action;//当前的动作状态，取值0~1
	int m_ActionTimeCount;//并非每个时钟周期都改变动作，而是要等该数器达到一定值时才改变。
	bool m_ToRight;//当前面向哪方。true:右 false:左
};

#endif
