/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "TortoiseDemon.h"
#include "ImgData.h"
#include "Game.h"

CTortoiseDemon::CTortoiseDemon(CGame * Game,int x, int y):CObject(Game,3,x,y+8,16,24,0)//�ڹ��ڵ�ͼ�ϵ�λ�ñ�ʵ��λ�ø���8������
{
	m_Action=0;
	m_ActionTimeCount=0;
	m_HorzSpeed=-2;//���ָճ���ʱ�����ƶ�
	m_ToRight=false;//�������
}

const int * CTortoiseDemon::GetImage(bool * HInv,bool * VInv)
{
	*VInv=false;
	*HInv=m_ToRight;//�����ұ���Ҫˮƽ��ת��ʾ
	return TortoiseDemonImage[m_Action];
}

void CTortoiseDemon::Clock()
{
	if(2==m_Action)
	{//�Ѿ�������ڹ��
		if(1==LiveState&&0==m_HorzSpeed)
		{//�ǻ���ڹ����û�б��߶������һ��ʱ����ٻָ����ڹ�
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
			{//�ڹ��ײ��ǽҪ��������
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

void CTortoiseDemon::Attack(CObject * Other,int Mode)
{
	if(1!=LiveState)return;//ֻ�л����ֲ��ܱ�����
	switch(Mode)
	{
	case 1://�ܵ��ӵ�������������ڹ�ǵĹ���
		m_Game->PlaySound(CSoundMan::KILLDEMON);
		m_Action=2;
		LiveState=2;
		m_VertSpeed=-10;
		m_HorzSpeed=2;
		Layer=1;//��������������һ����ʾ�ڱ���֮ǰ
		break;
	case 2://������ȵ�
		if(2!=m_Action||2==m_Action&&m_HorzSpeed)
		{//�ǻ��ڹ꣬�����Ѿ��������˶����ڹ�ǣ����ɾ�ֹ���ڹ��
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

void CTortoiseDemon::Bump(CObject * Other,int Mode,bool Volun)
{
	if(1!=LiveState)return;

	if(2==m_Action)
	{//�ѱ���ڹ��
		if(0==m_HorzSpeed)
		{//�Ǿ�ֹ���ڹ��
			if(1==Other->Type)
			{//������������������һ�α��ȵ����㣩����Ҫ��ʼ�˶�
				if(m_MarioBump)
				{
					m_Game->PlaySound(CSoundMan::ATTACKDEMON);
					if(Other->XPos>XPos+8)
					{//�����ڹ���Ҳ࣬�������˶�
						m_HorzSpeed=-10;
					}
					else
					{//�����ڹ����࣬�������˶�
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
		{//�Ǳ��߶��Ļ��ڹ�ǣ����ԴӲ�������湥���������������
			Other->Attack(this,1);
		}
	}
	else if(1==Other->Type&&(3==Mode||1==Mode))
	{//�ǻ��ڹֻ꣬�ܴӲ�������湥������
		Other->Attack(this,1);
	}
}

bool CTortoiseDemon::Block(CObject * Other)
{
	if(1!=LiveState)return false;//�������������岻���赲

	if(Other)
	{
		if(5==Other->Type)return false;//��ҡ�Ģ���Ȳ����赲����
		if(2==m_Action&&m_HorzSpeed&&3==Other->Type)return false;//�ѱ��߶����ڹ�ǲ����������ֵ��赲
		return true;//�ܱ����������赲
	}
	else
		return false;//���ܵ�ͼ�߽��赲
}
