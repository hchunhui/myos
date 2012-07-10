#ifndef _STAR_H_FILE_INCLUDED_

#define _STAR_H_FILE_INCLUDED_

#include "Object.h"

class CStar:public CObject
{
public:
	CStar(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual bool Block(CObject * Other);
private:
	int m_OriPos;//五星原始的位置，以判断是否完全升起。为0则表示已经完全升起了。
	int m_Action;//当前的动作状态，取值0~1
};

#endif
