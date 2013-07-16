/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "PipeBody.h"
#include "ImgData.h"
#include "Game.h"

CPipeBody::CPipeBody(CGame * Game,int x, int y):CObject(Game,2,x,y,32,16,0)
{
}

const int * CPipeBody::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return PipeBodyImage;
}
