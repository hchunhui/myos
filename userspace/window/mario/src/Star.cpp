/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Star.h"
#include "ImgData.h"
#include "Game.h"

CStar::CStar(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//五星位于背景层后（可被砖块遮挡）
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//五星刚出现时向上升起
	m_Action=0;
}

const int * CStar::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return StarImage[m_Action];
}

void CStar::Clock()
{
	m_Action=!m_Action;//改变当前的动作状态

	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//已完全升起，则开始向右移动，并向上弹起
			m_OriPos=0;
			m_VertSpeed=-8;
			m_HorzSpeed=3;
		}
	}
	else
	{//已经完全升起了，则具有重力加速度
		m_VertSpeed+=1;//重力加速度固定为1
		if(m_VertSpeed>8)m_VertSpeed=8;//重力速度最高为8
	}

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//水平方向受到阻挡，则改变移动方向
			m_HorzSpeed=-m_HorzSpeed;
		}
		if(MoveResult&2)
		{//竖直方向受到阻挡
			if(m_VertSpeed>0)
				m_VertSpeed=-8;//下落时受到阻挡，则向上弹起
			else
				m_VertSpeed=0;//上升时受到阻挡，则停止上升，在重力作用下下降
		}
	}
}

void CStar::Attack(CObject * Other,int Mode)
{//被玛莉吃掉
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddStar();
}

bool CStar::Block(CObject * Other)
{
	if(m_OriPos)return false;//上升期间不受阻挡
	if(Other)
	{//只受固定物体的阻挡
		if(2==Other->Type)return true;
	}
	return false;
}
