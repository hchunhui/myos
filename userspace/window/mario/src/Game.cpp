/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "Game.h"
#include "SoundMan.h"
#include "MapData.h"
#include "Brick.h"
#include "Ground.h"
#include "Stone.h"
#include "PipeBody.h"
#include "PipeTop.h"
#include "Question.h"
#include "FungusDemon.h"
#include "TortoiseDemon.h"
#include "FlyTortoiseDemon.h"
#include "ClipDemon.h"
#include "BeetleDemon.h"
#include "Coin.h"
//#include <queue>
#include "cross.h"


int g_FlushAction=0;//问号和金币当前的闪烁状态。所有问号的金币的闪烁状态是一致的。取值为0~2。
static int s_FlushTimeCount=0;//并非每个时钟周期闪烁一次，而是要等到该变量记录到一定值后再改变一次闪烁状态。
static int s_FlushDir;//当前的闪烁方向。1:由亮变暗 2:由暗变亮

CGame::CGame()
{
	m_Mario = (CMario *)NULL;
	m_ObjectCount = 0;
	m_Object[0] = (CObject *)NULL;
	printf("CGame init\n");
}

CObject ** CGame::GetAllObject()
{
/*
	返回所有角色和物体的列表。返回NULL表示游戏尚未开始。
*/
	if(!m_Mario)return (CObject **)NULL;//游戏尚未开始
	return m_Object;
}

void CGame::m_Object_insert(CObject *pObj)
{
	m_Object[m_ObjectCount++] = pObj;
}

void CGame::m_Object_erase(CObject **pObj)
{
	CObject **it;
	for(it = pObj; *it; it++)
		*it = *(it + 1);
	m_ObjectCount--;
}

void CGame::m_Object_clear()
{
	CObject **it;
	for(it = m_Object; *it; it++)
		*it = (CObject *)NULL;
	m_ObjectCount = 0;
}

void CGame::Start()
{
/*
	开始游戏。
*/
	if(m_Mario)return;//游戏已经开始，则不再响应该事件

	//清除所有角色和物体
	CObject **it;
	for(it=m_Object;*it;++it)
	{
		//(*it)->Destroy();
		delete *it;
	}
	m_Object_clear();

	//创建主角玛莉
	m_Mario=new CMario(this,0,0,1);
	m_Object_insert(m_Mario);

	//从第0关开始
	m_CurLevel=0;
	m_MapData=MapData+1;
	LoadMapData();
}

void CGame::InsertObject(int X,int Y,int Type)
{
/*
	插入一个新角色或物体。
	参数：
		[i]X,Y		要插入到哪个位置。
		[i]Type		要插入的物体类型。取值为：
			1		砖块。
			2		石头。
			3		水管体。
			4		水管顶。
			5		问号(内藏一枚金币)。
			6		问号(内藏蘑菇)。
			7		问号(内藏十枚金币)。
			8		砖块(内藏蘑菇)。
			9		砖块(内藏五星)。
			10		砖块(内藏十枚金币)。
			11		蘑菇妖怪。
			12		乌龟妖怪。
			13		飞乌龟妖怪。
			14		夹子妖怪。
			15		地板。
			16		金币。
			17		甲虫妖怪。
*/
	switch(Type)
	{
	case 1:
		m_Object_insert(new CBrick(this,X,Y,0));
		break;
	case 2:
		m_Object_insert(new CStone(this,X,Y));
		break;
	case 3:
		m_Object_insert(new CPipeBody(this,X,Y));
		break;
	case 4:
		m_Object_insert(new CPipeTop(this,X,Y));
		break;
	case 5:
		m_Object_insert(new CQuestion(this,X,Y,3));
		break;
	case 6:
		m_Object_insert(new CQuestion(this,X,Y,1));
		break;
	case 7:
		m_Object_insert(new CQuestion(this,X,Y,2));
		break;
	case 8:
		m_Object_insert(new CBrick(this,X,Y,1));
		break;
	case 9:
		m_Object_insert(new CBrick(this,X,Y,3));
		break;
	case 10:
		m_Object_insert(new CBrick(this,X,Y,2));
		break;
	case 11:
		m_Object_insert(new CFungusDemon(this,X,Y));
		break;
	case 12:
		m_Object_insert(new CTortoiseDemon(this,X,Y));
		break;
	case 13:
		m_Object_insert(new CFlyTortoiseDemon(this,X,Y));
		break;
	case 14:
		m_Object_insert(new CClipDemon(this,X,Y));
		break;
	case 15:
		m_Object_insert(new CGround(this,X,Y));
		break;
	case 16:
		m_Object_insert(new CCoin(this,X,Y));
		break;
	case 17:
		m_Object_insert(new CBeetleDemon(this,X,Y));
		break;
	}
}

void CGame::Clock(void)
{
/*
	执行一次时序信号动作。
*/
	//改变问号和金币当前的闪烁状态
	s_FlushTimeCount++;
	switch(g_FlushAction)
	{
	case 0:
		if(s_FlushTimeCount>=10)
		{//最亮的状态显示10个时钟周期
			g_FlushAction=1;
			s_FlushDir=1;
			s_FlushTimeCount=0;
		}
		break;
	case 1:
		if(s_FlushTimeCount>=2)
		{//稍暗的状态显示2个时钟周期
			g_FlushAction+=s_FlushDir;
			s_FlushTimeCount=0;
		}
		break;
	default://case 2:
		if(s_FlushTimeCount>=3)
		{//最暗的状态显示3个时钟周期
			g_FlushAction=1;
			s_FlushDir=-1;
			s_FlushTimeCount=0;
		}
	}

	CObject **it,**it2;
	//使所有的角色和物体动作一次
	for(it=m_Object;*it;)
	{
		if(3==(*it)->LiveState||(*it)->XPos>288+32||(*it)->XPos+(*it)->Width<-32||(*it)->YPos>256)
		{//对象已死亡，则删除
			//左边线超出右边界32像素以上，左边线超出左边界32像素以上，上边线超出下边界，则认为对象超出地图范围之外，要删除该对象
			if(*it==m_Mario)
			{//删除的是玛莉
				if(1==m_Mario->LiveState)
				{//删除的是活玛莉，则要停止背景音乐，播放玛莉死亡时的音乐
					m_SoundMan->PlayBackMusic(0);
					m_SoundMan->PlaySound(CSoundMan::DEATH);
				}
				m_Mario=(CMario *)NULL;
			}
			it2=it;
			++it;
			delete *it2;
			m_Object_erase(it2);
		}
		else
		{
			(*it)->Clock();
			++it;
		}
	}
	if(!m_Mario)return;//玛莉已被删除
	int Offset=m_Mario->XPos-((288-m_Mario->Width)>>1);
	if(Offset>0)
	{//玛莉超过了地图中线，则要将地图移动，使玛莉到达地图中央
		MoveMap(Offset);
	}
	if(m_Mario->XPos==288-m_Mario->Width)
	{//玛莉到达了地图右边线，则进入下一关
		//清除除玛莉外的所有角色和物体
		for(it=m_Object;*it;)
		{
			it2=it;
			it++;
			if(*it2==m_Mario)continue;//玛莉不能删除
			delete *it2;
			m_Object_erase(it2);
		}

		m_CurLevel++;
		if(MapData[0]==m_CurLevel)
		{//已经玩过了最后一关，则游戏结束
			m_SoundMan->PlayBackMusic(0);
			//删除玛莉
			m_Object_clear();
			delete m_Mario;
			m_Mario=(CMario *)NULL;
		}
		else
		{
			m_MapData+=3+m_MapData[2]*16;
			LoadMapData();
		}
	}
}

void CGame::Move(int Dir, bool Acc)
{
/*
	使主角开始或停止移动。
	参数：
		[i]Dir	移动方向。取值为：
				1	向上
				2	向下
				3	向左
				4	向右
				0	停止
		[i]Acc	是否加速移动。
*/
	if(!m_Mario)return;//游戏尚未开始
	m_Mario->Move(Dir,Acc);
}

void CGame::Jump(void)
{
/*
	使主角跳跃一次。
*/
	if(!m_Mario)return;//游戏尚未开始
	m_Mario->Jump();
}

void CGame::Fire(void)
{
/*
	使主角发射一次子弹。
*/
	if(!m_Mario)return;//游戏尚未开始
	m_Mario->Fire();
}

struct BLOCKINFO
{//移动路径内的阻挡物信息
	CObject * Blocker;//阻挡本对象运动的物体
	int x,y;//受该物体阻挡后能运动到的位置
	int BlockMode;//阻挡方式，取值与本函数的返回值一致。当MayBe为true时，忽略该成员
	int BumpMode;//与该物体的碰撞方式，取值取CObject::Bump函数的中Mode参数一致。当MayBe为true时，忽略该成员
	bool MayBe;//如果阻挡物刚好在运动区域的边界上，则可能阻挡，也可能不阻挡
};

struct BLOCKINFOCompare
{//BLOCKINFO的比较器，若b距离被阻挡物较近，则返回true。
	//以X坐标较近为准，若X值相同则以Y较近为准，若Y值也相同，则以一定阻挡的物体为准
	//不可能出现X较近而Y值较远的情况
	bool operator() (const BLOCKINFO & a,const BLOCKINFO & b)
	{
		if(XLarge)
		{
			if(b.x>a.x)return true;
			if(b.x<a.x)return false;
		}
		else
		{
			if(b.x<a.x)return true;
			if(b.x>a.x)return false;
		}
		if(YLarge)
		{
			if(b.y>a.y)return true;
			if(b.y<a.y)return false;
		}
		else
		{
			if(b.y<a.y)return true;
			if(b.y>a.y)return false;
		}
		if(!b.MayBe&&a.MayBe)return true;
		return false;
	}
	bool XLarge;//若为true，则X值越大则越近，否则X值小越近
	bool YLarge;//若为true，则Y值越大则越近，否则Y值小越近
};

#define BI_MAX 50

class bipriority_queue
{
private:
	int bi_count;
	BLOCKINFOCompare *cmp;
	struct BLOCKINFO bi[BI_MAX];
	struct BLOCKINFO nbi;
public:
	void init(BLOCKINFOCompare *mycmp)
	{
		cmp = mycmp;
		bi_count = 0;
		
		memset(bi, 0, sizeof(bi));
	}
	
	struct BLOCKINFO top()
	{
		int i;
		int max_idx = 0;
		//printf("top\n");
		if(bi_count == 0)
			exit(1);
		
		for(i = 0; i < bi_count; i++)
		{
			if((*cmp)(bi[max_idx], bi[i]))
				max_idx = i;
		}
		return bi[max_idx];
	}
	
	void pop()
	{
		int i;
		int max_idx = 0;
		//printf("pop\n");
		if(bi_count == 0)
			return;
		
		for(i = 0; i < bi_count; i++)
		{
			if((*cmp)(bi[max_idx], bi[i]))
				max_idx = i;
		}
		
		for(i = max_idx; i < bi_count; i++)
		{
			bi[i] = bi[i + 1];
		}
		
		bi_count--;
		
	}
	
	void push(struct BLOCKINFO & d)
	{
		int i;
		if(bi_count == BI_MAX - 1)
			exit(2);
		for(i = 0; i < bi_count; i++)
		{
			if(d.Blocker == bi[i].Blocker)
				return;
		}
		bi[bi_count++] = d;
	}
	
	bool empty()
	{
		return bi_count == 0 ? true :false;
	}
	
	void clear()
	{
		init(cmp);
	}
}BlockList;

int CGame::Move(CObject * Obj,int Horz,int Vert)
{
/*
	移动某个角色或物体。
	参数：
		[i]Obje		要移动的对象。
		[i]Horz		要移动的水平距离（像素），向右为正，向左为负。
		[i]Vert		要移动的竖直距离（像素），向下为正，向上为负。
	返回值：
		返回一个位段值。以下各值可用位或合并。
		0	成功。
		1	水平方向遇到阻挡。
		2	竖直方向遇到阻挡。
*/
	int retval=0;

	//如果没有阻挡，应该移动到的位置
	int OrDestX=Obj->XPos+Horz;
	int OrDestY=Obj->YPos+Vert;

	BLOCKINFOCompare Compare;
	BLOCKINFO bi;
	BLOCKINFO bitop;
	if(Vert>0)
	{//向下移动，则Y值越小越近
		Compare.YLarge=false;
	}
	else
	{//向上移动，则Y值越大越近
		Compare.YLarge=true;
	}
	if(Horz>0)
	{//向右移动，则X值越小越近
		Compare.XLarge=false;
	}
	else
	{//向左移动，则X值越大越近
		Compare.XLarge=true;
	}
	//std::priority_queue<BLOCKINFO,std::vector<BLOCKINFO>,BLOCKINFOCompare> BlockList(Compare);//在运动路径内的所有阻挡物
	BlockList.init(&Compare);

	int start,end;
	if(Vert<0)
	{//向上移动，只可能是本对象的顶线与阻挡物的底线相碰
		start=Obj->YPos;
		end=start+Vert;
		//判断有无物体在移动路径之内
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//是自己
			int ypos=(*it)->YPos+(*it)->Height;
			if(ypos>end&&ypos<=start)
			{//底线在运动范围之内
				//看阻挡物的横坐标是否在运动范围内
				int x1=Obj->XPos+Horz*(ypos-start)/Vert;
				int x2=x1+Obj->Width;
				if(!((*it)->XPos>=x2||(*it)->XPos+(*it)->Width<=x1))
				{//横坐标也在运动范围内，则受到阻挡
					bi.Blocker=(*it);
					bi.BlockMode=2;
					bi.BumpMode=2;
					bi.MayBe=false;
					bi.x=x1;
					bi.y=ypos;
					BlockList.push(bi);
				}
				else if( (Horz>0&&(*it)->XPos==x2) || (Horz<0&&(*it)->XPos+(*it)->Width==x1) )
				{//在水平方向上有速度，而阻挡物正好在运动区域的左或右边界上，则可能阻挡，也可能不阻挡
					bi.Blocker=(*it);
					bi.MayBe=true;
					bi.x=x1;
					bi.y=ypos;
					BlockList.push(bi);
				}
			}
		}
	}
	else if(Vert>0)
	{//向下移动，只可能是本对象的底线与阻挡物的顶线相碰
		start=Obj->YPos+Obj->Height;
		end=start+Vert;
		//判断有无物体在移动路径之内
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//是自己
			int ypos=(*it)->YPos;
			if(ypos>=start&&ypos<end)
			{//顶线在运动范围之内
				//看阻挡物的横坐标是否在运动范围内
				int x1=Obj->XPos+Horz*(ypos-start)/Vert;
				int x2=x1+Obj->Width;
				if(!((*it)->XPos>=x2||(*it)->XPos+(*it)->Width<=x1))
				{//横坐标也在运动范围内，则受到阻挡
					bi.Blocker=(*it);
					bi.BlockMode=2;
					bi.BumpMode=1;
					bi.MayBe=false;
					bi.x=x1;
					bi.y=ypos-Obj->Height;
					BlockList.push(bi);
				}
				else if( (Horz>0&&(*it)->XPos==x2) || (Horz<0&&(*it)->XPos+(*it)->Width==x1) )
				{//在水平方向上有速度，而阻挡物正好在运动区域的左或右边界上，则可能阻挡，也可能不阻挡
					bi.Blocker=(*it);
					bi.MayBe=true;
					bi.x=x1;
					bi.y=ypos-Obj->Height;
					BlockList.push(bi);
				}
			}
		}
	}

	if(Horz<0)
	{//向左移动，只可能是本对象的左边线与阻挡物的右边线相碰
		start=Obj->XPos;
		end=start+Horz;
		//判断有无物体在移动路径之内
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//是自己
			int xpos=(*it)->XPos+(*it)->Width;
			if(xpos>end&&xpos<=start)
			{//右边线在运动范围之内
				//看阻挡物的纵坐标是否在运动范围内
				int y1=Obj->YPos+Vert*(xpos-start)/Horz;
				int y2=y1+Obj->Height;
				if(!((*it)->YPos>=y2||(*it)->YPos+(*it)->Height<=y1))
				{//纵坐标也在运动范围内，则受到阻挡
					bi.Blocker=(*it);
					bi.BlockMode=1;
					bi.BumpMode=3;
					bi.MayBe=false;
					bi.x=xpos;
					bi.y=y1;
					BlockList.push(bi);
				}
				else if( (Vert>0&&(*it)->YPos==y2) || (Vert<0&&(*it)->YPos+(*it)->Height==y1) )
				{//在竖直方向上有速度，而阻挡物正好在运动区域的左或右边界上，则可能阻挡，也可能不阻挡
					bi.Blocker=(*it);
					bi.MayBe=false;
					bi.x=xpos;
					bi.y=y1;
					BlockList.push(bi);
				}
			}
		}
		if(end<0)
		{//左边线超出左边界
			bi.Blocker=(CObject *)NULL;
			bi.BlockMode=1;
			bi.MayBe=false;
			bi.x=0;
			bi.y=Obj->YPos+Vert*(0-start)/Horz;
			BlockList.push(bi);
		}
	}
	else if(Horz>0)
	{//向右移动，只可能是本对象的右边线与阻挡物的左边线相碰
		start=Obj->XPos+Obj->Width;
		end=start+Horz;
		//判断有无物体在移动路径之内
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//是自己
			int xpos=(*it)->XPos;
			if(xpos>=start&&xpos<end)
			{//左边线在运动范围之内
				//看阻挡物的纵坐标是否在运动范围内
				int y1=Obj->YPos+Vert*(xpos-start)/Horz;
				int y2=y1+Obj->Height;
				if(!((*it)->YPos>=y2||(*it)->YPos+(*it)->Height<=y1))
				{//纵坐标也在运动范围内，则受到阻挡
					bi.Blocker=(*it);
					bi.BlockMode=1;
					bi.BumpMode=3;
					bi.MayBe=false;
					bi.x=xpos-Obj->Width;
					bi.y=y1;
					BlockList.push(bi);
				}
				else if( (Vert>0&&(*it)->YPos==y2) || (Vert<0&&(*it)->YPos+(*it)->Height==y1) )
				{//在水平方向上有速度，而阻挡物正好在运动区域的左或右边界上，则可能阻挡，也可能不阻挡
					bi.Blocker=(*it);
					bi.MayBe=true;
					bi.x=xpos-Obj->Width;
					bi.y=y1;
					BlockList.push(bi);
				}
			}
		}
		if(end+Obj->Width>288)
		{//右边线超出左边界
			bi.Blocker=(CObject *)NULL;
			bi.BlockMode=1;
			bi.MayBe=false;
			bi.x=288-Obj->Width;
			bi.y=Obj->YPos+Vert*(288-start)/Horz;
			BlockList.push(bi);
		}
	}

	//若没有阻挡，则运动到指定的位置
	Obj->XPos=OrDestX;
	Obj->YPos=OrDestY;

	for(;!BlockList.empty();BlockList.pop())
	{
		bitop = BlockList.top();
		int BumpMode;
		if(bitop.MayBe)
		{//是一个刚好在边界上的阻挡物
			if(Obj==m_Mario)
			{//玛莉遇到这种情况，视为竖直方向遇到阻挡，仍可水平行走
				retval=2;
				BumpMode=Vert>0?1:2;
			}
			else
			{//妖怪遇到这种情况，视为水平方向遇到阻挡，使其掉下去
				retval=1;
				BumpMode=3;
			}
			Obj->Bump(bitop.Blocker,BumpMode,true);
			//自己碰对方和对方碰自己的方式正好上下相反
			if(1==BumpMode)
				BumpMode=2;
			else if(2==BumpMode)
				BumpMode=1;
			bitop.Blocker->Bump(Obj,BumpMode,false);
			if(!Obj->Block(bitop.Blocker))continue;//不受阻挡，则继续看更远的阻挡物
			Obj->XPos=bitop.x;
			Obj->YPos=bitop.y;
			break;
		}
		else
		{
			if(bitop.Blocker)
			{
				Obj->Bump(bitop.Blocker,bitop.BumpMode,true);
				//自己碰对方和对方碰自己的方式正好上下相反
				if(1==bitop.BumpMode)
					BumpMode=2;
				else if(2==bitop.BumpMode)
					BumpMode=1;
				else
					BumpMode=3;
				bitop.Blocker->Bump(Obj,BumpMode,false);
			}
			if(!Obj->Block(bitop.Blocker))continue;//不受阻挡，则继续看更远的阻挡物
			Obj->XPos=bitop.x;
			Obj->YPos=bitop.y;
			retval=bitop.BlockMode;
			BlockList.pop();
			//同一距离可能有多个阻挡物，与它们都相碰
			while(!BlockList.empty())
			{
				bitop = BlockList.top();
				if(bitop.MayBe)break;
				if(bitop.x!=Obj->XPos||bitop.y!=Obj->YPos)break;
				if(bitop.Blocker)
				{
					Obj->Bump(bitop.Blocker,bitop.BumpMode,true);
					//自己碰对方和对方碰自己的方式正好上下相反
					if(1==bitop.BumpMode)
						BumpMode=2;
					else if(2==bitop.BumpMode)
						BumpMode=1;
					else
						BumpMode=3;
					bitop.Blocker->Bump(Obj,BumpMode,false);
				}
				BlockList.pop();
			}
			break;
		}
	}

	if(1==retval)
	{
		if(Obj->YPos!=OrDestY)
		{//水平方向有阻挡，且未达到指定的纵坐标，则要在竖直方向上走完该距离
			retval|=Move(Obj,0,OrDestY-Obj->YPos);
		}
	}
	else if(2==retval||4==retval)
	{
		if(Obj->XPos!=OrDestX)
		{//竖直方向有阻挡，且未达到指定的横坐标，则要在水平方向上走完该距离
			retval|=Move(Obj,OrDestX-Obj->XPos,0);
		}
	}

	return retval;
}

void CGame::LoadMapData()
{
	m_SoundMan->PlayBackMusic(1);

	//将玛莉重置到这一关的起始位置
	m_Mario->ResetPos(m_MapData[0]*16,m_MapData[1]*16);

	//加载地图最前面16*20格的数据
	int x,y;
	const int (*pMap)[16];
	pMap=reinterpret_cast<const int(*)[16]>(m_MapData+3);
	for(x=0;x<20;x++)
	{
		for(y=0;y<16;y++)
		{
			if(pMap[x][y])InsertObject(x*16,y*16,pMap[x][y]);
		}
	}
	m_MapPos=0;
	m_NextMap=20;
}

void CGame::MoveMap(int Offset)
{
/*
	将地图向左移动，读取右边的新数据。
	参数：
		[i]Offset		要移动的像素。
*/
	int NewPos=m_MapPos+Offset;
	if(NewPos>m_MapData[2]*16-288)NewPos=m_MapData[2]*16-288;//已到达最右边
	Offset=NewPos-m_MapPos;
	if(!Offset)return;//没有移动
	m_MapPos=NewPos;

	//所有的角色和物体都向左移动
	CObject **it;
	for(it=m_Object;*it;it++)
	{
		(*it)->XPos-=Offset;
	}

	//读取右边的新数据
	int end=(m_MapPos+288+(16-1))/16+1;//读到右边界外的一格
	if(end>m_MapData[2])end=m_MapData[2];//右边界外已经没有了，则只读到右边界处
	int x;
	int y;
	const int (*pMap)[16];
	pMap=reinterpret_cast<const int(*)[16]>(m_MapData+3);
	for(x=m_NextMap;x<end;x++)
	{
		for(y=0;y<16;y++)
		{
			if(pMap[x][y])InsertObject(x*16-m_MapPos,y*16,pMap[x][y]);
		}
	}
	m_NextMap=end;
}

void CGame::AddObj(CObject * Obj)
{
/*
	新增一个角色或物体。
	参数：
		[i]Obj		要增加的对象。
*/
	m_Object_insert(Obj);
}

void CGame::SetSound(CSoundMan * Obj)
{
/*
	设置声音处理对象。
	参数：
		[i]Obj		要使用的CSoundMan对象。在游戏中，CGame将通过该对象控制声音。
*/
	m_SoundMan=Obj;
}

void CGame::PlaySound(CSoundMan::SOUNDNUM Num)
{
	m_SoundMan->PlaySound(Num);
}

void CGame::PlayBackMusic(int Num)
{
	m_SoundMan->PlayBackMusic(Num);
}
