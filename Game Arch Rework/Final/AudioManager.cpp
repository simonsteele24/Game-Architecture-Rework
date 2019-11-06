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
	mPlayingSounds.push_back(sf::Sound());
	mPlayingSounds[mPlayingSounds.size() - 1].setBuffer(mSounds[name].mSoundBuffer);
	mPlayingSounds[mPlayingSounds.size() - 1].play();
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
		mPlayingSounds[i].pause();
	}
}





void AudioManager::unmuteSounds() 
{
	for (int i = 0; i < (int)mPlayingSounds.size(); i++)
	{
		mPlayingSounds[i].play();
	}
}