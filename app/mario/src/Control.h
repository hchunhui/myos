#ifndef _CONTROL_H_FILE_INCLUDED_

#define _CONTROL_H_FILE_INCLUDED_

#include "GraphMan.h"
#include "Game.h"

class CControl
{
public:
	CControl();
	void SetGame(CGame * Game);
	void KeyDown(int KeyChange);
	void KeyUp(int KeyChange);
	void KeyChanged(int KeyState);
	void SetGraph(CGraphMan * Graph);
	void Clock();
private:
	CGraphMan * m_pGraphMan;
	CGame * m_pGame;
	int m_LastKeyState;//上次的按键状态
	bool m_Acc;
};

#endif
