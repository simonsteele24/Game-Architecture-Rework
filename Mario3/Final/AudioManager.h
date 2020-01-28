#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <string>
#include <deque>
#include <Audio.h>
#include <EventListener.h>
#include <EventSystem.h>
#include "GameEvent.h"

using namespace std;

class AudioManager : public EventListener
{
public:

	// Constructors
	AudioManager(EventSystem* pEventSystem);

	// Destructors
	~AudioManager();

	// Add sound functions
	void addSound(string name, Audio newAudio, bool loop);
	void addSound(string name);

	// Remove sound functions
	void removeSound(string name);

	// Play / Stop sound functions
	void playSound(string name);
	void stopSound(string name);
	void removeFromPlaying(string name);

	// Event Handlers
	void handleEvent(const Event& theEvent);

	// Mute / unmute sounds
	void muteSounds();
	void unmuteSounds();

	// Update functions
	void update();

	// Booleans
	bool themePlaying = false;

private:

	// Audio sounds map
	map<string, Audio> mSounds;
	
	bool mSoundsareMuted;

	//vector<Audio> mPlayingSounds;
	deque<Audio> mPlayingSounds;
};


#endif // AUDIOMANAGER_H
