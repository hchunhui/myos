/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "FlyTortoiseDemon.h"
#include "ImgData.h"
#include "Game.h"
#include "TortoiseDemon.h"

CFlyTortoiseDemon::CFlyTortoiseDemon(CGame * Game,int x, int y):CObject(Game,3,x,y+8,16,24,0)//�ڹ��ڵ�ͼ�ϵ�λ�ñ�ʵ��λ�ø���8������
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//���ָճ���ʱ�����ƶ�
	m_ToRight=false;//�������
}

const int * CFlyTortoiseDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//�����ұ���Ҫˮƽ��ת��ʾ
	return FlyTortoiseDemonImage[m_Action];
}

void CFlyTortoiseDemon::Clock()
{
	m_ActionTimeCount++;
	if(5<=m_ActionTimeCount)
	{
		m_Action=!m_Action;
		m_ActionTimeCount=0;
	}

	//���ۺ�ʱ�����������ٶ�
	m_VertSpeed+=1;//��Ϊ��ɣ������������ٶ�ֻ��1
	if(m_VertSpeed>10)m_VertSpeed=10;//�����ٶ����Ϊ10

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//ˮƽ�����ܵ��赲����ı��ƶ�����
			m_HorzSpeed=-m_HorzSpeed;
			m_ToRight=!m_ToRight;
		}
		if(MoveResult&2)
		{//��ֱ�����ܵ��赲
			if(m_VertSpeed>0)
				m_VertSpeed=-10;//����ʱ�ܵ��赲�������ϵ���
			else
				m_VertSpeed=0;//����ʱ�ܵ��赲����ֹͣ�������������������½�
		}
	}
}

void CFlyTortoiseDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//ֻ�л����ֲ��ܱ�����
	CTortoiseDemon * p;
	switch(Mode)
	{
	case 1://�ܵ��ӵ�������������ڹ�ǵĹ���
		//�ȱ����ͨ�ڹ꣬�ٱ�����
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		LiveState=3;
		p=new CTortoiseDemon(m_Game,XPos,YPos);
		p->Attack(Other,Mode);
		m_Game->AddObj(p);
		break;
	case 2://������ȵ�
		//�����ͨ�ڹ�
		m_Game->PlaySound(CSoundMan::ATTACKDEMON);
		LiveState=3;
		m_Game->AddObj(new CTortoiseDemon(m_Game,XPos,YPos));
		break;
	}
}

void CFlyTortoiseDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;
	if(1==Other->Type&&(3==Mode||1==Mode))
	{//�Ӳ�������湥������
		Other->Attack(this,1);
	}
}
