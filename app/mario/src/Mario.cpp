/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/
#include "cross.h"
#include "Mario.h"
#include "ImgData.h"
#include "Game.h"
#include "Bullet.h"

CMario::CMario(CGame * Game,int x, int y, int State):CObject(Game,1,x,y,16,16,-1)//玛莉位于背景层之后（可以被水管遮挡）
{
/*
	参数：
		[i]x,y		玛莉出现时的位置。
		[o]State	玛莉出现时的状态。取值意义与m_State一致。
*/
	m_State=State;
	if(1==State)
	{//小玛莉大小为16*16
		Width=16;
		Height=16;
	}
	else
	{//大玛莉大小为16*32
		Width=16;
		Height=32;
	}
	m_Action=0;//站立状态
	m_ToLeft=false;//面向右边
	m_MoveDir=0;//没有移动
	m_OnLand=false;//没有著地。如果著地，则在下一个时钟周期会自动改变该值。
	m_ChangeState=0;
	m_StarTime=0;
	m_HideTime=0;
}

const int * CMario::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToLeft;//面向左边则要水平翻转显示

	static int Image[32][16];
	int x,y;
	if(m_HideTime)
	{//隐形有效期间，要忽隐忽现
		static bool Hide=true;
		Hide=!Hide;
		if(Hide)
		{//本次隐藏，则设为全透明色
			if(1==m_State)
			{//小玛莉
				for(y=0;y<16;y++)
				{
					for(x=0;x<16;x++)
					{
						Image[y][x]=0xFF000000;
					}
				}
			}
			else
			{//大玛莉
				for(y=0;y<32;y++)
				{
					for(x=0;x<16;x++)
					{
						Image[y][x]=0xFF000000;
					}
				}
			}
			return reinterpret_cast<const int *>(Image);
		}
	}
	if(m_StarTime)
	{//五星有效期间，玛莉要闪烁
		static int NewColour1=0xFFA000;
		int NewColour2;
		int NewColour3;
		switch(NewColour1)
		{
		case 0xFFA000:
			NewColour1=0xFFC8B8;
			NewColour2=0x000000;
			NewColour3=0xC07000;
			break;
		case 0xFFC8B8:
			NewColour1=0xFFFFFF;
			NewColour2=0xE05000;
			NewColour3=0xFFA000;
			break;
		default:
			NewColour1=0xFFA000;
		}
		if(0xFFA000==NewColour1)
		{//不用换颜色
			goto lbl_NoChangeColour;
		}
		if(1==m_State)
		{//小玛莉
			memcpy(Image,SmallMarioImage[m_Action],sizeof(int)*16*16);
			for(y=0;y<16;y++)
			{
				for(x=0;x<16;x++)
				{
					switch(Image[y][x])
					{
					case 0xFFA000:
						Image[y][x]=NewColour1;
						break;
					case 0xE05000:
						Image[y][x]=NewColour2;
						break;
					case 0x888800:
						Image[y][x]=NewColour3;
						break;
					}
				}
			}
		}
		else
		{//大玛莉
			memcpy(Image,BigMarioImage[m_Action],sizeof Image);
			for(y=0;y<32;y++)
			{
				for(x=0;x<16;x++)
				{
					switch(Image[y][x])
					{
					case 0xFFA000:
						Image[y][x]=NewColour1;
						break;
					case 0xE05000:
						Image[y][x]=NewColour2;
						break;
					case 0x888800:
						Image[y][x]=NewColour3;
						break;
					}
				}
			}
		}
		return reinterpret_cast<const int *>(Image);
	}
lbl_NoChangeColour:
	switch(m_State)
	{
	case 1:
		return SmallMarioImage[m_Action];
	case 2:
		return BigMarioImage[m_Action];
	}
	//可发子弹的玛莉就是大玛莉，只是颜色不同
	memcpy(Image,BigMarioImage[m_Action],sizeof Image);
	for(y=0;y<32;y++)
	{
		for(x=0;x<16;x++)
		{
			switch(Image[y][x])
			{
			case 0xE05000:
				Image[y][x]=0xFFD8A0;
				break;
			case 0x888800:
				Image[y][x]=0xE05000;
				break;
			}
		}
	}
	return reinterpret_cast<const int *>(Image);
}

void CMario::Jump(void)
{
/*
	跳跃一次。
*/
	if(1!=LiveState)return;//正在死亡或已死亡则不再响应任何控制
	if(!m_OnLand)return;//双脚未著地，不能起跳。
	m_Game->PlaySound(CSoundMan::JUMP);
	//跳起后竖直速度向上
	if(m_HorzSpeed>5)
	{//水平速度超过5时，起跳速度可达20
		m_VertSpeed=-20;
	}
	else
	{//静立或未加到足够的速度，则起跳速度只有18
		m_VertSpeed=-18;
	}
	m_OnLand=false;//双脚不再著地
}

void CMario::Move(int Dir, bool Acc)
{
/*
	开始或停止移动。
	参数：
		[i]Dir	移动方向。取值为：
				1	向上
				2	向下
				3	向左
				4	向右
				0	停止
		[i]Acc	是否加速移动。
*/
	if(1!=LiveState)return;//正在死亡或已死亡则不再响应任何控制
	m_MoveDir=Dir;
	m_Acc=Acc;
	if(3==Dir)
	{//向左移动，要把面对方向改为向左
		m_ToLeft=true;
	}
	else if(4==Dir)
	{//向右移动，要把面对方向改为向右
		m_ToLeft=false;
		m_MoveDir=3;
	}
}

void CMario::Fire()
{
/*
	使主角发射一次子弹。
*/
	if(1!=LiveState)return;//正在死亡或已死亡则不再响应任何控制

	if(3!=m_State)return;//还没有发子弹的能力

	m_Game->PlaySound(CSoundMan::BULLET);

	if(m_ToLeft)
	{
		m_Game->AddObj(new CBullet(m_Game,XPos,YPos+8,true));
	}
	else
	{
		m_Game->AddObj(new CBullet(m_Game,XPos+Width-8,YPos+8,false));
	}
}

void CMario::Clock()
{
	//五星和隐身的有效时间逐次减少
	if(m_StarTime)
	{
		m_StarTime--;
		if(0==m_StarTime)m_Game->PlayBackMusic(1);//五星失效后要恢复正常背景音乐
	}
	if(m_HideTime)m_HideTime--;

	if(1==m_ChangeState)
	{
		if(1==m_State)
		{//由小变大
			m_State=2;
			YPos-=16;
			Height=32;
		}
		else
		{//变为可发子弹
			m_State=3;
		}
		m_ChangeState=0;
	}
	else if(-1==m_ChangeState)
	{//由大变小
		m_State=1;
		YPos+=16;
		Height=16;
		m_ChangeState=0;
	}

	switch(m_MoveDir)
	{
	case 3:
		if(m_ToLeft)
		{
			m_HorzSpeed--;
		}
		else
		{
			m_HorzSpeed++;
		}
		break;
	}
	if(m_Acc)
	{//加速时最高速度可到10
		if(m_HorzSpeed>10)
			m_HorzSpeed=10;
		else if(m_HorzSpeed<-10)
			m_HorzSpeed=-10;
	}
	else
	{//未加速时最高速度可到5
		if(m_HorzSpeed>5)
			m_HorzSpeed=5;
		else if(m_HorzSpeed<-5)
			m_HorzSpeed=-5;
	}
	if(1==LiveState)
	{
		if(m_OnLand)
		{
			if(m_HorzSpeed)
			{//双脚著地且有水平速度时，改变一次行走姿式
				m_Action++;
				if(m_Action>3)m_Action=1;
			}
			else
			{//无水平速度时为站立姿式
				m_Action=0;
			}
		}
		else
		{
			m_Action=4;//双脚离地时为跳跃姿式
		}
	}

	//无论何时都有重力加速度
	m_VertSpeed+=2;//重力加速度固定为2
	if(m_VertSpeed>20)m_VertSpeed=20;//重力速度最高为20
	m_OnLand=false;//双脚随时可能踏空而离地（若未踏空，则在向下移动时又会还原为“已著地”）

	if(m_HorzSpeed||m_VertSpeed)
	{//有速度则要移动
		int OVSpeed=m_VertSpeed;//记下原有的竖直速度
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//水平方向受到阻挡，则水平速度减为0
			m_HorzSpeed=0;
		}
		if(MoveResult&2)
		{//竖直方向受到阻挡，则竖直速度减为0
			if(m_VertSpeed==OVSpeed)m_VertSpeed=0;//但在碰撞过程中已改变了竖直速度，则不减为0
		}
	}
}

void CMario::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;//正在死亡或已经死亡的玛莉不响应该事件

	if(5==Other->Type)
	{//接触到蘑菇、五星、金币等，则将其吃掉
		Other->Attack(this,3);
		return;
	}

	if(m_StarTime)
	{
		if(3==Other->Type&&1==Other->LiveState)
		{//在五星有效期间，碰到活妖怪，则向其发动攻击
			Other->Attack(this,1);
		}
	}

	if(1==Mode)
	{//碰到任何物体的顶部，则认为双脚已著地
		m_OnLand=true;
		//受摩擦力，水平速度降低
		if(m_HorzSpeed>0)
		{
			if(3!=m_MoveDir||m_ToLeft)
			{//正在向右加速则不减速
				m_HorzSpeed--;
			}
		}
		else if(m_HorzSpeed<0)
		{
			if(3!=m_MoveDir||!m_ToLeft)
			{//正在向左加速则不减速
				m_HorzSpeed++;
			}
		}
		if(0==m_StarTime&&3==Other->Type&&1==Other->LiveState)
		{//碰到活妖怪的顶部，则向其发动攻击，但在五星有效期间不攻击（已以在上面攻击过了）
			Other->Attack(this,2);
			m_VertSpeed=-10;//踩到妖怪后弹起
		}
	}
	else if(2==Mode)
	{//碰到物体底部
		if(2==Other->Type&&1==Other->LiveState)
		{//顶到砖块等，则向其攻击
			m_Game->PlaySound(CSoundMan::BLOCK);
			Other->Attack(this,3);
		}
	}
}

bool CMario::Block(CObject * Other)
{
	if(Other)
	{
		if(2==Other->LiveState)return false;//正在死亡的物体不能阻挡玛莉
		if(5==Other->Type)return false;//金币、蘑菇等不能阻挡玛莉
		if((m_StarTime||m_HideTime)&&3==Other->Type)return false;//任何妖怪也不能阻挡吃了五星或隐身的玛莉
	}

	if(1==LiveState)
		return true;//活的玛莉可以被任何物体阻挡，也不能超越地图边界
	else
		return false;//正在死亡的玛莉不受任何物体阻挡
}

void CMario::ResetPos(int x,int y)
{
/*
	将玛莉的位置重置到指定的位置。
	参数：
		[i]x,y		要重置到的位置。
*/
	XPos=x;
	YPos=y;
	//置位后速度全部减为0
	m_HorzSpeed=0;
	m_VertSpeed=0;
}

bool CMario::IsBig()
{
/*
	是否为大玛莉。
*/
	return 1!=m_State;
}

void CMario::AddPower()
{
/*
	该变玛莉的状态。由小玛莉变为大玛莉，若已经是大玛莉，则变为可发子弹的玛莉
*/
	m_ChangeState=1;//在下一个时钟周期生效
}

void CMario::AddStar()
{
/*
	玛莉吃到了五星。
*/
	m_Game->PlayBackMusic(2);//五星有效期间要改变背景音乐
	m_StarTime=200;
}

void CMario::Attack(CObject * Other,int Mode)
{
	if(m_StarTime||m_HideTime)return;//在五星或隐身有效期间不受攻击
	if(1!=LiveState)return;//只有活的玛莉才能受攻击
	if(1!=m_State)
	{//大玛莉受到攻击则变成小玛莉
		m_Game->PlaySound(CSoundMan::ATTACKMARIO);
		m_ChangeState=-1;//在下一个时钟周期生效
		m_HideTime=40;
	}
	else
	{//小玛莉受到攻击则列亡
		m_Game->PlayBackMusic(0);
		m_Game->PlaySound(CSoundMan::DEATH);
		LiveState=2;
		Layer=1;//正在死亡的玛莉提到背景前面
		m_Action=5;
		m_MoveDir=0;
		m_HorzSpeed=0;
		m_VertSpeed=-20;
	}
}

