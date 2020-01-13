#ifndef ANIMATION_H
#define ANIMATION_H

// Standard Library includes
#include <vector>

// Graphics Library includes
#include <Sprite.h>

const double  DEFAULT_SPEED = 100.0;

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
	void addSprite( Sprite * spriteToAdd );
	void adjustCurrentSpeed( double speedToBeAdded );
	void resetAnimationIndex();

	// Accessors
	Sprite * getCurrentSprite();
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
	Sprite * mListOfSprites;

	// Vector2's
	Vector2 mSpritesPerRowAndColumn;
	Vector2 mSpriteDimensions;
	Vector2 mCurrentIndex;

	// Doubles
	double mTargetTime;
	double mTimeElapsed;
	int mUpdateIncrementor;

	// Strings
	string mNameOfAnimation;

};



#endif // !ANIMATION_H

