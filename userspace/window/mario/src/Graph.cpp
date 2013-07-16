/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/
#include "cross.h"
#include "Graph.h"

#ifndef MYOS
HDC CGraph::GetMemDC()
{
	return m_MemDC;
}

int ** CGraph::GetImageBuf()
{
/*
	���ͼ�񻺴�����ָ�롣
	����ֵ��
		���ص�ָ����ָ��һ��ָ�룬ÿһ��ָ��ָ��һ��ͼ�����ݡ�������ÿ�ĸ��ֽڱ�ʾһ�����ص㣬�ɵ͵����ֽ����α�ʾ���̺죬����ֽڲ��á�
*/
	return m_BitData;
}

void CGraph::Refresh()
{
/*
	���������е�ͼ������ˢ����ʾ����Ļ�ϡ�
*/
	RedrawWindow(m_hWnd,NULL,NULL,RDW_INVALIDATE|RDW_UPDATENOW);
}

void CGraph::Init(WHandle hWnd)
{
	m_hWnd=hWnd;
	HDC dc=GetDC(hWnd);
	m_MemDC=CreateCompatibleDC(dc);
	BITMAPINFO bi;
	memset(&bi,0,sizeof bi);
	bi.bmiHeader.biBitCount=32;
	bi.bmiHeader.biHeight=256;
	bi.bmiHeader.biPlanes=1;
	bi.bmiHeader.biSize=sizeof bi.bmiHeader;
	bi.bmiHeader.biWidth=288;
	HBITMAP bit=CreateDIBSection(dc,&bi,DIB_RGB_COLORS,reinterpret_cast<void**>(&m_BitData[255]),NULL,0);
	m_OldBitmap=SelectObject(m_MemDC,bit);
	ReleaseDC(hWnd,dc);
	int i;
	for(i=254;i>=0;i--)
	{
		m_BitData[i]=m_BitData[i+1]+288;
	}
}

void CGraph::UnInit()
{
	HGDIOBJ bit=SelectObject(m_MemDC,m_OldBitmap);
	DeleteObject(bit);
	DeleteDC(m_MemDC);
}

void CGraph::ShowText(int x,int y,const char * Text,int Colour)
{
/*
	��ʾ���֡�
	������
		[i]x,y		��ʾλ�á�
		[i]Text		Ҫ��ʾ���������ݡ�
		[i]Colour	���ֵ���ɫ���ֽ��ɵ͵������α�ʾ�����̡��졣
*/
	Colour=(Colour&0xff)<<16|(Colour&0xff00)|Colour>>16;//��Ϊ�졢�̡�����˳��
	SetTextColor(m_MemDC,Colour);
	SetBkMode(m_MemDC,TRANSPARENT);
	HGDIOBJ oldfont=SelectObject(m_MemDC,GetStockObject(SYSTEM_FIXED_FONT));
	TextOut(m_MemDC,x,y,Text,strlen(Text));
	SelectObject(m_MemDC,oldfont);
}

#else

extern DrawCanvas  _canv;
DrawCanvas * const canv = &_canv;
void w_refresh(WHandle hwnd, int x, int y ,int w, int h);

int CGraph::GetMemDC()
{
	return m_MemDC;
}

int ** CGraph::GetImageBuf()
{
/*
	���ͼ�񻺴�����ָ�롣
	����ֵ��
		���ص�ָ����ָ��һ��ָ�룬ÿһ��ָ��ָ��һ��ͼ�����ݡ�������ÿ�ĸ��ֽڱ�ʾһ�����ص㣬�ɵ͵����ֽ����α�ʾ���̺죬����ֽڲ��á�
*/
	int w = 288;
	int h = 256;
	int i, j;
	struct color24
	{
		__u8 b, g, r, unused;
	} *color;
	__u16 c565;
	
	// bmp �Ĵ��˳���Ǵ��µ��ϣ�������
	for(i = h - 1; i >= 0; --i)
	{
		color = (struct color24 *)&m_BitData[i][0];
		for(j = 0; j < w; j++)
		{
			c565 = RGB(color->r>>3,color->g>>2,color->b>>3);
			draw_set_point(canv, j, i, c565);
			color++;
		}
	}
	return m_BitData;
}

void CGraph::Refresh()
{
/*
	���������е�ͼ������ˢ����ʾ����Ļ�ϡ�
*/
	
}

void CGraph::Init(WHandle hWnd)
{
	int i;
	m_hWnd=hWnd;
	for(i = 0; i < 256; i++)
		m_BitData[i] = new int[288];
}

void CGraph::UnInit()
{
	int i;
	for(i = 0; i < 256; i++)
		delete [](m_BitData[i]);
}

void CGraph::ShowText(int x,int y,const char * Text,int Colour)
{
/*
	��ʾ���֡�

	������
		[i]x,y		��ʾλ�á�
		[i]Text		Ҫ��ʾ���������ݡ�
		[i]Colour	���ֵ���ɫ���ֽ��ɵ͵������α�ʾ�����̡��졣

*/
	struct color24
	{
		__u8 b, g, r, unused;
	} *color;
	__u16 c565;
	
	color = (color24 *)&Colour;
	c565 = RGB(color->r>>3,color->g>>2,color->b>>3);
	draw_string(canv, x, y, (char *)Text, c565);
}

#endif
