#ifndef SAVEGAMEEVENT_H
#define SAVEGAMEEVENT_H

// Local includes
#include "GameEvent.h"


class SaveGameEvent : public Event
{
public:

	// Constructors
	SaveGameEvent() :Event((EventType)SAVE_GAME) {};

	// Destructors
	~SaveGameEvent() {};

private:
};

#endif // !SAVEGAMEEVENT_H

