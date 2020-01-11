#include "AudioManager.h"



AudioManager::AudioManager(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{
}






AudioManager::~AudioManager()
{
}





void AudioManager::addSound(string name, Audio newAudio, bool loop) 
{
	mSounds[name] = newAudio;
	mSounds[name].currentSound.setLoop(loop);
}





void AudioManager::playSound(string name) 
{
	mPlayingSounds.push_back(mSounds[name]);
	mPlayingSounds.back().Play();
}


void AudioManager::removeSound(string name)
{
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




void AudioManager::update()
{
	for (int i = 0; i < mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].currentSound.getStatus() == sf::Sound::Stopped)
		{
			if (mPlayingSounds[i].mName != "Theme")
			{
  				mPlayingSounds.erase(mPlayingSounds.begin() + i);
				--i;
			}
			else if (mPlayingSounds[i].mName == "Theme")
			{
				mPlayingSounds[i].Play();
			}
			
		}
	}
}
