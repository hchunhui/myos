/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "Bullet.h"
#include "ImgData.h"
#include "Game.h"

CBullet::CBullet(CGame * Game,int x, int y,int ToLeft):CObject(Game,4,x,y,8,8,0)
{
/*
	������
		[i]ToLeft	�ӵ��ķ���true:���� false:����
*/
	if(ToLeft)
		m_HorzSpeed=-10;
	else
		m_HorzSpeed=10;
	m_Action=0;
}

const int * CBullet::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return BulletImage[m_Action];
}

void CBullet::Clock()
{
	//�ı䵱ǰ�Ķ���״̬
	m_Action++;
	if(4==m_Action)m_Action=0;

	//���ۺ�ʱ�����������ٶ�
	m_VertSpeed+=2;//�������ٶȹ̶�Ϊ2
	if(m_VertSpeed>20)m_VertSpeed=20;//�����ٶ����Ϊ20

	int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
	if(MoveResult&1)
	{//ˮƽ�����ܵ��赲������ʧ
		LiveState=3;
	}
	if(MoveResult&2)
	{//��ֱ�����ܵ��赲
		if(m_VertSpeed>0)
			m_VertSpeed=-8;//����ʱ�ܵ��赲�������ϵ���
		else
			LiveState=3;//����ʱ�ܵ��赲������ʧ
	}
}

void CBullet::Bump(CObject * Other,int Mode,bool Volun)
{
	if(3==Other->Type&&1==Other->LiveState)
	{//���������֣������乥��
		Other->Attack(this,1);
		LiveState=3;
	}
}

