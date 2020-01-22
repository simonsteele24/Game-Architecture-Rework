#ifndef PIRANHAPLANT_H
#define PIRANHAPLANT_H

// Local includes
#include "Unit.h"

class PiranhaPlant : public Unit
{
public:

	// Constructors
	PiranhaPlant();
	PiranhaPlant(Vector2 newPos);

	// Destructors
	~PiranhaPlant();

	// Update functions
	void update(double newTimeBetweenFrames);
	void swapAnimation(string nameOfNewAnimation);
	void setAnimation(Animation & newAnimation);

private:

	// Directions
	Direction mCurrentDirection;
	Direction mPreviousDirection;

	// Floats
	float mCooldownRemaining;
	float mMaxDistanceToTravel;
};


#endif // !PIRANHAPLANT_H

