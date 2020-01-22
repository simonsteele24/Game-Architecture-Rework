#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace std;

class Audio
{
public:

	// Friends
	friend class AudioManager;

	// Constructors
	Audio();
	Audio(string name, string filePath);
	Audio(string name, string filePath, int pitch, int volume);

	// Destructors
	~Audio();

	// Acessors
	string getName();
	int getPitch();
	int getVolume();

	// Mutators
	void setPitch(int newPitch);
	void setVolume(int newVolume);
	void Play();
	void Pause();

private:

	// Acessors
	sf::SoundBuffer getSound();

	// Strings
	string mName;

	// Sound Buffers
	sf::SoundBuffer mSoundBuffer;
	
	// Floats
	float mPitch;
	float mVolume;

	// Sounds
	sf::Sound currentSound;
};

#endif // !AUDIO_H

