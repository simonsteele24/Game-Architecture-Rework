#include "Game.h"
#include "DryBones.h"



// This function is the default constructor for this class
DryBones::DryBones() : Unit()
{
	mUnitType = DRYBONES;
	mVelocity = 0.0;
	mTimesBouncedOn = 0;
	mCooldownRemaining = 0;
	mCurrentDirection = LEFT;
	mIsWalking = true;
	mIsStationary = false;
	mIsSpinning = false;
	mUnitMovability = MOVEABLE;
}





// This constructor creates the Goomba unit at a given unit
DryBones::DryBones(Vector2 newPos)
{
	mUnitType = DRYBONES;
	mCurrentLocation = newPos;
	mVelocity = 0.0;
	mTimesBouncedOn = 0;
	mCooldownRemaining = 0;
	mCurrentDirection = LEFT;
	mIsWalking = true;
	mIsStationary = false;
	mIsSpinning = false;
	mUnitMovability = MOVEABLE;
}





// This function is the destructor for this class
DryBones::~DryBones()
{
}





// This function is the default update for this class
void DryBones::update(double newTimeBetweenFrames)
{
	if (!mIsWalking) 
	{
		mCooldownRemaining -= (int)newTimeBetweenFrames;
		if (mCooldownRemaining <= 0) 
		{
			mIsWalking = true;
		}
	}

	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}


	// Check for collision here
	mVelocity += Game::getStaticInstance()->getGravityScale();


	if (mIsWalking)
	{
		switch (mCurrentDirection)
		{
		case LEFT:
			moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
			swapAnimation(NAME_OF_DRY_BONES_LEFT_ANIMATION);
			break;
		case RIGHT:
			moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
			swapAnimation(NAME_OF_DRY_BONES_RIGHT_ANIMATION);
			break;
		case NONE:
			break;
		default:
			break;
		}
	}
}





// This function swaps the animations of the unit
void DryBones::swapAnimation(string nameOfNewAnimation)
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





void DryBones::onCollide(Unit & collidingObject, int collidingObjectIndex) 
{
	switch (collidingObject.getCurrentUnitType())
	{
	case PLAYER:
		if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < mCurrentLocation.mY && mIsWalking == true)
		{
			mIsWalking = false;
			mCooldownRemaining = DRYBONES_COOLDOWN_TIME;
			swapAnimation(NAME_OF_DRY_BONES_DOWN_ANIMATION);
		}
		break;
	default:
		if ((mCurrentLocation.mX - 16 <= collidingObject.getLocation().mX - collidingObject.getDimensions().mX || mCurrentLocation.mX + 16 >= collidingObject.getLocation().mX + collidingObject.getDimensions().mX) && collidingObject.getLocation().mY == round(mCurrentLocation.mY))
		{
			changeDirection();
		}
		else
		{
			mVelocity = 0;
		}
		break;
	}
}





void DryBones::changeDirection() 
{
	if (mCurrentDirection == LEFT)
	{
		mCurrentDirection = RIGHT;
	}
	else
	{
		mCurrentDirection = LEFT;
	}
}