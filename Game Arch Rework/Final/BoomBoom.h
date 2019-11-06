#ifndef BOOMBOOM_H
#define BOOMBOOM_H

// Local includes
#include "Unit.h"
#include <string>

class BoomBoom : public Unit
{
public:

	//Enum that holds the phases of the boss
	enum BoomBoomPhase
	{
		DEFENSE_MODE,//used to refer to the defense state where it can't take damage
		WALK_MODE,//used to refer to its neutral state of him walking around and following player
		JUMP_MODE,//used to refer to the state where the boss will jump up then come back down.
		INJURED_MODE,//used to refer to the state in which it has taken damage
		NONE,
	};

	// Constructors
	BoomBoom();
	BoomBoom(Vector2 newPos);
	BoomBoom(Vector2 newPos,int newIndex);

	// Destructors
	~BoomBoom();

	// Update functions
	void update(double newTimeBetweenFrames);

	bool getHealthStatus() { return isDying; }//used to keep track of the state of the boss, if its dead or not

private:

	// Numbers
	int mCount = 0;//this mCount and the max count is used to keep track of when the boss should swap directions.
	int mMaxCount = 100;
	int mTimesBouncedOn = 0;//used to keep track of how many times this boss has taken damage
	int mCurrentPhaseTime = 0;//the current time.
	int mTargetPhaseTime = 100;//the time the counter must reach for a phase change.
	int indexInUnitsManager;//used to keep track of where this object is in the unit manager

	//Booleans
	bool isDying = false;
	bool mChangeDirection = false;
	bool mCanChangeDirection = false;
	bool mPhaseChange = false;

	//Other
	BoomBoomPhase phase;
	Direction mCurrentDirection;
	Direction mDiagonalDirection;
};

#endif // !BOOMBOOM_H


