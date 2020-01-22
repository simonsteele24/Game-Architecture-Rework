#include "Game.h"
#include "EndBlock.h"


// This function is the default constructor of the class
EndBlock::EndBlock()
{
	mUnitType = END_BLOCK;
}





// This constructor uses a given position
EndBlock::EndBlock(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mUnitType = END_BLOCK;
}





// This function is the destructor of the class
EndBlock::~EndBlock()
{
}





// This function is the update function of the class
void EndBlock::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	
	}
}
