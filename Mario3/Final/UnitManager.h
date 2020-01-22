#ifndef UNITMANAGER_H
#define UNITMANAGER_H

// Local Includes
#include "Unit.h"
#include "Tile.h"
#include "Player.h"
#include "QuestionBlock.h"
#include "BrickBlock.h"
#include "EndBlock.h"
#include "Goomba.h"
#include "Koopa.h"
#include "PiranhaPlant.h"
#include "Prop.h"
#include "Thwomp.h"
#include "DryBones.h"
#include "Platform.h"
#include "Fireball.h"
#include "SuperMushroom.h"
#include "Starmen.h"

enum CameraDirection
{
	SHIFTLEFT,
	SHIFTRIGHT,
	STATIONARY
};

struct CollisionInfo 
{
	int aIndex;
	int bIndex;

	CollisionInfo(const int & _a, const int & _b) 
	{
		aIndex = _a;
		bIndex = _b;
	}
};

class UnitManager
{
public:

	// Constructors
	UnitManager();

	// Destuctors
	~UnitManager();

	// Acessors
	Unit * getUnit( int index );
	int getSize();
	int getPropSize();
	int getPlatformSize();
	int getTileSize();
	Player* getPlayer();
	Prop * getProp(int index);
	Tile * getTile(int index);
	Platform * getPlatform(int index);

	// Mutators
	void removeAllUnits();

	//Unit Creation
	void createUnit(Vector2 newPos);
	//Player 
	void createPlayer(Vector2 newPos);
	//Blocks
	void createQuestionBlock(Vector2 newPos);
	void createBrickBlock(Vector2 newPos);
	void createEndBlock(Vector2 newPos);
	//Enemies
	void createGoomba( Vector2 newPos );
	void createThwomp(Vector2 newPos);
	void createKoopa( Vector2 newPos );
	void createDryBones(Vector2 newPos);
	void createPiranhaPlant(Vector2 newPos);
	//Environment and Collectibles
	void createFireball(Vector2 newPos);
	void createProp(Vector2 newPos, Animation & newAnim);
	void createPlatform(Vector2 newPos);
	void createTile(Vector2 newPos, Animation & newAnim);
	void createMushroom(Vector2 newPos);
	void createStarmen(Vector2 newPos);

	//Other mutators
	void addAnimation( int index, Animation newAnim );
	void destroyUnit( int index );
	void playOrStopUnitAnimations();
	void addPlayerAnimation(Animation & newAnim);
	void movePlayer(Vector2 newPos);
	void setCameraDirection(CameraDirection newDir);
	void addToCameraPosition(Vector2 newAddition);
	void setCameraPosition(Vector2 newPos);

	// Accessors
	CameraDirection getCameraDirection();
	Vector2 getCameraPosition();

	// Update functions
	void update( double timeBetweenFrames );
	void draw();
	void calculateCollisions();

private:

	// Vectors
	vector<Unit*> mUnits;
	vector<Prop*> mProps;
	vector<Platform*> mPlatforms;
	vector<Tile*> mTiles;
	vector<CollisionInfo> mCollisions;

	// Player
	Player* mPlayer;

	// Camera Directions
	CameraDirection mCameraDirection;

	// Vector2's
	Vector2 mCameraPosition;
};
#endif // !UNITMANAGER_H

