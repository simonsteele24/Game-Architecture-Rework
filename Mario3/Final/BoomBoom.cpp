#include "BoomBoom.h"
#include "Game.h"

//Default constructor
BoomBoom::BoomBoom()
{
	mUnitType = BOOMBOOM;
	phase = WALK_MODE;
}

//Constructor that takes in a position
BoomBoom::BoomBoom(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mCurrentLocation.mY -= 25.0f;
	mUnitType = BOOMBOOM;
	mCurrentDirection = LEFT;
	phase = WALK_MODE;
}

//Constructor that takes in a position and the index of where it was created
BoomBoom::BoomBoom(Vector2 newPos, int newIndex)
{
	mCurrentLocation = newPos;
	mCurrentLocation.mY -= 25.0f;//this is extra security to make sure it doesn't spawn in an object.
	mUnitType = BOOMBOOM;
	mCurrentDirection = LEFT;//starting direction is left
	phase = WALK_MODE;//currently can move
	indexInUnitsManager = newIndex;
}

BoomBoom::~BoomBoom()
{
}

//update function that checks for collisions and animates
void BoomBoom::update(double newTimeBetweenFrames)
{
	if (!isDying)//if the boss isn't dead/dying
	{
		if (isAnimationStopped == false)
		{
			// The following code updates the current frame of the animation
			mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
			if (mCanChangeDirection)//if the boss can change directions count
				mCount++;
			if (mCount == mMaxCount)//once it reacjhes max, then it is possible to change direction
			{
				mChangeDirection = true;
				mCount = 0;
			}
			if (mPhaseChange)//same idea but with phase changes
			{
				mCurrentPhaseTime++;
				if (mCurrentPhaseTime > mTargetPhaseTime)
					mCurrentPhaseTime = 0;
			}
		}


		// Check for collision here
		mVelocity += Game::getStaticInstance()->getGravityScale();

		double minX = mCurrentLocation.mX;
		double maxX = mCurrentLocation.mX + mDimensions.mX;
		double minY = mCurrentLocation.mY;
		double maxY = mCurrentLocation.mY + mDimensions.mY - 1;

		for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
		{
			double minXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX;
			double maxXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mX);
			double minYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY;
			double maxYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mY);

			if (maxXOne > minX &&
				minXOne < maxX &&
				minYOne< maxY &&
				maxYOne > minY
				)
			{
				mVelocity = 0;

				if (Game::getStaticInstance()->getUnitManager()->getUnit(i) != this)
				{
					if (mCurrentDirection == LEFT)
					{
						mCurrentDirection = RIGHT;
						break;
					}
					else if (mCurrentDirection == RIGHT)
					{
						mCurrentDirection = LEFT;
						break;
					}
					else if (mCurrentDirection == UP)
					{
						mCurrentDirection = DOWN;
						break;
					}
					else if (mCurrentDirection == DOWN)
					{
						mCurrentDirection = STILL;
						break;
					}
				}
				//Collides with player
				//Walking Phase -> Injured Phase
				if (phase == WALK_MODE && Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mY < mCurrentLocation.mY &&
					Game::getStaticInstance()->getUnitManager()->getPlayer()->mCurrentLocation.mX  > this->mCurrentLocation.mX - 1.1f &&
					Game::getStaticInstance()->getUnitManager()->getPlayer()->mCurrentLocation.mX < this->mCurrentLocation.mX + 1.1f)
				{
					Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->setDamageState(true);
					phase = INJURED_MODE;
					mCurrentDirection = STILL;
					mPhaseChange = true;
					mTimesBouncedOn++;
					break;
				}
				//Injured Phase -> Defense Phase
				else if (phase == INJURED_MODE && mCurrentPhaseTime >= mTargetPhaseTime)
				{
					//if (mTimesBouncedOn >= 3)//if the boss has been injured 3 times or more, than it is dead/dying
					//{
					//	isDying = true;
					//	Game::getStaticInstance()->addToScore(1000);
					//	Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
					//	Game::getStaticInstance()->getUnitManager()->destroyUnit(indexInUnitsManager);
					//}
					phase = DEFENSE_MODE;
					mCurrentDirection = STILL;
					mPhaseChange = true;
					Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->setDamageState(false);
					break;
				}
				//Defense Phase -> Jump Phase
				else if (phase == DEFENSE_MODE && mCurrentPhaseTime >= mTargetPhaseTime)
				{
					phase = JUMP_MODE;
					mCurrentDirection = UP;
					mPhaseChange = true;
					Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->setDamageState(true);
					break;
				}
				//Jump Phase -> Walk Phase
				else if (phase == JUMP_MODE && mCurrentPhaseTime >= mTargetPhaseTime)
				{
					if (mTimesBouncedOn >= 1)//if the boss has been injured 3 times or more, than it is dead/dying
					{
						isDying = true;
						Game::getStaticInstance()->addToScore(1000);
						Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
						//Game::getStaticInstance()->getUnitManager()->destroyUnit(indexInUnitsManager);
						Game::getStaticInstance()->setStateOfApplication(false);
						break;
					}
					phase = WALK_MODE;
					mCurrentDirection = STILL;
					mPhaseChange = true;
					Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->setDamageState(true);
					break;
				}
				if (phase == WALK_MODE && Game::getStaticInstance()->getUnitManager()->getPlayer()->mCurrentLocation.mX > this->mCurrentLocation.mX)
				{
					mCanChangeDirection = true;
					if (mChangeDirection)
					{
						mCurrentDirection = RIGHT;
						mChangeDirection = false;
					}
					break;
				}
				else if (phase == WALK_MODE && Game::getStaticInstance()->getUnitManager()->getPlayer()->mCurrentLocation.mX < this->mCurrentLocation.mX)
				{
					mCanChangeDirection = true;
					if (mChangeDirection)
					{
						mCurrentDirection = LEFT;
						mChangeDirection = false;
					}
					break;
				}
				else
				{
					mCanChangeDirection = false;
					mPhaseChange = true;
				}

			}
		}

		for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
		{
			double minXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX;
			double maxXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mX);
			double minYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY;
			double maxYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mY);

			if (maxXOne > minX &&
				minXOne < maxX &&
				minYOne< maxY &&
				maxYOne > minY
				)
			{
				mVelocity = 0;
			}
		}

		if (!isDying)
		{


			for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++)
			{
				if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX + Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mX - 23.0f > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
					Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->getDimensions().mX &&
					Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->getDimensions().mY &&
					Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getUnitManager()->getUnit(indexInUnitsManager)->getDimensions().mY - 23.0f &&
					(mCurrentLocation.mY + mVelocity) < Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY
					)
				{
					double minXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX;
					double maxXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mX);
					double minYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY;
					double maxYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mY);

					if (maxXOne > minX &&
						minXOne < maxX &&
						minYOne< maxY &&
						maxYOne > minY
						)
					{
						mVelocity = 0;
					}
					else
						mVelocity += Game::getStaticInstance()->getGravityScale();
				}
			}
		}
		//Update animations according to the current phase.
		if (!isDying)
		{
			switch (phase)
			{
			case DEFENSE_MODE:
				swapAnimation(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION);
				break;
			case WALK_MODE:
				swapAnimation(NAME_OF_BOOMBOOM_ANIMATION);
				break;
			case JUMP_MODE:
				swapAnimation(NAME_OF_BOOMBOOM_JUMP_ANIMATION);
				break;
			case INJURED_MODE:
				swapAnimation(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION);
				break;
			default:
				break;
			}

			//Update the positions according to the current phase
			switch (mCurrentDirection)
			{
			case LEFT:
				moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
				break;
			case RIGHT:
				moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getGoombaWalkSpd(), mCurrentLocation.mY + mVelocity));
				break;
			case STILL:
				break;
			case UP:
				mVelocity += Game::getStaticInstance()->getGravityScale();
				moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY - (mVelocity * 15)));
				break;
			case DOWN:
				mVelocity += Game::getStaticInstance()->getGravityScale();
				if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX > mCurrentLocation.mX)
				{
					moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getUnitManager()->getPlayer()->mDimensions.mX, mCurrentLocation.mY + (mVelocity * 15)));
				}
				else if (Game::getStaticInstance()->getUnitManager()->getPlayer()->getLocation().mX < mCurrentLocation.mX)
				{
					moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getUnitManager()->getPlayer()->mDimensions.mX, mCurrentLocation.mY + (mVelocity * 15)));
				}
				else 
					moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + (mVelocity * 15)));
				break;
			default:
				break;
			}
		}
	}
}