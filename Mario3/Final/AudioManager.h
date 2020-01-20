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
	AudioManager(EventSystem* pEventSystem);
	~AudioManager();

	void addSound(string name, Audio newAudio, bool loop);
	void addSound(string name);
	void removeSound(string name);

	void playSound(string name);
	void stopSound(string name);
	void removeFromPlaying(string name);
	void playMainTheme();
	void playCastleTheme();

	void handleEvent(const Event& theEvent);

	void muteSounds();
	void unmuteSounds();

	void update();

	bool themePlaying = false;
private:

	map<string, Audio> mSounds;
	
	//vector<Audio> mPlayingSounds;
	deque<Audio> mPlayingSounds;
};


#endif // AUDIOMANAGER_H
