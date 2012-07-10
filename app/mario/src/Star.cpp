/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Star.h"
#include "ImgData.h"
#include "Game.h"

CStar::CStar(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,-1)//����λ�ڱ�����󣨿ɱ�ש���ڵ���
{
	m_Game->PlaySound(CSoundMan::FLOWERRISE);
	m_OriPos=y;
	m_VertSpeed=-1;//���Ǹճ���ʱ��������
	m_Action=0;
}

const int * CStar::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return StarImage[m_Action];
}

void CStar::Clock()
{
	m_Action=!m_Action;//�ı䵱ǰ�Ķ���״̬

	if(m_OriPos)
	{
		if(m_OriPos-YPos==16)
		{//����ȫ������ʼ�����ƶ��������ϵ���
			m_OriPos=0;
			m_VertSpeed=-8;
			m_HorzSpeed=3;
		}
	}
	else
	{//�Ѿ���ȫ�����ˣ�������������ٶ�
		m_VertSpeed+=1;//�������ٶȹ̶�Ϊ1
		if(m_VertSpeed>8)m_VertSpeed=8;//�����ٶ����Ϊ8
	}

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//ˮƽ�����ܵ��赲����ı��ƶ�����
			m_HorzSpeed=-m_HorzSpeed;
		}
		if(MoveResult&2)
		{//��ֱ�����ܵ��赲
			if(m_VertSpeed>0)
				m_VertSpeed=-8;//����ʱ�ܵ��赲�������ϵ���
			else
				m_VertSpeed=0;//����ʱ�ܵ��赲����ֹͣ�������������������½�
		}
	}
}

void CStar::Attack(CObject * Other,int Mode)
{//������Ե�
	m_Game->PlaySound(CSoundMan::EATFLOWER);
	LiveState=3;
	static_cast<CMario*>(Other)->AddStar();
}

bool CStar::Block(CObject * Other)
{
	if(m_OriPos)return false;//�����ڼ䲻���赲
	if(Other)
	{//ֻ�̶ܹ�������赲
		if(2==Other->Type)return true;
	}
	return false;
}
