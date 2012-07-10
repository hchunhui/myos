#ifndef _BROKENBRICK_H_FILE_INCLUDED_

#define _BROKENBRICK_H_FILE_INCLUDED_

#include "Object.h"

class CBrokenBrick:public CObject
{
public:
	CBrokenBrick(CGame * Game,int x, int y,int HorzSpeed,int VertSpeed);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
};

#endif
