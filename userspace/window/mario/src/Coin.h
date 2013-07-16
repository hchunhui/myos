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
	int m_OriPos;//���ԭʼ��λ�ã��Ա㱻������ԭ
	int m_Rotate;//��ҵ���ת״̬��ȡֵΪ3~5��Ϊ0��ʾ����ת��
	bool m_RotateThin;//��ǰ����ת����true:�ɴֱ�ϸ false:��ϸ���
};

#endif
