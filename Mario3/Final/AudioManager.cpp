#include "AudioManager.h"
#include "Constants.h"

// This function is the default constructor for this class
AudioManager::AudioManager(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{
	mSoundsareMuted = false;
}





// This function is destructor for this class
AudioManager::~AudioManager()
{
}





// This function adds sound to the manager based on a given name, audio, and if it should loop
void AudioManager::addSound(string name, Audio newAudio, bool loop) 
{
	if (mSoundsareMuted == false) 
	{
		mSounds[name] = newAudio;
		mSounds[name].currentSound.setLoop(loop);
	}
}





// This function adds sound based on a given string
void AudioManager::addSound(string name)
{
	if (mSoundsareMuted == false) 
	{
		mPlayingSounds.push_back(mSounds[name]);
	}
}





// This function removes an audio clip based on a given string
void AudioManager::removeSound(string name)
{
	mSounds.erase(name);
}





// This function removes an playing audio clip based on a given string
void AudioManager::removeFromPlaying(string name)
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == name)
		{

			stopSound(name);

			mPlayingSounds.pop_back();
		}
	}
}





// This function plays a sound based on a given string
void AudioManager::playSound(string name)
{
	addSound(name);
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == name)
		{
			mPlayingSounds[i].currentSound.play();
			mPlayingSounds[i] = mSounds[name];
			mPlayingSounds[i].Play();
			break;
		}
	}
}





// This function stops a sound based on a given name
void AudioManager::stopSound(string name)
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{		
		if (mPlayingSounds[i].mName == name) 
		{
			mPlayingSounds[i].currentSound.stop();
		}
	}
}





// This function handles events for the event handler
void AudioManager::handleEvent(const Event& theEvent) 
{
	if (theEvent.getType() == MAKE_PLAYER_JUMP) 
	{
		playSound(NAME_OF_AUDIO_JUMP);
	}
}





void AudioManager::muteSounds() 
{
	mSoundsareMuted = true;
	for (int i = 0; i < (int)mPlayingSounds.size(); i++) 
	{
		mPlayingSounds[i].Pause();
	}
}





void AudioManager::unmuteSounds() 
{
	mSoundsareMuted = false;
	for (int i = 0; i < (int)mPlayingSounds.size(); i++)
	{
		mPlayingSounds[i].Play();
	}
}




void AudioManager::update()     
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].currentSound.getStatus() == sf::Sound::Stopped)
		{
			if (mPlayingSounds[i].mName != NAME_OF_THEME || mPlayingSounds[i].mName != NAME_OF_CASTLE_THEME)
			{
				mPlayingSounds.pop_back();
			}

		}
	}
}
