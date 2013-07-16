#ifndef _GRAPH_H_FILE_INCLUDED_

#define _GRAPH_H_FILE_INCLUDED_

#include "cross.h"

#ifndef MYOS
class CGraph
{
public:
	void UnInit();
	void Init(HWND hWnd);
	void Refresh();
	int ** GetImageBuf();
	HDC GetMemDC();
	void ShowText(int x,int y,const char * Text,int Colour);
private:
	HWND m_hWnd;//�ڸô�������ʾͼ��
	HDC m_MemDC;//ͼ���Ȼ��Ƶ����ڴ�DC������ʾ������
	HGDIOBJ m_OldBitmap;//�ڴ�DCԭ�е�λͼ
	int * m_BitData[256];//�ڴ�DC��ͼ������
};
#else

class CGraph
{
public:
	void UnInit();
	void Init(WHandle hWnd);
	void Refresh();
	int ** GetImageBuf();
	int GetMemDC();
	void ShowText(int x,int y,const char * Text,int Colour);
private:
	WHandle m_hWnd;//�ڸô�������ʾͼ��
	int m_MemDC;//ͼ���Ȼ��Ƶ����ڴ�DC������ʾ������
	int * m_BitData[256];//�ڴ�DC��ͼ������
};

#endif

#endif
