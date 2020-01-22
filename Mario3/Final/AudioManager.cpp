#include "AudioManager.h"
#include "Constants.h"

// This function is the default constructor for this class
AudioManager::AudioManager(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{
}





// This function is destructor for this class
AudioManager::~AudioManager()
{
}





// This function adds sound to the manager based on a given name, audio, and if it should loop
void AudioManager::addSound(string name, Audio newAudio, bool loop) 
{
	mSounds[name] = newAudio;
	mSounds[name].currentSound.setLoop(loop);
}





// This function adds sound based on a given string
void AudioManager::addSound(string name)
{
	mPlayingSounds.push_back(mSounds[name]);
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





// This function plays the main theme for the game
void AudioManager::playMainTheme()
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == NAME_OF_CASTLE_THEME)
		{
			mPlayingSounds[i].currentSound.stop();
			mPlayingSounds[i] = mSounds[NAME_OF_SECONDARY_THEME];
			mPlayingSounds[i].Play();
			break;
		}
	}

}





// This function plays the castle theme for the game
void AudioManager::playCastleTheme()
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == NAME_OF_THEME)
		{
			mPlayingSounds[i].currentSound.stop();
			mPlayingSounds[i] = mSounds[NAME_OF_CASTLE_THEME];
			mPlayingSounds[i].Play();		
			break;
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
			mPlayingSounds[i].Play();
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
