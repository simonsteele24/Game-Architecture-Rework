#ifndef ENDBLOCK_H
#define ENDBLOCK_H

// Local includes
#include "Unit.h"

class EndBlock : public Unit
{
public:

	// Constructors
	EndBlock();
	EndBlock(Vector2 newPos);

	// Destructors
	~EndBlock();

	// Update functions
	void update(double newTimeBetweenFrames);

private:

	int numOfAnims = 2;
	int currentAnim = 0;
};

#endif // !ENDBLOCK_H


