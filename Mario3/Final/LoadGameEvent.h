#ifndef LOADGAMEEVENT_H
#define LOADGAMEEVENT_H

// Local includes
#include "GameEvent.h"


class LoadGameEvent : public Event
{
public:

	// Constructors
	LoadGameEvent() :Event((EventType)LOAD_GAME) {};

	// Destructors
	~LoadGameEvent() {};

private:
};

#endif // !SAVEGAMEEVENT_H

