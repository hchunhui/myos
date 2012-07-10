#ifndef _FLYTORTOISEDEMON_H_FILE_INCLUDED_

#define _FLYTORTOISEDEMON_H_FILE_INCLUDED_

#include "Object.h"

class CFlyTortoiseDemon:public CObject
{
public:
	CFlyTortoiseDemon(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
private:
	int m_Action;//��ǰ�Ķ���״̬��ȡֵ0~1
	int m_ActionTimeCount;//����ÿ��ʱ�����ڶ��ı䶯��������Ҫ�ȸ������ﵽһ��ֵʱ�Ÿı䡣
	bool m_ToRight;//��ǰ�����ķ���true:�� false:��
};

#endif
