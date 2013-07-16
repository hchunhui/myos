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
	int m_State;//�����״̬��ȡֵΪ��
				//1		С����
				//2		������
				//3		�����򣨿ɷ��ӵ�����
	int m_Action;//��ǰ�Ķ�����ȡֵΪ��
				//0		վ��
				//1		���ߵ�һ��
				//2		���ߵڶ���
				//3		���ߵ�����
				//4		����
	bool m_ToLeft;//��ǰ�����ķ���true:�� false:��
	int m_MoveDir;//��ǰ�����ĸ������ƶ���ȡֵΪ��
				//0		δ�ƶ�
				//1		��
				//2		��
				//3		����ң���m_ToLeft��������
	bool m_Acc;//�Ƿ�����ƶ�����m_MoveDirΪ0ʱ�ò����������á�
	bool m_OnLand;//˫���Ƿ����ػ�ȵ��������Ծ����Ƿ������߻�������
	int m_ChangeState;//�Ƿ�ı�״̬��ȡֵΪ��
				//0		���ı�
				//1		��С��󣬻��Ϊ�ɷ��ӵ�
				//-1	��С��������
	int m_StarTime;//���ǵ�ʣ����Чʱ��
	int m_HideTime;//�������Чʱ��
};

#endif
