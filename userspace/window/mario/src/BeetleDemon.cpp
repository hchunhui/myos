/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "BeetleDemon.h"
#include "ImgData.h"
#include "Game.h"

CBeetleDemon::CBeetleDemon(CGame * Game,int x, int y):CObject(Game,3,x,y,16,16,0)
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-3;//���ָճ���ʱ�����ƶ�
	m_ToRight=false;//�������
}

const int * CBeetleDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//�����ұ���Ҫˮƽ��ת��ʾ
	return BeetleDemonImage[m_Action];
}

void CBeetleDemon::Clock()
{
	if(2==m_Action)
	{//�Ѿ�����˼׳��
		if(1==LiveState&&0==m_HorzSpeed)
		{//�ǻ�ļ׳����û�б��߶������һ��ʱ����ٻָ��ɼ׳�
			m_ActionTimeCount++;
			if(100<=m_ActionTimeCount)
			{
				m_Action=0;
				m_ActionTimeCount=0;
				m_HorzSpeed=-2;
				m_ToRight=false;
			}
		}
	}
	else
	{
		m_ActionTimeCount++;
		if(5<=m_ActionTimeCount)
		{
			m_Action=!m_Action;
			m_ActionTimeCount=0;
		}
	}

	//���ۺ�ʱ�����������ٶ�
	m_VertSpeed+=2;//�������ٶȹ̶�Ϊ2
	if(m_VertSpeed>20)m_VertSpeed=20;//�����ٶ����Ϊ20

	if(m_HorzSpeed||m_VertSpeed)
	{//���ٶ���Ҫ�ƶ�
		int MoveResult=m_Game->Move(this,m_HorzSpeed,m_VertSpeed);
		if(MoveResult&1)
		{//ˮƽ�����ܵ��赲����ı��ƶ�����
			if(2==m_Action)
			{//�׳��ײ��ǽҪ��������
				m_Game->PlaySound(CSoundMan::BLOCK);
			}
			m_HorzSpeed=-m_HorzSpeed;
			m_ToRight=!m_ToRight;
		}
		if(MoveResult&2)
		{//��ֱ�����ܵ��赲������ֱ�ٶȼ�Ϊ0
			m_VertSpeed=0;
		}
	}
}

void CBeetleDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//ֻ�л����ֲ��ܱ�����
	switch(Mode)
	{
	case 1://�ܵ��ӵ������������׳�ǵĹ���
		if(4==Other->Type)return;//�����ӵ��Ĺ���
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		Layer=1;//��������������һ����ʾ�ڱ���֮ǰ
		break;
	case 2://������ȵ�
		if(2!=m_Action||2==m_Action&&m_HorzSpeed)
		{//�ǻ�׳棬�����Ѿ��������˶��ļ׳�ǣ����ɾ�ֹ�ļ׳��
			m_Game->PlaySound(CSoundMan::ATTACKDEMON);
			m_Action=2;
			m_VertSpeed=0;
			m_HorzSpeed=0;
			m_ActionTimeCount=0;
			m_MarioBump=false;
		}
		break;
	default:
		if(2==Other->Type)
		{//��ש�鶥��
			m_Game->PlaySound(CSoundMan::ATTACKDEMON);
			m_Action=2;
			m_VertSpeed=-4;
			m_HorzSpeed=0;
			m_ActionTimeCount=0;
			m_MarioBump=true;//�´α���������ʱֱ���˶������õ�����
		}
	}
}

void CBeetleDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;

	if(2==m_Action)
	{//�ѱ�ɼ׳��
		if(0==m_HorzSpeed)
		{//�Ǿ�ֹ�ļ׳��
			if(1==Other->Type)
			{//������������������һ�α��ȵ����㣩����Ҫ��ʼ�˶�
				if(m_MarioBump)
				{
					m_Game->PlaySound(CSoundMan::ATTACKDEMON);
					if(Other->XPos>XPos+8)
					{//�����׳���Ҳ࣬�������˶�
						m_HorzSpeed=-10;
					}
					else
					{//�����׳����࣬�������˶�
						m_HorzSpeed=10;
					}
				}
				else
				{
					m_MarioBump=true;
				}
			}
		}
		else if(1==LiveState&&(3==Mode||1==Mode)&&(1==Other->Type||3==Other->Type))
		{//�Ǳ��߶��Ļ�׳�ǣ����ԴӲ�������湥���������������
			Other->Attack(this,1);
		}
	}
	else if(1==Other->Type&&(3==Mode||1==Mode))
	{//�ǻ�׳棬ֻ�ܴӲ�������湥������
		Other->Attack(this,1);
	}
}

bool CBeetleDemon::Block(CObject * Other)
{
	if(1!=LiveState)return false;//�������������岻���赲

	if(Other)
	{
		if(5==Other->Type)return false;//��ҡ�Ģ���Ȳ����赲����
		if(2==m_Action&&m_HorzSpeed&&3==Other->Type)return false;//�ѱ��߶��ļ׳�ǲ����������ֵ��赲
		if(4==Other->Type)return false;//�����ӵ��赲
		return true;//�ܱ����������赲
	}
	else
		return false;//���ܵ�ͼ�߽��赲
}
