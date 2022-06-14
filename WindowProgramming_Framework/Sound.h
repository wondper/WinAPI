#pragma once
#include "stdafx.h"

class Sound
{
private:
	FMOD_SYSTEM* mSoundSystem;
	FMOD_SOUND* mSoundFile[4];
	FMOD_CHANNEL* mChannel[4];
public:
	Sound();
	Sound(const char* SoundFilePath[4], FMOD_MODE mode[4]);
	~Sound();
	void InitSound(const char* SoundFilePath[4], FMOD_MODE mode[4]);
	//void SetVolume(float volume);
	void Play(float volume, int channel);
	void Stop(int channel);
	void Update();
};

