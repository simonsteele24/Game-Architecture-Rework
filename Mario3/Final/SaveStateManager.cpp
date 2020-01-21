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
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_JUMP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_DEATH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_DEATH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_JUMP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_JUMP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_JUMP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_JUMP].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER_RED, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_RED), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER_RED_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_RED_JUMP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED_JUMP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED_JUMP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_RED_JUMP].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER_GREEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_GREEN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_SUPER_PLAYER_GREEN_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_GREEN_JUMP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN_JUMP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN_JUMP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_PLAYER_GREEN_JUMP].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_RED, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_RED), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_RED].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_RED].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_RED].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_GREEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_GREEN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_GREEN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_GREEN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_GREEN].mSpriteDimensions));

	fin >> input;

	Game::getStaticInstance()->mUnitManager->getPlayer()->setVelocity(stoi(input));

	fin >> input;

	Game::getStaticInstance()->mUnitManager->getPlayer()->mIsThicc = (input == "1");
	Game::getStaticInstance()->mUnitManager->getPlayer()->mStillThicc = (input == "1");

	// Add the dean smurf walk animation and the default smurf walk animation to the newly created smurf unit
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_JUMP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_JUMP].mSpriteDimensions));
	Game::getStaticInstance()->mUnitManager->addPlayerAnimation(Animation(NAME_OF_PLAYER_DEATH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_DEATH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLAYER_DEATH_ANIMATION].mSpriteDimensions));


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
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setEffect(true);
			
			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_QUESTION_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_EMPTY_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_EMPTY_QUESTION_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(QUESTION_BLOCK);
			break;
		case 2:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createBrickBlock(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BRICK_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BRICK_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(BRICK_BLOCK);
			break;
		case 3:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createEndBlock(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_END_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_END_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(END_BLOCK);
			break;
		case 4:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createGoomba(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_GOOMBA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GOOMBA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(GOOMBA);
			break;
		case 5:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createKoopa(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_RIGHT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_SHELL_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(KOOPA);
			break;
		case 6:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPiranhaPlant(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_PIRANHA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIRANHA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIRANHAPLANT);
			break;
		case 7:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_COIN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_COIN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].mSpriteDimensions));
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
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_SUPER_MUSHROOM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_MUSHROOM), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(SUPER_MUSHROOM);
			break;
		case 9:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIPE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].mSpriteDimensions));
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
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_WOOD_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_WOOD_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].mSpriteDimensions));
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
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_LAVA_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LAVA_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].mSpriteDimensions));
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
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_STARMEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_STARMEN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(STARMEN);
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

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_THWOMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_THWOMP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(THWOMP);
			break;
		case 15:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createDryBones(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_LEFT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_LEFT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_RIGHT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_DOWN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(DRYBONES);
			break;
		case 16:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createBoomBoom(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_JUMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_JUMP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(BOOMBOOM);
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

			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_FIREBALL_UP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_UP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_FIREBALL_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_DOWN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(FIREBALL);
			break;
		case 18:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_HORIZONTAL_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_HORIZONTAL_PIPE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(SIDE_PIPE);

			break;

		default:
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createUnit(temp);

			fin >> input;

			Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setVelocity(stoi(input));
			Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DEFAULT_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEFAULT_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].mSpriteDimensions));
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

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_CLOUD, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CLOUD), Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('C');
			break;
		case '#':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_DEFAULT_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEFAULT_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('#');
			break;
		case 'V':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_DEEP_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEEP_GRASS_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('V');
			break;
		case 'X':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_CASTLE_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CASTLE_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('X');
			break;
		case 'v':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GRASS_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('v');
			break;
		case 'Z':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_SLOPE_LEFT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT_CORNER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('Z');
			break;
		case 'h':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_SLOPE_RIGHT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT_CORNER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('h');
			break;
		case 'c':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_SLOPE_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('c');
			break;
		case 'l':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_SLOPE_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('l');
			break;
		case 't':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_SLOPE_TOP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_TOP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('t');
			break;
		case '!':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_POLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_POLE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('!');
			break;
		case '<':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_PLATFORM_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_LEFT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('<');
			break;
		case '>':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_PLATFORM_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_RIGHT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('>');
			break;
		case 'N':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_PLATFORM_MIDDLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_MIDDLE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('N');
			break;
		case 'K':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createTile(temp, Animation(NAME_OF_LARGE_PLATFORM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_PLATFORM), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('K');
			break;
		case 'd':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_DONUT_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_BUSH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('d');
			break;
		case '=':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_DONUT_HILL_ONE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_ONE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('=');
			break;
		case 'z':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_DONUT_HILL_TWO, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_TWO), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('z');
			break;
		case '6':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_BLUE_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BLUE_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('6');
			break;
		case '7':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_GREEN_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GREEN_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('7');
			break;
		case '8':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('8');
			break;
		case '9':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('9');
			break;
		case 'f':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BUSH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('f');
			break;

		case 'W':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_WHITE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_WHITE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('W');
			break;
		case 'B':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_TALL_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_BLUE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('B');
			break;
		case 'o':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_SMALL_ORANGE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_ORANGE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('o');
			break;
		case 'G':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('G');
			break;
		case 'R':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_MEDIUM_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_MEDIUM_RED_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('R');
			break;
		case '2':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LONG_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LONG_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('2');
			break;
		case '3':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('3');
			break;
		case '4':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_BLUE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].mSpriteDimensions));
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('4');
			break;
		case '5':
			fin >> input;
			temp.mX = stoi(input);
			fin >> input;
			temp.mY = stoi(input);

			Game::getStaticInstance()->mUnitManager->createPlatform(temp);
			Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_TALL_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].mSpriteDimensions));
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

			Game::getStaticInstance()->mUnitManager->createProp(temp, Animation(NAME_OF_BIG_HILL, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BIG_HILL), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].mSpriteDimensions));
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

		fout << Game::getStaticInstance()->mUnitManager->getPlayer()->getLocation().mX << " " << Game::getStaticInstance()->mUnitManager->getPlayer()->getLocation().mY << " " << Game::getStaticInstance()->mUnitManager->getPlayer()->getVelocity() << " " << Game::getStaticInstance()->mUnitManager->getPlayer()->getPlayerSize() << endl;

		for (int i = 0; i < Game::getStaticInstance()->mUnitManager->getSize(); i++) 
		{
			if (Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() == THWOMP || Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() == FIREBALL) 
			{
				fout << (int)Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mX << " " <<
					Game::getStaticInstance()->mUnitManager->getUnit(i)->getLocation().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getVelocity() << " " <<
					Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mX << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getIsMovingDown() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getIsMovingUp() << endl;
			}
			if (Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() == PIRANHAPLANT) 
			{
				fout << (int)Game::getStaticInstance()->mUnitManager->getUnit(i)->getCurrentUnitType() << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mX << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getInitialPosition().mY << " " << Game::getStaticInstance()->mUnitManager->getUnit(i)->getVelocity() << endl;
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