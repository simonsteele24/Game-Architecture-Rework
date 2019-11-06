#include "Prop.h"
#include "Game.h"


// This function is the default constructor for the class 
Prop::Prop() : Unit()
{
	mPropIdentity = ' ';
}





// This constructor moves the player Unit to a given position
Prop::Prop(Vector2 newPos)
{
	mCurrentLocation = newPos;
}





// This is the destructor for the class
Prop::~Prop()
{
}





// This function sets the identity of a prop based on a given value
void Prop::setPropIdentity(char newID) 
{
	mPropIdentity = newID;
}





// This function getsthe identity of the prop
char Prop::getPropIdentity() 
{
	return mPropIdentity;
}