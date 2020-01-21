#include "UnitManager.h"
#include "Game.h"
#include <algorithm>


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
void UnitManager::addAnimation( int index, Animation newAnim ) 
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
	Game::getStaticInstance()->time += timeBetweenFrames;

	calculateCollisions();

	for (int i = 0, max = mProps.size(); i < max; i++)
	{
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

	for (int i = 0, max = mPlatforms.size(); i < max; i++)
	{
		if (mPlatforms[i]->isVisible()) 
		{
			mPlatforms[i]->draw();
		}
	}

	for (int i = 0, max = mTiles.size(); i < max; i++)
	{
		if (mTiles[i]->isVisible()) 
		{
			mTiles[i]->draw();
		}
	}

	vector<int> unitsToDrawLast = vector<int>();

	for (int i = 0, max = mUnits.size(); i < max; i++)
	{
		if (mUnits[i]->isVisible()) 
		{
			if (mUnits[i]->getDrawLastIndex()) 
			{
				unitsToDrawLast.push_back(i);
			}
			else 
			{
				mUnits[i]->draw();
			}
		}
	}

	for (int i = 0, max = unitsToDrawLast.size(); i < max; i++) 
	{
		mUnits[unitsToDrawLast[i]]->draw();
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
	mPlayer->mIsThicc = Game::getStaticInstance()->getPlayerPowerupState();
	mPlayer->mStillThicc = Game::getStaticInstance()->getPlayerPowerupState();
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





// This function calculates all collisions for all units once per loop
void UnitManager::calculateCollisions() 
{
	Vector2 xMinCorner = Vector2();
	Vector2 yMinCorner = Vector2();
	Vector2 xMaxCorner = Vector2();
	Vector2 yMaxCorner = Vector2();

	mCollisions.clear();

	for (int x = 0, max = mUnits.size() - 1; x < max; x++)
	{
		for (int y = x + 1, max = mUnits.size(); y < max; y++)
		{
			if (mUnits[x]->isVisible() && mUnits[y]->isVisible())
			{
				xMinCorner = mUnits[x]->getLocation();
				yMinCorner = mUnits[y]->getLocation();
				xMaxCorner = Vector2(mUnits[x]->getLocation().mX + mUnits[x]->getDimensions().mX, mUnits[x]->getLocation().mY + mUnits[x]->getDimensions().mY);
				yMaxCorner = Vector2(mUnits[y]->getLocation().mX + mUnits[y]->getDimensions().mX, mUnits[y]->getLocation().mY + mUnits[y]->getDimensions().mY);

				if (xMinCorner < yMaxCorner && yMinCorner < xMaxCorner)
				{
					mUnits[x]->onCollide(*mUnits[y], y);
					mUnits[y]->onCollide(*mUnits[x], x);

					if (mUnits[x]->mUnitMovability == MOVEABLE)
					{
						Vector2 normal = Vector2(mUnits[x]->getLocation().mX - mUnits[y]->getLocation().mX, mUnits[x]->getLocation().mY - mUnits[y]->getLocation().mY);

						if (normal.mX != 0 && normal.mY != 0)
						{
							if (abs(normal.mX) > abs(normal.mY))
							{
								normal.mX /= abs(normal.mX);
								mUnits[x]->setLocationX(mUnits[y]->getLocation().mX + (normal.mX * mUnits[x]->getDimensions().mX));
							}
							else
							{
								normal.mY /= abs(normal.mY);
								mUnits[x]->setLocationY(mUnits[y]->getLocation().mY + (normal.mY * mUnits[x]->getDimensions().mY));
							}
						}
						else
						{
							if (normal.mX != 0)
							{
								normal.mX /= abs(normal.mX);
								mUnits[x]->setLocationX(mUnits[y]->getLocation().mX + (normal.mX * mUnits[x]->getDimensions().mX));
							}
							if (normal.mY != 0)
							{
								normal.mY /= abs(normal.mY);
								mUnits[x]->setLocationY(mUnits[y]->getLocation().mY + (normal.mY * mUnits[x]->getDimensions().mY));
							}
						}
					}
					else if (mUnits[y]->mUnitMovability == MOVEABLE)
					{
						Vector2 normal = Vector2(mUnits[y]->getLocation().mX - mUnits[x]->getLocation().mX, mUnits[y]->getLocation().mY - mUnits[x]->getLocation().mY);

						if (normal.mX != 0 && normal.mY != 0)
						{
							if (abs(normal.mX) > abs(normal.mY))
							{
								normal.mX /= abs(normal.mX);
								mUnits[y]->setLocationX(mUnits[x]->getLocation().mX + (normal.mX * mUnits[x]->getDimensions().mX));
							}
							else
							{
								normal.mY /= abs(normal.mY);
								mUnits[y]->setLocationY(mUnits[x]->getLocation().mY + (normal.mY * mUnits[x]->getDimensions().mY));
							}
						}
						else
						{
							if (normal.mX != 0)
							{
								normal.mX /= abs(normal.mX);
								mUnits[y]->setLocationX(mUnits[x]->getLocation().mX + (normal.mX * mUnits[y]->getDimensions().mX));
							}
							if (normal.mY != 0)
							{
								normal.mY /= abs(normal.mY);
								mUnits[y]->setLocationY(mUnits[x]->getLocation().mY + (normal.mY * mUnits[y]->getDimensions().mY));
							}
						}
					}
				}
			}
		}
	}

	for (int x = 0, max = mUnits.size() - 1; x < max; x++)
	{
		for (int y = 0, max = mTiles.size(); y < max; y++)
		{
			if (mUnits[x]->isVisible() && mTiles[y]->isVisible() && mUnits[x]->mUnitMovability == MOVEABLE)
			{
				xMinCorner = mUnits[x]->getLocation();
				yMinCorner = mTiles[y]->getLocation();
				xMaxCorner = Vector2(mUnits[x]->getLocation().mX + mUnits[x]->getDimensions().mX, mUnits[x]->getLocation().mY + mUnits[x]->getDimensions().mY);
				yMaxCorner = Vector2(mTiles[y]->getLocation().mX + mTiles[y]->getDimensions().mX, mTiles[y]->getLocation().mY + mTiles[y]->getDimensions().mY);

				if (xMinCorner < yMaxCorner && yMinCorner < xMaxCorner)
				{
					mUnits[x]->onCollide(*mTiles[y], y);

					Vector2 normal = Vector2(mUnits[x]->getLocation().mX - mTiles[y]->getLocation().mX, mUnits[x]->getLocation().mY - mTiles[y]->getLocation().mY);

					if (normal.mX != 0 && normal.mY != 0)
					{
						if (abs(normal.mX) > abs(normal.mY))
						{
							normal.mX /= abs(normal.mX);
							mUnits[x]->setLocationX(mTiles[y]->getLocation().mX + (normal.mX * mTiles[y]->getDimensions().mX));
						}
						else
						{
							normal.mY /= abs(normal.mY);
							mUnits[x]->setLocationY(mTiles[y]->getLocation().mY + (normal.mY * mUnits[x]->getDimensions().mY));
						}
					}
					else
					{
						if (normal.mX != 0)
						{
							normal.mX /= abs(normal.mX);
							mUnits[x]->setLocationX(mTiles[y]->getLocation().mX + (normal.mX * mUnits[x]->getDimensions().mX));
						}
						if (normal.mY != 0)
						{
							normal.mY /= abs(normal.mY);
							mUnits[x]->setLocationY(mTiles[y]->getLocation().mY + (normal.mY * mUnits[x]->getDimensions().mY));
						}
					}
				}
			}
		}
	}

	if (mPlayer != nullptr) 
	{
		mPlayer->mInMidAir = true;
	}

	for (int i = 0, max = mUnits.size(); i < max; i++) 
	{
		max = mUnits.size();
		if (i < max) 
		{
			if (mUnits[i]->isVisible() && mPlayer != nullptr && mUnits[i] != nullptr && !mPlayer->mIsDying)
			{
				xMinCorner = mUnits[i]->getLocation();
				yMinCorner = mPlayer->getLocation();
				xMaxCorner = Vector2(mUnits[i]->getLocation().mX + mUnits[i]->getDimensions().mX, mUnits[i]->getLocation().mY + mUnits[i]->getDimensions().mY);
				yMaxCorner = Vector2(mPlayer->getLocation().mX + mPlayer->getDimensions().mX, mPlayer->getLocation().mY + mPlayer->getDimensions().mY);

				if (xMinCorner < yMaxCorner && yMinCorner < xMaxCorner)
				{
					Vector2 normal = Vector2(mPlayer->getLocation().mX + (mPlayer->mDimensions.mX - 32) - mUnits[i]->getLocation().mX, (mPlayer->getLocation().mY + (mPlayer->mDimensions.mY - 32)) - mUnits[i]->getLocation().mY);
					Vector2 regularCoordinatesPlayer = Vector2(mPlayer->getLocation().mX + (mPlayer->mDimensions.mX / 2), mPlayer->getLocation().mY + (mPlayer->mDimensions.mY / 2));
					Vector2 regularCollidingCoordinates = Vector2(mUnits[i]->getLocation().mX + (mUnits[i]->mDimensions.mX / 2), mUnits[i]->getLocation().mY + (mUnits[i]->mDimensions.mY / 2));
					Vector2 normal2 = Vector2(regularCoordinatesPlayer.mX - regularCollidingCoordinates.mX, regularCoordinatesPlayer.mY - regularCollidingCoordinates.mY);

					double foo = abs(normal2.mX) - (mUnits[i]->mDimensions.mX / 2);

					if (mUnits[i]->mUnitType != COIN) 
					{
						if (normal.mX != 0 && normal.mY != 0)
						{
							if (abs(normal2.mX) > abs(normal2.mY) && abs(normal2.mX) - (mUnits[i]->mDimensions.mX / 2) > 0)
							{
								if (normal.mX < 0)
								{
									normal.mX /= abs(normal.mX);
									mPlayer->setLocationX(mUnits[i]->getLocation().mX + (normal.mX * mPlayer->getDimensions().mX));
								}
								else
								{
									normal.mX /= abs(normal.mX);
									mPlayer->setLocationX(mUnits[i]->getLocation().mX + (normal.mX * mUnits[i]->getDimensions().mX));
								}
							}
							else 
							{
								if (normal.mY > 0)
								{
									normal.mY /= abs(normal.mY);
									mPlayer->setLocationY(mUnits[i]->getLocation().mY + (normal.mY * mUnits[i]->getDimensions().mY));
								}
								else
								{
									normal.mY /= abs(normal.mY);
									mPlayer->setLocationY(mUnits[i]->getLocation().mY + (normal.mY * mPlayer->getDimensions().mY));
								}
							}
						}
						else
						{
							if (normal.mX != 0)
							{
								normal.mX /= abs(normal.mX);
								mPlayer->setLocationX(mUnits[i]->getLocation().mX + (normal.mX * mUnits[i]->getDimensions().mX));
							}
							if (normal.mY != 0)
							{
								normal.mY /= abs(normal.mY);
								mPlayer->setLocationY(mUnits[i]->getLocation().mY + (normal.mY * mPlayer->getDimensions().mY));
							}
						}
					}
					
					mUnits[i]->onCollide(*mPlayer, 0);
					mPlayer->onCollide(*mUnits[i], i);
	
				}
			}
		}
		max = mUnits.size();
	}

	for (int i = 0, max = mTiles.size(); i < max; i++) 
	{
		if (mTiles[i]->isVisible() && !mPlayer->mIsDying)
		{
			xMinCorner = mTiles[i]->getLocation();
			yMinCorner = mPlayer->getLocation();
			xMaxCorner = Vector2(mTiles[i]->getLocation().mX + mTiles[i]->getDimensions().mX, mTiles[i]->getLocation().mY + mTiles[i]->getDimensions().mY);
			yMaxCorner = Vector2(mPlayer->getLocation().mX + mPlayer->getDimensions().mX, mPlayer->getLocation().mY + mPlayer->getDimensions().mY);

			if (xMinCorner < yMaxCorner && yMinCorner < xMaxCorner)
			{
				mPlayer->onCollide(*mTiles[i], i);
				mTiles[i]->onCollide(*mPlayer, 0);

				Vector2 normal = Vector2(mPlayer->getLocation().mX - mTiles[i]->getLocation().mX, mPlayer->getLocation().mY - mTiles[i]->getLocation().mY);
				
				if (normal.mX != 0 && normal.mY != 0)
				{
					if (normal.mY < 0 || normal.mY > mTiles[i]->mDimensions.mY / 2)
					{
						if (normal.mY > 0)
						{
							normal.mY /= abs(normal.mY);
							mPlayer->setLocationY(mTiles[i]->getLocation().mY + (normal.mY * mTiles[i]->getDimensions().mY));
						}
						else
						{
							normal.mY /= abs(normal.mY);
							mPlayer->setLocationY(mTiles[i]->getLocation().mY + (normal.mY * mPlayer->getDimensions().mY));
						}
					}
					else
					{
						if (normal.mX < 0)
						{
							normal.mX /= abs(normal.mX);
							mPlayer->setLocationX(mTiles[i]->getLocation().mX + (normal.mX * mPlayer->getDimensions().mX));
						}
						else
						{
							normal.mX /= abs(normal.mX);
							mPlayer->setLocationX(mTiles[i]->getLocation().mX + (normal.mX * mTiles[i]->getDimensions().mX));
						}
					}
				}
				else
				{
					if (normal.mX != 0)
					{
						normal.mX /= abs(normal.mX);
						mPlayer->setLocationX(mTiles[i]->getLocation().mX + (normal.mX * mTiles[i]->getDimensions().mX));
					}
					if (normal.mY != 0)
					{
						normal.mY /= abs(normal.mY);
						mPlayer->setLocationY(mTiles[i]->getLocation().mY + (normal.mY * mPlayer->getDimensions().mY));
					}
				}
				mTiles[i]->onCollide(*mPlayer, 0);
				mPlayer->onCollide(*mTiles[i], i);
			}
		}
	}

	for (int i = 0, max = mPlatforms.size(); i < max; i++)
	{
		if (mPlatforms[i]->isVisible() && !mPlayer->mIsDying)
		{
			xMinCorner = mPlatforms[i]->getLocation();
			yMinCorner = mPlayer->getLocation();
			xMaxCorner = Vector2(mPlatforms[i]->getLocation().mX + mPlatforms[i]->getDimensions().mX, mPlatforms[i]->getLocation().mY + mPlatforms[i]->getDimensions().mY);
			yMaxCorner = Vector2(mPlayer->getLocation().mX + mPlayer->getDimensions().mX, mPlayer->getLocation().mY + mPlayer->getDimensions().mY);

			if (xMinCorner < yMaxCorner && yMinCorner < xMaxCorner)
			{
				if (mPlayer->getLocation().mY <= mPlatforms[i]->getLocation().mY && mPlayer->getVelocity() > 0) 
				{
					Vector2 normal = Vector2(mPlayer->getLocation().mX - mPlatforms[i]->getLocation().mX, (mPlayer->getLocation().mY - mPlayer->mVelocity) - mPlatforms[i]->getLocation().mY);

					if (normal.mY <= -mPlayer->mDimensions.mY)
					{
						normal.mY /= abs(normal.mY);
						mPlayer->setLocationY(mPlatforms[i]->getLocation().mY + (normal.mY * mPlayer->getDimensions().mY));
						mPlayer->onCollide(*mPlatforms[i], i);
						mPlatforms[i]->onCollide(*mPlayer, 0);
					}
				}
			}
		}
	}

	for (int i = 0, max = mCollisions.size(); i < max; i++) 
	{
		mUnits[mCollisions[i].aIndex]->onCollide(*mUnits[mCollisions[i].bIndex], mCollisions[i].bIndex);
		mUnits[mCollisions[i].bIndex]->onCollide(*mUnits[mCollisions[i].aIndex], mCollisions[i].aIndex);
	}
}