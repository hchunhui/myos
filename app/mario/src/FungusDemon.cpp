/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "FungusDemon.h"
#include "ImgData.h"
#include "Game.h"

CFungusDemon::CFungusDemon(CGame * Game,int x, int y):CObject(Game,3,x,y,16,16,0)
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//���ָճ���ʱ�����ƶ�
}

const int * CFungusDemon::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	if(2==LiveState&&0==m_Action)
		*VInv=true;//�ѱ�����������ֱ��ת
	else
		*VInv=false;
	return FungusDemonImage[m_Action];
}

void CFungusDemon::Clock()
{
	if(1==LiveState)
	{//��������Ҫ�ı�����
		m_ActionTimeCount++;
		if(5<=m_ActionTimeCount)
		{
			m_Action=!m_Action;
			m_ActionTimeCount=0;
		}
	}
	
	if(2==LiveState&&2==m_Action)
	{//�ѱ��ȱ⣬���һ��ʱ�����ʧ
		m_ActionTimeCount++;
		if(10==m_ActionTimeCount)
		{
			LiveState=3;
		}
	}
	else
	{//�ѱ��ȱ���û���������ٶ�
		m_VertSpeed+=2;//�������ٶȹ̶�Ϊ2
		if(m_VertSpeed>20)m_VertSpeed=20;//�����ٶ����Ϊ20
	}

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//ˮƽ�����ܵ��赲����ı��ƶ�����
			m_HorzSpeed=-m_HorzSpeed;
		}
		if(MoveResult&2)
		{//��ֱ�����ܵ��赲������ֱ�ٶȼ�Ϊ0
			m_VertSpeed=0;
		}
	}
}

void CFungusDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//ֻ�л����ֲ��ܱ�����
	switch(Mode)
	{
	case 1://�ܵ��ӵ�������������ڹ�ǵĹ���
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=0;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		break;
	case 2://������ȵ�
		m_Game->PlaySound(CSoundMan::ATTACKDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=0;
		m_HorzSpeed=0;
		m_ActionTimeCount=0;
		break;
	default:
		if(2==Other->Type)
		{//��ש�鶥��
			m_Game->PlaySound(CSoundMan::KILLDEMON);
			m_Action=0;
			LiveState=2;
			m_VertSpeed=-10;
			m_HorzSpeed=2;
		}
	}
	Layer=1;//��������������һ����ʾ�ڱ���֮ǰ
}

void CFungusDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;
	if(1==Other->Type&&(3==Mode||1==Mode))
	{//�Ӳ�������湥������
		Other->Attack(this,1);
	}
}
