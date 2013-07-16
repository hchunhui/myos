/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "TortoiseDemon.h"
#include "ImgData.h"
#include "Game.h"

CTortoiseDemon::CTortoiseDemon(CGame * Game,int x, int y):CObject(Game,3,x,y+8,16,24,0)//乌龟在地图上的位置比实际位置高了8个像素
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//妖怪刚出现时向左移动
	m_ToRight=false;//面向左边
}

const int * CTortoiseDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//面向右边则要水平翻转显示
	return TortoiseDemonImage[m_Action];
}

void CTortoiseDemon::Clock()
{
	if(2==m_Action)
	{//已经变成了乌龟壳
		if(1==LiveState&&0==m_HorzSpeed)
		{//是活的乌龟壳且没有被踢动，则过一段时间后再恢复成乌龟
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
			{//乌龟壳撞到墙要发出声音
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

void CTortoiseDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//只有活妖怪才能被攻击
	switch(Mode)
	{
	case 1://受到子弹、隐形玛莉或乌龟壳的攻击
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		Layer=1;//正在死亡的妖怪一律显示在背景之前
		break;
	case 2://被玛莉踩到
		if(2!=m_Action||2==m_Action&&m_HorzSpeed)
		{//是活乌龟，或者已经是正在运动的乌龟壳，则变成静止的乌龟壳
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

void CTortoiseDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;

	if(2==m_Action)
	{//已变成乌龟壳
		if(0==m_HorzSpeed)
		{//是静止的乌龟壳
			if(1==Other->Type)
			{//被玛莉两次碰到（第一次被踩到不算），则要开始运动
				if(m_MarioBump)
				{
					m_Game->PlaySound(CSoundMan::ATTACKDEMON);
					if(Other->XPos>XPos+8)
					{//碰到乌龟的右侧，则向左运动
						m_HorzSpeed=-10;
					}
					else
					{//碰到乌龟的左侧，则向右运动
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
		{//是被踢动的活乌龟壳，可以从侧面或上面攻击玛莉或其他妖怪
			Other->Attack(this,1);
		}
	}
	else if(1==Other->Type&&(3==Mode||1==Mode))
	{//是活乌龟，只能从侧面或上面攻击玛莉
		Other->Attack(this,1);
	}
}

bool CTortoiseDemon::Block(CObject * Other)
{
	if(1!=LiveState)return false;//正在死亡的物体不受阻挡

	if(Other)
	{
		if(5==Other->Type)return false;//金币、蘑菇等不能阻挡别人
		if(2==m_Action&&m_HorzSpeed&&3==Other->Type)return false;//已被踢动的乌龟壳不受其他妖怪的阻挡
		return true;//能被其他物体阻挡
	}
	else
		return false;//不受地图边界阻挡
}
