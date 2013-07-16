#ifndef _MARIO_H_FILE_INCLUDED_

#define _MARIO_H_FILE_INCLUDED_

#include "Object.h"

class CMario:public CObject
{
public:
	CMario(CGame * Game,int x,int y,int State);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	void Jump(void);
	void Move(int Dir, bool Acc);
	void Fire(void);
	void ResetPos(int x,int y);
	virtual void Clock();
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	virtual bool Block(CObject * Other);
	virtual void Attack(CObject * Other,int Mode);
	bool IsBig();
	void AddPower();
	void AddStar();
private:
	int m_State;//玛莉的状态。取值为：
				//1		小玛莉。
				//2		大玛莉。
				//3		大玛莉（可发子弹）。
	int m_Action;//当前的动作。取值为：
				//0		站立
				//1		行走第一步
				//2		行走第二步
				//3		行走第三步
				//4		跳起
	bool m_ToLeft;//当前面向哪方。true:左 false:右
	int m_MoveDir;//当前正向哪个方向移动。取值为：
				//0		未移动
				//1		上
				//2		下
				//3		左或右，由m_ToLeft决定方向
	bool m_Acc;//是否加速移动。当m_MoveDir为0时该参数不起作用。
	bool m_OnLand;//双脚是否著地或踩到东西，以决定是否能行走或起跳。
	int m_ChangeState;//是否改变状态。取值为：
				//0		不改变
				//1		由小变大，或变为可发子弹
				//-1	变小，或死亡
	int m_StarTime;//五星的剩余有效时间
	int m_HideTime;//隐身的有效时间
};

#endif
