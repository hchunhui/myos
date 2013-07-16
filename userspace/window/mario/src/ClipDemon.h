#ifndef _CLIPDEMON_H_FILE_INCLUDED_

#define _CLIPDEMON_H_FILE_INCLUDED_

#include "Object.h"

class CClipDemon:public CObject
{
public:
	CClipDemon(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual bool Block(CObject * Other);
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
private:
	int m_Action;//��ǰ�Ķ���״̬��ȡֵ0~1
	int m_ActionTimeCount;//����ÿ��ʱ�����ڶ��ı䶯��������Ҫ�ȸ������ﵽһ��ֵʱ�Ÿı䡣
	int m_UpDownTimeCount;//����ÿ��ʱ�����ڶ����������ȥ������Ҫ�ȸ������ﵽһ��ֵʱ�ų������ȥ��
	int m_Top;//�����������������λ��
};

#endif
