#include "Game.h"
#include "EndBlock.h"

EndBlock::EndBlock()
{
	mUnitType = END_BLOCK;
}

EndBlock::EndBlock(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = END_BLOCK;
}

EndBlock::~EndBlock()
{
}

void EndBlock::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	
	}
}
