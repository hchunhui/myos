#ifndef _QUESTION_H_FILE_INCLUDED_

#define _QUESTION_H_FILE_INCLUDED_

#include "Object.h"

class CQuestion:public CObject
{
public:
	CQuestion(CGame * Game,int x, int y,int Content);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	virtual bool Block(CObject * Other);
	virtual void Clock();
	void MoveUp();
private:
	int m_OriPos;//问号原始的位置，以便被顶动后还原
	int m_TimeCount;//被顶动后并不立即还原，而是要等该计时器到一定的值再还原
	int m_Content;//问号的内藏物。取值为：
					//0		没有东西
					//-1	蘑菇
					//正数	金币数
};

#endif
