/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "BeetleDemon.h"
#include "ImgData.h"
#include "Game.h"

CBeetleDemon::CBeetleDemon(CGame * Game,int x, int y):CObject(Game,3,x,y,16,16,0)
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-3;//妖怪刚出现时向左移动
	m_ToRight=false;//面向左边
}

const int * CBeetleDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//面向右边则要水平翻转显示
	return BeetleDemonImage[m_Action];
}

void CBeetleDemon::Clock()
{
	if(2==m_Action)
	{//已经变成了甲虫壳
		if(1==LiveState&&0==m_HorzSpeed)
		{//是活的甲虫壳且没有被踢动，则过一段时间后再恢复成甲虫
			m_ActionTimeCount++;
			if(100<=m_ActionTimeCount)
			{
				m_Action=0;
				m_ActionTimeCount=0;
				m_HorzSpeed=-2;
				m_ToRight=false;
			}
		}
	}
	else
	{
		m_ActionTimeCount++;
		if(5<=m_ActionTimeCount)
		{
			m_Action=!m_Action;
			m_ActionTimeCount=0;
		}
	}

	//无论何时都有重力加速度
	m_VertSpeed+=2;//重力加速度固定为2
	if(m_VertSpeed>20)m_VertSpeed=20;//重力速度最高为20

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//水平方向受到阻挡，则改变移动方向
			if(2==m_Action)
			{//甲虫壳撞到墙要发出声音
				m_Game->PlaySound(CSoundMan::BLOCK);
			}
			m_HorzSpeed=-m_HorzSpeed;
			m_ToRight=!m_ToRight;
		}
		if(MoveResult&2)
		{//竖直方向受到阻挡，则竖直速度减为0
			m_VertSpeed=0;
		}
	}
}

void CBeetleDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//只有活妖怪才能被攻击
	switch(Mode)
	{
	case 1://受到子弹、隐形玛莉或甲虫壳的攻击
		if(4==Other->Type)return;//不受子弹的攻击
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		Layer=1;//正在死亡的妖怪一律显示在背景之前
		break;
	case 2://被玛莉踩到
		if(2!=m_Action||2==m_Action&&m_HorzSpeed)
		{//是活甲虫，或者已经是正在运动的甲虫壳，则变成静止的甲虫壳
			m_Game->PlaySound(CSoundMan::ATTACKDEMON);
			m_Action=2;
			m_VertSpeed=0;
			m_HorzSpeed=0;
			m_ActionTimeCount=0;
			m_MarioBump=false;
		}
		break;
	default:
		if(2==Other->Type)
		{//被砖块顶到
			m_Game->PlaySound(CSoundMan::ATTACKDEMON);
			m_Action=2;
			m_VertSpeed=-4;
			m_HorzSpeed=0;
			m_ActionTimeCount=0;
			m_MarioBump=true;//下次被玛莉碰到时直接运动，不用等两次
		}
	}
}

void CBeetleDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;

	if(2==m_Action)
	{//已变成甲虫壳
		if(0==m_HorzSpeed)
		{//是静止的甲虫壳
			if(1==Other->Type)
			{//被玛莉两次碰到（第一次被踩到不算），则要开始运动
				if(m_MarioBump)
				{
					m_Game->PlaySound(CSoundMan::ATTACKDEMON);
					if(Other->XPos>XPos+8)
					{//碰到甲虫的右侧，则向左运动
						m_HorzSpeed=-10;
					}
					else
					{//碰到甲虫的左侧，则向右运动
						m_HorzSpeed=10;
					}
				}
				else
				{
					m_MarioBump=true;
				}
			}
		}
		else if(1==LiveState&&(3==Mode||1==Mode)&&(1==Other->Type||3==Other->Type))
		{//是被踢动的活甲虫壳，可以从侧面或上面攻击玛莉或其他妖怪
			Other->Attack(this,1);
		}
	}
	else if(1==Other->Type&&(3==Mode||1==Mode))
	{//是活甲虫，只能从侧面或上面攻击玛莉
		Other->Attack(this,1);
	}
}

bool CBeetleDemon::Block(CObject * Other)
{
	if(1!=LiveState)return false;//正在死亡的物体不受阻挡

	if(Other)
	{
		if(5==Other->Type)return false;//金币、蘑菇等不能阻挡别人
		if(2==m_Action&&m_HorzSpeed&&3==Other->Type)return false;//已被踢动的甲虫壳不受其他妖怪的阻挡
		if(4==Other->Type)return false;//不受子弹阻挡
		return true;//能被其他物体阻挡
	}
	else
		return false;//不受地图边界阻挡
}
