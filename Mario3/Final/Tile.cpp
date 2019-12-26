#include "Tile.h"
#include "Game.h"


// This function is the default constructor for the class 
Tile::Tile() : Unit()
{
	mTileIdentity = ' ';
}





// This constructor moves the player Unit to a given position
Tile::Tile(Vector2 newPos)
{
	mCurrentLocation = newPos;
	mLocation = newPos;
}





// This is the destructor for the class
Tile::~Tile()
{
}





// This function sets the identity of a prop based on a given value
void Tile::setTileIdentity(char newID)
{
	mTileIdentity = newID;
}





// This function getsthe identity of the prop
char Tile::getTileIdentity()
{
	return mTileIdentity;
}