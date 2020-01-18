#ifndef UNIT_H
#define UNIT_H

// Standard Library includes
#include <vector>

// Project-local includes
#include "Animation.h"
#include "Direction.h"

const int DEFAULT_SCALING_VALUE = 1;

enum UnitTypes
{
	PLAYER,
	QUESTION_BLOCK,
	BRICK_BLOCK,
	END_BLOCK,
	GOOMBA,
	KOOPA,
	PIRANHAPLANT,
	COIN,
	SUPER_MUSHROOM,
	PIPE,
	PLATFORM,
	WOOD_BLOCK,
	LAVA,
	STARMEN,
	THWOMP,
	DRYBONES,
	BOOMBOOM,
	FIREBALL,
	NONE
};

enum UnitMovabilityType 
{
	NON_MOVEABLE,
	MOVEABLE
};

class Unit : public Trackable
{
public:

	// Friends
	friend class UnitManager;
	friend class Player;
	friend class SuperMushroom;
	friend class Starmen;
	friend class QuestionBlock;
	friend class BrickBlock;
	friend class EndBlock;
	friend class Goomba;
	friend class Koopa;
	friend class PiranhaPlant;
	friend class Prop;
	friend class Platform;
	friend class Thwomp;
	friend class DryBones;
	friend class BoomBoom;
	friend class Fireball;
	friend class Tile;

	// Destructors
	~Unit();

	// Updates
	virtual void update( double newTimeBetweenFrames );
	void updateCameraToUnitPosition();
	void moveToMousePosition( Vector2 newMousePos );
	void moveToPosition(Vector2 newPos);

	// Accessors
	bool isVisible();
	Vector2 getLocation();
	UnitTypes getCurrentUnitType();
	Animation * getCurrentAnimation();
	double getVelocity();
	Vector2 getInitialPosition() { return mInitialPosition; }
	bool getIsMovingDown() { return mIsMovingDown; }
	bool getIsMovingUp() { return mIsMovingDown; }
	bool getEffectStatus() { return mEffect; }
	bool getDamageState() { return mCanBeDamaged; }

	// Mutators
	void draw();
	virtual void onCollide(Unit & collidingObject, int collidingObjectIndex);
	void switchStateOfAnimation();
	void destroyThisGameObject(UnitManager * manager);
	void changeAnimationSpeeds(double speedsToBeChanged);
	virtual void setAnimation(Animation & newAnimation);
	virtual void swapAnimation( string nameOfNewAnimation );
	void setUnitType(UnitTypes typeToBeSet);
	void setVelocity(double newVelocity);
	Vector2 getDimensions();
	void setInitialPosition(Vector2 newPos);
	void setLocationX(double newLocation) { mCurrentLocation.mX = newLocation; }
	void setLocationY(double newLocation) { mCurrentLocation.mY = newLocation; }
	void setZIndex(int newZIndex) { mZIndex = newZIndex; }
	void setUnitMoveability(UnitMovabilityType newMovability) { mUnitMovability = newMovability; }
	void setIsMovingDown(bool newCondition);
	void setIsMovingUp(bool newCondition);

	void setEffect(bool effectStatus);
	void setDamageState(bool damageState);

private:

	GraphicsBuffer * tempBuffer;

	// UnitTypes
	UnitTypes mUnitType;
	UnitMovabilityType mUnitMovability = NON_MOVEABLE;

	// Constructors
	Unit();
	Unit(Vector2 newPos);
	Unit(Vector2 newPosition, Animation * newAnimation);

	// Animations
	vector<Animation*> mCurrentAnimations;

	// Ints
	int mCurrentAnimationIndex;
	int mZIndex;

	// Vector 2s
	Vector2 mCurrentLocation;
	Vector2 mDimensions;
	Vector2 mInitialPosition;

	// Booleans
	bool isAnimationStopped;
	bool mIsSpinning;
	bool mSuccessfulHit;
	bool mIsMovingDown;
	bool mIsMovingUp;
	bool mEffect;//use to check if the effect is active or not
	bool mCanBeDamaged;//used to check if the object is damagable;
	bool mIsWalking;
	bool mIsStationary;

	Direction mCurrentDirection;

	// Doubles
	double mVelocity;
};

#endif // !UNIT_H

