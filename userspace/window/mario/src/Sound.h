#ifndef _SOUND_H_FILE_INCLUDED_

#define _SOUND_H_FILE_INCLUDED_


struct SOUNDCHANNEL
{
	
	int CurPos;
	bool Loop;
};

class CSound
{
public:
	~CSound();
	bool Init();
	void Stop();
	void * AddChannel(const void * Data,unsigned long Len,bool Loop);
	void DeleteChannel(void * Chn);
	void ReadData(void * Buf,int Len);
};

#endif
