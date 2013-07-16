#ifndef _FLOWER_H_FILE_INCLUDED_

#define _FLOWER_H_FILE_INCLUDED_

#include "Object.h"

class CFlower:public CObject
{
public:
	CFlower(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual bool Block(CObject * Other);
private:
	int m_OriPos;//����ԭʼ��λ�ã����ж��Ƿ���ȫ����Ϊ0���ʾ�Ѿ���ȫ�����ˡ�
	int m_Action;//��ǰ�Ķ���״̬��ȡֵ0~1
};

#endif
