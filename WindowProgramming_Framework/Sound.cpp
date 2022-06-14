#include "Sound.h"

Sound::Sound()
{

}

Sound::Sound(const char* SoundFilePath, FMOD_MODE mode)
{
	InitSound(SoundFilePath, mode);
}

Sound::~Sound()
{

}

void Sound::InitSound(const char* SoundFilePath, FMOD_MODE mode)
{
	FMOD_System_Create(&mSoundSystem, FMOD_VERSION);
	FMOD_System_Init(mSoundSystem, 32, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(mSoundSystem, SoundFilePath, mode, 0, &mSoundFile);
}

void Sound::Play()
{
	FMOD_System_PlaySound(mSoundSystem, mSoundFile, NULL, 0, &mChannel);
}
