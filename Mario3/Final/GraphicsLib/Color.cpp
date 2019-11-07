#include "Color.h"



// This constructor is the default constructor of the class
Colors::Colors()
{
}





// This constructor initializes the color based on the red,
// green, blue values given by the user
Colors::Colors(float r, float g, float b)
{
	mCurrentColor = sf::Color(sf::Uint8(r), sf::Uint8(g), sf::Uint8(b));
}





// This constructor initializes the color based on the red,
// green, blue, and alpha values given by the user
Colors::Colors(float r, float g, float b, float a)
{
	mCurrentColor = sf::Color(sf::Uint8(r), sf::Uint8(g), sf::Uint8(b), sf::Uint8(a));
}







// The destructor for the color class
Colors::~Colors()
{
}





// This function sets the R value of the current color
void Colors::setR(float newR)
{
	mCurrentColor.r = sf::Uint8(newR);
}





// This function sets the G value of the current color
void Colors::setG(float newG)
{
	mCurrentColor.g = sf::Uint8(newG);
}





// This function sets the B value of the current color
void Colors::setB(float newB)
{
	mCurrentColor.b = sf::Uint8(newB);
}