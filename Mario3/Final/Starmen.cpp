#include "Game.h"
#include "Starmen.h"

Starmen::Starmen()
{
	mUnitType = STARMEN;
}

Starmen::Starmen(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = STARMEN;
}

Starmen::~Starmen()
{
}

void Starmen::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}
}