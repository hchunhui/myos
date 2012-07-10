/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Object.h"

CObject::CObject(CGame * Game,int Tp,int X,int Y,int W,int H,int Ly)
{
	m_Game=Game;
	Type=Tp;
	XPos=X;
	YPos=Y;
	Width=W;
	Height=H;
	Layer=Ly;
	//��ʼΪ��ֹ״̬
	m_HorzSpeed=0;
	m_VertSpeed=0;
	//��ʼΪ�״��
	LiveState=1;
}

void CObject::Clock()
{
}

bool CObject::Block(CObject * Other)
{
/*
	���ƶ������������赲��
	������
		[i]Other		�赲�Լ��Ķ������ΪNULL�����ʾ�ܵ���ͼ�߽��赲��
	����ֵ��
		true			�����赲��ֹͣ�ƶ���
		false			������赲�������ƶ���
*/
	if(1!=LiveState)return false;//�������������岻���赲

	if(Other)
	{
		if(5==Other->Type)return false;//��ҡ�Ģ���Ȳ����赲����
		return true;//�ܱ����������赲
	}
	else
		return false;//���ܵ�ͼ�߽��赲
}

void CObject::Bump(CObject * Other,int Mode,bool Volun)
{
/*
	��������������ײ��
	������
		[i]Other	��֮��ײ����һ������
		[i]Mode		��ײ��ʽ��ȡֵΪ��
					1		�����Է�������
					2		�����Է��ײ���
					3		�����Է����档
		[i]Volun	ȡֵΪ��true:�Լ��������Է���false:�Լ����Է�������
*/
}

void CObject::Attack(CObject * Other,int Mode)
{
/*
	�⵽��������Ĺ�����
	������
		[i]Other	���𹥻��Ķ���
		[i]Mode		������ʽ��ȡֵΪ��
					1		�Ӵ�ʽ�����������������ǽӴ�����ɱ�����ǣ�����ʹ�����޵�����������ֽӴ���ɱ�����֣��ӵ������ֽӴ���ɱ�����ֵȡ�
					2		��̤ʽ���������������ǲ�̤���֡�
					3		ͷ��ʽ�����������Ƕ���ש�顢ש�鶥�����ֵȡ�
*/
}
