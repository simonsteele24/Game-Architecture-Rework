#include "Fireball.h"
#include "Game.h"


// This function is the default constructor for this class
Fireball::Fireball() : Unit()
{
	mUnitType = FIREBALL;
	mVelocity = 0.0;
	mIsMovingDown = false;
	mIsMovingUp = false;
	mInitialPosition = Vector2(0, 0);
	mRemainingTime = 0;
	mVelocity = FIREBALL_FORCE;
}





// This constructor creates the Goomba unit at a given unit
Fireball::Fireball(Vector2 newPos)
{
	mUnitType = FIREBALL;
	mCurrentLocation = newPos;
	mVelocity = 0.0;
	mIsMovingDown = false;
	mIsMovingUp = false;
	mInitialPosition = newPos;
	mRemainingTime = 0;
	mVelocity = FIREBALL_FORCE;
}





// This function is the destructor for this class
Fireball::~Fireball()
{
}





// This function is the default update for this class
void Fireball::update(double newTimeBetweenFrames)
{
	if (mRemainingTime != 0) 
	{
		mRemainingTime -= (int)newTimeBetweenFrames;
		if (mRemainingTime < 0) 
		{
			mRemainingTime = 0;
			mVelocity = FIREBALL_FORCE;
		}
	}

	if (mRemainingTime == 0) 
	{
		if (mVelocity <= 0.0f)
		{
			swapAnimation(NAME_OF_FIREBALL_UP_ANIMATION);
		}
		else
		{
			swapAnimation(NAME_OF_FIREBALL_DOWN_ANIMATION);
		}

		if (mCurrentLocation.mY > mInitialPosition.mY && mCurrentLocation.mY != mInitialPosition.mY)
		{
			mVelocity = 0;
			mCurrentLocation.mY = mInitialPosition.mY;
			mRemainingTime = DRYBONES_COOLDOWN_TIME;
		}
		else
		{
			mVelocity += Game::getStaticInstance()->getGravityScale();
		}

		moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + mVelocity));
	}
}