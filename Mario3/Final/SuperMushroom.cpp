#include "Game.h"
#include "SuperMushroom.h"


// This function is the default constructor of the class
SuperMushroom::SuperMushroom()
{
	mUnitType = SUPER_MUSHROOM;
}





// This constructor uses a given position
SuperMushroom::SuperMushroom(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = SUPER_MUSHROOM;
}





// This function is the destructor of the class
SuperMushroom::~SuperMushroom()
{
}





// This function is the update function of the class
void SuperMushroom::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}
}
