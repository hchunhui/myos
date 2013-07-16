/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "GraphMan.h"

void CGraphMan::SetGraph(CGraph * Graph)
{
/*
	设置图像显示对象。
	参数：
		[i]Graph		CGraphMan类将通过该对象显示图像。
*/
	m_pGraph=Graph;
}

void CGraphMan::SetGame(CGame *Game)
{
/*
	设置游戏对象。
	参数：
		[i]Game		将从该对象中读取游戏数据。
*/
	m_pGame=Game;
}

void CGraphMan::Update()
{
/*
	刷新一次显示。
*/
	int ** pbit=m_pGraph->GetImageBuf();
	CObject **pObj=m_pGame->GetAllObject();

	//背景设为蓝色
	int x,y;
	for(y=0;y<256;y++)
	{
		for(x=0;x<288;x++)
		{
			pbit[y][x]=0x005080ff;
		}
	}

	if(pObj)
	{
		//依次绘制背景层之后、背景层、背景层之前的对象
		CObject **it;
		int layer;
		for(layer=-1;layer<=1;layer++)
		{
			for(it=pObj;*it;it++)
			{
				if((*it)->Layer!=layer)continue;
				bool HInv,VInv;
				const int * Img=(*it)->GetImage(&HInv,&VInv);
				int destx,desty;
				int xstart,ystart;
				int xstep,ystep;
				if(HInv)
				{//要左右反转显示图像
					xstart=(*it)->XPos+(*it)->Width-1;
					xstep=-1;
				}
				else
				{
					xstart=(*it)->XPos;
					xstep=1;
				}
				if(VInv)
				{//要上下反转显示图像
					ystart=(*it)->YPos+(*it)->Height-1;
					ystep=-1;
				}
				else
				{
					ystart=(*it)->YPos;
					ystep=1;
				}
				for(y=0,desty=ystart;y<(*it)->Height;y++,desty+=ystep)
				{
					for(x=0,destx=xstart;x<(*it)->Width;x++,destx+=xstep,Img++)
					{
						if(!(*Img&0x80000000)&&desty>=0&&desty<256&&destx>=0&&destx<288)
						{
							pbit[desty][destx]=*Img;
						}
					}
				}
			}
		}
	}
	else
	{//游戏未开始，则显示文字
		/*m_pGraph->ShowText(30,30,"操作说明：",0xffff00);
		m_pGraph->ShowText(50,60,"Enter: 开始",0xffff00);
		m_pGraph->ShowText(50,80,"'J': 跳跃",0xffff00);
		m_pGraph->ShowText(50,100,"'K': 发射子弹、加速",0xffff00);
		m_pGraph->ShowText(50,120,"WASD: 行走",0xffff00);
		m_pGraph->ShowText(30,160,"程序设计: 罗穆峰 2008-11-20",0xffff00);
		m_pGraph->ShowText(30,180,"http://lmf.biaotian.com",0xffff00);
		m_pGraph->ShowText(30,200,"E-mail: lmf@biaotian.com",0xffff00);
		m_pGraph->ShowText(30,220,"QQ: 16324942 [模范英雄]",0xffff00);*/
		
		m_pGraph->ShowText(30,20,"Guide:",0x0000);
		m_pGraph->ShowText(50,50,"Enter: Start",0x000000);
		m_pGraph->ShowText(50,70,"'J': Jump",0x000000);
		m_pGraph->ShowText(50,90,"'K': Fire",0x000000);
		m_pGraph->ShowText(50,110,"WASD: Go",0x000000);
		m_pGraph->ShowText(20,150,"Program: LuoMuFeng 2008-11-20",0x000000);
		m_pGraph->ShowText(20,170,"Modify: HeChunHui 2011-06-26",0x000000);
		m_pGraph->ShowText(20,190,"http://lmf.biaotian.com",0x000000);
		m_pGraph->ShowText(20,210,"QQ[L]: 16324942", 0x000000);
		m_pGraph->ShowText(20,230,"E-mail[L]: lmf@biaotian.com",0x000000);
	}

	//显示到屏幕上
	m_pGraph->Refresh();
}
