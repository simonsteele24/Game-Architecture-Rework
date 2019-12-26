#ifndef DRYBONES_H
#define DRYBONES_H

// Local includes
#include "Unit.h"

class DryBones : public Unit
{
public:

	// Constructors
	DryBones();
	DryBones(Vector2 newPos);

	// Destructors
	~DryBones();

	// Update functions
	void update(double newTimeBetweenFrames);
	void swapAnimation(string nameOfNewAnimation);

	// Accessors
	int getNumBounced() { return mTimesBouncedOn; };
	void onCollide(Unit & collidingObject, int collidingObjectIndex);

private:

	void changeDirection();

	//Int 
	int mTimesBouncedOn;

	// Goomba Directions
	Direction mCurrentDirection;

	int mCooldownRemaining;

	// Booleans
	bool mIsWalking;
	bool mIsStationary;

};

#endif // !DRYBONES_H

