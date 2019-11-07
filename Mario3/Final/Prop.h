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

	void setPropIdentity(char newID);
	char getPropIdentity();

private:

	Animation * mCurrentAnimation;
	Vector2 mLocation;

	char mPropIdentity;
};

#endif // !PROP_H

