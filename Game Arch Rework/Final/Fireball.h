#ifndef FIREBALL_H
#define FIREBALL_H

#include "Unit.h"

class Fireball : public Unit
{
public:

	// Constructors
	Fireball();
	Fireball(Vector2 newPos);

	// Destructors
	~Fireball();

	// Update functions
	void update(double newTimeBetweenFrames);

private:

	int mRemainingTime;
};


#endif // !FIREBALL_H

