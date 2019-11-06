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


	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > mCurrentLocation.mX - mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < mCurrentLocation.mX + mDimensions.mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - mDimensions.mY &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + mDimensions.mY
			)
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this)
			{
				mVelocity = 0;
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
			mVelocity = 0;
		}
	}

	double minX = (mCurrentLocation.mX) - mDimensions.mX;
	double maxX = (mCurrentLocation.mX) + mDimensions.mX;
	double minY = mCurrentLocation.mY - mDimensions.mY - 1;
	double maxY = mCurrentLocation.mY + mDimensions.mY - 1;


	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		if (mCurrentDirection == LEFT) 
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY
				)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == KOOPA && Game::getStaticInstance()->getUnitManager()->getUnit(i)->mIsSpinning == false && mIsSpinning == true) 
				{
					Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit = true;//the unit has been hit
					Game::getStaticInstance()->addToScore(100);//add to member score variable
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));//pass in the variable to 
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				}
				else
				{
					if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this)
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
				}
			}
		}
		else 
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY
				)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == KOOPA && Game::getStaticInstance()->getUnitManager()->getUnit(i)->mIsSpinning == false && mIsSpinning == true)
				{
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				}
				else
				{
					if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this)
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
				}
			}
		}
		
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++) 
	{
		if (mCurrentDirection == LEFT)
		{
			if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < maxY
				)
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
		}
		else
		{
			if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < maxY
				)
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
		}
	}


	if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX > minX &&
		Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX < maxX &&
		Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY > minY &&
		Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < maxY
		)
	{
		if (mIsStationary && mTimesBouncedOn > 2)//if the koopa is stationary, and it has been bounced on multiple times, then it will spin.
		{
			if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX < mCurrentLocation.mX && Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY)
			{
				mCurrentDirection = LEFT;
				mIsStationary = false;
				mIsSpinning = true;
				swapAnimation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION);
			}
			else if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX > mCurrentLocation.mX && Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY)
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
			mTimesBouncedOn ++;//this means if they player is still jumping on the koopa, it still gets a bounced value
		}
	}


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