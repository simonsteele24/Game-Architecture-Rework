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
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == LAVA)
				{
					destroyThisGameObject(Game::getStaticInstance()->getUnitManager());
					break;
				}
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
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY - 20
				)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == LAVA)
				{
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				}
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
		else
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY - 20
				)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == LAVA)
				{
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				}
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
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > minX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < maxX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > minY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY - 20
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
				Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < maxY - 20
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
		if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < mCurrentLocation.mY && mIsWalking == true) 
		{
			mIsWalking = false;
			mCooldownRemaining = DRYBONES_COOLDOWN_TIME;
			swapAnimation(NAME_OF_DRY_BONES_DOWN_ANIMATION);
		}
	}


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