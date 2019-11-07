#include "System.h"




// This function is the default constructor for this class
System::System()
{
	GraphicsSystem::initStaticInstance();
	mCurrentGraphicsSystem = new GraphicsSystem();
}





// This function is the destructor for this class
System::~System()
{
	if (mIsDisplaying)
	{
		cleanup();
	}
}





// This function initializes all of the allegro systems
void System::init(int screenWidth, int screenHeight)
{
	mCurrentGraphicsSystem->init((float)screenWidth, (float)screenHeight);
	mCurrentGraphicsSystem->flip();

	mIsDisplaying = true; // Set the bool that checks if the program is displaying as true
}

void System::init(sf::Sprite* backGround, int screenWidth, int screenHeight)
{
	mCurrentGraphicsSystem->init(backGround, (float)screenWidth, (float)screenHeight);
	mCurrentGraphicsSystem->flip();

	mIsDisplaying = true; // Set the bool that checks if the program is displaying as true
}





// This function initializes all of the allegro-based add-ons
// If they can't be found, the will print the error to the console
void System::initializeSystems()
{
}




// This function cleans up and destroys all of the allegro systems
void System::cleanup()
{
	mCurrentGraphicsSystem->cleanup();
	delete mCurrentGraphicsSystem;
	mIsDisplaying = false; // Set the bool that checks if the program is displaying as false
}





// This function calls to graphics system to flip the display 
// to change frames
void System::flipDisplay()
{
	mCurrentGraphicsSystem->flip();
}





// This function gets the current graphics system attached to the system class
GraphicsSystem System::getGraphicsSystem()
{
	return *mCurrentGraphicsSystem;
}