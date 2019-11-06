#include "Game.h"
#include "SuperMushroom.h"

SuperMushroom::SuperMushroom()
{
	mUnitType = SUPER_MUSHROOM;
}

SuperMushroom::SuperMushroom(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = SUPER_MUSHROOM;
}

SuperMushroom::~SuperMushroom()
{
}

void SuperMushroom::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}
}
