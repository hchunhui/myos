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
	CMario * m_Mario;//主角玛莉
	int m_CurLevel;//当前是第几关
	int * m_MapData;//当前关卡的数据起始地址
	int m_MapPos;//当前地图左边界是整幅地图的第几个像素
	int m_NextMap;//下一个将要读取的地图数据列号
	CSoundMan * m_SoundMan;//声音管理器
	
	CObject *m_Object[OBJ_LIST_MAX];//所有的角色和物体列表（包括主角）
	int m_ObjectCount;
	void m_Object_insert(CObject *pObj);
	void m_Object_erase(CObject **pObj);
	void m_Object_clear();
};

#endif
