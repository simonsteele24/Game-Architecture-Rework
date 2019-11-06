#include "Thwomp.h"
#include "Game.h"



// This function is the default constructor for this class
Thwomp::Thwomp() : Unit()
{
	mUnitType = THWOMP;
	mVelocity = 0.0;
	mIsMovingDown = false;
	mIsMovingUp = false;
	mInitialPosition = Vector2(0, 0);
}





// This constructor creates the Goomba unit at a given unit
Thwomp::Thwomp(Vector2 newPos)
{
	mUnitType = THWOMP;
	mCurrentLocation = newPos;
	mVelocity = 0.0;
	mIsMovingDown = false;
	mIsMovingUp = false;
	mInitialPosition = newPos;
}





// This function is the destructor for this class
Thwomp::~Thwomp()
{
}





// This function is the default update for this class
void Thwomp::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}

	if (mIsMovingDown) 
	{
		mVelocity += Game::getStaticInstance()->getGravityScale() * Game::getStaticInstance()->getDifficulty();
	}
	else if (mIsMovingUp)
	{
		mVelocity = -THWOMP_UPWARD_SPEED;
	}

	if (mCurrentLocation.mY <= mInitialPosition.mY && mIsMovingUp) 
	{
		mVelocity = 0.0;
		mIsMovingUp = false;
	}

	if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX > mCurrentLocation.mX &&
		Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX < mCurrentLocation.mX + mDimensions.mX &&
		mIsMovingDown == false &&
		mIsMovingUp == false
		) 
	{
		mVelocity = 0.0;
		mIsMovingDown = true;
		mIsMovingUp = false;
	}


	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > mCurrentLocation.mX - mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < mCurrentLocation.mX + mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - mDimensions.mY &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + mDimensions.mY
			)
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this && mIsMovingDown)
			{
				mVelocity = 0;
				mIsMovingDown = false;
				mIsMovingUp = true;
			}
		}
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX > mCurrentLocation.mX - mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < mCurrentLocation.mX + mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - mDimensions.mY &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + mDimensions.mY
			)
		{
			if (mIsMovingDown) 
			{
				mVelocity = 0;
				mIsMovingDown = false;
				mIsMovingUp = true;
			}
		}
	}


	moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + mVelocity));
}