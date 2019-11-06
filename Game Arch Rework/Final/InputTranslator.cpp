#include "InputTranslator.h"
#include "Game.h"

InputTranslator::InputTranslator(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{
	pEventSystem->addListener(ENTER_KEY_RELEASED, this);
	pEventSystem->addListener(ESCAPE_KEY_RELEASED, this);
	pEventSystem->addListener(SPACE_KEY_RELEASED, this);
	pEventSystem->addListener(LEFT_MOUSE_PRESSED, this);
	pEventSystem->addListener(RIGHT_MOUSE_PRESSED, this);
	pEventSystem->addListener(MOUSE_CURSOR_MOVED, this);
	pEventSystem->addListener(RIGHT_KEY_PRESSED, this);
	pEventSystem->addListener(LEFT_KEY_PRESSED, this);
	pEventSystem->addListener(S_KEY_RELEASED, this);
	pEventSystem->addListener(ONE_KEY_PRESSED, this);
	pEventSystem->addListener(TWO_KEY_PRESSED, this);
	pEventSystem->addListener(THREE_KEY_PRESSED, this);
	pEventSystem->addListener(FOUR_KEY_PRESSED, this);
}

InputTranslator::~InputTranslator()
{
}

void InputTranslator::handleEvent(const Event &theEvent)
{
	if (theEvent.getType() == ENTER_KEY_RELEASED)
	{
		getEventSystem()->fireEvent(LoadGameEvent());
	}
	if (theEvent.getType() == ESCAPE_KEY_RELEASED) 
	{
		getEventSystem()->fireEvent(QuitEvent());
	}
	if (theEvent.getType() == SPACE_KEY_RELEASED)
	{
		getEventSystem()->fireEvent(JumpEvent());
	}
	if (theEvent.getType() == LEFT_MOUSE_PRESSED) 
	{
		getEventSystem()->fireEvent(ShootBulletEvent());
	}
	if (theEvent.getType() == RIGHT_MOUSE_PRESSED) 
	{
		const RightClickPressedEvent& moveEvent = static_cast<const RightClickPressedEvent&>(theEvent);
		getEventSystem()->fireEvent(DestroyUnitEvent(moveEvent.getLocation()));
	}
	if (theEvent.getType() == MOUSE_CURSOR_MOVED) 
	{
		const MouseMovedEvent& moveEvent = static_cast<const MouseMovedEvent&>(theEvent);
		getEventSystem()->fireEvent(MovePlayerEvent(moveEvent.getLocation()));
	}
	if (theEvent.getType() == RIGHT_KEY_PRESSED) 
	{
		getEventSystem()->fireEvent(MovePlayerRightEvent());
	}
	if (theEvent.getType() == LEFT_KEY_PRESSED)
	{
		getEventSystem()->fireEvent(MovePlayerLeftEvent());
	}
	if (theEvent.getType() == S_KEY_RELEASED) 
	{
		getEventSystem()->fireEvent(SaveGameEvent());
	}
	if (theEvent.getType() == ONE_KEY_PRESSED) 
	{
		getEventSystem()->fireEvent(LoadLanguageEvent("1"));
	}
	if (theEvent.getType() == TWO_KEY_PRESSED)
	{
		getEventSystem()->fireEvent(LoadLanguageEvent("2"));
	}
	if (theEvent.getType() == THREE_KEY_PRESSED)
	{
		getEventSystem()->fireEvent(LoadLanguageEvent("3"));
	}
	if (theEvent.getType() == FOUR_KEY_PRESSED)
	{
		getEventSystem()->fireEvent(LoadLanguageEvent("4"));
	}
}