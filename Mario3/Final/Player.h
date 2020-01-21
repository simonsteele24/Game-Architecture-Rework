#ifndef PLAYER_H
#define PLAYER_H

// Local includes
#include "Unit.h"


class Player : public Unit
{
public:

	// Friends
	friend class UnitManager;
	friend class SaveStateManager;

	// Update functions
	void update(double newTimeBetweenFrames);
	void onCollide(Unit & collidingObject, int collidingObjectIndex);

	// Accessors
	bool getGameStatus() { return mDone; }
	bool getBounceStatus() { return mBounce; }
	bool getPlayerSize() { return mIsThicc; }

	// Mutators
	void jump();
	void movePlayerRight();
	void movePlayerLeft();



	//Events
	void unitCollisions();//checks collisions for anything in unit manager
	void readyToKill(bool kill);
	void commenceDeath();
	void setGameStatus(bool status);
	void powerUpTimer(float timeReducer);
	void invincibilityFrameTimer(float timeReducer);//when player takes damage, it waits a bit before it can die

	//Powerup effects
	// Mutators
	void calculateTimeToAdd();
	void addIndex() { colorIndex++; }

	// Accessors
	int getIndexOfColor();//gets the current index of what the color mario should be in this invincibility form

private:

	// Constructors
	Player();
	Player(Vector2 newPos);

	// Destructors
	~Player();

	// Numbers
	double mMaxJumpForce;//used to limit how high the player can bounce/jump
	int mBounceKills;//used to keep track of number of enemies killed when bouncing.
	int* mpBounceToKill;//used to keep track of how many bounces any enemy needs in order to die.
	int timeLimit = 300;//how long an affect should last. these numbers dont represent seconds. 300 is about 15 seconds or so
	int invincibilityCounter = 0;
	int colorIndex = 0;//0-2 0 is original, 1 is color2, 2 is color 3.
	double mTargetTime;
	double mTimeElapsed;
	double mTimeElapsedInvincibilityFrame;

	// Booleans
	bool mIsJumping;
	bool mInMidAir;
	bool mBounce;
	bool mIsMoving;
	bool mCanDestroyTarget;
	bool mIsDying;
	bool mDone;
	bool mIsThicc = false;
	bool mInvincible;
	bool mStillThicc;
	bool mIsTrigger;

	// Directions
};


#endif // !PLAYER_H

