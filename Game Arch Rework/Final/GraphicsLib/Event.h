#pragma once

#include <string>
#include <trackable.h>

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	ENTER_KEY_RELEASED,
	SPACE_KEY_RELEASED,
	ESCAPE_KEY_RELEASED,
	S_KEY_RELEASED,
	LEFT_MOUSE_PRESSED,
	RIGHT_MOUSE_PRESSED,
	MIDDLE_MOUSE_PRESSED,
	MOUSE_CURSOR_MOVED,
	LEFT_KEY_PRESSED,
	RIGHT_KEY_PRESSED,
	ONE_KEY_PRESSED,
	TWO_KEY_PRESSED,
	THREE_KEY_PRESSED,
	FOUR_KEY_PRESSED,
	MAKE_PLAYER_JUMP,
	NUM_EVENT_TYPES
};

const string EVENT_NAMES[NUM_EVENT_TYPES] = { "Enter Key Pressed",
												"Space Key Pressed",
												"Escape Key Pressed",
												"S Key Pressed",
												"Left Mouse Pressed",
												"Right Mouse Pressed",
												"Middle Mouse Pressed",
												"Left Key Pressed",
												"Right Key Pressed",
												"One Key Pressed",
												"Two Key Pressed",
												"Three Key Pressed",
												"Make Player jump",
												"Mouse Cursor Moved"
											};


class Event:public Trackable
{
public:
	Event( EventType type );
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;

};