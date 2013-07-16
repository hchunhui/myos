/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Bullet.h"
#include "ImgData.h"
#include "Game.h"

CBullet::CBullet(CGame * Game,int x, int y,int ToLeft):CObject(Game,4,x,y,8,8,0)
{
/*
	参数：
		[i]ToLeft	子弹的方向。true:向左 false:向右
*/
	if(ToLeft)
		m_HorzSpeed=-10;
	else
		m_HorzSpeed=10;
	m_Action=0;
}

const int * CBullet::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return BulletImage[m_Action];
}

void CBullet::Clock()
{
	//改变当前的动作状态
	m_Action++;
	if(4==m_Action)m_Action=0;

	//无论何时都有重力加速度
	m_VertSpeed+=2;//重力加速度固定为2
	if(m_VertSpeed>20)m_VertSpeed=20;//重力速度最高为20

	int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
	if(MoveResult&1)
	{//水平方向受到阻挡，则消失
		LiveState=3;
	}
	if(MoveResult&2)
	{//竖直方向受到阻挡
		if(m_VertSpeed>0)
			m_VertSpeed=-8;//下落时受到阻挡，则向上弹起
		else
			LiveState=3;//上升时受到阻挡，则消失
	}
}

void CBullet::Bump(CObject * Other,int Mode,bool Volun)
{
	if(3==Other->Type&&1==Other->LiveState)
	{//碰到活妖怪，则向其攻击
		Other->Attack(this,1);
		LiveState=3;
	}
}

