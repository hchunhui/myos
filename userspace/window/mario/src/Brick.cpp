/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Brick.h"
#include "ImgData.h"
#include "Game.h"
#include "Fungus.h"
#include "Flower.h"
#include "Question.h"
#include "Star.h"
#include "Coin.h"
#include "BrokenBrick.h"


CBrick::CBrick(CGame * Game,int x, int y,int Content):CObject(Game,2,x,y,16,16,0)
{
/*
	参数：
		[i]Content		砖块内藏何物。
						0		没有东西。
						1		蘑菇。
						2		十枚金币。
						3		五星。
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
		m_Content=-2;
		break;
	default:
		m_Content=0;
	}
}

const int * CBrick::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return BrickImage;
}

void CBrick::Attack(CObject * Other,int Mode)
{//砖块只会被玛莉顶到
	int OriContent=m_Content;//记下原来是否有东西
	switch(m_Content)
	{
	case 0://没有东西
		break;
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
	case -2://五星
		m_Game->AddObj(new CStar(m_Game,XPos,YPos));
		m_Content=0;
		break;
	default://金币
		CCoin * pcoin=new CCoin(m_Game,XPos,YPos-16);
		m_Game->AddObj(pcoin);
		pcoin->ThrowUp();
		m_Content--;
	}

	if(0!=OriContent&&0==m_Content)
	{//原来有东西的，现在变成没东西，则要变成空盒
		LiveState=3;//删除自己
		//在相同位置添加盒子
		CQuestion * pbox=new CQuestion(m_Game,XPos,YPos,0);
		m_Game->AddObj(pbox);
		//将盒子向上移动几个像素
		pbox->MoveUp();
	}
	else
	{
		//向上移动几个像素
		m_Game->Move(this,0,-4);
		m_TimeCount=0;
		if(0==OriContent)
		{
			if(static_cast<CMario*>(Other)->IsBig())
			{//被顶前没有东西，而且是被大玛莉顶到，则砖块碎裂
				m_Game->PlaySound(CSoundMan::BRICKBROKEN);
				LiveState=3;//自己消失
				//在该位置添加四块碎砖，向不同的方向弹开
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos,YPos,-3,-16));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos+8,YPos,3,-16));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos,YPos+8,-3,-10));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos+8,YPos+8,3,-10));
			}
		}
	}
}

void CBrick::Bump(CObject * Other,int Mode,bool Volun)
{
	if(!Volun)return;//不是主动碰别人，则不攻击
	if(3==Other->Type&&1==Other->LiveState)
	{//砖块被顶动后又顶到妖怪，则攻击该妖怪
		Other->Attack(this,3);
	}
}

bool CBrick::Block(CObject * Other)
{
	return false;//砖块被顶动时不受任何物体阻挡
}

void CBrick::Clock()
{
	if(YPos==m_OriPos)return;//转块没被顶动，则不用执行任何操作
	m_TimeCount++;
	if(3==m_TimeCount)
	{//到一定的时间后将砖块回复到原始位置
		m_Game->Move(this,0,m_OriPos-YPos);
	}
}

