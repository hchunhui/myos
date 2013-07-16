#ifndef _BRICK_H_FILE_INCLUDED_

#define _BRICK_H_FILE_INCLUDED_

#include "Object.h"

class CBrick:public CObject
{
public:
	CBrick(CGame * Game,int x, int y,int Content);
	virtual const int * GetImage(bool * HInv,bool * VInv);
	virtual void Attack(CObject * Other,int Mode);
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	virtual bool Block(CObject * Other);
	virtual void Clock();
private:
	int m_OriPos;//ש��ԭʼ��λ�ã��Ա㱻������ԭ
	int m_TimeCount;//�������󲢲�������ԭ������Ҫ�ȸü�ʱ����һ����ֵ�ٻ�ԭ
	int m_Content;//ש����ڲ��ȡֵΪ��
					//0		û�ж���
					//-1	Ģ��
					//-2	����
					//����	�����
};

#endif
