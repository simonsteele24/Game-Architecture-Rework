#include "Platform.h"
#include "Game.h"



// This function is the default constructor for the class 
Platform::Platform() : Unit()
{
	mUnitType = PLATFORM;
}





// This is the destructor for the class
Platform::~Platform()
{

}





// This function sets the identity of a prop based on a given value
void Platform::setPlatformIdentity(char newID)
{
	mPlatformIdentity = newID;
}





// This function getsthe identity of the prop
char Platform::getPlatformIdentity()
{
	return mPlatformIdentity;
}





// This constructor moves the player Unit to a given position
Platform::Platform(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = PLATFORM;
}