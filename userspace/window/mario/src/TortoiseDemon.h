#ifndef _TORTOISEDEMON_H_FILE_INCLUDED_

#define _TORTOISEDEMON_H_FILE_INCLUDED_

#include "Object.h"

class CTortoiseDemon:public CObject
{
public:
	CTortoiseDemon(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	virtual bool Block(CObject * Other);
	virtual void Attack(CObject * Other,int Mode);
private:
	int m_Action;//��ǰ�Ķ���״̬��ȡֵ0~2
	int m_ActionTimeCount;//����ÿ��ʱ�����ڶ��ı䶯��������Ҫ�ȸ������ﵽһ��ֵʱ�Ÿı䡣
	bool m_ToRight;//��ǰ�����ķ���true:�� false:��
	bool m_MarioBump;//����ڹ��ʱ���Ƿ�ֻҪ�������������˶�
};

#endif
