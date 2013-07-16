/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Flower.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CFlower::CFlower(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//花位于背景层后（可被砖块遮挡）
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//花刚出现时向上升起
	m_Action=0;
}

const int * CFlower::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return FlowerImage[m_Action];
}

void CFlower::Clock()
{
	m_Action=!m_Action;//改变当前的动作状态

	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//已完全升起，则停止上升
			m_OriPos=0;
			m_VertSpeed=0;
		}
	}

	if(m_VertSpeed)
	{//有速度则要移动
		m_Game->Move(this,0,m_VertSpeed);
	}
}

void CFlower::Attack(CObject * Other,int Mode)
{//被玛莉吃掉
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddPower();
}

bool CFlower::Block(CObject * Other)
{//不受任何阻挡
	return false;
}
