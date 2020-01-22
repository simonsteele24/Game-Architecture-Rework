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

	// Mutators
	void setTileIdentity(char newID);
	
	// Acessors
	char getTileIdentity();

private:

	// Animations
	Animation * mCurrentAnimation;
	
	// Vector2's
	Vector2 mLocation;

	// Characters
	char mTileIdentity;
};

#endif // !TILE_H
