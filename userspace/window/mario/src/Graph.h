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
	HWND m_hWnd;//在该窗体上显示图像
	HDC m_MemDC;//图像先绘制到该内存DC，再显示到窗体
	HGDIOBJ m_OldBitmap;//内存DC原有的位图
	int * m_BitData[256];//内存DC的图像数据
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
	WHandle m_hWnd;//在该窗体上显示图像
	int m_MemDC;//图像先绘制到该内存DC，再显示到窗体
	int * m_BitData[256];//内存DC的图像数据
};

#endif

#endif
