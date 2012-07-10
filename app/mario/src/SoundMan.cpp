/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/

#include "SoundMan.h"
#include "cross.h"

//各种声音和音乐
const char * BackMusic_Sound[2];//两种背景音乐
int BackMusic_Len[2];
const char * AttackDemon_Sound;//妖怪被踩到
int AttackDemon_Len;
const char * AttackMario_Sound;//玛莉被攻击
int AttackMario_Len;
const char * Block_Sound;//玛莉撞到墙
int Block_Len;
const char * Bullet_Sound;//发射子弹
int Bullet_Len;
const char * Coin_Sound;//吃到金币
int Coin_Len;
const char * Death_Sound;//玛莉死亡
int Death_Len;
const char * EatFlower_Sound;//吃到花、蘑菇等
int EatFlower_Len;
const char * FlowerRise_Sound;//花、蘑菇等升起
int FlowerRise_Len;
const char * Jump_Sound;//玛莉跳起
int Jump_Len;
const char * KillDemon_Sound;//子弹打死妖怪
int KillDemon_Len;
const char * BrickBroken_Sound;//砖块碎裂
int BrickBroken_Len;

CSoundMan::CSoundMan()
{
	m_BackMusic=NULL;
}

void CSoundMan::SetSound(CSound * Obj)
{
/*
	设置声音播放对象。
	参数：
		[i]Obj		要使用的CSound对象。CSoundMan将通过该对象播放声音。
*/
	m_pSound=Obj;
}

void CSoundMan::PlayBackMusic(int Num)
{
/*
	播放、改变或停止背景音乐。
	参数：
		[i]Num		要播放的背景音乐编号。0表示停止背景音乐。
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
	播放音效。
	参数：
		[i]Num		要播放的音效。
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
