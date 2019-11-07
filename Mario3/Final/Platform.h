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
	void setPlatformIdentity(char newID);
	char getPlatformIdentity();

private:

	char mPlatformIdentity;
};

#endif // !PLATFORM_H

