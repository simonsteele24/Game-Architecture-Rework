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

	// Goomba Directions
	Direction mCurrentDirection;
	Direction mPreviousDirection;

	float mCooldownRemaining;
	float mMaxDistanceToTravel;
	float mMinDistanceToTravel;
};


#endif // !PIRANHAPLANT_H

