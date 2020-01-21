#include "LevelManager.h"
#include "Game.h"

LevelManager::LevelManager()
{
	mLevelNum = 0;
}

LevelManager::~LevelManager()
{
}

void LevelManager::loadNextLevel() 
{
	mLevelNum++;

	if (mLevelNum == 5)
	{
		Game::getStaticInstance()->mAudioManager->playCastleTheme();
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





void LevelManager::loadCurrentLevel() 
{
	if (mLevelNum == 5)
	{
		Game::getStaticInstance()->mAudioManager->playCastleTheme();
	}
	Game::getStaticInstance()->mUnitManager->removeAllUnits();
	Game::getStaticInstance()->mUnitManager->setCameraPosition(Vector2(0, 0));
	Game::getStaticInstance()->mReader.readLevelsFile(LEVEL_TEXT_FILE_PATH + to_string(mLevelNum) + ".txt");
}





int LevelManager::getLevelNumber() 
{
	return mLevelNum;
}





void LevelManager::setLevelNumber(int newNum) 
{
	mLevelNum = newNum;
}