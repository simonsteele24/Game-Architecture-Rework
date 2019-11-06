#include "SaveStateManager.h"
#include "Game.h"

SaveStateManager::SaveStateManager()
{
}

SaveStateManager::~SaveStateManager()
{
}

bool SaveStateManager::readFile(string fileName)
{
	string input;
	ifstream fin;
	Vector2 temp = Vector2(0, 0);
	string tempStr = "";
	Colors * tempColor = new Colors(0, 0, 0);

	// Open the text file
	fin.open(fileName);

	fin >> input;

	if (input == "" || fin.fail())
	{
		return false;
	}

	Game::getStaticInstance()->mUnitManager->removeAllUnits();

	Game::getStaticInstance()->mLevelManager.setLevelNumber(stoi(input));

	fin >> input;

	Game::getStaticInstance()->mNumOfCoins = stoi(input);
	Game::getStaticInstance()->mTextManager->getText(NAME_OF_COIN_TEXT)->changeMessage("Coins " + to_string(Game::getStaticInstance()->mNumOfCoins));

	fin >> input;

	Game::getStaticInstance()->mLives = stoi(input);
	Game::getStaticInstance()->mTextManager->getText(NAME_OF_LIVES_TEXT)->changeMessage("Lives " + to_string(Game::getStaticInstance()->mLives));

	fin >> input;
	Game::getStaticInstance()->addToScore(stoi(input));

	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	Game::getStaticInstance()->mUnitManager->setCameraPosition(temp);

	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	// Create a unit within the unit manager
	Game::getStaticInstance()->mUnitManager->createPlayer(Vector2(temp.mX, temp.mY));

	fin >> input;

	Game::getStaticInstance()->mUnitManager->getPlayer()->setVelocity(stoi(input));

	// Add the dean smurf walk animation and the default smurf walk animation to the newly created smurf unit
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerAnimation);
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerJumpAnimation);
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerDeathAnimation);


	fin >> input;
	while (input[0] < 58)
	{
		
		switch (stoi(input))
		{
		case 1:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createQuestionBlock(temp);
			
			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mQuestionBlockAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mQuestionBlockEmptyAnimation);
			break;
		case 2:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createBrickBlock(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBrickBlockAnimation);
			break;
		case 3:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createEndBlock(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mEndBlockAnimation);
			break;
		case 4:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createGoomba(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mGoombaAnimation);
			break;
		case 5:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createKoopa(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaRightAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaShellAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaShellSpinAnimation);
			break;
		case 6:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPiranhaPlant(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mPiranhaAnimation);
			break;
		case 7:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mCoinAnimation);
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(COIN);
			break;
		case 8:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createMushroom(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mSuperMushroomAnimation);
			break;
		case 9:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mPipeAnimation);
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIPE);
			break;
		case 11:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mWoodBlockAnimation);
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(WOOD_BLOCK);
			break;
		case 12:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mLavaAnimation);
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(LAVA);
			break;
		case 13:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createStarmen(temp);


			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mStarmenAnimation);
			break;
		case 14:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createThwomp(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));

			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setInitialPosition(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setIsMovingDown(stoi(input));

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setIsMovingUp(stoi(input));

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mThwompAnimation);
			break;
		case 15:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createDryBones(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesLeftAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesRightAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesDownAnimation);
			break;
		case 16:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createBoomBoom(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomWalkAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomDefenseAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomJumpAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomSquishedAnimation);
			break;
		case 17:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createFireball(temp);

			fin >> input;
			
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));

			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setInitialPosition(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setIsMovingDown(stoi(input));

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setIsMovingUp(stoi(input));

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mFireballUpAnimation);
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mFireballDownAnimation);
			break;
		default:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDefaultBlockAnimation);
			break;
		}
		fin >> input;
	}


	input = input;
	while (!fin.eof())
	{
		switch (input[0])
		{
		case 'C':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mCloudAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('C');
			break;
		case '#':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mDefaultBlockAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('#');
			break;
		case 'V':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mDeepGrassAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('V');
			break;
		case 'X':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mCastleBlockAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('X');
			break;
		case 'v':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mGrassAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('v');
			break;
		case 'Z':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mLeftCornerSlopeAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('Z');
			break;
		case 'h':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mRightCornerSlopeAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('h');
			break;
		case 'c':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mRightSlopeAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('c');
			break;
		case 'l':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mLeftSlopeAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('l');
			break;
		case 't':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mTopSlopeAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('t');
			break;
		case '!':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mPoleAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('!');
			break;
		case '<':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mLeftPlatformAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('<');
			break;
		case '>':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mRightPlatformAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('>');
			break;
		case 'N':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mMiddlePlatformAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('N');
			break;
		case 'K':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, *Game::getStaticInstance()->mLargePlatformAnimation);
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('K');
			break;
		case 'd':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mDonutBushAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('d');
			break;
		case '=':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mDonutHillOneAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('=');
			break;
		case 'z':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mDonutHillTwoAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('z');
			break;
		case '6':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mBlueFloatingBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('6');
			break;
		case '7':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mGreenFloatingBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('7');
			break;
		case '8':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeRedFloatingBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('8');
			break;
		case '9':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mSmallRedFloatingBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('9');
			break;
		case 'f':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mBushAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('f');
			break;

		case 'W':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeWhiteBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('W');
			break;
		case 'B':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mTallBlueBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('B');
			break;
		case 'o':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mSmalllOrangeBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('o');
			break;
		case 'G':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeGreenBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('G');
			break;
		case 'R':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mMediumRedBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('R');
			break;
		case '2':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLongGreenBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('2');
			break;
		case '3':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeRedBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('3');
			break;
		case '4':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeBlueBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('4');
			break;
		case '5':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mTallGreenBoxAnimation);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('5');
			break;
		case 'e':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mBackgroundEndImage);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('e');
			break;
		default:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, *Game::getStaticInstance()->mBigHillAnimation);
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('H');
			break;
		}

		fin >> input;
	}

	delete tempColor;
	return true;
}

bool SaveStateManager::saveFile(string fileToSaveTo) 
{
	ofstream fout;

	fout.open(fileToSaveTo);

	if (fout.fail()) 
	{
		return false;
	}
	else 
	{
		fout << Game::getStaticInstance()->mLevelManager.getLevelNumber() << endl;
		fout << Game::getStaticInstance()->mNumOfCoins << endl;
		fout << Game::getStaticInstance()->mLives << endl;
		fout << Game::getStaticInstance()->mScore << endl;
		fout << Game::getStaticInstance()->mUnitManager->getCameraPosition().mX << " " << Game::getStaticInstance()->mUnitManager->getCameraPosition().mX << endl;

		fout << Game::getStaticInstance()->mUnitManager->getPlayer()->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getPlayer()->getLocation().mY << " " << Game::getStaticInstance()->mUnitManager->getPlayer()->getVelocity() << endl;

		for (int i = 0; i < Game::getStaticInstance()->mUnitManager->getSize(); i++) 
		{
			if (Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() == THWOMP || Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() == FIREBALL) 
			{
				fout << (int)Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mX << " " <<
					Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getVelocity() << " " <<
					Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mX << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getIsMovingDown() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getIsMovingUp() << endl;
			}
			else
			{
				fout << (int)Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getVelocity() << endl;
			}
		}

		fout << endl;

		for (int i = 0; i < Game::getStaticInstance()->mUnitManager->getPropSize(); i++) 
		{
			fout << Game::getStaticInstance()->mUnitManager->getProp(i)->getPropIdentity() << " " << Game::getStaticInstance()->mUnitManager->getProp(i)->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getProp(i)->getLocation().mY << endl;
		}

		for (int i = 0; i < Game::getStaticInstance()->mUnitManager->getPlatformSize(); i++) 
		{
			fout << Game::getStaticInstance()->mUnitManager->getPlatform(i)->getPlatformIdentity() << " " << Game::getStaticInstance()->mUnitManager->getPlatform(i)->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getPlatform(i)->getLocation().mY << endl;
		}

		for (int i = 0; i < Game::getStaticInstance()->mUnitManager->getTileSize(); i++) 
		{
			fout << Game::getStaticInstance()->mUnitManager->getTile(i)->getTileIdentity() << " " << Game::getStaticInstance()->mUnitManager->getTile(i)->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getTile(i)->getLocation().mY << endl;
		}

		fout.close();
		return true;
	}
}