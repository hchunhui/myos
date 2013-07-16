/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Control.h"

void CControl::Clock()
{
/*
	执行一次时序信号动作。
*/
	//使游戏动作一次
	m_pGame->Clock();
	//刷新图像显示
	m_pGraphMan->Update();
}

void CControl::SetGraph(CGraphMan *Graph)
{
/*
	设置图像处理对象。
	参数：
		[i]Game		将要受CControl控制的CGraphMan对象。
*/
	m_pGraphMan=Graph;
}

void CControl::KeyDown(int KeyChange)
{
	int KeyState = m_LastKeyState | KeyChange;
	if(KeyState != m_LastKeyState)
	{
		KeyChanged(KeyState);
	}	
}

void CControl::KeyUp(int KeyChange)
{
	int KeyState = m_LastKeyState & (~KeyChange);
	if(KeyState != m_LastKeyState)
	{
		KeyChanged(KeyState);
	}
}

void CControl::KeyChanged(int KeyState)
{
/*
	按键状态发生改变。
	参数：
		[i]KeyState	按钮状态，是一个位段值。相应的位值为1，表式该键是按下状态，为0表示该键是弹起状态。
					从最低位开始，各位依次表示如下按键：上方向、下方向、左方向、右方向、跳跃键、发射键、开始键。
*/
	if(!(m_LastKeyState&(1<<6))&&(KeyState&(1<<6)))
	{//上次没按下开始键，这次按下了，则开始游戏
		m_pGame->Start();
		printf("start!\n");
	}

	if(!(KeyState&0xf)&&(m_LastKeyState&0xf))
	{//上次有方向键被按下，这次没有，则停止移动
		m_pGame->Move(0,false);
	}
	else
	{
		bool Acc=(KeyState&(1<<5))!=0;//按了发射键，则加速移动
		bool AccChanged=(KeyState&(1<<5))!=(m_LastKeyState&(1<<5));//加速键的状态和上次不同，则表示加速状态有改变
		if((KeyState&(1<<0))&&(!(m_LastKeyState&(1<<0))||AccChanged))
		{//这次按下了向上键，而上次没按下或者加速状态改变，则向上移动
			m_pGame->Move(1,Acc);
		}
		else if((KeyState&(1<<1))&&(!(m_LastKeyState&(1<<1))||AccChanged))
		{//这次按下了向下键，而上次没按下或者加速状态改变，则向下移动
			m_pGame->Move(2,Acc);
		}
		else if((KeyState&(1<<2))&&(!(m_LastKeyState&(1<<2))||AccChanged))
		{//这次按下了向左键，而上次没按下或者加速状态改变，则向左移动
			m_pGame->Move(3,Acc);
		}
		else if((KeyState&(1<<3))&&(!(m_LastKeyState&(1<<3))||AccChanged))
		{//这次按下了向右键，而上次没按下或者加速状态改变，则向右移动
			m_pGame->Move(4,Acc);
		}
	}

	if(!(m_LastKeyState&(1<<4))&&(KeyState&(1<<4)))
	{//上次没按下跳跃键，这次按下了，则跳跃一次
		m_pGame->Jump();
	}

	if(!(m_LastKeyState&(1<<5))&&(KeyState&(1<<5)))
	{//上次没按下发射键，这次按下了，则发射一次
		m_pGame->Fire();
	}

	m_LastKeyState=KeyState;
}

void CControl::SetGame(CGame *Game)
{
/*
	设置游戏对象。
	参数：
		[i]Game		将要受CControl控制的CGame对象。
*/
	m_pGame=Game;
}

CControl::CControl()
{
	m_LastKeyState=0;//最开始时没有任何键按下
	printf("CControl init\n");
}
