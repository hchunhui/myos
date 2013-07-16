/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Flower.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CFlower::CFlower(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//��λ�ڱ�����󣨿ɱ�ש���ڵ���
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//���ճ���ʱ��������
	m_Action=0;
}

const int * CFlower::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return FlowerImage[m_Action];
}

void CFlower::Clock()
{
	m_Action=!m_Action;//�ı䵱ǰ�Ķ���״̬

	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//����ȫ������ֹͣ����
			m_OriPos=0;
			m_VertSpeed=0;
		}
	}

	if(m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		m_Game->Move(this,0,m_VertSpeed);
	}
}

void CFlower::Attack(CObject * Other,int Mode)
{//������Ե�
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddPower();
}

bool CFlower::Block(CObject * Other)
{//�����κ��赲
	return false;
}
