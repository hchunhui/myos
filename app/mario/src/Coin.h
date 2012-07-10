#ifndef _COIN_H_FILE_INCLUDED_

#define _COIN_H_FILE_INCLUDED_

#include "Object.h"

class CCoin:public CObject
{
public:
	CCoin(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Attack(CObject * Other,int Mode);
	virtual bool Block(CObject * Other);
	virtual void Clock();
	void ThrowUp();
private:
	int m_OriPos;//金币原始的位置，以便被顶动后还原
	int m_Rotate;//金币的旋转状态。取值为3~5。为0表示不旋转。
	bool m_RotateThin;//当前的旋转方向。true:由粗变细 false:由细变粗
};

#endif
