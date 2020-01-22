#ifndef PROP_H
#define PROP_H

#include "Unit.h"

class Prop : public Unit
{
public:

	// Constructors
	Prop();
	Prop(Vector2 newPos);

	// Destructors
	~Prop();

	// Mutators
	void setPropIdentity(char newID);
	
	// Accessors
	char getPropIdentity();

private:

	// Animations
	Animation * mCurrentAnimation;

	// Vector2's
	Vector2 mLocation;

	// Characters
	char mPropIdentity;
};

#endif // !PROP_H

