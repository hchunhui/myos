/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Coin.h"
#include "ImgData.h"
#include "Game.h"

CCoin::CCoin(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,1)//金币在背景之前显示
{
	m_OriPos=y;
	m_Rotate=0;
}

const int * CCoin::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	if(m_Rotate)
	{//正在旋转
		return CoinImage[m_Rotate];
	}
	else
	{//未旋转
		return CoinImage[g_FlushAction];
	}
}

void CCoin::Attack(CObject * Other,int Mode)
{
	if(2==LiveState)return;//已经被顶出的金币不能再被吃
	m_Game->PlaySound(CSoundMan::COIN);
	LiveState=3;
}

bool CCoin::Block(CObject * Other)
{
	return false;//金币不受任何物体阻挡
}

void CCoin::Clock()
{
	switch(m_Rotate)
	{
	case 3:
		m_Rotate=4;
		m_RotateThin=true;
		break;
	case 4:
		if(m_RotateThin)
			m_Rotate=5;
		else
			m_Rotate=3;
		break;
	case 5:
		m_Rotate=4;
		m_RotateThin=false;
		break;
	default:
		return;//金币没有旋转，则不用执行任何操作
	}
	
	//无论何时都有重力加速度
	m_VertSpeed+=1;//重力加速度固定为1
	if(m_VertSpeed>10)m_VertSpeed=10;//重力速度最高为10

	if(m_VertSpeed)
	{//有速度则要移动
		m_Game->Move(this,0,m_VertSpeed);
	}

	if(YPos>m_OriPos)
	{//金币掉到了原始位置之下，则消失
		LiveState=3;
	}
}

void CCoin::ThrowUp()
{
/*
	将金币向上抛起。
*/
	m_Game->PlaySound(CSoundMan::COIN);
	m_VertSpeed=-9;
	m_Rotate=3;
	LiveState=2;
}
