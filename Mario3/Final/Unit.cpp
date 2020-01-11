#include "Unit.h"
#include "Game.h"




// This function is the default constructor for this class
Unit::Unit()
{
	mCurrentLocation = Vector2(0, 0);
	mCurrentAnimationIndex = 0;
	isAnimationStopped = false;
	mUnitType = NONE;
	mVelocity = 0;
	mEffect = false;
	mZIndex = 1;
}





// This constructor is for if the user wants to 
// initialize the position of a sprite
Unit::Unit( Vector2 newPos ) 
{
	mCurrentLocation = newPos;
	mCurrentAnimationIndex = 0;
	isAnimationStopped = false;
	mUnitType = NONE;
	mVelocity = 0;
	mEffect = false;
	mZIndex = 1;
}





// This constructor creates the Unit at a given position 
// and adds an animation to said Unit as well
Unit::Unit(Vector2 newPosition, Animation * newAnimation) 
{
	mCurrentLocation = newPosition;
	setAnimation(*newAnimation);
	isAnimationStopped = false;
	mUnitType = NONE;
	mVelocity = 0;
	mEffect = false;
	mZIndex = 1;
}





// This function is the destructor for this class
Unit::~Unit()
{
	for (int i = 0, max = mCurrentAnimations.size(); i < max; i++) 
	{
		mCurrentAnimations[i]->cleanupAnimation();
		delete mCurrentAnimations[i];
	}
}





// This function sets the animation(s) for the unit
void Unit::setAnimation( Animation & newAnimation ) 
{
	mCurrentAnimations.push_back(new Animation(newAnimation));

	if (mDimensions.mX <= 0 && mDimensions.mY <= 0) 
	{
		mDimensions = mCurrentAnimations[0]->getAnimationDimensions();
	}
}





// This function moves the Unit to the given mouse position
void Unit::moveToMousePosition( Vector2 newMousePos )
{
	Vector2 newPos = Vector2( newMousePos.mX - getCurrentAnimation()->getCurrentSprite()->getDisplacement().mX, newMousePos.mY - getCurrentAnimation()->getCurrentSprite()->getDisplacement().mY );
	mCurrentLocation = newPos;
}





// This function moves the Unit to a given position
void Unit::moveToPosition(Vector2 newPos) 
{
	mCurrentLocation = newPos;
}





// This function switches the state of the Unit animation to either play or stop
void Unit::switchStateOfAnimation()
{
	if (isAnimationStopped) 
	{
		isAnimationStopped = false;
	}
	else 
	{
		isAnimationStopped = true;
	}
}





// This function is the default update for this class
void Unit::update( double newTimeBetweenFrames )
{
	if (isAnimationStopped == false) 
	{
		// The following code updates the current frame of the animation
		mCurrentAnimations[mCurrentAnimationIndex]->update(newTimeBetweenFrames);
	}
}





// This function is the default oncollision for this class
void Unit::onCollide(Unit & collidingObject, int collidingObjectIndex) 
{

}





// This function adjusts the animation speed for al animations
void Unit::changeAnimationSpeeds( double speedsToBeChanged ) 
{
	for (int i = 0, max = mCurrentAnimations.size(); i < max; i++) 
	{
		mCurrentAnimations[i]->adjustCurrentSpeed( speedsToBeChanged );
	}
}





// This function gets the current animation that is being played
Animation * Unit::getCurrentAnimation() 
{
	return mCurrentAnimations[mCurrentAnimationIndex];
}




// This function draws the unit's sprite to the screen
void Unit::draw() 
{
	if (mCurrentAnimations.size() != 0) 
	{
		Game::getStaticInstance()->getCurrentSystem()->getGraphicsSystem().draw(mCurrentLocation, *mCurrentAnimations[mCurrentAnimationIndex]->getCurrentSprite(), DEFAULT_SCALING_VALUE);
	}
}





// This function swaps the current animation that is being played
void Unit::swapAnimation( string nameOfNewAnimation )
{

	// The following code determines if the current animation is the
	// last animation in the animations vector. If it is, cycle back to 
	// the start of the vector other wise just go to the next animation.
	for (int i = 0, max = mCurrentAnimations.size(); i < max; i++) 
	{
		if (mCurrentAnimations[i]->getAnimationName() == nameOfNewAnimation) 
		{
			mCurrentAnimationIndex = i;
		}
	}

	mDimensions = mCurrentAnimations[mCurrentAnimationIndex]->getAnimationDimensions();

}





// This function checks if the current unit is visible
bool Unit::isVisible() 
{
	// The following code checks if the current unit is within the current display window
	return mCurrentLocation.mX >= Game::getStaticInstance()->getCameraLeftOffset() - 300 && mCurrentLocation.mX <= Game::getStaticInstance()->getCameraRightOffset() + 300;
}


// This function destroys the Unit and then calls UnitManager to remove it from the Unit List
void Unit::destroyThisGameObject(UnitManager * manager) 
{
	for (int i = 0; i < manager->getSize(); i++) 
	{
		if (manager->getUnit(i) == this) 
		{
			manager->destroyUnit(i);
			break;
		}
	}
}





// This function gets the current location of the Unit
Vector2 Unit::getLocation() 
{
	if (this != nullptr)
	{
		Vector2 temp = Vector2(mCurrentLocation.mX, mCurrentLocation.mY);
		return temp;
	}
	return Vector2(0, 0);
}





// This function gets the current Unit Type of the Unit
UnitTypes Unit::getCurrentUnitType() 
{
	if (this != nullptr)
		return mUnitType;
	return NONE;
}





// This function sets the Unit type of the Unit
void Unit::setUnitType(UnitTypes typeToBeSet)
{
	mUnitType = typeToBeSet;
}





// This update function updates the positioning of the tile is compared to the camera
void Unit::updateCameraToUnitPosition() 
{
	switch (Game::getStaticInstance()->getUnitManager()->getCameraDirection())
	{
	case SHIFTLEFT:
		moveToPosition(Vector2(mCurrentLocation.mX - Game::getStaticInstance()->getPlayerWalkSpd(), mCurrentLocation.mY));
		break;
	case SHIFTRIGHT:
		moveToPosition(Vector2(mCurrentLocation.mX + Game::getStaticInstance()->getPlayerWalkSpd(), mCurrentLocation.mY));
		break;
	default:
		break;
	}
	
}




// This function gets the velocity of a specific object
double Unit::getVelocity() 
{
	return mVelocity;
}





// This function sets the velocity of a certain object based on a specific value
void Unit::setVelocity(double newVelocity) 
{
	mVelocity = newVelocity;
}





// This function gets the dimensions of the platform
Vector2 Unit::getDimensions()
{
	return mDimensions;
}





void Unit::setInitialPosition(Vector2 newPos)
{
	mInitialPosition = newPos;
}





void Unit::setIsMovingUp(bool newCondition)
{
	mIsMovingUp = newCondition;
}

void Unit::setEffect(bool effectStatus)
{
	mEffect = effectStatus;
}

void Unit::setDamageState(bool damageState)
{
	mCanBeDamaged = damageState;
}





void Unit::setIsMovingDown(bool newCondition)
{
	mIsMovingDown = newCondition;
}