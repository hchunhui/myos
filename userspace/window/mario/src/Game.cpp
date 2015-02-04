/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
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


int g_FlushAction=0;//�ʺźͽ�ҵ�ǰ����˸״̬�������ʺŵĽ�ҵ���˸״̬��һ�µġ�ȡֵΪ0~2��
static int s_FlushTimeCount=0;//����ÿ��ʱ��������˸һ�Σ�����Ҫ�ȵ��ñ�����¼��һ��ֵ���ٸı�һ����˸״̬��
static int s_FlushDir;//��ǰ����˸����1:�����䰵 2:�ɰ�����

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
	�������н�ɫ��������б�����NULL��ʾ��Ϸ��δ��ʼ��
*/
	if(!m_Mario)return (CObject **)NULL;//��Ϸ��δ��ʼ
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
	��ʼ��Ϸ��
*/
	if(m_Mario)return;//��Ϸ�Ѿ���ʼ��������Ӧ���¼�

	//������н�ɫ������
	CObject **it;
	for(it=m_Object;*it;++it)
	{
		//(*it)->Destroy();
		delete *it;
	}
	m_Object_clear();

	//������������
	m_Mario=new CMario(this,0,0,1);
	m_Object_insert(m_Mario);

	//�ӵ�0�ؿ�ʼ
	m_CurLevel=0;
	m_MapData=MapData+1;
	LoadMapData();
}

void CGame::InsertObject(int X,int Y,int Type)
{
/*
	����һ���½�ɫ�����塣
	������
		[i]X,Y		Ҫ���뵽�ĸ�λ�á�
		[i]Type		Ҫ������������͡�ȡֵΪ��
			1		ש�顣
			2		ʯͷ��
			3		ˮ���塣
			4		ˮ�ܶ���
			5		�ʺ�(�ڲ�һö���)��
			6		�ʺ�(�ڲ�Ģ��)��
			7		�ʺ�(�ڲ�ʮö���)��
			8		ש��(�ڲ�Ģ��)��
			9		ש��(�ڲ�����)��
			10		ש��(�ڲ�ʮö���)��
			11		Ģ�����֡�
			12		�ڹ����֡�
			13		���ڹ����֡�
			14		�������֡�
			15		�ذ塣
			16		��ҡ�
			17		�׳����֡�
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
	ִ��һ��ʱ���źŶ�����
*/
	//�ı��ʺźͽ�ҵ�ǰ����˸״̬
	s_FlushTimeCount++;
	switch(g_FlushAction)
	{
	case 0:
		if(s_FlushTimeCount>=10)
		{//������״̬��ʾ10��ʱ������
			g_FlushAction=1;
			s_FlushDir=1;
			s_FlushTimeCount=0;
		}
		break;
	case 1:
		if(s_FlushTimeCount>=2)
		{//�԰���״̬��ʾ2��ʱ������
			g_FlushAction+=s_FlushDir;
			s_FlushTimeCount=0;
		}
		break;
	default://case 2:
		if(s_FlushTimeCount>=3)
		{//���״̬��ʾ3��ʱ������
			g_FlushAction=1;
			s_FlushDir=-1;
			s_FlushTimeCount=0;
		}
	}

	CObject **it,**it2;
	//ʹ���еĽ�ɫ�����嶯��һ��
	for(it=m_Object;*it;)
	{
		if(3==(*it)->LiveState||(*it)->XPos>288+32||(*it)->XPos+(*it)->Width<-32||(*it)->YPos>256)
		{//��������������ɾ��
			//����߳����ұ߽�32�������ϣ�����߳�����߽�32�������ϣ��ϱ��߳����±߽磬����Ϊ���󳬳���ͼ��Χ֮�⣬Ҫɾ���ö���
			if(*it==m_Mario)
			{//ɾ����������
				if(1==m_Mario->LiveState)
				{//ɾ�����ǻ�������Ҫֹͣ�������֣�������������ʱ������
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
	if(!m_Mario)return;//�����ѱ�ɾ��
	int Offset=m_Mario->XPos-((288-m_Mario->Width)>>1);
	if(Offset>0)
	{//���򳬹��˵�ͼ���ߣ���Ҫ����ͼ�ƶ���ʹ���򵽴��ͼ����
		MoveMap(Offset);
	}
	if(m_Mario->XPos==288-m_Mario->Width)
	{//���򵽴��˵�ͼ�ұ��ߣ��������һ��
		//���������������н�ɫ������
		for(it=m_Object;*it;)
		{
			it2=it;
			it++;
			if(*it2==m_Mario)continue;//������ɾ��
			delete *it2;
			m_Object_erase(it2);
		}

		m_CurLevel++;
		if(MapData[0]==m_CurLevel)
		{//�Ѿ���������һ�أ�����Ϸ����
			m_SoundMan->PlayBackMusic(0);
			//ɾ������
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
	ʹ���ǿ�ʼ��ֹͣ�ƶ���
	������
		[i]Dir	�ƶ�����ȡֵΪ��
				1	����
				2	����
				3	����
				4	����
				0	ֹͣ
		[i]Acc	�Ƿ�����ƶ���
*/
	if(!m_Mario)return;//��Ϸ��δ��ʼ
	m_Mario->Move(Dir,Acc);
}

void CGame::Jump(void)
{
/*
	ʹ������Ծһ�Ρ�
*/
	if(!m_Mario)return;//��Ϸ��δ��ʼ
	m_Mario->Jump();
}

void CGame::Fire(void)
{
/*
	ʹ���Ƿ���һ���ӵ���
*/
	if(!m_Mario)return;//��Ϸ��δ��ʼ
	m_Mario->Fire();
}

struct BLOCKINFO
{//�ƶ�·���ڵ��赲����Ϣ
	CObject * Blocker;//�赲�������˶�������
	int x,y;//�ܸ������赲�����˶�����λ��
	int BlockMode;//�赲��ʽ��ȡֵ�뱾�����ķ���ֵһ�¡���MayBeΪtrueʱ�����Ըó�Ա
	int BumpMode;//����������ײ��ʽ��ȡֵȡCObject::Bump��������Mode����һ�¡���MayBeΪtrueʱ�����Ըó�Ա
	bool MayBe;//����赲��պ����˶�����ı߽��ϣ�������赲��Ҳ���ܲ��赲
};

struct BLOCKINFOCompare
{//BLOCKINFO�ıȽ�������b���뱻�赲��Ͻ����򷵻�true��
	//��X����Ͻ�Ϊ׼����Xֵ��ͬ����Y�Ͻ�Ϊ׼����YֵҲ��ͬ������һ���赲������Ϊ׼
	//�����ܳ���X�Ͻ���Yֵ��Զ�����
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
	bool XLarge;//��Ϊtrue����XֵԽ����Խ��������XֵСԽ��
	bool YLarge;//��Ϊtrue����YֵԽ����Խ��������YֵСԽ��
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
	�ƶ�ĳ����ɫ�����塣
	������
		[i]Obje		Ҫ�ƶ��Ķ���
		[i]Horz		Ҫ�ƶ���ˮƽ���루���أ�������Ϊ��������Ϊ����
		[i]Vert		Ҫ�ƶ�����ֱ���루���أ�������Ϊ��������Ϊ����
	����ֵ��
		����һ��λ��ֵ�����¸�ֵ����λ��ϲ���
		0	�ɹ���
		1	ˮƽ���������赲��
		2	��ֱ���������赲��
*/
	int retval=0;

	//���û���赲��Ӧ���ƶ�����λ��
	int OrDestX=Obj->XPos+Horz;
	int OrDestY=Obj->YPos+Vert;

	BLOCKINFOCompare Compare;
	BLOCKINFO bi;
	BLOCKINFO bitop;
	if(Vert>0)
	{//�����ƶ�����YֵԽСԽ��
		Compare.YLarge=false;
	}
	else
	{//�����ƶ�����YֵԽ��Խ��
		Compare.YLarge=true;
	}
	if(Horz>0)
	{//�����ƶ�����XֵԽСԽ��
		Compare.XLarge=false;
	}
	else
	{//�����ƶ�����XֵԽ��Խ��
		Compare.XLarge=true;
	}
	//std::priority_queue<BLOCKINFO,std::vector<BLOCKINFO>,BLOCKINFOCompare> BlockList(Compare);//���˶�·���ڵ������赲��
	BlockList.init(&Compare);

	int start,end;
	if(Vert<0)
	{//�����ƶ���ֻ�����Ǳ�����Ķ������赲��ĵ�������
		start=Obj->YPos;
		end=start+Vert;
		//�ж������������ƶ�·��֮��
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//���Լ�
			int ypos=(*it)->YPos+(*it)->Height;
			if(ypos>end&&ypos<=start)
			{//�������˶���Χ֮��
				//���赲��ĺ������Ƿ����˶���Χ��
				int x1=Obj->XPos+Horz*(ypos-start)/Vert;
				int x2=x1+Obj->Width;
				if(!((*it)->XPos>=x2||(*it)->XPos+(*it)->Width<=x1))
				{//������Ҳ���˶���Χ�ڣ����ܵ��赲
					bi.Blocker=(*it);
					bi.BlockMode=2;
					bi.BumpMode=2;
					bi.MayBe=false;
					bi.x=x1;
					bi.y=ypos;
					BlockList.push(bi);
				}
				else if( (Horz>0&&(*it)->XPos==x2) || (Horz<0&&(*it)->XPos+(*it)->Width==x1) )
				{//��ˮƽ���������ٶȣ����赲���������˶����������ұ߽��ϣ�������赲��Ҳ���ܲ��赲
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
	{//�����ƶ���ֻ�����Ǳ�����ĵ������赲��Ķ�������
		start=Obj->YPos+Obj->Height;
		end=start+Vert;
		//�ж������������ƶ�·��֮��
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//���Լ�
			int ypos=(*it)->YPos;
			if(ypos>=start&&ypos<end)
			{//�������˶���Χ֮��
				//���赲��ĺ������Ƿ����˶���Χ��
				int x1=Obj->XPos+Horz*(ypos-start)/Vert;
				int x2=x1+Obj->Width;
				if(!((*it)->XPos>=x2||(*it)->XPos+(*it)->Width<=x1))
				{//������Ҳ���˶���Χ�ڣ����ܵ��赲
					bi.Blocker=(*it);
					bi.BlockMode=2;
					bi.BumpMode=1;
					bi.MayBe=false;
					bi.x=x1;
					bi.y=ypos-Obj->Height;
					BlockList.push(bi);
				}
				else if( (Horz>0&&(*it)->XPos==x2) || (Horz<0&&(*it)->XPos+(*it)->Width==x1) )
				{//��ˮƽ���������ٶȣ����赲���������˶����������ұ߽��ϣ�������赲��Ҳ���ܲ��赲
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
	{//�����ƶ���ֻ�����Ǳ��������������赲����ұ�������
		start=Obj->XPos;
		end=start+Horz;
		//�ж������������ƶ�·��֮��
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//���Լ�
			int xpos=(*it)->XPos+(*it)->Width;
			if(xpos>end&&xpos<=start)
			{//�ұ������˶���Χ֮��
				//���赲����������Ƿ����˶���Χ��
				int y1=Obj->YPos+Vert*(xpos-start)/Horz;
				int y2=y1+Obj->Height;
				if(!((*it)->YPos>=y2||(*it)->YPos+(*it)->Height<=y1))
				{//������Ҳ���˶���Χ�ڣ����ܵ��赲
					bi.Blocker=(*it);
					bi.BlockMode=1;
					bi.BumpMode=3;
					bi.MayBe=false;
					bi.x=xpos;
					bi.y=y1;
					BlockList.push(bi);
				}
				else if( (Vert>0&&(*it)->YPos==y2) || (Vert<0&&(*it)->YPos+(*it)->Height==y1) )
				{//����ֱ���������ٶȣ����赲���������˶����������ұ߽��ϣ�������赲��Ҳ���ܲ��赲
					bi.Blocker=(*it);
					bi.MayBe=false;
					bi.x=xpos;
					bi.y=y1;
					BlockList.push(bi);
				}
			}
		}
		if(end<0)
		{//����߳�����߽�
			bi.Blocker=(CObject *)NULL;
			bi.BlockMode=1;
			bi.MayBe=false;
			bi.x=0;
			bi.y=Obj->YPos+Vert*(0-start)/Horz;
			BlockList.push(bi);
		}
	}
	else if(Horz>0)
	{//�����ƶ���ֻ�����Ǳ�������ұ������赲������������
		start=Obj->XPos+Obj->Width;
		end=start+Horz;
		//�ж������������ƶ�·��֮��
		CObject **it;
		for(it=m_Object;*it;it++)
		{
			if(*it==Obj)continue;//���Լ�
			int xpos=(*it)->XPos;
			if(xpos>=start&&xpos<end)
			{//��������˶���Χ֮��
				//���赲����������Ƿ����˶���Χ��
				int y1=Obj->YPos+Vert*(xpos-start)/Horz;
				int y2=y1+Obj->Height;
				if(!((*it)->YPos>=y2||(*it)->YPos+(*it)->Height<=y1))
				{//������Ҳ���˶���Χ�ڣ����ܵ��赲
					bi.Blocker=(*it);
					bi.BlockMode=1;
					bi.BumpMode=3;
					bi.MayBe=false;
					bi.x=xpos-Obj->Width;
					bi.y=y1;
					BlockList.push(bi);
				}
				else if( (Vert>0&&(*it)->YPos==y2) || (Vert<0&&(*it)->YPos+(*it)->Height==y1) )
				{//��ˮƽ���������ٶȣ����赲���������˶����������ұ߽��ϣ�������赲��Ҳ���ܲ��赲
					bi.Blocker=(*it);
					bi.MayBe=true;
					bi.x=xpos-Obj->Width;
					bi.y=y1;
					BlockList.push(bi);
				}
			}
		}
		if(end+Obj->Width>288)
		{//�ұ��߳�����߽�
			bi.Blocker=(CObject *)NULL;
			bi.BlockMode=1;
			bi.MayBe=false;
			bi.x=288-Obj->Width;
			bi.y=Obj->YPos+Vert*(288-start)/Horz;
			BlockList.push(bi);
		}
	}

	//��û���赲�����˶���ָ����λ��
	Obj->XPos=OrDestX;
	Obj->YPos=OrDestY;

	for(;!BlockList.empty();BlockList.pop())
	{
		bitop = BlockList.top();
		int BumpMode;
		if(bitop.MayBe)
		{//��һ���պ��ڱ߽��ϵ��赲��
			if(Obj==m_Mario)
			{//�������������������Ϊ��ֱ���������赲���Կ�ˮƽ����
				retval=2;
				BumpMode=Vert>0?1:2;
			}
			else
			{//�������������������Ϊˮƽ���������赲��ʹ�����ȥ
				retval=1;
				BumpMode=3;
			}
			Obj->Bump(bitop.Blocker,BumpMode,true);
			//�Լ����Է��ͶԷ����Լ��ķ�ʽ���������෴
			if(1==BumpMode)
				BumpMode=2;
			else if(2==BumpMode)
				BumpMode=1;
			bitop.Blocker->Bump(Obj,BumpMode,false);
			if(!Obj->Block(bitop.Blocker))continue;//�����赲�����������Զ���赲��
			Obj->XPos=bitop.x;
			Obj->YPos=bitop.y;
			break;
		}
		else
		{
			if(bitop.Blocker)
			{
				Obj->Bump(bitop.Blocker,bitop.BumpMode,true);
				//�Լ����Է��ͶԷ����Լ��ķ�ʽ���������෴
				if(1==bitop.BumpMode)
					BumpMode=2;
				else if(2==bitop.BumpMode)
					BumpMode=1;
				else
					BumpMode=3;
				bitop.Blocker->Bump(Obj,BumpMode,false);
			}
			if(!Obj->Block(bitop.Blocker))continue;//�����赲�����������Զ���赲��
			Obj->XPos=bitop.x;
			Obj->YPos=bitop.y;
			retval=bitop.BlockMode;
			BlockList.pop();
			//ͬһ��������ж���赲������Ƕ�����
			while(!BlockList.empty())
			{
				bitop = BlockList.top();
				if(bitop.MayBe)break;
				if(bitop.x!=Obj->XPos||bitop.y!=Obj->YPos)break;
				if(bitop.Blocker)
				{
					Obj->Bump(bitop.Blocker,bitop.BumpMode,true);
					//�Լ����Է��ͶԷ����Լ��ķ�ʽ���������෴
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
		{//ˮƽ�������赲����δ�ﵽָ���������꣬��Ҫ����ֱ����������þ���
			retval|=Move(Obj,0,OrDestY-Obj->YPos);
		}
	}
	else if(2==retval||4==retval)
	{
		if(Obj->XPos!=OrDestX)
		{//��ֱ�������赲����δ�ﵽָ���ĺ����꣬��Ҫ��ˮƽ����������þ���
			retval|=Move(Obj,OrDestX-Obj->XPos,0);
		}
	}

	return retval;
}

void CGame::LoadMapData()
{
	m_SoundMan->PlayBackMusic(1);

	//���������õ���һ�ص���ʼλ��
	m_Mario->ResetPos(m_MapData[0]*16,m_MapData[1]*16);

	//���ص�ͼ��ǰ��16*20�������
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
	����ͼ�����ƶ�����ȡ�ұߵ������ݡ�
	������
		[i]Offset		Ҫ�ƶ������ء�
*/
	int NewPos=m_MapPos+Offset;
	if(NewPos>m_MapData[2]*16-288)NewPos=m_MapData[2]*16-288;//�ѵ������ұ�
	Offset=NewPos-m_MapPos;
	if(!Offset)return;//û���ƶ�
	m_MapPos=NewPos;

	//���еĽ�ɫ�����嶼�����ƶ�
	CObject **it;
	for(it=m_Object;*it;it++)
	{
		(*it)->XPos-=Offset;
	}

	//��ȡ�ұߵ�������
	int end=(m_MapPos+288+(16-1))/16+1;//�����ұ߽����һ��
	if(end>m_MapData[2])end=m_MapData[2];//�ұ߽����Ѿ�û���ˣ���ֻ�����ұ߽紦
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
	����һ����ɫ�����塣
	������
		[i]Obj		Ҫ���ӵĶ���
*/
	m_Object_insert(Obj);
}

void CGame::SetSound(CSoundMan * Obj)
{
/*
	���������������
	������
		[i]Obj		Ҫʹ�õ�CSoundMan��������Ϸ�У�CGame��ͨ���ö������������
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
