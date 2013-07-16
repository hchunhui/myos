/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Question.h"
#include "ImgData.h"
#include "Game.h"
#include "Fungus.h"
#include "Flower.h"
#include "Coin.h"

CQuestion::CQuestion(CGame * Game,int x, int y,int Content):CObject(Game,2,x,y,16,16,0)
{
/*
	������
		[i]Content		�ʺ��ڲغ��
						0		û�ж�����
						1		Ģ����
						2		ʮö��ҡ�
						3		һö��ҡ�
*/
	m_OriPos=y;
	switch(Content)
	{
	case 1:
		m_Content=-1;
		break;
	case 2:
		m_Content=10;
		break;
	case 3:
		m_Content=1;
		break;
	default:
		m_Content=0;
	}
}

const int * CQuestion::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	if(0==m_Content)return QuestionImage[3];//�ǿպ�
	return QuestionImage[g_FlushAction];
}

void CQuestion::MoveUp()
{
/*
	�������������ƶ���������
*/
	m_Game->Move(this,0,-4);
	m_TimeCount=0;
}

void CQuestion::Attack(CObject * Other,int Mode)
{//�ʺ�ֻ�ᱻ���򶥵���Ҫ�����ƶ���������
	if(0==m_Content)return;//�պ��Ƕ�������

	switch(m_Content)
	{
	case -1://Ģ��
		if(static_cast<CMario*>(Other)->IsBig())
		{//�Ǵ����������һ�仨
			m_Game->AddObj(new CFlower(m_Game,XPos,YPos));
		}
		else
		{//��С���������Ģ��
			m_Game->AddObj(new CFungus(m_Game,XPos,YPos));
		}
		m_Content=0;
		break;
	default://���
		CCoin * pcoin=new CCoin(m_Game,XPos,YPos-16);
		m_Game->AddObj(pcoin);
		pcoin->ThrowUp();
		m_Content--;
	}

	//�����ƶ���������
	MoveUp();
}

void CQuestion::Bump(CObject * Other,int Mode,bool Volun)
{
	if(!Volun)return;//�������������ˣ��򲻹���
	if(3==Other->Type&&1==Other->LiveState)
	{//�ʺű��������ֶ������֣��򹥻�������
		Other->Attack(this,3);
	}
}

bool CQuestion::Block(CObject * Other)
{
	return false;//�ʺű�����ʱ�����κ������赲
}

void CQuestion::Clock()
{
	if(YPos==m_OriPos)return;//ת��û������������ִ���κβ���
	m_TimeCount++;
	if(3==m_TimeCount)
	{//��һ����ʱ����ʺŻظ���ԭʼλ��
		m_Game->Move(this,0,m_OriPos-YPos);
	}
}

