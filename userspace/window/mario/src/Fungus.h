#ifndef _FUNGUS_H_FILE_INCLUDED_

#define _FUNGUS_H_FILE_INCLUDED_

#include "Object.h"

class CFungus:public CObject
{
public:
	CFungus(CGame * Game,int x, int y);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Clock();
	virtual void Attack(CObject * Other,int Mode);
	virtual bool Block(CObject * Other);
private:
	int m_OriPos;//Ģ��ԭʼ��λ�ã����ж��Ƿ���ȫ����Ϊ0���ʾ�Ѿ���ȫ�����ˡ�
};

#endif
