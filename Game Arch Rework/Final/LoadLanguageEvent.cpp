#include "LoadLanguageEvent.h"

// This is the default constructor for the class
LoadLanguageEvent::LoadLanguageEvent(const string& lan)
	:Event(EventType(LOAD_LANGUAGE))
	, mLanguage(lan)
{
}