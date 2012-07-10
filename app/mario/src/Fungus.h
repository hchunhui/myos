#ifndef _FUNGUS_H_FILE_INCLUDED_

#define _FUNGUS_H_FILE_INCLUDED_

#include "Object.h"

class CFungus:public CObject
{
public:
	CFungus(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual bool Block(CObject * Other);
private:
	int m_OriPos;//蘑菇原始的位置，以判断是否完全升起。为0则表示已经完全升起了。
};

#endif
