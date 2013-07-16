/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/

#include "SoundMan.h"
#include "cross.h"

//��������������
const char * BackMusic_Sound[2];//���ֱ�������
int BackMusic_Len[2];
const char * AttackDemon_Sound;//���ֱ��ȵ�
int AttackDemon_Len;
const char * AttackMario_Sound;//���򱻹���
int AttackMario_Len;
const char * Block_Sound;//����ײ��ǽ
int Block_Len;
const char * Bullet_Sound;//�����ӵ�
int Bullet_Len;
const char * Coin_Sound;//�Ե����
int Coin_Len;
const char * Death_Sound;//��������
int Death_Len;
const char * EatFlower_Sound;//�Ե�����Ģ����
int EatFlower_Len;
const char * FlowerRise_Sound;//����Ģ��������
int FlowerRise_Len;
const char * Jump_Sound;//��������
int Jump_Len;
const char * KillDemon_Sound;//�ӵ���������
int KillDemon_Len;
const char * BrickBroken_Sound;//ש������
int BrickBroken_Len;

CSoundMan::CSoundMan()
{
	m_BackMusic=NULL;
}

void CSoundMan::SetSound(CSound * Obj)
{
/*
	�����������Ŷ���
	������
		[i]Obj		Ҫʹ�õ�CSound����CSoundMan��ͨ���ö��󲥷�������
*/
	m_pSound=Obj;
}

void CSoundMan::PlayBackMusic(int Num)
{
/*
	���š��ı��ֹͣ�������֡�
	������
		[i]Num		Ҫ���ŵı������ֱ�š�0��ʾֹͣ�������֡�
*/
	if(m_BackMusic)m_pSound->DeleteChannel(m_BackMusic);
	if(0==Num)
	{
		m_BackMusic=NULL;
		return;
	}
	m_BackMusic=m_pSound->AddChannel(BackMusic_Sound[Num-1],BackMusic_Len[Num-1],true);
}

void CSoundMan::PlaySound(CSoundMan::SOUNDNUM Num)
{
/*
	������Ч��
	������
		[i]Num		Ҫ���ŵ���Ч��
*/
	switch(Num)
	{
	case ATTACKDEMON:
		m_pSound->AddChannel(AttackDemon_Sound,AttackDemon_Len,false);
		break;
	case ATTACKMARIO:
		m_pSound->AddChannel(AttackMario_Sound,AttackMario_Len,false);
		break;
	case BLOCK:
		m_pSound->AddChannel(Block_Sound,Block_Len,false);
		break;
	case BULLET:
		m_pSound->AddChannel(Bullet_Sound,Bullet_Len,false);
		break;
	case COIN:
		m_pSound->AddChannel(Coin_Sound,Coin_Len,false);
		break;
	case DEATH:
		m_pSound->AddChannel(Death_Sound,Death_Len,false);
		break;
	case EATFLOWER:
		m_pSound->AddChannel(EatFlower_Sound,EatFlower_Len,false);
		break;
	case FLOWERRISE:
		m_pSound->AddChannel(FlowerRise_Sound,FlowerRise_Len,false);
		break;
	case JUMP:
		m_pSound->AddChannel(Jump_Sound,Jump_Len,false);
		break;
	case KILLDEMON:
		m_pSound->AddChannel(KillDemon_Sound,KillDemon_Len,false);
		break;
	case BRICKBROKEN:
		m_pSound->AddChannel(BrickBroken_Sound,BrickBroken_Len,false);
		break;
	}
}
