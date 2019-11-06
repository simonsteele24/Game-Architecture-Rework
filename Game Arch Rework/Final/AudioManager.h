#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <string>
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

	void addSound(string name, Audio newAudio);
	void playSound(string name);

	void handleEvent(const Event& theEvent);

	void muteSounds();
	void unmuteSounds();
private:

	map<string, Audio> mSounds;

	vector<sf::Sound> mPlayingSounds;

};


#endif // AUDIOMANAGER_H
