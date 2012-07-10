/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Object.h"

CObject::CObject(CGame * Game,int Tp,int X,int Y,int W,int H,int Ly)
{
	m_Game=Game;
	Type=Tp;
	XPos=X;
	YPos=Y;
	Width=W;
	Height=H;
	Layer=Ly;
	//初始为静止状态
	m_HorzSpeed=0;
	m_VertSpeed=0;
	//初始为活动状能
	LiveState=1;
}

void CObject::Clock()
{
}

bool CObject::Block(CObject * Other)
{
/*
	在移动过程中遇到阻挡。
	参数：
		[i]Other		阻挡自己的对象。如果为NULL，则表示受到地图边界阻挡。
	返回值：
		true			接受阻挡，停止移动。
		false			不理会阻挡，继续移动。
*/
	if(1!=LiveState)return false;//正在死亡的物体不受阻挡

	if(Other)
	{
		if(5==Other->Type)return false;//金币、蘑菇等不能阻挡别人
		return true;//能被其他物体阻挡
	}
	else
		return false;//不受地图边界阻挡
}

void CObject::Bump(CObject * Other,int Mode,bool Volun)
{
/*
	与其他对象发生碰撞。
	参数：
		[i]Other	与之碰撞的另一个对象。
		[i]Mode		碰撞方式。取值为：
					1		碰到对方顶部。
					2		碰到对方底部。
					3		碰到对方侧面。
		[i]Volun	取值为：true:自己主动碰对方；false:自己被对方碰到。
*/
}

void CObject::Attack(CObject * Other,int Mode)
{
/*
	遭到其他对象的攻击。
	参数：
		[i]Other	发起攻击的对象。
		[i]Mode		攻击方式。取值为：
					1		接触式攻击。如妖怪与主角接触即可杀死主角；主角使用了无敌隐身后与妖怪接触可杀死妖怪；子弹与妖怪接触可杀死妖怪等。
					2		踩踏式攻击。仅限于主角踩踏妖怪。
					3		头顶式攻击。如主角顶到砖块、砖块顶到妖怪等。
*/
}
