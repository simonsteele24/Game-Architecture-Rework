#ifndef THWOMP_H
#define THWOMP_H

#include "Unit.h"

class Thwomp : public Unit
{
public:

	// Constructors
	Thwomp();
	Thwomp(Vector2 newPos);

	// Destructors
	~Thwomp();

	// Update functions
	void update(double newTimeBetweenFrames);
private:

	// Vector2's
	Vector2 mInitialPosition;
	bool mIsMovingDown;
	bool mIsMovingUp;

};

#endif // !1

