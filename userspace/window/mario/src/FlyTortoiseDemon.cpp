/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "FlyTortoiseDemon.h"
#include "ImgData.h"
#include "Game.h"
#include "TortoiseDemon.h"

CFlyTortoiseDemon::CFlyTortoiseDemon(CGame * Game,int x, int y):CObject(Game,3,x,y+8,16,24,0)//乌龟在地图上的位置比实际位置高了8个像素
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//妖怪刚出现时向左移动
	m_ToRight=false;//面向左边
}

const int * CFlyTortoiseDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//面向右边则要水平翻转显示
	return FlyTortoiseDemonImage[m_Action];
}

void CFlyTortoiseDemon::Clock()
{
	m_ActionTimeCount++;
	if(5<=m_ActionTimeCount)
	{
		m_Action=!m_Action;
		m_ActionTimeCount=0;
	}

	//无论何时都有重力加速度
	m_VertSpeed+=1;//因为会飞，所以重力加速度只有1
	if(m_VertSpeed>10)m_VertSpeed=10;//重力速度最高为10

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//水平方向受到阻挡，则改变移动方向
			m_HorzSpeed=-m_HorzSpeed;
			m_ToRight=!m_ToRight;
		}
		if(MoveResult&2)
		{//竖直方向受到阻挡
			if(m_VertSpeed>0)
				m_VertSpeed=-10;//下落时受到阻挡，则向上弹起
			else
				m_VertSpeed=0;//上升时受到阻挡，则停止上升，在重力作用下下降
		}
	}
}

void CFlyTortoiseDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//只有活妖怪才能被攻击
	CTortoiseDemon * p;
	switch(Mode)
	{
	case 1://受到子弹、隐形玛莉或乌龟壳的攻击
		//先变成普通乌龟，再被打死
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		LiveState=3;
		p=new CTortoiseDemon(m_Game,XPos,YPos);
		p->Attack(Other,Mode);
		m_Game->AddObj(p);
		break;
	case 2://被玛莉踩到
		//变成普通乌龟
		m_Game->PlaySound(CSoundMan::ATTACKDEMON);
		LiveState=3;
		m_Game->AddObj(new CTortoiseDemon(m_Game,XPos,YPos));
		break;
	}
}

void CFlyTortoiseDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;
	if(1==Other->Type&&(3==Mode||1==Mode))
	{//从侧面或上面攻击玛莉
		Other->Attack(this,1);
	}
}
