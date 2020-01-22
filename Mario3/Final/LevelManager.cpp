#include "LevelManager.h"
#include "Game.h"

// This is the default constructor for this class
LevelManager::LevelManager()
{
	mLevelNum = 0;
}





// This is the destructor for the class
LevelManager::~LevelManager()
{
}





// This function loads the next level in the sequence
void LevelManager::loadNextLevel() 
{
	mLevelNum++;

	if (mLevelNum == MAX_LEVELS)
	{
		Game::getStaticInstance()->mAudioManager->playSound(NAME_OF_CASTLE_THEME);
	}

	if (mLevelNum > MAX_LEVELS) 
	{
		Game::getStaticInstance()->mInApplication = false;
		Game::getStaticInstance()->mInGame = false;
	}
	else 
	{
		Game::getStaticInstance()->mUnitManager->removeAllUnits();
		Game::getStaticInstance()->mUnitManager->setCameraPosition(Vector2(0, 0));
		Game::getStaticInstance()->mReader.readLevelsFile(LEVEL_TEXT_FILE_PATH + to_string(mLevelNum) + ".txt");
	}
}





// This function loads the current level 
void LevelManager::loadCurrentLevel() 
{
	if (mLevelNum == 5)
	{
		Game::getStaticInstance()->mAudioManager->playSound(NAME_OF_CASTLE_THEME);
	}
	Game::getStaticInstance()->mUnitManager->removeAllUnits();
	Game::getStaticInstance()->mUnitManager->setCameraPosition(Vector2(0, 0));
	Game::getStaticInstance()->mReader.readLevelsFile(LEVEL_TEXT_FILE_PATH + to_string(mLevelNum) + ".txt");
}





// This function gets the level number
int LevelManager::getLevelNumber() 
{
	return mLevelNum;
}





// This function sets the level number based on a given integer
void LevelManager::setLevelNumber(int newNum) 
{
	mLevelNum = newNum;
}