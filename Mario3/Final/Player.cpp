#include "Player.h"
#include "Game.h"



// This function is the default constructor for the class 
Player::Player() : Unit()
{
	mUnitType = PLAYER;
	mVelocity = 0;
	mMaxJumpForce = -1.5 * Game::getStaticInstance()->getJumpForce();
	mIsJumping = false;
	mInMidAir = false;
	mBounce = false;
	mIsMoving = false;
	mCurrentDirection = RIGHT;
	mIsDying = false;
	mIsTrigger = false;
	mTargetTime = DEFAULT_SPEED;
	mTimeElapsed = mTargetTime;
	mTimeElapsedInvincibilityFrame = mTargetTime;
}





// This constructor moves the player Unit to a given position
Player::Player(Vector2 newPos) 
{
	mCurrentLocation = newPos;
	mCurrentLocation.mY -= 10.0f;//this is tweaking the y so its not spawnning inside accidently
	mUnitType = PLAYER;
	mVelocity = 0;
	mMaxJumpForce = -1.5 * Game::getStaticInstance()->getJumpForce();
	mIsJumping = false;
	mInMidAir = false;
	mBounce = false;
	mIsMoving = false;
	mCurrentDirection = RIGHT;
	mIsDying = false;
	mIsTrigger = false;
	mTargetTime = DEFAULT_SPEED;
	mTimeElapsed = mTargetTime;
	mTimeElapsedInvincibilityFrame = mTargetTime;
}





// This is the destructor for the class
Player::~Player()
{

}





// This function is the update function for the Player Unit
void Player::update(double newTimeBetweenFrames) 
{
	mInMidAir = true;

	if (isAnimationStopped == false)
	{
		if (mIsMoving == false) 
		{
			mCurrentAnimations[mCurrentAnimationIndex]->resetAnimationIndex();
		}
		else 
		{
			// The following code updates the current frame of the animation
			mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
		
		}
	}

	powerUpTimer((float)newTimeBetweenFrames);//updates timer for any active powerups
	invincibilityFrameTimer((float)newTimeBetweenFrames);//updates timer for player dmg taken

	if (mCurrentLocation.mY > Game::getStaticInstance()->getDisplayDimensions().mY) 
	{
		Game::getStaticInstance()->deductLife();
	}

	// Check for collision here
	mVelocity += Game::getStaticInstance()->getGravityScale();

	if (mIsDying == false)
	{
		unitCollisions();//find/check collisions for any units in the unit manager
	}

	switch (mCurrentDirection)
	{
	case LEFT:
		for (int i = 0; i < (int)mCurrentAnimations.size(); i++)
		{
			mCurrentAnimations[i]->invertAnimation(-1);
		}
		break;
	case RIGHT:
		for (int i = 0; i < (int)mCurrentAnimations.size(); i++)
		{
			mCurrentAnimations[i]->invertAnimation(1);
		}
		break;
	default:
		break;
	}


	if (mInMidAir && mIsDying == false) 
	{
		if (mIsThicc == true)
			swapAnimation(NAME_OF_SUPER_PLAYER_JUMP);
		else if (mIsThicc == false)
			swapAnimation(NAME_OF_PLAYER_JUMP);

		if (mInvincible == true && !mIsThicc)
		{
			switch (getIndexOfColor())
			{
			case 0://original
				swapAnimation(NAME_OF_PLAYER_JUMP);
				break;

			case 1://second color
				swapAnimation(NAME_OF_PLAYER_RED_JUMP);
				break;

			case 2://third color
				swapAnimation(NAME_OF_PLAYER_GREEN_JUMP);
				break;

			default://default is original
				swapAnimation(NAME_OF_PLAYER_JUMP);
				break;
			}
		}
		else if(mInvincible && mIsThicc)
		{
			switch (getIndexOfColor())
			{
			case 0://original
				swapAnimation(NAME_OF_SUPER_PLAYER_JUMP);
				break;

			case 1://second color
				swapAnimation(NAME_OF_SUPER_PLAYER_RED_JUMP);
				break;

			case 2://third color
				swapAnimation(NAME_OF_SUPER_PLAYER_GREEN_JUMP);
				break;

			default://default is original
				swapAnimation(NAME_OF_SUPER_PLAYER_JUMP);
				break;
			}
		}
	}
	else if (mIsDying == false)
	{
		if (mIsThicc == true)
			swapAnimation(NAME_OF_SUPER_PLAYER);
		else if (mIsThicc == false)
			swapAnimation(NAME_OF_PLAYER);
		
		if (mInvincible == true && !mIsThicc)
		{

			switch (getIndexOfColor())
			{
			case 0://original
				swapAnimation(NAME_OF_PLAYER);
				break;

			case 1://second color
				swapAnimation(NAME_OF_PLAYER_RED);
				break;

			case 2://third color
				swapAnimation(NAME_OF_PLAYER_GREEN);
				break;

			default://default is original
				swapAnimation(NAME_OF_PLAYER);
				break;
			}
		}
		else if (mInvincible && mIsThicc)
		{
			switch (getIndexOfColor())
			{
			case 0://original
				swapAnimation(NAME_OF_SUPER_PLAYER);
				break;

			case 1://second color
				swapAnimation(NAME_OF_SUPER_PLAYER_RED);
				break;

			case 2://third color
				swapAnimation(NAME_OF_SUPER_PLAYER_GREEN);
				break;

			default://default is original
				swapAnimation(NAME_OF_SUPER_PLAYER);
				break;
			}
		}
	}

	// Is the player about to jump?
	if (mIsJumping && mIsDying == false) 
	{
		// Set the velocity to the force of a jump
		mVelocity = -(Game::getStaticInstance()->getJumpForce());
		mIsJumping = false;
	}

	moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + mVelocity));

	switch (Game::getStaticInstance()->getUnitManager()->getCameraDirection())
	{
	case SHIFTLEFT:
		moveToPosition(Vector2(mCurrentLocation.mX - (Game::getStaticInstance()->getPlayerWalkSpd()), mCurrentLocation.mY));
		break;
	case SHIFTRIGHT:
		moveToPosition(Vector2(mCurrentLocation.mX + (Game::getStaticInstance()->getPlayerWalkSpd()), mCurrentLocation.mY));
		break;
	default:
		break;
	}
	mIsMoving = false;
}





// This function changes the velocity such that the player jumps
void Player::jump() 
{
	// Is the player grounded?
	if (mVelocity == 0 && mIsDying == false) 
	{
		mBounceKills = 0;
		// If yes, then let the player jump
		mIsJumping = true;
		//EventSystem::getStaticInstance()->fireEvent((Event(MAKE_PLAYER_JUMP)));
	}
}





// This function moves the player unit right
void Player::movePlayerLeft() 
{
	bool canMove = true;

    double minX = mCurrentLocation.mX - Game::getStaticInstance()->getPlayerWalkSpd();
	double maxX = mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX - Game::getStaticInstance()->getPlayerWalkSpd();
	double minY = mCurrentLocation.mY;
	double maxY = mCurrentLocation.mY + Game::getStaticInstance()->getPlayerBounds().mY - 1.3;

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++) 
	{
		double minXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX;
		double maxXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mX);
		double minYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY;
		double maxYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mY);

		if (maxXOne > minX &&
			minXOne < maxX &&
			minYOne < maxY &&
			maxYOne > minY
			)
		{
			canMove = false;
		}
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++)
	{
		double minXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX;
		double maxXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mX);
		double minYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY;
		double maxYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mY);

		if (maxXOne > minX &&
			minXOne < maxX &&
			minYOne < maxY &&
			maxYOne > minY
			)
		{
			canMove = false;
		}

	}

	if (canMove && mIsDying == false) 
	{
		mIsMoving = true;
		mCurrentDirection = LEFT;
		if (mCurrentLocation.mX - Game::getStaticInstance()->getPlayerWalkSpd() < Game::getStaticInstance()->getCameraLeftOffset() && Game::getStaticInstance()->getUnitManager()->getCameraPosition().mX > 0)
		{
			Game::getStaticInstance()->getUnitManager()->addToCameraPosition(Vector2(-(Game::getStaticInstance()->getPlayerWalkSpd()), 0));
			moveToPosition(Vector2(Game::getStaticInstance()->getCameraLeftOffset(), mCurrentLocation.mY));
			Game::getStaticInstance()->getUnitManager()->setCameraDirection(SHIFTRIGHT);
		}
		moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getPlayerWalkSpd(), mCurrentLocation.mY));
	}
}

void Player::unitCollisions()
{
	bool mNotModifiedByVelocity = false;

	Vector2 startPos = mCurrentLocation;//used to reset positions of need be

	double minX = mCurrentLocation.mX;
	double maxX = mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX;
	double minY = mCurrentLocation.mY;
	double maxY = mCurrentLocation.mY + Game::getStaticInstance()->getPlayerBounds().mY - 1;

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		double minXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX;
		double maxXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mX);
		double minYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY;
		double maxYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mY );

		if (maxXOne > minX &&
			minXOne < maxX &&
			minYOne < maxY &&
			maxYOne > minY
			)
		{
			double defaultVelocity = mVelocity;
			mVelocity = 0;

			powerUpCollisions(i);//find/check collisions for any powerups in the powerup manager

			//Question Block
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + 23.0f < mCurrentLocation.mY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == QUESTION_BLOCK)
			{
				cout << Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY << endl;
				cout << mCurrentLocation.mY << endl;
				moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + 1.0));
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getEffectStatus() != false)
				{
					Game::getStaticInstance()->getUnitManager()->getUnit(i)->setEffect(false);
					Game::getStaticInstance()->addToCoinAmount();
					Game::getStaticInstance()->getUnitManager()->getUnit(i)->swapAnimation(NAME_OF_EMPTY_QUESTION_BLOCK);
				}
				mBounce = false;
			}
			//Boom Boom
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == BOOMBOOM)
			{
				mBounce = false;
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDamageState() == false)
				{
					if (mIsThicc)
					{
						mStillThicc = false;
					}
					else
						commenceDeath();
				}
			}
			//Coin
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == COIN)
			{
				Game::getStaticInstance()->addToCoinAmount();
				Game::getStaticInstance()->getUnitManager()->destroyUnit(i);//destroy unit
				mBounce = false;
				mIsTrigger = true;
				mVelocity = defaultVelocity;
				mNotModifiedByVelocity = true;
			}
			//Brick Block
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + 23.0f < mCurrentLocation.mY && Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == BRICK_BLOCK)
			{
				moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY + 1.0));
				if (mIsThicc)
				{
					Game::getStaticInstance()->addToScore(10);
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				}
			
				
				mBounce = false;
			}
			//End Block
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < mCurrentLocation.mY && Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == END_BLOCK)
			{
				Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
				Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier()));
				Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
				Game::getStaticInstance()->loadLevel();
				return;
				mBounce = false;
			}
			//Lava
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == LAVA)
			{
				commenceDeath();
				mBounce = true;
			}
			//Fireball
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == FIREBALL && !mInvincible)
			{
				if (mIsThicc)
				{
					mStillThicc = false;
				}
				else
					commenceDeath();
		
				mBounce = false;
			}
			//Thwomp
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == THWOMP && !mInvincible)
			{
				if (mIsThicc)
				{
					mStillThicc = false;
				}
				else
					commenceDeath();

				mBounce = true;
			}
			//Goomba
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == GOOMBA)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > mCurrentLocation.mY)
				{
					//200, 400, 800, 1600, 3200, and 6400 . At the 7+ bounce kill they get 1 extra life for each enemy
					mBounceKills += 1;
					Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier() * mBounceKills));
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);//destroy unit
					mBounce = true;//player can bounce
				}
				else
				{
					if (!mInvincible)
					{
						if (mIsThicc)
						{
							mStillThicc = false;
						}
						else
							commenceDeath();
					}
				
					mBounce = true;
				}

			}
			//Koopa
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == KOOPA)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > mCurrentLocation.mY)
				{
					if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit == false && Game::getStaticInstance()->getUnitManager()->getUnit(i)->mIsSpinning == true)
					{
						mBounceKills += 1;
						Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit = true;//the unit has been hit
						Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier() * mBounceKills));//add to member score variable
						Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));//pass in the variable to change score
						//mCanDestroyTarget = false;//reset it			
					}
				}
				else
				{
					if (!mInvincible)
					{
						if (mIsThicc)
						{
							mStillThicc = false;
						}
						else
							commenceDeath();
					}
				}

				mBounce = true;//player can bounce
			}
			//Dry Bones
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == DRYBONES)
			{
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > mCurrentLocation.mY)
				{
					if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit == false)
					{
						mBounceKills += 1;
						Game::getStaticInstance()->getUnitManager()->getUnit(i)->mSuccessfulHit = true;//the unit has been hit
						Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier() * mBounceKills));//add to member score variable
						Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));//pass in the variable to change score
						//mCanDestroyTarget = false;//reset it			
					}
				}
				else
				{
					if (!mInvincible)
					{
						if (mIsThicc)
						{
							mStillThicc = false;
						}
						else
							commenceDeath();
					}
				}
				mBounce = true;//player can bounce
			}
			//Piranha Plant
			else if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == PIRANHAPLANT && !mInvincible)
			{
				if (mIsThicc)
				{
					mStillThicc = false;
				}
				else
					commenceDeath();
			
				mBounce = true;
			}

			else if (mIsJumping == false)
			{
				mInMidAir = false;
				mBounce = false;
				mBounceKills = 0;
			}

			if (mBounce == true)
			{
				mVelocity = 0;
				mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by

				if (mVelocity < mMaxJumpForce)
				{
					mVelocity = 0;
					mVelocity += Game::getStaticInstance()->getJumpForce() - 5.0f;//if it gets too much, this will act as a ceiling and limit the drastic bounce.
				}
			}
			else
			{
				if (mCurrentLocation.mY < Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY && !mIsTrigger)
				{
					mCurrentLocation = (Vector2(mCurrentLocation.mX, Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY - Game::getStaticInstance()->getPlayerBounds().mY + 1.1));
				}
				else if (mCurrentLocation.mY < Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY && mIsTrigger)
				{
					mIsTrigger = false;
				}
				if (mNotModifiedByVelocity == false)
				{			
					mVelocity = 0;
				}
			}
			//Check to make sure player cant jump after hitting ceiling
			if (mCurrentLocation.mY + 1.1f > Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY)
			{
				mIsJumping = false;
			}
			//Check to make sure player cant jump after hitting tile ceilings
			if (mCurrentLocation.mY + 1.1f > Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY)
			{
				mIsJumping = false;
			}
			//these two check to see if the player hits the sides, if so, move the player and apply gravity
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < mCurrentLocation.mY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX  < mCurrentLocation.mX )
			{
				moveToPosition(Vector2(mCurrentLocation.mX + 1.0f, mCurrentLocation.mY));
				mVelocity += Game::getStaticInstance()->getGravityScale();
			}
			else if(Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < mCurrentLocation.mY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > mCurrentLocation.mX)
			{
				moveToPosition(Vector2(mCurrentLocation.mX - 1.0f, mCurrentLocation.mY));
				mVelocity += Game::getStaticInstance()->getGravityScale();
			}
		}
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getPlatformSize(); i++)
	{
		if (Game::getStaticInstance()->getUnitManager()->getPlatform(i)->getLocation().mX + Game::getStaticInstance()->getUnitManager()->getPlatform(i)->getDimensions().mX - 23.0f > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getPlatform(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getPlatform(i)->getLocation().mY > (mCurrentLocation.mY) + Game::getStaticInstance()->getPlayerBounds().mY &&
			Game::getStaticInstance()->getUnitManager()->getPlatform(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getPlayerBounds().mY &&
			mVelocity > 0
			)
		{
			mVelocity = 0;
			mInMidAir = false;
		}
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++) 
	{
		if (Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX + Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mX - 23.0f > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY >(mCurrentLocation.mY + mVelocity) - Game::getStaticInstance()->getPlayerBounds().mY &&
			Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getPlayerBounds().mY &&
			(mCurrentLocation.mY + mVelocity) < Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY
			)
		{
			mVelocity = 0;
			mInMidAir = false;
		}
	}

}


void Player::powerUpCollisions(int i)
{
			if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX > mCurrentLocation.mX - Game::getStaticInstance()->getPlayerBounds().mX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX < mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY > (mCurrentLocation.mY + mVelocity) - Game::getStaticInstance()->getPlayerBounds().mY &&
				Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY < (mCurrentLocation.mY + mVelocity) + Game::getStaticInstance()->getPlayerBounds().mY)
			{
				//Super Mushroom
				if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == SUPER_MUSHROOM)
				{
					moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY - Game::getStaticInstance()->getUnitManager()->getPlayer()->mDimensions.mY));//move player so they arent inside anything
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
					Game::getStaticInstance()->addToScore(1000);
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
					mIsThicc = true;
					mStillThicc = true;
					mBounce = false;
				}
				//Starmen
				else 	if (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getCurrentUnitType() == STARMEN)
				{
					Game::getStaticInstance()->getUnitManager()->destroyUnit(i);
					Game::getStaticInstance()->addToScore(1000);
					Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
					mInvincible = true;
					mBounce = false;
				}
			}
}

void Player::readyToKill(bool kill)
{
	mCanDestroyTarget = kill;
}




// This function moves the player unit right
void Player::movePlayerRight() 
{
	bool canMove = true;

	double minX = mCurrentLocation.mX + Game::getStaticInstance()->getPlayerWalkSpd();
	double maxX = mCurrentLocation.mX + Game::getStaticInstance()->getPlayerBounds().mX + Game::getStaticInstance()->getPlayerWalkSpd();
	double minY = mCurrentLocation.mY;
	double maxY = mCurrentLocation.mY + Game::getStaticInstance()->getPlayerBounds().mY - 1.3;

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getSize(); i++)
	{
		double minXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX;
		double maxXOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mX);
		double minYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY;
		double maxYOne = Game::getStaticInstance()->getUnitManager()->getUnit(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getUnit(i)->getDimensions().mY);

		if (maxXOne > minX &&
			minXOne < maxX &&
			minYOne < maxY &&
			maxYOne > minY
			)
		{
			canMove = false;
		}
	}

	for (int i = 0; i < Game::getStaticInstance()->getUnitManager()->getTileSize(); i++)
	{
		double minXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX;
		double maxXOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mX + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mX);
		double minYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY;
		double maxYOne = Game::getStaticInstance()->getUnitManager()->getTile(i)->getLocation().mY + (Game::getStaticInstance()->getUnitManager()->getTile(i)->getDimensions().mY);

		if (maxXOne > minX &&
			minXOne < maxX &&
			minYOne < maxY &&
			maxYOne > minY
			)
		{
			canMove = false;
		}

	}

	if (canMove && mIsDying == false)
	{
		mIsMoving = true;
		mCurrentDirection = RIGHT;
		if (mCurrentLocation.mX + Game::getStaticInstance()->getPlayerWalkSpd() > Game::getStaticInstance()->getCameraRightOffset() && Game::getStaticInstance()->getUnitManager()->getCameraPosition().mX < LENGTH_OF_LEVEL)
		{
			Game::getStaticInstance()->getUnitManager()->addToCameraPosition(Vector2(Game::getStaticInstance()->getPlayerWalkSpd(), 0));
			moveToPosition(Vector2(Game::getStaticInstance()->getCameraRightOffset(), mCurrentLocation.mY));
			Game::getStaticInstance()->getUnitManager()->setCameraDirection(SHIFTLEFT);
		}
		moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getPlayerWalkSpd(), mCurrentLocation.mY));
	}
}


int Player::getIndexOfColor()
{
	if (colorIndex > 2)
	{
		colorIndex = 0;
	}
	return colorIndex;
}


// This function sets the ability of death to true
void Player::commenceDeath() 
{
	swapAnimation(NAME_OF_PLAYER_DEATH_ANIMATION);
	mIsDying = true;
}

void Player::setGameStatus(bool status)
{
	mDone = status;
}

void Player::powerUpTimer(float timeReducer)
{
	mTimeElapsed -= timeReducer * 2;

	if (mTimeElapsed <= 0.0)
	{
		if (mInvincible)
		{
			addIndex();
			timeLimit--;
			calculateTimeToAdd();
		}
		mTimeElapsed = mTargetTime;
	}
}

void Player::invincibilityFrameTimer(float timeReducer)
{
	mTimeElapsedInvincibilityFrame -= timeReducer;

	if (mTimeElapsedInvincibilityFrame <= 0.0)
	{
		if (mStillThicc == false)
		{
			invincibilityCounter++;
			if (invincibilityCounter == 10)
			{
 				mIsThicc = false;
				invincibilityCounter = 0;
			}
				
		}	
		mTimeElapsedInvincibilityFrame = mTargetTime;
	}
}

void Player::calculateTimeToAdd()
{
	if (mInvincible == true)
	{
		if (timeLimit <= 0)
		{
			mInvincible = false;
			colorIndex = 0;
			timeLimit = 100;
		}
	}
}
