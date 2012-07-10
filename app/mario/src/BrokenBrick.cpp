/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "BrokenBrick.h"
#include "ImgData.h"
#include "Game.h"
#include "Mario.h"

CBrokenBrick::CBrokenBrick(CGame * Game,int x, int y,int HorzSpeed,int VertSpeed):CObject(Game,2,x,y,8,8,1)//��ש��ʾ�ڱ�����֮ǰ
{
	m_HorzSpeed=HorzSpeed;
	m_VertSpeed=VertSpeed;
	LiveState=2;//��ש��������������������
}

const int * CBrokenBrick::GetImage(bool * HInv,bool * VInv)
{
	*HInv=false;
	*VInv=false;
	return BrokenBrickImage;
}

void CBrokenBrick::Clock()
{
	//�����������ٶ�
	m_VertSpeed+=2;//�������ٶȹ̶�Ϊ2
	if(m_VertSpeed>20)m_VertSpeed=20;//�����ٶ����Ϊ20

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
	}
}
