#pragma once

#include <string>
#include <trackable.h>

// Local includes
#include "Event.h"

using namespace std;

// Game Event Type Enum
enum GameEventType
{
	STOP_START_ANIMATION = NUM_EVENT_TYPES,
	SWITCH_ANIMATIONS,
	QUIT_GAME,
	CREATE_UNITS,
	DELETE_UNITS,
	MOVE_PLAYER,
	SHOOT_BULLET,
	START_GAME,
	SAVE_GAME,
	MOVE_PLAYER_RIGHT,
	LOAD_GAME,
	LOAD_LANGUAGE,
	MOVE_PLAYER_LEFT
};