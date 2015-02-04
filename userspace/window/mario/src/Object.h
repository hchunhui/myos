#ifndef _OBJECT_H_FILE_INCLUDED_

#define _OBJECT_H_FILE_INCLUDED_

class CGame;

class CObject
{
public:
	int Type;//�ö����Ǻ��ֽ�ɫ�����塣ȡֵΪ��
				//1		�������
				//2		���������塣��ש�顢ˮ�ܵȡ�
				//3		���֡�
				//4		�ӵ���
				//5		��ҡ�Ģ���ȿɱ��Ե����塣
	int LiveState;//�״̬��ȡֵΪ��
				//1		����
				//2		��������
				//3		������
	int XPos,YPos;//�ö������Ͻ��ڵ�ͼ�ϵ�λ�á�
	int Width,Height;//����Ŀ�Ⱥ͸߶ȡ�
	int Layer;//�ö����ͼ������ʾʱ�Ĳ�Ρ�ȡֵΪ��
				//0		�����㡣
				//-1	������֮��
				//1		������֮ǰ��
	virtual const int * GetImage(bool * HInv,bool * VInv)=0;
	/*
		ȡ�øö���ǰ��ͼ�����ݡ�
		������
			[o]HInv		�Ƿ����ҷ�ת��
			[o]VInv		�Ƿ����·�ת��
		����ֵ��
			����ͼ������ָ�롣��ָ��ָ��һ����ά���飬����Ĵ�С������Ĵ�Сһ�¡�ÿ��Ԫ�ر�ʾһ�����ء�
	*/
	virtual void Clock();
	/*
		ִ��һ��ʱ���źŶ�����
	*/
	virtual bool Block(CObject * Other);
	/*
		���ƶ������������赲��
		������
			[i]Other	�赲�Լ��Ķ������ΪNULL�����ʾ�ܵ���ͼ�߽��赲��
		����ֵ��
			true		�����赲��ֹͣ�ƶ���
			false		������赲�������ƶ���
	*/
	virtual void Bump(CObject * Other,int Mode,bool Volun);
	/*
		��������������ײ��
		������
			[i]Other	��֮��ײ����һ������
			[i]Mode		��ײ��ʽ��ȡֵΪ��
						1		�����Է�������
						2		�����Է��ײ���
						3		�����Է����档
			[i]Volun	ȡֵΪ��true:�Լ��������Է���false:�Լ����Է�������
	*/
	virtual void Attack(CObject * Other,int Mode);
	/*
		�⵽��������Ĺ�����
		������
			[i]Other	���𹥻��Ķ���
			[i]Mode		������ʽ��ȡֵΪ��
						1		�Ӵ�ʽ�����������������ǽӴ�����ɱ�����ǣ�����ʹ�����޵�����������ֽӴ���ɱ�����֣��ӵ������ֽӴ���ɱ�����ֵȡ�
						2		��̤ʽ���������������ǲ�̤���֡�
						3		ͷ��ʽ�����������Ƕ���ש�顢ש�鶥�����ֵȡ�
	*/
	virtual ~CObject() {};
	CObject(CGame * Game,int Tp,int X,int Y,int W,int H,int Ly);
protected:
	CGame * m_Game;
	int m_HorzSpeed;//��ǰˮƽ�˶��ٶȣ�����Ϊ����
	int m_VertSpeed;//��ǰ��ֱ�˶��ٶȣ�����Ϊ����
};

#endif
