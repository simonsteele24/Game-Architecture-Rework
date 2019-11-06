#ifndef STARMEN_H
#define STARMEN_H

// Local includes
#include "Unit.h"

class Starmen : public Unit
{
public:

	// Constructors
	Starmen();
	Starmen(Vector2 newPos);

	// Destructors
	~Starmen();

	// Update functions
	void update(double newTimeBetweenFrames);



private:

	
};

#endif // !STARMEN_H


