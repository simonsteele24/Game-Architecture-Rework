#include "Game.h"
#include "Koopa.h"



// This function is the default constructor for this class
Koopa::Koopa() : Unit()
{
	mUnitType = KOOPA;
	mVelocity = 0.0;
	mTimesBouncedOn = 0;
	mCurrentDirection = LEFT;
	mIsWalking = true;
	mIsStationary = false;
	mIsSpinning = false;
	mUnitMovability = MOVEABLE;
}





// This constructor creates the Goomba unit at a given unit
Koopa::Koopa(Vector2 newPos)
{
	mUnitType = KOOPA;
	mCurrentLocation = newPos;
	mCurrentLocation.mY -= 25.0f;
	mVelocity = 0.0;
	mTimesBouncedOn = 0;
	mCurrentDirection = LEFT;
	mIsWalking = true;
	mIsStationary = false;
	mIsSpinning = false;
	mUnitMovability = MOVEABLE;
}





// This function is the destructor for this class
Koopa::~Koopa()
{
}





// This function is the default update for this class
void Koopa::update(double newTimeBetweenFrames)
{
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
			swapAnimation(NAME_OF_KOOPA_RIGHT_ANIMATION);
			break;
		case RIGHT:
			moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
			swapAnimation(NAME_OF_KOOPA);
			break;
		case NONE:
			break;
		default:
			break;
		}
	}

	if (mIsSpinning) 
	{
		switch (mCurrentDirection)
		{
		case LEFT:
			moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getKoopaSpinSpd(), mCurrentLocation.mY + mVelocity));
			break;
		case RIGHT:
			moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getKoopaSpinSpd(), mCurrentLocation.mY + mVelocity));
			break;
		case NONE:
			break;
		default:
			break;
		}
	}
}





// This function swaps the animations of the unit
void Koopa::swapAnimation(string nameOfNewAnimation)
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





void Koopa::onCollide(Unit & collidingObject, int collidingObjectIndex) 
{
	switch (collidingObject.getCurrentUnitType()) 
	{
	case PLAYER:
		if (mIsStationary)//if the koopa is stationary, and it has been bounced on multiple times, then it will spin.
		{
			if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX > mCurrentLocation.mX)
			{
				mCurrentDirection = LEFT;
				mIsStationary = false;
				mIsSpinning = true;
				swapAnimation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION);
			}
			else
			{
				mCurrentDirection = RIGHT;
				mIsStationary = false;
				mIsSpinning = true;
				swapAnimation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION);
			}

		}

		else if (mIsWalking && Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < mCurrentLocation.mY)
		{

			Game::getStaticInstance()->getUnitManager()->getPlayer()->readyToKill(true);

			mIsStationary = true;
			mIsWalking = false;
			swapAnimation(NAME_OF_KOOPA_SHELL_ANIMATION);
			mTimesBouncedOn += 1;
		}
		else if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < mCurrentLocation.mY)
		{
			mTimesBouncedOn++;//this means if they player is still jumping on the koopa, it still gets a bounced value
		}
		break;
	default:
		if ((mCurrentLocation.mX  <= collidingObject.getLocation().mX || mCurrentLocation.mX + mDimensions.mX >= collidingObject.getLocation().mX + collidingObject.getDimensions().mX) && abs(collidingObject.getLocation().mY - mCurrentLocation.mY) < mDimensions.mY / 2)
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





void Koopa::changeDirection()
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