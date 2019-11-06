#ifndef TILE_H
#define TILE_H

#include "Unit.h"

class Tile : public Unit
{
public:

	// Constructors
	Tile();
	Tile(Vector2 newPos);

	// Destructors
	~Tile();

	void setTileIdentity(char newID);
	char getTileIdentity();

private:

	Animation * mCurrentAnimation;
	Vector2 mLocation;

	char mTileIdentity;
};

#endif // !TILE_H
