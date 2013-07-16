#ifndef _GROUND_H_FILE_INCLUDED_

#define _GROUND_H_FILE_INCLUDED_

#include "Object.h"

class CGround:public CObject
{
public:
	CGround(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
};

#endif
