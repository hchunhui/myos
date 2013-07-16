/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "ClipDemon.h"
#include "ImgData.h"
#include "Game.h"

CClipDemon::CClipDemon(CGame * Game,int x, int y):CObject(Game,3,x+8,y+8,16,24,-1)//夹子在地图上的位置比实际位置偏左上8个像素
																				//夹子位于背景层之后（可以被水管遮挡）
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_UpDownTimeCount=0;
	m_Top=y+8;//在地图上设定的位置(加8)就是最高位置
}

const int * CClipDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return ClipDemonImage[m_Action];
}

void CClipDemon::Clock()
{
	m_ActionTimeCount++;
	if(5<=m_ActionTimeCount)
	{
		m_Action=!m_Action;
		m_ActionTimeCount=0;
	}

	m_UpDownTimeCount++;
	if(m_VertSpeed)
	{//正在运动过程中
		m_Game->Move(this,m_HorzSpeed,m_VertSpeed);//绝不会受到阻挡
		if(YPos==m_Top||YPos==m_Top+25)
		{//已到到达运动的最高点或最低点，则停止运动
			m_VertSpeed=0;
			m_UpDownTimeCount=0;//开始计时
		}
	}
	else
	{//在静止状态，则等30个周期再恢复运动
		if(30==m_UpDownTimeCount)
		{
			if(YPos==m_Top)
			{//当前在最高点，则向下运动
				m_VertSpeed=1;
			}
			else
			{//当前在最低点，则向上运动
				m_VertSpeed=-1;
			}
			m_UpDownTimeCount=0;
		}
	}
}

bool CClipDemon::Block(CObject * Other)
{
	return false;//夹子不受水管及任何物体阻挡
}

void CClipDemon::Attack(CObject * Other,int Mode)
{
	switch(Mode)
	{
	case 1://受到子弹、隐形玛莉或乌龟壳的攻击
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		LiveState=3;
		break;
	}
}

void CClipDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1==Other->Type)
	{//攻击玛莉
		Other->Attack(this,1);
	}
}
