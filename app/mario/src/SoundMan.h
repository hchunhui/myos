#ifndef _SOUNDMAN_H_FILE_INCLUDED_

#define _SOUNDMAN_H_FILE_INCLUDED_

#include "Sound.h"

extern const char * BackMusic_Sound[2];
extern int BackMusic_Len[2];
extern const char * AttackDemon_Sound;
extern int AttackDemon_Len;
extern const char * AttackMario_Sound;
extern int AttackMario_Len;
extern const char * Block_Sound;
extern int Block_Len;
extern const char * Bullet_Sound;
extern int Bullet_Len;
extern const char * Coin_Sound;
extern int Coin_Len;
extern const char * Death_Sound;
extern int Death_Len;
extern const char * EatFlower_Sound;
extern int EatFlower_Len;
extern const char * FlowerRise_Sound;
extern int FlowerRise_Len;
extern const char * Jump_Sound;
extern int Jump_Len;
extern const char * KillDemon_Sound;
extern int KillDemon_Len;
extern const char * BrickBroken_Sound;
extern int BrickBroken_Len;

class CSoundMan
{
public:
	enum SOUNDNUM
	{
		ATTACKDEMON,
		ATTACKMARIO,
		BLOCK,
		BULLET,
		COIN,
		DEATH,
		EATFLOWER,
		FLOWERRISE,
		JUMP,
		KILLDEMON,
		BRICKBROKEN,
	};
	CSoundMan();
	void SetSound(CSound * Obj);
	void PlayBackMusic(int Num);
	void PlaySound(SOUNDNUM Num);
private:
	void * m_BackMusic;//±≥æ∞“Ù¿÷
	CSound * m_pSound;
};

#endif
