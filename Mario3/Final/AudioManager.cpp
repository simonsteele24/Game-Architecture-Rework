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

void AudioManager::addSound(string name)
{
	mPlayingSounds.push_back(mSounds[name]);
}


void AudioManager::removeSound(string name)
{
	mSounds.erase(name);
}

void AudioManager::removeFromPlaying(string name)
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == name)
		{

			stopSound(name);

			mPlayingSounds.pop_back();
			/*mPlayingSounds.pop_back();
			if (mPlayingSounds[i].mName == name)
			{
				mPlayingSounds.pop_back();
			}
			*/
		}
	}
}

void AudioManager::playMainTheme()
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == "CastleTheme")
		{
			mPlayingSounds[i].currentSound.stop();
			mPlayingSounds[i] = mSounds["Themes"];
			mPlayingSounds[i].Play();
			break;
		}
	}

}

void AudioManager::playCastleTheme()
{
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].mName == "Theme")
		{
			mPlayingSounds[i].currentSound.stop();
			mPlayingSounds[i] = mSounds["CastleTheme"];
			mPlayingSounds[i].Play();		
			break;
		}
	}
}


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
	for (int i = 0; i < (int)mPlayingSounds.size(); ++i)
	{
		if (mPlayingSounds[i].currentSound.getStatus() == sf::Sound::Stopped)
		{
			if (mPlayingSounds[i].mName != "Theme" || mPlayingSounds[i].mName != "CastleTheme")
			{
				mPlayingSounds.pop_back();
			}

		}
	}
}
