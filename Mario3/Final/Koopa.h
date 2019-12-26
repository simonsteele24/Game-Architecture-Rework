#ifndef KOOPA_H
#define KOOPA_H

// Local includes
#include "Unit.h"

class Koopa : public Unit
{
public:

	// Constructors
	Koopa();
	Koopa(Vector2 newPos);

	// Destructors
	~Koopa();

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

	// Booleans
	bool mIsWalking;
	bool mIsStationary;

};

#endif // !KOOPA_H

