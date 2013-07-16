/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Stone.h"
#include "ImgData.h"
#include "Game.h"

CStone::CStone(CGame * Game,int x, int y):CObject(Game,2,x,y,16,16,0)
{
}

const int * CStone::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return StoneImage;
}
