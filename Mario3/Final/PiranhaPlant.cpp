#include "Game.h"
#include "PiranhaPlant.h"

// This function is the default constructor for this class
PiranhaPlant::PiranhaPlant() : Unit()
{
	mUnitType = PIRANHAPLANT;
	mCurrentDirection = UP;
	mPreviousDirection = STILL;
	mCooldownRemaining = 0;
	mMinDistanceToTravel = 0;
	mMaxDistanceToTravel = 0;
}





// This constructor creates the Goomba unit at a given unit
PiranhaPlant::PiranhaPlant(Vector2 newPos)
{
	mUnitType = PIRANHAPLANT;
	mCurrentLocation = newPos;
	mCurrentDirection = UP;
	mPreviousDirection = STILL;
	mCooldownRemaining = 0;
}





// This function is the destructor for this class
PiranhaPlant::~PiranhaPlant()
{
}





// This function is the default update for this class
void PiranhaPlant::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}

	if (mCurrentLocation.mY > mMinDistanceToTravel && mCurrentDirection == DOWN) 
	{
		mCooldownRemaining = (float) Game::getStaticInstance()->getPiranhaWaitTime();
		mPreviousDirection = DOWN;
		mCurrentDirection = STILL;
	}
	else if (mCurrentLocation.mY < mMaxDistanceToTravel && mCurrentDirection == UP) 
	{
		mCooldownRemaining = (float) Game::getStaticInstance()->getPiranhaWaitTime();
		mPreviousDirection = UP;
		mCurrentDirection = STILL;
	}


	if (mPreviousDirection != STILL)
	{
		mCooldownRemaining -= (float) newTimeBetweenFrames;

		if (mCooldownRemaining <= 0)
		{
			if (mPreviousDirection == UP) 
			{
				mCurrentDirection = DOWN;
			}
			else 
			{
				mCurrentDirection = UP;
			}
			mPreviousDirection = STILL;
		
		}


	}

	switch (mCurrentDirection)
	{
	case UP:
		moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY - Game::getStaticInstance()->getPiranhaMoveSpd()));
		break;
	case DOWN:
		moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + Game::getStaticInstance()->getPiranhaMoveSpd()));
		break;
	case STILL:
		break;
	default:
		break;
	}
}





// This function is the default animation swap class for this class
void PiranhaPlant::swapAnimation(string nameOfNewAnimation) 
{
	// The following code determines if the current animation is the
	// last animation in the animations vector. If it is, cycle back to 
	// the start of the vector other wise just go to the next animation.
	for (int i = 0, max = mCurrentAnimations.size(); i < max; i++)
	{
		if (mCurrentAnimations[i]->getAnimationName() == nameOfNewAnimation)
		{
			mCurrentAnimationIndex = i;
		}
	}
}





// This function is the default animation set function for this class
void PiranhaPlant::setAnimation(Animation & newAnimation) 
{
	mCurrentAnimations.push_back(new Animation(newAnimation));

	if (mDimensions.mX <= 0 && mDimensions.mY <= 0)
	{
		mDimensions = mCurrentAnimations[0]->getAnimationDimensions();
	}

	mMinDistanceToTravel = (float)(mCurrentLocation.mY + (mDimensions.mY / 2.0));
	mMaxDistanceToTravel = (float)(mCurrentLocation.mY - (mDimensions.mY / 2.0));
}