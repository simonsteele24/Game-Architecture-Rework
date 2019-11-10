#include "UnitManager.h"
#include "Game.h"


// This function is the default constructor for the class
UnitManager::UnitManager()
{
	mCameraDirection = STATIONARY;
}





// This function is the destructor for the class
UnitManager::~UnitManager()
{
	removeAllUnits();
}





// This function gets a specific unit from the units vector
// Based on a given index
Unit * UnitManager::getUnit( int index ) 
{
	int max = mUnits.size();

	if (index > max)
	{
		return 0;
	}
	return mUnits[index];
}





// This function gets a specific prop from the props vector
// Based on a given index
Prop * UnitManager::getProp(int index)
{
	return mProps[index];
}




Platform * UnitManager::getPlatform(int index) 
{
	return mPlatforms[index];
}





Tile * UnitManager::getTile(int index) 
{
	return mTiles[index];
}





// This function creates a unit at a given position and also adds
// a animation to said unit
void UnitManager::createUnit( Vector2 newPos )
{
	mUnits.push_back( new Unit(newPos) );
}





// This function creates the question block unit at a given position
void UnitManager::createQuestionBlock(Vector2 newPos) 
{
	mUnits.push_back(new QuestionBlock(newPos));
}





// This function creates the fireball unit at a given position
void UnitManager::createFireball(Vector2 newPos) 
{
	mUnits.push_back(new Fireball(newPos));
}





// This function creates the brick block unit at a given position
void UnitManager::createBrickBlock(Vector2 newPos) 
{
	mUnits.push_back(new BrickBlock(newPos));
}





// This function creates a Goomba unit at a given position
void UnitManager::createGoomba(Vector2 newPos) 
{
	mUnits.push_back(new Goomba(newPos));
}





// This function creates a Thwomp at a given position
void UnitManager::createThwomp(Vector2 newPos) 
{
	mUnits.push_back(new Thwomp(newPos));
	mUnits[mUnits.size() - 1]->setInitialPosition(newPos);
}





// This function creates a dry bones at a given position
void UnitManager::createDryBones(Vector2 newPos) 
{
	mUnits.push_back(new DryBones(newPos));
}





// This function creates a Koopa Unit at a given position
void UnitManager::createKoopa(Vector2 newPos) 
{
	mUnits.push_back(new Koopa(newPos));
}





// This function creates a Piranha Plant Unit at a given position
void UnitManager::createPiranhaPlant(Vector2 newPos) 
{
	mUnits.push_back(new PiranhaPlant(newPos));
}




void UnitManager::createBoomBoom(Vector2 newPos)
{
	mUnits.push_back(new BoomBoom(newPos,mUnits.size()));
}




// This function creates a Prop at a given position
void UnitManager::createProp(Vector2 newPos, Animation & newAnim) 
{
	mProps.push_back((new Prop(newPos)));
	mProps[mProps.size() - 1]->setAnimation(newAnim);
}





void UnitManager::createTile(Vector2 newPos, Animation & newAnim) 
{
	mTiles.push_back((new Tile(newPos)));
	mTiles[mTiles.size() - 1]->setAnimation(newAnim);
}


void UnitManager::createPlatform(Vector2 newPos) 
{
	mPlatforms.push_back((new Platform(newPos)));
}

void UnitManager::createMushroom(Vector2 newPos)
{
	mUnits.push_back(new SuperMushroom(newPos));
}

void UnitManager::createStarmen(Vector2 newPos)
{
	mUnits.push_back(new Starmen(newPos));
}


void UnitManager::createEndBlock(Vector2 newPos)
{
	mUnits.push_back(new EndBlock(newPos));
}





// This functions adds a given animation to a unit based on a given index
void UnitManager::addAnimation( int index, Animation & newAnim ) 
{
	mUnits[index]->setAnimation(newAnim);
}





// This functions adds a given animation to a unit based on a given index
void UnitManager::addPlayerAnimation(Animation & newAnim)
{
	mPlayer->setAnimation(newAnim);
}





// This function destroys and deletes a unit from the
// vector based on a given index
void UnitManager::destroyUnit( int index ) 
{
	delete mUnits[index];
	mUnits.erase( mUnits.begin() + index );
}





// This function plays or stops all animations for all units
void UnitManager::playOrStopUnitAnimations() 
{
	for ( int i = 0, max = mUnits.size(); i < max; i++ ) 
	{
		mUnits[i]->switchStateOfAnimation();
	}
}





// This function calls the update function for all units in the game and
// also passed to all units the given time that has passed since last update
void UnitManager::update( double timeBetweenFrames ) 
{

	for (int i = 0, max = mProps.size(); i < max; i++)
	{
		mProps[i]->update(timeBetweenFrames);
		mProps[i]->updateCameraToUnitPosition();
	}

	for (int i = 0, max = mTiles.size(); i < max; i++) 
	{
		mTiles[i]->updateCameraToUnitPosition();
	}

	for ( int i = 0, max = mUnits.size(); i < max; i++ ) 
	{
		if (mUnits[i]->isVisible()) 
		{
			mUnits[i]->update(timeBetweenFrames);
			max = mUnits.size();
		}
		mUnits[i]->updateCameraToUnitPosition();
	}

	for (int i = 0, max = mPlatforms.size(); i < max; i++)
	{
		if (mPlatforms[i]->isVisible())
		{
			mPlatforms[i]->update(timeBetweenFrames);
			max = mPlatforms.size();
		}
		mPlatforms[i]->updateCameraToUnitPosition();
	}

	if (mPlayer != nullptr)
	{
		mPlayer->update(timeBetweenFrames);
	}

	mCameraDirection = STATIONARY;
}





// This function calls all units in the game to draw
// themselves to the back buffer
void UnitManager::draw() 
{
	for (int i = 0, max = mProps.size(); i < max; i++)
	{
		mProps[i]->draw();
	}

	for ( int i = 0, max = mUnits.size(); i < max; i++ )
	{
		mUnits[i]->draw();
	}

	for (int i = 0, max = mPlatforms.size(); i < max; i++)
	{
		mPlatforms[i]->draw();
	}

	for (int i = 0, max = mTiles.size(); i < max; i++)
	{
		mTiles[i]->draw();
	}

	if (mPlayer != nullptr)
	{
		mPlayer->draw();
	}
}





// This function moves the Player Unit to a given position
void UnitManager::movePlayer(Vector2 newPos) 
{
}





// This function gets the size of the units member vector,
// which stores all of the units of the game
int UnitManager::getSize() 
{
	return mUnits.size();
}





// This function gets the size of the props member vector,
// which stores all of the props of the game
int UnitManager::getPropSize()
{
	return mProps.size();
}




int UnitManager::getPlatformSize() 
{
	return mPlatforms.size();
}





int UnitManager::getTileSize() 
{
	return mTiles.size();
}





// This function removes all of the units within the unit list and erases the unit vector
void UnitManager::removeAllUnits() 
{
	delete mPlayer;
	mPlayer = nullptr;
	for ( int i = 0, max = mUnits.size(); i < max; i++ )
	{
		delete mUnits[i];
	}
	for (int i = 0, max = mProps.size(); i < max; i++)
	{
		delete mProps[i];
	}
	for (int i = 0, max = mPlatforms.size(); i < max; i++) 
	{
		delete mPlatforms[i];
	}
	for (int i = 0, max = mTiles.size(); i < max; i++)
	{
		delete mTiles[i];
	}

	mPlatforms.clear();
	mUnits.clear();
	mProps.clear();
	mTiles.clear();
}





// This function creates the Player Unit at a given position
void UnitManager::createPlayer(Vector2 newPos) 
{
	mPlayer = new Player(newPos);
}





// This function gets the current object of the Player Unit
Player * UnitManager::getPlayer() 
{
	return mPlayer;
}





// This function sets the direction the camera is going
void UnitManager::setCameraDirection(CameraDirection newDir) 
{
	mCameraDirection = newDir;
}





// This function gets the direction the camera is currently going
CameraDirection UnitManager::getCameraDirection() 
{
	return mCameraDirection;
}





// This function adds to the current position of the camera
void UnitManager::addToCameraPosition(Vector2 newAddition) 
{
	mCameraPosition.mX += newAddition.mX;
	mCameraPosition.mY += newAddition.mY;
}





// This function gets the current position of the camera
Vector2 UnitManager::getCameraPosition() 
{
	return mCameraPosition;
}





// This function sets the current current camera position by a given amount
void UnitManager::setCameraPosition(Vector2 newPos) 
{
	mCameraPosition = newPos;
}