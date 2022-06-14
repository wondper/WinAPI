#include "Sound.h"

Sound::Sound()
{

}

Sound::Sound(const char* SoundFilePath[4], FMOD_MODE mode[4])
{
	InitSound(SoundFilePath, mode);
}

Sound::~Sound()
{

}

void Sound::InitSound(const char* SoundFilePath[4], FMOD_MODE mode[4])
{
	FMOD_System_Create(&mSoundSystem, FMOD_VERSION);
	FMOD_System_Init(mSoundSystem, 1, FMOD_INIT_NORMAL, NULL);
	for (int i = 0; i < 4; ++i)
	{
		FMOD_System_CreateSound(mSoundSystem, SoundFilePath[i], mode[i], 0, &mSoundFile[i]);
		mChannel[i] = nullptr;
	}
}

void Sound::Play(float volume, int channel)
{

	FMOD_System_PlaySound(mSoundSystem, mSoundFile[channel], NULL, 0, &mChannel[channel]);
	FMOD_Channel_SetVolume(mChannel[channel], volume);
}

void Sound::Stop(int channel)
{
	FMOD_Channel_Stop(mChannel[channel]);
}

void Sound::Update()
{
	FMOD_System_Update(mSoundSystem);
}
//void Sound::SetVolume(float volume)
//{
//	FMOD_Channel_SetVolume(mChannel, volume);
//}