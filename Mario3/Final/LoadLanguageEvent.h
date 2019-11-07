#ifndef LOADLANGUAGEEVENT_H
#define LOADLANGUAGEEVENT_H

// Local includes
#include "GameEvent.h"

// Graphics-lib includes
#include <Vector2.h>


class LoadLanguageEvent : public Event
{
public:

	// Constructors
	LoadLanguageEvent(const string& lan);

	// Accessors
	string getLocation() const { return mLanguage; };

private:

	// Vector2's
	string mLanguage;
};

#endif // !MOVEPLAYEREVENT_H

