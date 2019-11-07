#ifndef GOOMBA_H
#define GOOMBA_H


// Local includes
#include "Unit.h"

class Goomba : public Unit
{
public:

	// Constructors
	Goomba();
	Goomba(Vector2 newPos);

	// Destructors
	~Goomba();

	// Update functions
	void update(double newTimeBetweenFrames);

private:

	// Goomba Directions
	Direction mCurrentDirection;

};

#endif // !GOOMBA_H
