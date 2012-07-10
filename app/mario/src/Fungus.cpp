/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Fungus.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CFungus::CFungus(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//Ģ��λ�ڱ�����󣨿ɱ�ש���ڵ���
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//Ģ���ճ���ʱ��������
}

const int * CFungus::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return FungusImage;
}

void CFungus::Clock()
{
	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//����ȫ������ֹͣ��������ʼ�����ƶ�
			m_OriPos=0;
			m_VertSpeed=0;
			m_HorzSpeed=3;
		}
	}
	else
	{//�Ѿ���ȫ�����ˣ�������������ٶ�
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

void CFungus::Attack(CObject * Other,int Mode)
{//������Ե�
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddPower();
}

bool CFungus::Block(CObject * Other)
{
	if(m_OriPos)return false;//�����ڼ䲻���赲
	if(Other)
	{//ֻ�̶ܹ�������赲
		if(2==Other->Type)return true;
	}
	return false;
}
