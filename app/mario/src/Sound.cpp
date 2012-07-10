/*********************************************
程序设计：罗穆峰  2008-11-20
http://lmf.biaotian.com
E-mail: lmf@biaotian.com
QQ: 16324942 [模范英雄]
*********************************************/
#include "cross.h"

#include "Sound.h"

//void CALLBACK WaveCallBack(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2)
//{
//}

bool CSound::Init()
{
/*
	初始化声音设备。
	返回值：
		true		成功。
		false		失败。
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
	读取音频数据进行播放。
	参数：
		[o]Buf		读取的数据存在该缓存中。如果缺少数据，则缺少的数据填为128。
		[i]Len		缓存的长度。
*/
}

void CSound::Stop()
{
}

CSound::~CSound()
{
}
