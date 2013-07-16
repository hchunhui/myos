/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "FungusDemon.h"
#include "ImgData.h"
#include "Game.h"

CFungusDemon::CFungusDemon(CGame * Game,int x, int y):CObject(Game,3,x,y,16,16,0)
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//妖怪刚出现时向左移动
}

const int * CFungusDemon::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	if(2==LiveState&&0==m_Action)
		*VInv=true;//已被打死，则竖直翻转
	else
		*VInv=false;
	return FungusDemonImage[m_Action];
}

void CFungusDemon::Clock()
{
	if(1==LiveState)
	{//还活著则要改变资势
		m_ActionTimeCount++;
		if(5<=m_ActionTimeCount)
		{
			m_Action=!m_Action;
			m_ActionTimeCount=0;
		}
	}
	
	if(2==LiveState&&2==m_Action)
	{//已被踩扁，则等一段时间后消失
		m_ActionTimeCount++;
		if(10==m_ActionTimeCount)
		{
			LiveState=3;
		}
	}
	else
	{//已被踩扁则没有重力加速度
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

void CFungusDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//只有活妖怪才能被攻击
	switch(Mode)
	{
	case 1://受到子弹、隐形玛莉或乌龟壳的攻击
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=0;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		break;
	case 2://被玛莉踩到
		m_Game->PlaySound(CSoundMan::ATTACKDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=0;
		m_HorzSpeed=0;
		m_ActionTimeCount=0;
		break;
	default:
		if(2==Other->Type)
		{//被砖块顶到
			m_Game->PlaySound(CSoundMan::KILLDEMON);
			m_Action=0;
			LiveState=2;
			m_VertSpeed=-10;
			m_HorzSpeed=2;
		}
	}
	Layer=1;//正在死亡的妖怪一律显示在背景之前
}

void CFungusDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;
	if(1==Other->Type&&(3==Mode||1==Mode))
	{//从侧面或上面攻击玛莉
		Other->Attack(this,1);
	}
}
