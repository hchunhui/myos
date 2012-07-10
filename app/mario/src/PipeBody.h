#ifndef _PIPEBODY_H_FILE_INCLUDED_

#define _PIPEBODY_H_FILE_INCLUDED_

#include "Object.h"

class CPipeBody:public CObject
{
public:
	CPipeBody(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
};

#endif
