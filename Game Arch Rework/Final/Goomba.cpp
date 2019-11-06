#include "Game.h"
#include "Goomba.h"



// This function is the default constructor for this class
Goomba::Goomba() : Unit()
{
	mUnitType = GOOMBA;
	mVelocity = 0.0;
	mCurrentDirection = LEFT;
}





// This constructor creates the Goomba unit at a given unit
Goomba::Goomba(Vector2 newPos) 
{
	mUnitType = GOOMBA;
	mCurrentLocation = newPos;
	mVelocity = 0.0;
	mCurrentDirection = LEFT;
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


	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - Game::getStaticInstance()->getPlayerBounds().mY &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getPlayerBounds().mY
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
		if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - Game::getStaticInstance()->getPlayerBounds().mY &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getPlayerBounds().mY
			)
		{
			mVelocity = 0;
		}
	}

	double minX = (mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd()) - Game::getStaticInstance()->getPlayerBounds().mX;
	double maxX = (mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd()) + Game::getStaticInstance()->getPlayerBounds().mX;
	double minY = mCurrentLocation.mY - Game::getStaticInstance()->getPlayerBounds().mY - 1;
	double maxY = mCurrentLocation.mY + Game::getStaticInstance()->getPlayerBounds().mY - 1;

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > minX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < maxX &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > minY &&
			Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < maxY
			)
		{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this) 
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == KOOPA && Game::getStaticInstance()->getUnitManager()->getUnit(i)->mIsSpinning)
				{
					Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit = true;//the unit has been hit
					Game::getStaticInstance()->addToScore(100);//add to member score variable
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));//pass in the variable to 
					destroyThisGameObject(Game::getStaticInstance()->getUnitManager());
				}
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

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++) 
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