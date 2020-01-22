#ifndef ANIMATION_H
#define ANIMATION_H

// Standard Library includes
#include <vector>

// Graphics Library includes
#include <Sprite.h>

// Doubles
const double  DEFAULT_SPEED = 100.0;

struct AnimationInformation
{
	int spritesPerRow;
	int spritesPerColumn;
	Vector2 mDisplayDimensions;
	Vector2 mSpriteDimensions;

	AnimationInformation()
	{

	}

	AnimationInformation(int _spritesPerRow, int _spritesPerColumn, Vector2 _mDisplayDimensions, Vector2 _mSpriteDimensions)
	{
		spritesPerRow = _spritesPerRow;
		spritesPerColumn = _spritesPerColumn;
		mDisplayDimensions = _mDisplayDimensions;
		mSpriteDimensions = _mSpriteDimensions;
	}
};

class Animation : public Trackable
{
public:

	// Constructors
	Animation();
	Animation( string name, GraphicsBuffer * spriteSheet, int spritesPerRow, int spritesPerColumn,  Vector2 displayDimensions, Vector2 spriteDimensions);

	// Destructors
	~Animation();
	void cleanupAnimation();

	// Update functions
	void update( double framesPassed );
	void updateSpritePositions( Vector2 newPos );
	void updateSprite();

	// Mutators
	void addSprite( Sprite & spriteToAdd );
	void adjustCurrentSpeed( double speedToBeAdded );
	void resetAnimationIndex();

	// Accessors
	Sprite getCurrentSprite();
	string getAnimationName();
	void setAnimationIndex(int newIndex);
	int getAnimationIndex();
	Vector2 getAnimationDimensions();
	void invertAnimation(int val);
	void forceUpdateInversion();

private:

	// Booleans
	bool mHasCleanedUp;
	bool mIsInverted = false;

	// Vectors
	Sprite mListOfSprites;

	// Vector2's
	Vector2 mSpritesPerRowAndColumn;
	Vector2 mSpriteDimensions;
	Vector2 mCurrentIndex;

	// Doubles
	double mTargetTime;
	double mTimeElapsed;

	// Integers
	int mUpdateIncrementor;

	// Strings
	string mNameOfAnimation;

};



#endif // !ANIMATION_H

