#ifndef SUPERMUSHROOM_H
#define SUPERMUSHROOM_H

// Local includes
#include "Unit.h"

class SuperMushroom : public Unit
{
public:

	// Constructors
	SuperMushroom();
	SuperMushroom(Vector2 newPos);

	// Destructors
	~SuperMushroom();

	// Update functions
	void update(double newTimeBetweenFrames);

private:

};

#endif // !SUPERMUSHROOM_H


