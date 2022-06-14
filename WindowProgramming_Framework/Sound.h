#pragma once
#include "stdafx.h"

class Sound
{
private:
	FMOD_SYSTEM* mSoundSystem;
	FMOD_SOUND* mSoundFile;
	FMOD_CHANNEL* mChannel;
public:
	Sound();
	Sound(const char* SoundFilePath, FMOD_MODE mode);
	~Sound();
	void InitSound(const char* SoundFilePath, FMOD_MODE mode);
	void Play();
};

