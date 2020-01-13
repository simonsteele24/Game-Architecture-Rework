#include "Player.h"
#include "Game.h"



// This function is the default constructor for the class 
Player::Player() : Unit()
{
	mUnitType = PLAYER;
	mUnitMovability = MOVEABLE;
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
	mUnitMovability = MOVEABLE;
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

	if (mIsJumping && mVelocity == 0) 
	{
		mIsJumping = false;
		mInMidAir = true;
		Game::getStaticInstance()->getAudioManager()->playSound("Jump");
		mVelocity = -(Game::getStaticInstance()->getJumpForce());
	}
	else {
		mIsJumping = false;
	}

	powerUpTimer((float)newTimeBetweenFrames);//updates timer for any active powerups
	invincibilityFrameTimer((float)newTimeBetweenFrames);//updates timer for player dmg taken

	if (mCurrentLocation.mY > Game::getStaticInstance()->getDisplayDimensions().mY) 
	{
		Game::getStaticInstance()->deductLife();
	}

	if (mIsDying == false)
	{
		unitCollisions();//find/check collisions for any units in the unit manager
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

	mVelocity += Game::getStaticInstance()->getGravityScale();

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

	switch (mCurrentDirection)
	{
	case LEFT:
		for (int i = 0; i < (int)mCurrentAnimations.size(); i++)
		{
			mCurrentAnimations[i]->invertAnimation(-1);
			mCurrentAnimations[i]->forceUpdateInversion();
		}
		break;
	case RIGHT:
		for (int i = 0; i < (int)mCurrentAnimations.size(); i++)
		{
			mCurrentAnimations[i]->invertAnimation(1);
			mCurrentAnimations[i]->forceUpdateInversion();
		}
		break;
	default:
		break;
	}
}





// This function changes the velocity such that the player jumps
void Player::jump() 
{
	if (!mInMidAir && mIsDying == false) 
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
	if (mIsDying == false) 
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
}

void Player::readyToKill(bool kill)
{
	mCanDestroyTarget = kill;
}




// This function moves the player unit right
void Player::movePlayerRight() 
{
	if (mIsDying == false)
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

void Player::onCollide(Unit & collidingObject, int collidingObjectIndex) 
{
	switch (collidingObject.getCurrentUnitType())
	{
	case COIN:
		Game::getStaticInstance()->addToCoinAmount();
		Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);
		Game::getStaticInstance()->getAudioManager()->playSound("Coin");
		break;
	case QUESTION_BLOCK:
		if (mCurrentLocation.mY >= collidingObject.getLocation().mY + collidingObject.getDimensions().mY && mVelocity < 0) 
		{
			mVelocity = 0;
			if (Game::getStaticInstance()->getUnitManager()->getUnit(collidingObjectIndex)->getEffectStatus() != false)
			{
				Game::getStaticInstance()->getUnitManager()->getUnit(collidingObjectIndex)->setEffect(false);
				Game::getStaticInstance()->addToCoinAmount();
				Game::getStaticInstance()->getAudioManager()->playSound("Coin");
				Game::getStaticInstance()->getUnitManager()->getUnit(collidingObjectIndex)->swapAnimation(NAME_OF_EMPTY_QUESTION_BLOCK);
			}
		}
		else if (mCurrentLocation.mY <= collidingObject.getLocation().mY - collidingObject.getDimensions().mY) 
		{
			mVelocity = 0;
			mInMidAir = false;
		}
		break;
	case END_BLOCK:
		Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);
		Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier()));
		Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
		Game::getStaticInstance()->loadLevel();
		break;
	case PIRANHAPLANT:

		if (!mInvincible) 
		{
			if (mIsThicc)
			{
				mStillThicc = false;
			}
			else
				commenceDeath();

			mVelocity = 0;
			mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by

			if (mVelocity < mMaxJumpForce)
			{
				mVelocity = 0;
				mVelocity += Game::getStaticInstance()->getJumpForce() - 5.0f;//if it gets too much, this will act as a ceiling and limit the drastic bounce.
			}
		}
		break;
	case BOOMBOOM :
		if (Game::getStaticInstance()->getUnitManager()->getUnit(collidingObjectIndex)->getDamageState() == false)
		{
			if (mIsThicc)
			{
				mStillThicc = false;
			}
			else
				commenceDeath();
		}
		break;
	case BRICK_BLOCK:
		if (mCurrentLocation.mY >= collidingObject.getLocation().mY + collidingObject.getDimensions().mY)
		{
			mVelocity = 0;
			if (mIsThicc)
			{
				Game::getStaticInstance()->addToScore(10);
				Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
				Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);
			}
		}
		else if (mCurrentLocation.mY <= collidingObject.getLocation().mY - collidingObject.getDimensions().mY)
		{
			mVelocity = 0;
			mInMidAir = false;
		}
		break;
	case LAVA:
		commenceDeath();
		mVelocity = 0;
		mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by

		if (mVelocity < mMaxJumpForce)
		{
			mVelocity = 0;
			mVelocity += Game::getStaticInstance()->getJumpForce() - 5.0f;//if it gets too much, this will act as a ceiling and limit the drastic bounce.
		}
		break;
	case FIREBALL:
		if (!mInvincible) 
		{
			if (mIsThicc)
			{
				mStillThicc = false;
			}
			else
				commenceDeath();
			mVelocity = 0;
			mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by

			if (mVelocity < mMaxJumpForce)
			{
				mVelocity = 0;
				mVelocity += Game::getStaticInstance()->getJumpForce() - 5.0f;//if it gets too much, this will act as a ceiling and limit the drastic bounce.
			}
		}
		break;
	case THWOMP:
		if (!mInvincible) 
		{
			if (mIsThicc)
			{
				mStillThicc = false;
			}
			else
				commenceDeath();
			mVelocity = 0;
			mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by

			if (mVelocity < mMaxJumpForce)
			{
				mVelocity = 0;
				mVelocity += Game::getStaticInstance()->getJumpForce() - 5.0f;//if it gets too much, this will act as a ceiling and limit the drastic bounce.
			}
		}
		break;
	case GOOMBA:
		if (collidingObject.getLocation().mY > mCurrentLocation.mY && mCurrentLocation.mY <= collidingObject.getLocation().mY - collidingObject.getDimensions().mY)
		{
			//200, 400, 800, 1600, 3200, and 6400 . At the 7+ bounce kill they get 1 extra life for each enemy
			mBounceKills += 1;
			Game::getStaticInstance()->addToScore(Game::getStaticInstance()->getScoreAddAmt() * (Game::getStaticInstance()->getScoreMultiplier() * mBounceKills));
			Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
			Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);//destroy unit
			mVelocity = 0;
			mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by
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
		break;
	case KOOPA:
		if (collidingObject.getLocation().mY > mCurrentLocation.mY)
		{
			mVelocity = 0;
			mVelocity -= Game::getStaticInstance()->getJumpForce() - 5.0f;//substract from velocity the JUMP force times what multiplier we want bounce force by
		}
		else if (!collidingObject.mIsStationary && !(collidingObject.mCurrentDirection == LEFT && collidingObject.mCurrentLocation.mX < mCurrentLocation.mX) && !(collidingObject.mCurrentDirection == RIGHT && collidingObject.mCurrentLocation.mX > mCurrentLocation.mX))
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
		break;
	case DRYBONES:
		if (collidingObject.getLocation().mY > mCurrentLocation.mY)
		{
			if (collidingObject.mSuccessfulHit == false)
			{
				mBounceKills += 1;
				collidingObject.mSuccessfulHit = true;//the unit has been hit
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
		break;
	case SUPER_MUSHROOM:
		moveToPosition(Vector2(mCurrentLocation.mX, mCurrentLocation.mY - Game::getStaticInstance()->getUnitManager()->getPlayer()->mDimensions.mY));//move player so they arent inside anything
		Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);
		Game::getStaticInstance()->addToScore(1000);
		Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
		mIsThicc = true;
		mStillThicc = true;
		break;
	case STARMEN:
		Game::getStaticInstance()->getUnitManager()->destroyUnit(collidingObjectIndex);
		Game::getStaticInstance()->addToScore(1000);
		Game::getStaticInstance()->getTextManager()->getText(NAME_OF_SCORE_AMOUNT_TEXT)->addScore((Game::getStaticInstance()->getTotalScore()));
		mInvincible = true;
		mBounce = false;
		break;
	case PLATFORM:
		mInMidAir = false;
		mVelocity = 0;
		break;
	case PIPE:
		if (mCurrentLocation.mY <= collidingObject.getLocation().mY - mDimensions.mY) 
		{
			mInMidAir = false;
			mVelocity = 0;
		}
		break;
	default:
		mInMidAir = false;
		mVelocity = 0;
		break;
	}
}