/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Question.h"
#include "ImgData.h"
#include "Game.h"
#include "Fungus.h"
#include "Flower.h"
#include "Coin.h"

CQuestion::CQuestion(CGame * Game,int x, int y,int Content):CObject(Game,2,x,y,16,16,0)
{
/*
	参数：
		[i]Content		问号内藏何物。
						0		没有东西。
						1		蘑菇。
						2		十枚金币。
						3		一枚金币。
*/
	m_OriPos=y;
	switch(Content)
	{
	case 1:
		m_Content=-1;
		break;
	case 2:
		m_Content=10;
		break;
	case 3:
		m_Content=1;
		break;
	default:
		m_Content=0;
	}
}

const int * CQuestion::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	if(0==m_Content)return QuestionImage[3];//是空盒
	return QuestionImage[g_FlushAction];
}

void CQuestion::MoveUp()
{
/*
	被顶到后向上移动几个像素
*/
	m_Game->Move(this,0,-4);
	m_TimeCount=0;
}

void CQuestion::Attack(CObject * Other,int Mode)
{//问号只会被玛莉顶到，要向上移动几个像素
	if(0==m_Content)return;//空盒是顶不动的

	switch(m_Content)
	{
	case -1://蘑菇
		if(static_cast<CMario*>(Other)->IsBig())
		{//是大玛莉，则产生一朵花
			m_Game->AddObj(new CFlower(m_Game,XPos,YPos));
		}
		else
		{//是小玛莉，则产生蘑菇
			m_Game->AddObj(new CFungus(m_Game,XPos,YPos));
		}
		m_Content=0;
		break;
	default://金币
		CCoin * pcoin=new CCoin(m_Game,XPos,YPos-16);
		m_Game->AddObj(pcoin);
		pcoin->ThrowUp();
		m_Content--;
	}

	//向上移动几个像素
	MoveUp();
}

void CQuestion::Bump(CObject * Other,int Mode,bool Volun)
{
	if(!Volun)return;//不是主动碰别人，则不攻击
	if(3==Other->Type&&1==Other->LiveState)
	{//问号被顶动后又顶到妖怪，则攻击该妖怪
		Other->Attack(this,3);
	}
}

bool CQuestion::Block(CObject * Other)
{
	return false;//问号被顶动时不受任何物体阻挡
}

void CQuestion::Clock()
{
	if(YPos==m_OriPos)return;//转块没被顶动，则不用执行任何操作
	m_TimeCount++;
	if(3==m_TimeCount)
	{//到一定的时间后将问号回复到原始位置
		m_Game->Move(this,0,m_OriPos-YPos);
	}
}

