#ifndef _GAME_H_FILE_INCLUDED_

#define _GAME_H_FILE_INCLUDED_

#include "Object.h"
#include "Mario.h"
#include "SoundMan.h"

#define OBJ_LIST_MAX 10000
extern int g_FlushAction;

class CGame
{
public:
	void MoveMap(int Offset);
	void Clock(void);
	CGame();
	void Start();
	CObject ** GetAllObject();
	void Move(int Dir, bool Acc);
	int Move(CObject * Obj,int Horz,int Vert);
	void Jump(void);
	void Fire(void);
	void AddObj(CObject * Obj);
	void SetSound(CSoundMan * Obj);
	void PlaySound(CSoundMan::SOUNDNUM Num);
	void PlayBackMusic(int Num);
private:
	void LoadMapData();
	void InsertObject(int X,int Y,int Type);
	CMario * m_Mario;//��������
	int m_CurLevel;//��ǰ�ǵڼ���
	int * m_MapData;//��ǰ�ؿ���������ʼ��ַ
	int m_MapPos;//��ǰ��ͼ��߽���������ͼ�ĵڼ�������
	int m_NextMap;//��һ����Ҫ��ȡ�ĵ�ͼ�����к�
	CSoundMan * m_SoundMan;//����������
	
	CObject *m_Object[OBJ_LIST_MAX];//���еĽ�ɫ�������б��������ǣ�
	int m_ObjectCount;
	void m_Object_insert(CObject *pObj);
	void m_Object_erase(CObject **pObj);
	void m_Object_clear();
};

#endif
