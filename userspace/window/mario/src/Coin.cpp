/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Coin.h"
#include "ImgData.h"
#include "Game.h"

CCoin::CCoin(CGame * Game,int x, int y):CObject(Game,5,x,y,16,16,1)//����ڱ���֮ǰ��ʾ
{
	m_OriPos=y;
	m_Rotate=0;
}

const int * CCoin::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	if(m_Rotate)
	{//������ת
		return CoinImage[m_Rotate];
	}
	else
	{//δ��ת
		return CoinImage[g_FlushAction];
	}
}

void CCoin::Attack(CObject * Other,int Mode)
{
	if(2==LiveState)return;//�Ѿ��������Ľ�Ҳ����ٱ���
	m_Game->PlaySound(CSoundMan::COIN);
	LiveState=3;
}

bool CCoin::Block(CObject * Other)
{
	return false;//��Ҳ����κ������赲
}

void CCoin::Clock()
{
	switch(m_Rotate)
	{
	case 3:
		m_Rotate=4;
		m_RotateThin=true;
		break;
	case 4:
		if(m_RotateThin)
			m_Rotate=5;
		else
			m_Rotate=3;
		break;
	case 5:
		m_Rotate=4;
		m_RotateThin=false;
		break;
	default:
		return;//���û����ת������ִ���κβ���
	}
	
	//���ۺ�ʱ�����������ٶ�
	m_VertSpeed+=1;//�������ٶȹ̶�Ϊ1
	if(m_VertSpeed>10)m_VertSpeed=10;//�����ٶ����Ϊ10

	if(m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		m_Game->Move(this,0,m_VertSpeed);
	}

	if(YPos>m_OriPos)
	{//��ҵ�����ԭʼλ��֮�£�����ʧ
		LiveState=3;
	}
}

void CCoin::ThrowUp()
{
/*
	�������������
*/
	m_Game->PlaySound(CSoundMan::COIN);
	m_VertSpeed=-9;
	m_Rotate=3;
	LiveState=2;
}
