#ifndef _BULLET_H_FILE_INCLUDED_

#define _BULLET_H_FILE_INCLUDED_

#include "Object.h"

class CBullet:public CObject
{
public:
	CBullet(CGame * Game,int x, int y,int ToLeft);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Bump(CObject * Other,int Mode,bool Volun);
private:
	int m_Action;//当前的动作状态，取值0~3
};

#endif
