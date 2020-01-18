#include "Game.h"
#include "Goomba.h"



// This function is the default constructor for this class
Goomba::Goomba() : Unit()
{
	mUnitType = GOOMBA;
	mVelocity = 0.0;
	mCurrentDirection = LEFT;
	mUnitMovability = MOVEABLE;
}





// This constructor creates the Goomba unit at a given unit
Goomba::Goomba(Vector2 newPos) 
{
	mUnitType = GOOMBA;
	mCurrentLocation = newPos;
	mVelocity = 0.0;
	mCurrentDirection = LEFT;
	mUnitMovability = MOVEABLE;
}





// This function is the destructor for this class
Goomba::~Goomba()
{
}





// This function is the default update for this class
void Goomba::update(double newTimeBetweenFrames)
{
	if (isAnimationStopped == false)
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}

	// Check for collision here
	mVelocity += Game::getStaticInstance()->getGravityScale();

	switch (mCurrentDirection)
	{
	case LEFT:
		moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
		break;
	case RIGHT:
		moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
		break;
	case NONE:
		break;
	default:
		break;
	}
}





void Goomba::onCollide(Unit & collidingObject, int collidingObjectIndex) 
{
	if ((mCurrentLocation.mX <= collidingObject.getLocation().mX || mCurrentLocation.mX + 16 >= collidingObject.getLocation().mX + collidingObject.getDimensions().mX) && (abs(collidingObject.getLocation().mY - mCurrentLocation.mY) < mDimensions.mY / 2 || abs(collidingObject.getLocation().mY - mCurrentLocation.mY) < collidingObject.mDimensions.mY / 2))
	{
		changeDirection();
	}
	else 
	{
		mVelocity = 0;
	}
}





void Goomba::changeDirection() 
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