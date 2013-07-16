/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Fungus.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CFungus::CFungus(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//蘑菇位于背景层后（可被砖块遮挡）
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//蘑菇刚出现时向上升起
}

const int * CFungus::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return FungusImage;
}

void CFungus::Clock()
{
	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//已完全升起，则停止上升，开始向右移动
			m_OriPos=0;
			m_VertSpeed=0;
			m_HorzSpeed=3;
		}
	}
	else
	{//已经完全升起了，则具有重力加速度
		m_VertSpeed+=2;//重力加速度固定为2
		if(m_VertSpeed>20)m_VertSpeed=20;//重力速度最高为20
	}

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//水平方向受到阻挡，则改变移动方向
			m_HorzSpeed=-m_HorzSpeed;
		}
		if(MoveResult&2)
		{//竖直方向受到阻挡，则竖直速度减为0
			m_VertSpeed=0;
		}
	}
}

void CFungus::Attack(CObject * Other,int Mode)
{//被玛莉吃掉
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddPower();
}

bool CFungus::Block(CObject * Other)
{
	if(m_OriPos)return false;//上升期间不受阻挡
	if(Other)
	{//只受固定物体的阻挡
		if(2==Other->Type)return true;
	}
	return false;
}
