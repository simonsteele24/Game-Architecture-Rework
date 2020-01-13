#include "Animation.h"
#include "Game.h"

// This function is the default constructor for this class
Animation::Animation()
{
	mCurrentIndex = Vector2(0,0);
	mTargetTime = DEFAULT_SPEED;
	mTimeElapsed = mTargetTime;
	mNameOfAnimation = "";
}





// This constructor takes in the sprite sheet, the sprites per row and column, dimensions, and the display dimensions
// To divide the a given sprite to create an animation
Animation::Animation(string name, GraphicsBuffer * spriteSheet, int spritesPerRow, int spritesPerColumn, Vector2 displayDimensions, Vector2 spriteDimensions )
{
	mUpdateIncrementor = 0;
	mNameOfAnimation = name;
	addSprite(new Sprite(new GraphicsBuffer(*spriteSheet), 0, 0, true, spriteDimensions));
	mSpritesPerRowAndColumn = Vector2(spritesPerRow, spritesPerColumn);
	mSpriteDimensions = spriteDimensions;

	mCurrentIndex = Vector2(0, 0); // Initialize all member variables
	mTargetTime = DEFAULT_SPEED;
	mTimeElapsed = mTargetTime;
	getCurrentSprite()->getGraphicsBuffer()->setIntRect((int)(mSpriteDimensions.mX * mCurrentIndex.mX), (int)(mCurrentIndex.mY * mSpriteDimensions.mY), (int)mSpriteDimensions.mX, (int)mSpriteDimensions.mY);
}





// This function is the destructor for this class
Animation::~Animation()
{
	if (mHasCleanedUp == false) 
	{
		//delete mListOfSprites;
	}
}





// This function checks by frame for what sprite to draw in the animation loop
void Animation::update( double framesPassed ) 
{
	// The following code subtracts the time that has passed and if
	// enough time has passed, it will change frames
 	mTimeElapsed -= framesPassed;

	if ((int)Game::getStaticInstance()->time%(int)mTargetTime <= 10 || (int)Game::getStaticInstance()->time % (int)mTargetTime >= 90)
	{
		updateSprite();
		mTimeElapsed = mTargetTime;
	}
}





// This function adds a sprite, which is determined from function call in main
void Animation::addSprite( Sprite * spriteToAdd )
{
	mListOfSprites = spriteToAdd;
}





// This function adjusts the speed of animation, which is determined from function call in main
void Animation::adjustCurrentSpeed( double speedToBeAdded )
{
	mTargetTime += speedToBeAdded;
}





// This function gets the current sprite of the animation
Sprite * Animation::getCurrentSprite() 
{
	return mListOfSprites;
}





// This function updates the current sprite being display
void Animation::updateSprite()
{

	// The following code determines if the current animation frame is the
	// last frame in the animation. If it is, cycle back to the start of the
	// vector other wise just go to the next frame.

	mCurrentIndex.mX++;

	if (mCurrentIndex.mX >= mSpritesPerRowAndColumn.mY)
	{
		mCurrentIndex.mX = 0;
		mCurrentIndex.mY++;
		if (mCurrentIndex.mY >= mSpritesPerRowAndColumn.mX)
		{
			mCurrentIndex.mY = 0;
		}
	}

	// Update the current sprite displayed

	if (!mIsInverted) 
	{
		getCurrentSprite()->getGraphicsBuffer()->setIntRect((int)(mSpriteDimensions.mX * mCurrentIndex.mX), (int)(mCurrentIndex.mY * mSpriteDimensions.mY), (int)mSpriteDimensions.mX, (int)mSpriteDimensions.mY);
	}
	else
	{
		getCurrentSprite()->getGraphicsBuffer()->setIntRect((int)(mSpriteDimensions.mX * mCurrentIndex.mX) + (int)mSpriteDimensions.mX, (int)(mCurrentIndex.mY * mSpriteDimensions.mY), -(int)mSpriteDimensions.mX, (int)mSpriteDimensions.mY);
	}

	
}





// This function updates all of the sprite positions of the animation. 
// This is called from unit so the position update is based on where the unit is position
void Animation::updateSpritePositions( Vector2 newPos ) 
{
	mListOfSprites->changeLoc((int)newPos.mX, (int)newPos.mY);
}





void Animation::cleanupAnimation() 
{
	mHasCleanedUp = true;
}





// This function resets the animation index to zero
void Animation::resetAnimationIndex() 
{
	mCurrentIndex = Vector2(0, 0);
}





// This function gets the name of the animation clip
string Animation::getAnimationName() 
{
	return mNameOfAnimation;
}





// This function sets the animation index to a given value
void Animation::setAnimationIndex(int newIndex) 
{
}





// This function gets the current index of the animation
int Animation::getAnimationIndex()
{
	return 0;
}





// This function gets the dimensions of the animation
Vector2 Animation::getAnimationDimensions() 
{
	return mSpriteDimensions;
}





void Animation::invertAnimation(int val) 
{
	if (val > 0) 
	{
		mIsInverted = false;
	}
	else 
	{
		mIsInverted = true;
	}
}





void Animation::forceUpdateInversion() 
{
	if (!mIsInverted)
	{
		getCurrentSprite()->getGraphicsBuffer()->setIntRect((int)(mSpriteDimensions.mX * mCurrentIndex.mX), (int)(mCurrentIndex.mY * mSpriteDimensions.mY), (int)mSpriteDimensions.mX, (int)mSpriteDimensions.mY);
	}
	else
	{
		getCurrentSprite()->getGraphicsBuffer()->setIntRect((int)(mSpriteDimensions.mX * mCurrentIndex.mX) + (int)mSpriteDimensions.mX, (int)(mCurrentIndex.mY * mSpriteDimensions.mY), -(int)mSpriteDimensions.mX, (int)mSpriteDimensions.mY);
	}
}