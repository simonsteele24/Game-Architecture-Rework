#include "Audio.h"




// This function is the default constructor for the class
Audio::Audio()
{
}





// This constructor created an audio clip based on name and file path
Audio::Audio(string name, string filePath) 
{
	mName = name;
	mSoundBuffer = sf::SoundBuffer();
	mSoundBuffer.loadFromFile(filePath);
}





// This constructor created an audio clip based on name, file path, pitch, and volume
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





// This function gets the name of the audio clip
string Audio::getName() 
{
	return mName;
}





// This function gets the pitch of the audio clip
int Audio::getPitch() 
{
	return (int)mPitch;
}





// This function gets the volume of the audio clip
int Audio::getVolume() 
{
	return (int)mVolume;
}





// This function sets the pitch of the audio clip based on a given value
void Audio::setPitch(int newPitch) 
{
	mPitch = (float)newPitch;
}





// This function sets the volume of the audio clip based on a given value
void Audio::setVolume(int newVolume) 
{
	mVolume = (float)newVolume;
}




// This function gets the audio clip
sf::SoundBuffer Audio::getSound() 
{
	return mSoundBuffer;
}





// This function plays the class's audio clip
void Audio::Play() 
{
	currentSound = sf::Sound();
	currentSound.setBuffer(mSoundBuffer);
	currentSound.play();
}





// This function pauses the audio clip
void Audio::Pause() 
{
	currentSound.pause();
}