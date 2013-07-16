/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "BrokenBrick.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CBrokenBrick::CBrokenBrick(CGame * Game,int x, int y,int HorzSpeed,int VertSpeed):CObject(Game,2,x,y,8,8,1)//碎砖显示在背景层之前
{
	m_HorzSpeed=HorzSpeed;
	m_VertSpeed=VertSpeed;
	LiveState=2;//碎砖块属于正在死亡的物体
}

const int * CBrokenBrick::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return BrokenBrickImage;
}

void CBrokenBrick::Clock()
{
	//具有重力加速度
	m_VertSpeed+=2;//重力加速度固定为2
	if(m_VertSpeed>20)m_VertSpeed=20;//重力速度最高为20

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
	}
}
