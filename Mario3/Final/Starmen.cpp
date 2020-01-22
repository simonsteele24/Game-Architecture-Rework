#include "Game.h"
#include "Starmen.h"

// This function is the default constructor of the class
Starmen::Starmen()
{
	mUnitType = STARMEN;
}





// This constructor uses a given position
Starmen::Starmen(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = STARMEN;
}





// This function is the destructor of the class
Starmen::~Starmen()
{
}





// This function is the update function of the class
void Starmen::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}
}