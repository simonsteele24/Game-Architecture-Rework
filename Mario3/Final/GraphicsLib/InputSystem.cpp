#include "InputSystem.h"

// This is the default constructo for the class
InputSystem::InputSystem()
{
}





// This function is the default destructor for the class
InputSystem::~InputSystem()
{
	cleanup();
}





// This function initializes the input system whenever called
void InputSystem::init() 
{
	mIsEnterDown = false;
	mIsSpaceDown = false;
	mIsEscapeDown = false;
	mIsLeftButtonDown = false;
}





// This function cleansup and destroys the input system whenever called
void InputSystem::cleanup() 
{
	mIsEnterDown = false;
	mIsSpaceDown = false;
	mIsEscapeDown = false;
	mIsLeftButtonDown = false;
}





// This function gets called in the game loop within the game class and
// checks for input between the last frames
void InputSystem::update() 
{
	sf::Keyboard boardState;

	//// The following code finds if any of the keys
	//// are being pressed and will fire an event if said key has recently been released
	if (boardState.isKeyPressed(boardState.Escape))
	{
		mIsEscapeDown = true;
	}
	else if (mIsEscapeDown == true)
	{
		mIsEscapeDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(ESCAPE_KEY_RELEASED));
	}

	if(boardState.isKeyPressed(boardState.Enter))
	{
		mIsEnterDown = true;
	}
	else if (mIsEnterDown == true) 
	{
		mIsEnterDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(ENTER_KEY_RELEASED));
	}

	if (boardState.isKeyPressed(boardState.Left))
	{
		EventSystem::getStaticInstance()->fireEvent(Event(LEFT_KEY_PRESSED));
	}

	if (boardState.isKeyPressed(boardState.Right) )
	{
		EventSystem::getStaticInstance()->fireEvent(Event(RIGHT_KEY_PRESSED));
	}

	if (boardState.isKeyPressed(boardState.S))
	{
		mIsSDown = true;
	}
	else if (mIsSDown == true)
	{
		mIsSDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(S_KEY_RELEASED));
	}

	if (boardState.isKeyPressed(boardState.Num1)) 
	{
		mIsOneDown = true;
	}
	else if (mIsOneDown == true) 
	{
		mIsOneDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(ONE_KEY_PRESSED));
	}

	if (boardState.isKeyPressed(boardState.Num2))
	{
		mIsTwoDown = true;
	}
	else if (mIsTwoDown == true)
	{
		mIsTwoDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(TWO_KEY_PRESSED));
	}

	if (boardState.isKeyPressed(boardState.Num3))
	{
		mIsThreeDown = true;
	}
	else if (mIsThreeDown == true)
	{
		mIsThreeDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(THREE_KEY_PRESSED));
	}

	if (boardState.isKeyPressed(boardState.Num4)) 
	{
		mIsFourDown = true;
	}
	else if (mIsFourDown == true)
	{
		mIsFourDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(FOUR_KEY_PRESSED));
	}


	if (boardState.isKeyPressed(boardState.Space))
	{
		mIsSpaceDown = true;
	}
	else if (mIsSpaceDown == true) 
	{
		mIsSpaceDown = false;
		EventSystem::getStaticInstance()->fireEvent(Event(SPACE_KEY_RELEASED));
	}
}