/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/
#include "cross.h"
#include "Mario.h"
#include "ImgData.h"
#include "Game.h"
#include "Bullet.h"

CMario::CMario(CGame * Game,int x, int y, int State):CObject(Game,1,x,y,16,16,-1)//����λ�ڱ�����֮�󣨿��Ա�ˮ���ڵ���
{
/*
	������
		[i]x,y		�������ʱ��λ�á�
		[o]State	�������ʱ��״̬��ȡֵ������m_Stateһ�¡�
*/
	m_State=State;
	if(1==State)
	{//С�����СΪ16*16
		Width=16;
		Height=16;
	}
	else
	{//�������СΪ16*32
		Width=16;
		Height=32;
	}
	m_Action=0;//վ��״̬
	m_ToLeft=false;//�����ұ�
	m_MoveDir=0;//û���ƶ�
	m_OnLand=false;//û�����ء�������أ�������һ��ʱ�����ڻ��Զ��ı��ֵ��
	m_ChangeState=0;
	m_StarTime=0;
	m_HideTime=0;
}

const int * CMario::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToLeft;//���������Ҫˮƽ��ת��ʾ

	static int Image[32][16];
	int x,y;
	if(m_HideTime)
	{//������Ч�ڼ䣬Ҫ��������
		static bool Hide=true;
		Hide=!Hide;
		if(Hide)
		{//�������أ�����Ϊȫ͸��ɫ
			if(1==m_State)
			{//С����
				for(y=0;y<16;y++)
				{
					for(x=0;x<16;x++)
					{
						Image[y][x]=0xFF000000;
					}
				}
			}
			else
			{//������
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
	{//������Ч�ڼ䣬����Ҫ��˸
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
		{//���û���ɫ
			goto lbl_NoChangeColour;
		}
		if(1==m_State)
		{//С����
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
		{//������
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
	//�ɷ��ӵ���������Ǵ�����ֻ����ɫ��ͬ
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
	��Ծһ�Ρ�
*/
	if(1!=LiveState)return;//����������������������Ӧ�κο���
	if(!m_OnLand)return;//˫��δ���أ�����������
	m_Game->PlaySound(CSoundMan::JUMP);
	//�������ֱ�ٶ�����
	if(m_HorzSpeed>5)
	{//ˮƽ�ٶȳ���5ʱ�������ٶȿɴ�20
		m_VertSpeed=-20;
	}
	else
	{//������δ�ӵ��㹻���ٶȣ��������ٶ�ֻ��18
		m_VertSpeed=-18;
	}
	m_OnLand=false;//˫�Ų�������
}

void CMario::Move(int Dir, bool Acc)
{
/*
	��ʼ��ֹͣ�ƶ���
	������
		[i]Dir	�ƶ�����ȡֵΪ��
				1	����
				2	����
				3	����
				4	����
				0	ֹͣ
		[i]Acc	�Ƿ�����ƶ���
*/
	if(1!=LiveState)return;//����������������������Ӧ�κο���
	m_MoveDir=Dir;
	m_Acc=Acc;
	if(3==Dir)
	{//�����ƶ���Ҫ����Է����Ϊ����
		m_ToLeft=true;
	}
	else if(4==Dir)
	{//�����ƶ���Ҫ����Է����Ϊ����
		m_ToLeft=false;
		m_MoveDir=3;
	}
}

void CMario::Fire()
{
/*
	ʹ���Ƿ���һ���ӵ���
*/
	if(1!=LiveState)return;//����������������������Ӧ�κο���

	if(3!=m_State)return;//��û�з��ӵ�������

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
	//���Ǻ��������Чʱ����μ���
	if(m_StarTime)
	{
		m_StarTime--;
		if(0==m_StarTime)m_Game->PlayBackMusic(1);//����ʧЧ��Ҫ�ָ�������������
	}
	if(m_HideTime)m_HideTime--;

	if(1==m_ChangeState)
	{
		if(1==m_State)
		{//��С���
			m_State=2;
			YPos-=16;
			Height=32;
		}
		else
		{//��Ϊ�ɷ��ӵ�
			m_State=3;
		}
		m_ChangeState=0;
	}
	else if(-1==m_ChangeState)
	{//�ɴ��С
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
	{//����ʱ����ٶȿɵ�10
		if(m_HorzSpeed>10)
			m_HorzSpeed=10;
		else if(m_HorzSpeed<-10)
			m_HorzSpeed=-10;
	}
	else
	{//δ����ʱ����ٶȿɵ�5
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
			{//˫����������ˮƽ�ٶ�ʱ���ı�һ��������ʽ
				m_Action++;
				if(m_Action>3)m_Action=1;
			}
			else
			{//��ˮƽ�ٶ�ʱΪվ����ʽ
				m_Action=0;
			}
		}
		else
		{
			m_Action=4;//˫�����ʱΪ��Ծ��ʽ
		}
	}

	//���ۺ�ʱ�����������ٶ�
	m_VertSpeed+=2;//�������ٶȹ̶�Ϊ2
	if(m_VertSpeed>20)m_VertSpeed=20;//�����ٶ����Ϊ20
	m_OnLand=false;//˫����ʱ����̤�ն���أ���δ̤�գ����������ƶ�ʱ�ֻỹԭΪ�������ء���

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		int OVSpeed=m_VertSpeed;//����ԭ�е���ֱ�ٶ�
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//ˮƽ�����ܵ��赲����ˮƽ�ٶȼ�Ϊ0
			m_HorzSpeed=0;
		}
		if(MoveResult&2)
		{//��ֱ�����ܵ��赲������ֱ�ٶȼ�Ϊ0
			if(m_VertSpeed==OVSpeed)m_VertSpeed=0;//������ײ�������Ѹı�����ֱ�ٶȣ��򲻼�Ϊ0
		}
	}
}

void CMario::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;//�����������Ѿ�������������Ӧ���¼�

	if(5==Other->Type)
	{//�Ӵ���Ģ�������ǡ���ҵȣ�����Ե�
		Other->Attack(this,3);
		return;
	}

	if(m_StarTime)
	{
		if(3==Other->Type&&1==Other->LiveState)
		{//��������Ч�ڼ䣬���������֣������䷢������
			Other->Attack(this,1);
		}
	}

	if(1==Mode)
	{//�����κ�����Ķ���������Ϊ˫��������
		m_OnLand=true;
		//��Ħ������ˮƽ�ٶȽ���
		if(m_HorzSpeed>0)
		{
			if(3!=m_MoveDir||m_ToLeft)
			{//�������Ҽ����򲻼���
				m_HorzSpeed--;
			}
		}
		else if(m_HorzSpeed<0)
		{
			if(3!=m_MoveDir||!m_ToLeft)
			{//������������򲻼���
				m_HorzSpeed++;
			}
		}
		if(0==m_StarTime&&3==Other->Type&&1==Other->LiveState)
		{//���������ֵĶ����������䷢������������������Ч�ڼ䲻���������������湥�����ˣ�
			Other->Attack(this,2);
			m_VertSpeed=-10;//�ȵ����ֺ���
		}
	}
	else if(2==Mode)
	{//��������ײ�
		if(2==Other->Type&&1==Other->LiveState)
		{//����ש��ȣ������乥��
			m_Game->PlaySound(CSoundMan::BLOCK);
			Other->Attack(this,3);
		}
	}
}

bool CMario::Block(CObject * Other)
{
	if(Other)
	{
		if(2==Other->LiveState)return false;//�������������岻���赲����
		if(5==Other->Type)return false;//��ҡ�Ģ���Ȳ����赲����
		if((m_StarTime||m_HideTime)&&3==Other->Type)return false;//�κ�����Ҳ�����赲�������ǻ����������
	}

	if(1==LiveState)
		return true;//���������Ա��κ������赲��Ҳ���ܳ�Խ��ͼ�߽�
	else
		return false;//�����������������κ������赲
}

void CMario::ResetPos(int x,int y)
{
/*
	�������λ�����õ�ָ����λ�á�
	������
		[i]x,y		Ҫ���õ���λ�á�
*/
	XPos=x;
	YPos=y;
	//��λ���ٶ�ȫ����Ϊ0
	m_HorzSpeed=0;
	m_VertSpeed=0;
}

bool CMario::IsBig()
{
/*
	�Ƿ�Ϊ������
*/
	return 1!=m_State;
}

void CMario::AddPower()
{
/*
	�ñ������״̬����С�����Ϊ���������Ѿ��Ǵ��������Ϊ�ɷ��ӵ�������
*/
	m_ChangeState=1;//����һ��ʱ��������Ч
}

void CMario::AddStar()
{
/*
	����Ե������ǡ�
*/
	m_Game->PlayBackMusic(2);//������Ч�ڼ�Ҫ�ı䱳������
	m_StarTime=200;
}

void CMario::Attack(CObject * Other,int Mode)
{
	if(m_StarTime||m_HideTime)return;//�����ǻ�������Ч�ڼ䲻�ܹ���
	if(1!=LiveState)return;//ֻ�л����������ܹ���
	if(1!=m_State)
	{//�������ܵ���������С����
		m_Game->PlaySound(CSoundMan::ATTACKMARIO);
		m_ChangeState=-1;//����һ��ʱ��������Ч
		m_HideTime=40;
	}
	else
	{//С�����ܵ�����������
		m_Game->PlayBackMusic(0);
		m_Game->PlaySound(CSoundMan::DEATH);
		LiveState=2;
		Layer=1;//���������������ᵽ����ǰ��
		m_Action=5;
		m_MoveDir=0;
		m_HorzSpeed=0;
		m_VertSpeed=-20;
	}
}

