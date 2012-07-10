/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "ClipDemon.h"
#include "ImgData.h"
#include "Game.h"

CClipDemon::CClipDemon(CGame * Game,int x, int y):CObject(Game,3,x+8,y+8,16,24,-1)//�����ڵ�ͼ�ϵ�λ�ñ�ʵ��λ��ƫ����8������
																				//����λ�ڱ�����֮�󣨿��Ա�ˮ���ڵ���
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_UpDownTimeCount=0;
	m_Top=y+8;//�ڵ�ͼ���趨��λ��(��8)�������λ��
}

const int * CClipDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return ClipDemonImage[m_Action];
}

void CClipDemon::Clock()
{
	m_ActionTimeCount++;
	if(5<=m_ActionTimeCount)
	{
		m_Action=!m_Action;
		m_ActionTimeCount=0;
	}

	m_UpDownTimeCount++;
	if(m_VertSpeed)
	{//�����˶�������
		m_Game->Move(this,m_HorzSpeed,m_VertSpeed);//�������ܵ��赲
		if(YPos==m_Top||YPos==m_Top+25)
		{//�ѵ������˶�����ߵ����͵㣬��ֹͣ�˶�
			m_VertSpeed=0;
			m_UpDownTimeCount=0;//��ʼ��ʱ
		}
	}
	else
	{//�ھ�ֹ״̬�����30�������ٻָ��˶�
		if(30==m_UpDownTimeCount)
		{
			if(YPos==m_Top)
			{//��ǰ����ߵ㣬�������˶�
				m_VertSpeed=1;
			}
			else
			{//��ǰ����͵㣬�������˶�
				m_VertSpeed=-1;
			}
			m_UpDownTimeCount=0;
		}
	}
}

bool CClipDemon::Block(CObject * Other)
{
	return false;//���Ӳ���ˮ�ܼ��κ������赲
}

void CClipDemon::Attack(CObject * Other,int Mode)
{
	switch(Mode)
	{
	case 1://�ܵ��ӵ�������������ڹ�ǵĹ���
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		LiveState=3;
		break;
	}
}

void CClipDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1==Other->Type)
	{//��������
		Other->Attack(this,1);
	}
}
