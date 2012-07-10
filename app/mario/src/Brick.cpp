/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Brick.h"
#include "ImgData.h"
#include "Game.h"
#include "Fungus.h"
#include "Flower.h"
#include "Question.h"
#include "Star.h"
#include "Coin.h"
#include "BrokenBrick.h"


CBrick::CBrick(CGame * Game,int x, int y,int Content):CObject(Game,2,x,y,16,16,0)
{
/*
	������
		[i]Content		ש���ڲغ��
						0		û�ж�����
						1		Ģ����
						2		ʮö��ҡ�
						3		���ǡ�
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
		m_Content=-2;
		break;
	default:
		m_Content=0;
	}
}

const int * CBrick::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=false;
	return BrickImage;
}

void CBrick::Attack(CObject * Other,int Mode)
{//ש��ֻ�ᱻ���򶥵�
	int OriContent=m_Content;//����ԭ���Ƿ��ж���
	switch(m_Content)
	{
	case 0://û�ж���
		break;
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
	case -2://����
		m_Game->AddObj(new CStar(m_Game,XPos,YPos));
		m_Content=0;
		break;
	default://���
		CCoin * pcoin=new CCoin(m_Game,XPos,YPos-16);
		m_Game->AddObj(pcoin);
		pcoin->ThrowUp();
		m_Content--;
	}

	if(0!=OriContent&&0==m_Content)
	{//ԭ���ж����ģ����ڱ��û��������Ҫ��ɿպ�
		LiveState=3;//ɾ���Լ�
		//����ͬλ����Ӻ���
		CQuestion * pbox=new CQuestion(m_Game,XPos,YPos,0);
		m_Game->AddObj(pbox);
		//�����������ƶ���������
		pbox->MoveUp();
	}
	else
	{
		//�����ƶ���������
		m_Game->Move(this,0,-4);
		m_TimeCount=0;
		if(0==OriContent)
		{
			if(static_cast<CMario*>(Other)->IsBig())
			{//����ǰû�ж����������Ǳ������򶥵�����ש������
				m_Game->PlaySound(CSoundMan::BRICKBROKEN);
				LiveState=3;//�Լ���ʧ
				//�ڸ�λ������Ŀ���ש����ͬ�ķ��򵯿�
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos,YPos,-3,-16));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos+8,YPos,3,-16));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos,YPos+8,-3,-10));
				m_Game->AddObj(new CBrokenBrick(m_Game,XPos+8,YPos+8,3,-10));
			}
		}
	}
}

void CBrick::Bump(CObject * Other,int Mode,bool Volun)
{
	if(!Volun)return;//�������������ˣ��򲻹���
	if(3==Other->Type&&1==Other->LiveState)
	{//ש�鱻�������ֶ������֣��򹥻�������
		Other->Attack(this,3);
	}
}

bool CBrick::Block(CObject * Other)
{
	return false;//ש�鱻����ʱ�����κ������赲
}

void CBrick::Clock()
{
	if(YPos==m_OriPos)return;//ת��û������������ִ���κβ���
	m_TimeCount++;
	if(3==m_TimeCount)
	{//��һ����ʱ���ש��ظ���ԭʼλ��
		m_Game->Move(this,0,m_OriPos-YPos);
	}
}

