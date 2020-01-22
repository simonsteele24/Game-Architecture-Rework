#ifndef PLATFORM_H
#define PLATFORM_H

// Local includes
#include "Unit.h"


class Platform : public Unit
{
public:

	// Constructors
	Platform();
	Platform(Vector2 newPos);

	// Destructors
	~Platform();

	// Mutators
	void setPlatformIdentity(char newID);

	// Acessors
	char getPlatformIdentity();

private:

	//Characters
	char mPlatformIdentity;
};

#endif // !PLATFORM_H

