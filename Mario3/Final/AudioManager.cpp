#include "AudioManager.h"



AudioManager::AudioManager(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{
}






AudioManager::~AudioManager()
{
}





void AudioManager::addSound(string name, Audio newAudio) 
{
	mSounds[name] = newAudio;
}





void AudioManager::playSound(string name) 
{
	mPlayingSounds.push_back(mSounds[name]);
	mPlayingSounds[mPlayingSounds.size() - 1].Play();
}





void AudioManager::handleEvent(const Event& theEvent) 
{
	if (theEvent.getType() == MAKE_PLAYER_JUMP) 
	{
		playSound("Jump");
	}
}





void AudioManager::muteSounds() 
{
	for (int i = 0; i < (int)mPlayingSounds.size(); i++) 
	{
		mPlayingSounds[i].Pause();
	}
}





void AudioManager::unmuteSounds() 
{
	for (int i = 0; i < (int)mPlayingSounds.size(); i++)
	{
		mPlayingSounds[i].Play();
	}
}