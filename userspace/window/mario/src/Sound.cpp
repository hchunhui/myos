/*********************************************
������ƣ����·�  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [ģ��Ӣ��]
*********************************************/
#include "cross.h"

#include "Sound.h"

//void CALLBACK WaveCallBack(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2)
//{
//}

bool CSound::Init()
{
/*
	��ʼ�������豸��
	����ֵ��
		true		�ɹ���
		false		ʧ�ܡ�
*/
	return true;
}

void * CSound::AddChannel(const void * Data,unsigned long Len,bool Loop)
{
	return NULL;
}

void CSound::DeleteChannel(void * Chn)
{
}

void CSound::ReadData(void * Buf,int Len)
{
/*
	��ȡ��Ƶ���ݽ��в��š�
	������
		[o]Buf		��ȡ�����ݴ��ڸû����С����ȱ�����ݣ���ȱ�ٵ�������Ϊ128��
		[i]Len		����ĳ��ȡ�
*/
}

void CSound::Stop()
{
}

CSound::~CSound()
{
}
