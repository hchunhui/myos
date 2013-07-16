#ifndef _PIPETOP_H_FILE_INCLUDED_

#define _PIPETOP_H_FILE_INCLUDED_

#include "Object.h"

class CPipeTop:public CObject
{
public:
	CPipeTop(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
};

#endif
