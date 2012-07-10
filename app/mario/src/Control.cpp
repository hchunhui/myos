/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Control.h"

void CControl::Clock()
{
/*
	ִ��һ��ʱ���źŶ�����
*/
	//ʹ��Ϸ����һ��
	m_pGame->Clock();
	//ˢ��ͼ����ʾ
	m_pGraphMan->Update();
}

void CControl::SetGraph(CGraphMan *Graph)
{
/*
	����ͼ�������
	������
		[i]Game		��Ҫ��CControl���Ƶ�CGraphMan����
*/
	m_pGraphMan=Graph;
}

void CControl::KeyDown(int KeyChange)
{
	int KeyState = m_LastKeyState | KeyChange;
	if(KeyState != m_LastKeyState)
	{
		KeyChanged(KeyState);
	}	
}

void CControl::KeyUp(int KeyChange)
{
	int KeyState = m_LastKeyState & (~KeyChange);
	if(KeyState != m_LastKeyState)
	{
		KeyChanged(KeyState);
	}
}

void CControl::KeyChanged(int KeyState)
{
/*
	����״̬�����ı䡣
	������
		[i]KeyState	��ť״̬����һ��λ��ֵ����Ӧ��λֵΪ1����ʽ�ü��ǰ���״̬��Ϊ0��ʾ�ü��ǵ���״̬��
					�����λ��ʼ����λ���α�ʾ���°������Ϸ����·��������ҷ�����Ծ�������������ʼ����
*/
	if(!(m_LastKeyState&(1<<6))&&(KeyState&(1<<6)))
	{//�ϴ�û���¿�ʼ������ΰ����ˣ���ʼ��Ϸ
		m_pGame->Start();
		printf("start!\n");
	}

	if(!(KeyState&0xf)&&(m_LastKeyState&0xf))
	{//�ϴ��з���������£����û�У���ֹͣ�ƶ�
		m_pGame->Move(0,false);
	}
	else
	{
		bool Acc=(KeyState&(1<<5))!=0;//���˷������������ƶ�
		bool AccChanged=(KeyState&(1<<5))!=(m_LastKeyState&(1<<5));//���ټ���״̬���ϴβ�ͬ�����ʾ����״̬�иı�
		if((KeyState&(1<<0))&&(!(m_LastKeyState&(1<<0))||AccChanged))
		{//��ΰ��������ϼ������ϴ�û���»��߼���״̬�ı䣬�������ƶ�
			m_pGame->Move(1,Acc);
		}
		else if((KeyState&(1<<1))&&(!(m_LastKeyState&(1<<1))||AccChanged))
		{//��ΰ��������¼������ϴ�û���»��߼���״̬�ı䣬�������ƶ�
			m_pGame->Move(2,Acc);
		}
		else if((KeyState&(1<<2))&&(!(m_LastKeyState&(1<<2))||AccChanged))
		{//��ΰ���������������ϴ�û���»��߼���״̬�ı䣬�������ƶ�
			m_pGame->Move(3,Acc);
		}
		else if((KeyState&(1<<3))&&(!(m_LastKeyState&(1<<3))||AccChanged))
		{//��ΰ��������Ҽ������ϴ�û���»��߼���״̬�ı䣬�������ƶ�
			m_pGame->Move(4,Acc);
		}
	}

	if(!(m_LastKeyState&(1<<4))&&(KeyState&(1<<4)))
	{//�ϴ�û������Ծ������ΰ����ˣ�����Ծһ��
		m_pGame->Jump();
	}

	if(!(m_LastKeyState&(1<<5))&&(KeyState&(1<<5)))
	{//�ϴ�û���·��������ΰ����ˣ�����һ��
		m_pGame->Fire();
	}

	m_LastKeyState=KeyState;
}

void CControl::SetGame(CGame *Game)
{
/*
	������Ϸ����
	������
		[i]Game		��Ҫ��CControl���Ƶ�CGame����
*/
	m_pGame=Game;
}

CControl::CControl()
{
	m_LastKeyState=0;//�ʼʱû���κμ�����
	printf("CControl init\n");
}
