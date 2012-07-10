#ifndef _STONE_H_FILE_INCLUDED_

#define _STONE_H_FILE_INCLUDED_

#include "Object.h"

class CStone:public CObject
{
public:
	CStone(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
};

#endif
