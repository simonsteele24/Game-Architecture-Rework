#include "Audio.h"




// This function is the default constructor for the class
Audio::Audio()
{
}





Audio::Audio(string name, string filePath) 
{
	mName = name;
	mSoundBuffer = sf::SoundBuffer();
	mSoundBuffer.loadFromFile(filePath);
}





Audio::Audio(string name, string filePath, int pitch, int volume) 
{
	mName = name;
	mSoundBuffer = sf::SoundBuffer();
	mSoundBuffer.loadFromFile(filePath);
	mPitch = (float)pitch;
	mVolume = (float)volume;
}




// This function is the default constructor for the class
Audio::~Audio()
{
}





string Audio::getName() 
{
	return mName;
}





int Audio::getPitch() 
{
	return (int)mPitch;
}





int Audio::getVolume() 
{
	return (int)mVolume;
}





void Audio::setPitch(int newPitch) 
{
	mPitch = (float)newPitch;
}





void Audio::setVolume(int newVolume) 
{
	mVolume = (float)newVolume;
}





sf::SoundBuffer Audio::getSound() 
{
	return mSoundBuffer;
}





void Audio::Play() 
{
	currentSound = sf::Sound();
	currentSound.setBuffer(mSoundBuffer);
	currentSound.play();
}





void Audio::Pause() 
{
	currentSound.pause();
}