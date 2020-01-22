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

	// Mutators
	void onCollide(Unit & collidingObject, int collidingObjectIndex);

private:

	// Mutators
	void changeDirection();

	//Int 
	int mTimesBouncedOn;

};

#endif // !KOOPA_H

