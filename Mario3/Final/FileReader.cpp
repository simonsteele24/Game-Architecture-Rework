#include "FileReader.h"
#include "Game.h"

// This function is the default constructor of the class
FileReader::FileReader()
{
}





// This function is the destructor of the class
FileReader::~FileReader()
{
}





// This function reads text file with all modifiable in-game values
// and assigns them to their respective variables
void FileReader::readFile(string fileName)
{
	string input;
	ifstream fin;
	Vector2 temp = Vector2(0, 0);
	Vector2 temp2 = Vector2(0, 0);
	string tempStr = "";
	Colors * tempColor = new Colors(0, 0, 0);

	// Open the text file
	fin.open(fileName);

	// Get the display dimensions of the game
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mDisplayDimensions.mX = stoi(input);
	fin >> input;
	Game::getStaticInstance()->mDisplayDimensions.mY = stoi(input);


	fin.ignore();


	// Get the background image
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BACKGROUND_BUFFER);

	// Get the value to scale the background image by
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBackgroundScalingValue = stod(input);


	fin.ignore();


	// Get the end tear background image
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BACKGROUND_TEAR_BUFFER);


	// Get the value to scale the background image by
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBackgroundEndScalingValue = stod(input);


	fin.ignore();


	// Get the end black background image
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BACKGROUND_END_BUFFER);


	// Get the value to scale the background image by
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBackgroundEndImage = new Animation(NAME_OF_BACKGROUND_END_BUFFER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BACKGROUND_END_BUFFER), 1, 1, Game::getStaticInstance()->mDisplayDimensions, Vector2(Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BACKGROUND_END_BUFFER)->getHeight(), Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BACKGROUND_END_BUFFER)->getWidth()));
	Game::getStaticInstance()->mBackgroundEndScalingValue = stod(input);


	fin.ignore();


	// Get the Player Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER);

	// Get the dimensions of the Player Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Player Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerAnimation = new Animation(NAME_OF_PLAYER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Player Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_JUMP);

	// Get the Sprites per row and column for the Player Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerJumpAnimation = new Animation(NAME_OF_PLAYER_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();
		

	// Get the Player Death Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_DEATH_ANIMATION);

	// Get the Sprites per row and column for the Player Death Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerDeathAnimation = new Animation(NAME_OF_PLAYER_DEATH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_DEATH_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	// Get the dimensions of the Player Red Sprite but since they same as first mini sprite, it dont matter
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_RED);

	// Get the Sprites per row and column for the Player Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerRedAnimation = new Animation(NAME_OF_PLAYER_RED, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_RED), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the  Player Red Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_RED_JUMP);

	// Get the Sprites per row and column for the Player Red Walking Left Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerRedJumpAnimation = new Animation(NAME_OF_PLAYER_RED_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_RED_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the dimensions of the Player Green Sprite but since they same as first mini sprite, it dont matter
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_GREEN);

	// Get the Sprites per row and column for the Player Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerGreenAnimation = new Animation(NAME_OF_PLAYER_GREEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_GREEN), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the  Player Green Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLAYER_GREEN_JUMP);

	// Get the Sprites per row and column for the Player Green Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPlayerGreenJumpAnimation = new Animation(NAME_OF_PLAYER_GREEN_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLAYER_GREEN_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER);

	// Get the dimensions of the Super Player Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Player Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerAnimation = new Animation(NAME_OF_SUPER_PLAYER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Red Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER_RED);

	// Get the Sprites per row and column for the Super Player Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerRedAnimation = new Animation(NAME_OF_SUPER_PLAYER_RED, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_RED), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Green Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER_GREEN);

	// Get the Sprites per row and column for the Super Player Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerGreenAnimation = new Animation(NAME_OF_SUPER_PLAYER_GREEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_GREEN), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER_JUMP);

	// Get the Sprites per row and column for the Super Player Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerJumpAnimation = new Animation(NAME_OF_SUPER_PLAYER_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Red Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER_RED_JUMP);

	// Get the Sprites per row and column for the Super Player Red Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerRedJumpAnimation = new Animation(NAME_OF_SUPER_PLAYER_RED_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_RED_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Super Player Green Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_PLAYER_GREEN_JUMP);

	// Get the Sprites per row and column for the Super Player Green Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperPlayerGreenJumpAnimation = new Animation(NAME_OF_SUPER_PLAYER_GREEN_JUMP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_PLAYER_GREEN_JUMP), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Default Block Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DEFAULT_BLOCK);

	// Get the dimensions of the Default Block Sprite
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mDefaultBlockDimensions.mX = stoi(input);
	fin >> input;
	Game::getStaticInstance()->mDefaultBlockDimensions.mY = stoi(input);

	// Get the Sprites per row and column for the Default Block Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mDefaultBlockAnimation = new Animation(NAME_OF_DEFAULT_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEFAULT_BLOCK), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mDefaultBlockDimensions);


	fin.ignore();

	// Get the Brick Block Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BRICK_BLOCK);

	// Get the dimensions of the Brick Block Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Brick Block Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBrickBlockAnimation = new Animation(NAME_OF_BRICK_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BRICK_BLOCK), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Question Block Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_QUESTION_BLOCK);

	// Get the dimensions of the Question Block Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Question Block Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mQuestionBlockAnimation = new Animation(NAME_OF_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_QUESTION_BLOCK), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Empty Question Block Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_EMPTY_QUESTION_BLOCK);

	// Get the dimensions of the Empty Question Block Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Empty Question Block Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mQuestionBlockEmptyAnimation = new Animation(NAME_OF_EMPTY_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_EMPTY_QUESTION_BLOCK), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the End Block Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_END_BLOCK);

	// Get the dimensions of the End Block Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the End Block Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mEndBlockAnimation = new Animation(NAME_OF_END_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_END_BLOCK), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	
	fin.ignore();


	// Get the Goomba Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_GOOMBA);

	// Get the dimensions of the Goomba Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Goomba Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mGoombaAnimation = new Animation(NAME_OF_GOOMBA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GOOMBA), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	
	fin.ignore();


	// Get the Koopa Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_KOOPA);

	// Get the dimensions of the Koopa Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Koopa Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mKoopaAnimation = new Animation(NAME_OF_KOOPA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Koopa Right Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_KOOPA_RIGHT_ANIMATION);

	// Get the Sprites per row and column for the Koopa Right Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mKoopaRightAnimation = new Animation(NAME_OF_KOOPA_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_RIGHT_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Koopa Shell Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_KOOPA_SHELL_ANIMATION);

	// Get the Sprites per row and column for the Koopa Shell Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mKoopaShellAnimation = new Animation(NAME_OF_KOOPA_SHELL_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Koopa Shell Spin Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_KOOPA_SHELL_SPIN_ANIMATION);

	// Get the Sprites per row and column for the Koopa Shell Spin Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mKoopaShellSpinAnimation = new Animation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Big Hill Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BIG_HILL);

	// Get the Sprites per row and column for the Big Hill Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBigHillAnimation = new Animation(NAME_OF_BIG_HILL, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BIG_HILL), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();

	// Get the Big Hill Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BUSH_ANIMATION);
	Game::getStaticInstance()->mBushAnimation = new Animation(NAME_OF_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BUSH_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mDefaultBlockDimensions);

	fin.ignore();


	// Get the Pipe Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PIPE);

	// Get the Sprites per row and column for the Pipe Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPipeAnimation = new Animation(NAME_OF_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIPE), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	// Get the Piranha Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PIRANHA);

	// Get the dimensions of the Piranha Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Piranha Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mPiranhaAnimation = new Animation(NAME_OF_PIRANHA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIRANHA), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Cloud Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_CLOUD);

	// Get the Sprites per row and column for the Cloud Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mCloudAnimation = new Animation(NAME_OF_CLOUD, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CLOUD), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	// Get the Coin Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_COIN);

	// Get the dimensions of the Coin Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Coin Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mCoinAnimation = new Animation(NAME_OF_COIN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_COIN), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	// Get the Super Mushroom Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SUPER_MUSHROOM);

	// Get the dimensions of the Super Mushroom Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Super Mushroom Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mSuperMushroomAnimation = new Animation(NAME_OF_SUPER_MUSHROOM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_MUSHROOM), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Starmen Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_STARMEN);

	// Get the dimensions of the Starmen Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Starmen Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mStarmenAnimation = new Animation(NAME_OF_STARMEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_STARMEN), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Small Orange Box Sprite Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SMALL_ORANGE_BOX_ANIMATION);

	// Get the dimensions of the Small Orange Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mSmalllOrangeBoxAnimation = new Animation(NAME_OF_SMALL_ORANGE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_ORANGE_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	

	fin.ignore();


	// Get the Tall Blue Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_TALL_BLUE_BOX_ANIMATION);

	// Get the dimensions of the Tall Blue Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mTallBlueBoxAnimation = new Animation(NAME_OF_TALL_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_BLUE_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Large Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_GREEN_BOX_ANIMATION);

	// Get the dimensions of the Large Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLargeGreenBoxAnimation = new Animation(NAME_OF_LARGE_GREEN_BOX_ANIMATION , Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_GREEN_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Medium Red Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_MEDIUM_RED_BOX_ANIMATION);

	// Get the dimensions of the Medium Red Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mMediumRedBoxAnimation = new Animation(NAME_OF_MEDIUM_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_MEDIUM_RED_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Long Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LONG_GREEN_BOX_ANIMATION);

	// Get the dimensions of the Long Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLongGreenBoxAnimation = new Animation(NAME_OF_LONG_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LONG_GREEN_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Large White Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_WHITE_BOX_ANIMATION);

	// Get the dimensions of the Large White Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLargeWhiteBoxAnimation = new Animation(NAME_OF_LARGE_WHITE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_WHITE_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Large Red Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_RED_BOX_ANIMATION);

	// Get the dimensions of the Large Red Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLargeRedBoxAnimation = new Animation(NAME_OF_LARGE_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Large Blue Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_BLUE_BOX_ANIMATION);

	// Get the dimensions of the Large Blue Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLargeBlueBoxAnimation = new Animation(NAME_OF_LARGE_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_BLUE_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the Tall Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_TALL_GREEN_BOX_ANIMATION);

	// Get the dimensions of the Tall Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mTallGreenBoxAnimation = new Animation(NAME_OF_TALL_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_GREEN_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the Tall Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BLUE_FLOATING_BOX_ANIMATION);

	// Get the dimensions of the Tall Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mBlueFloatingBoxAnimation = new Animation(NAME_OF_BLUE_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BLUE_FLOATING_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the Tall Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_GREEN_FLOATING_BOX_ANIMATION);

	// Get the dimensions of the Tall Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mGreenFloatingBoxAnimation = new Animation(NAME_OF_GREEN_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GREEN_FLOATING_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the Tall Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION);

	// Get the dimensions of the Tall Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mLargeRedFloatingBoxAnimation = new Animation(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the Tall Green Box Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION);

	// Get the dimensions of the Tall Green Box Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mSmallRedFloatingBoxAnimation = new Animation(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the Thwomp Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_THWOMP_ANIMATION);

	// Get the dimensions of the Thwomp Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);
	Game::getStaticInstance()->mThwompAnimation = new Animation(NAME_OF_THWOMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_THWOMP_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();

	
	// Get the dimensions of the Wood Block Sprite
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_WOOD_BLOCK);
	Game::getStaticInstance()->mWoodBlockAnimation = new Animation(NAME_OF_WOOD_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_WOOD_BLOCK), 1, 1, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mDefaultBlockDimensions);

	fin.ignore();

	// Get the Lava Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LAVA_ANIMATION);

	// Get the dimensions of the Lava Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the Lava Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mLavaAnimation = new Animation(NAME_OF_LAVA_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LAVA_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the dimensions of the Super Mushroom Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the dimensions of the Super Mushroom Sprite
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);


	// Get the information of Dry Bones Left
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DRY_BONES_LEFT_ANIMATION);
	Game::getStaticInstance()->mDryBonesLeftAnimation = new Animation(NAME_OF_DRY_BONES_LEFT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_LEFT_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	// Get the information of Dry Bones Right
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DRY_BONES_RIGHT_ANIMATION);
	Game::getStaticInstance()->mDryBonesRightAnimation = new Animation(NAME_OF_DRY_BONES_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_RIGHT_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DRY_BONES_DOWN_ANIMATION);
	Game::getStaticInstance()->mDryBonesDownAnimation = new Animation(NAME_OF_DRY_BONES_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_DOWN_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	fin.ignore();

	// Fire ball spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_FIREBALL_UP_ANIMATION);
	Game::getStaticInstance()->mFireballUpAnimation = new Animation(NAME_OF_FIREBALL_UP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_UP_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_FIREBALL_DOWN_ANIMATION);
	Game::getStaticInstance()->mFireballDownAnimation = new Animation(NAME_OF_FIREBALL_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_DOWN_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	fin.ignore();

	// Get the BoomBoom Walk Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BOOMBOOM_ANIMATION);

	// Get the dimensions of the BoomBoom Walk Sprite
	fin >> input;
	fin >> input;
	temp2.mX = stoi(input);
	fin >> input;
	temp2.mY = stoi(input);

	// Get the Sprites per row and column for the BoomBoom Walk Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBoomBoomWalkAnimation = new Animation(NAME_OF_BOOMBOOM_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

	fin.ignore();

	// Get the BoomBoom Squished Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BOOMBOOM_SQUISHED_ANIMATION);

	// Get the Sprites per row and column for the BoomBoom Squished Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBoomBoomSquishedAnimation = new Animation(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();

	// Get the BoomBoom Defense Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BOOMBOOM_DEFENSE_ANIMATION);

	// Get the Sprites per row and column for the BoomBoom Defense Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBoomBoomDefenseAnimation = new Animation(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	// Get the BoomBoom Jump Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_BOOMBOOM_JUMP_ANIMATION);

	// Get the Sprites per row and column for the BoomBoom Jump Sprites
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);
	Game::getStaticInstance()->mBoomBoomJumpAnimation = new Animation(NAME_OF_BOOMBOOM_JUMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_JUMP_ANIMATION), (int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);


	fin.ignore();


	//Get the Grass  Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_GRASS_ANIMATION);
	Game::getStaticInstance()->mGrassAnimation = new Animation(NAME_OF_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GRASS_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	//Get the Left Corner Slope Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SLOPE_LEFT_CORNER);
	Game::getStaticInstance()->mLeftCornerSlopeAnimation = new Animation(NAME_OF_SLOPE_LEFT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT_CORNER), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	//Get the Right Corner Slope  Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SLOPE_RIGHT_CORNER);
	Game::getStaticInstance()->mRightCornerSlopeAnimation = new Animation(NAME_OF_SLOPE_RIGHT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT_CORNER), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	//Get the Left Slope Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SLOPE_LEFT);
	Game::getStaticInstance()->mLeftSlopeAnimation = new Animation(NAME_OF_SLOPE_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	//Get the Right Slope Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SLOPE_RIGHT);
	Game::getStaticInstance()->mRightSlopeAnimation = new Animation(NAME_OF_SLOPE_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);

	//Get the Top Slope Spritesheet
	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_SLOPE_TOP);
	Game::getStaticInstance()->mTopSlopeAnimation = new Animation(NAME_OF_SLOPE_TOP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_TOP), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Deeeep grass  Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DEEP_GRASS_ANIMATION);
	Game::getStaticInstance()->mDeepGrassAnimation = new Animation(NAME_OF_DEEP_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEEP_GRASS_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Donust Bush Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DONUT_BUSH_ANIMATION);
	Game::getStaticInstance()->mDonutBushAnimation = new Animation(NAME_OF_DONUT_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_BUSH_ANIMATION), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Donust Hill One Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DONUT_HILL_ONE);
	Game::getStaticInstance()->mDonutHillOneAnimation = new Animation(NAME_OF_DONUT_HILL_ONE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_ONE), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Donust Hill Two Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_DONUT_HILL_TWO);
	Game::getStaticInstance()->mDonutHillTwoAnimation = new Animation(NAME_OF_DONUT_HILL_TWO, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_TWO), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Horizontal Pipe Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_HORIZONTAL_PIPE);
	Game::getStaticInstance()->mHorizontalPipeAnimation = new Animation(NAME_OF_HORIZONTAL_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_HORIZONTAL_PIPE), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Right Platform Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLATFORM_RIGHT);
	Game::getStaticInstance()->mRightPlatformAnimation = new Animation(NAME_OF_PLATFORM_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_RIGHT), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Left Platform Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLATFORM_LEFT);
	Game::getStaticInstance()->mLeftPlatformAnimation = new Animation(NAME_OF_PLATFORM_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_LEFT), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Middle Platform Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_PLATFORM_MIDDLE);
	Game::getStaticInstance()->mMiddlePlatformAnimation = new Animation(NAME_OF_PLATFORM_MIDDLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_MIDDLE), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Large Platform Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_LARGE_PLATFORM);
	Game::getStaticInstance()->mLargePlatformAnimation = new Animation(NAME_OF_LARGE_PLATFORM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_PLATFORM), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Pole Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_POLE);
	Game::getStaticInstance()->mPoleAnimation = new Animation(NAME_OF_POLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_POLE), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.ignore();


	//Get the Castle Block Spritesheet
	fin >> input;
	fin >> input;
	temp.mX = stoi(input);
	fin >> input;
	temp.mY = stoi(input);

	fin >> input;
	fin >> input;
	Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, NAME_OF_CASTLE_BLOCK);
	Game::getStaticInstance()->mCastleBlockAnimation = new Animation(NAME_OF_CASTLE_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CASTLE_BLOCK), 1, 1, Game::getStaticInstance()->mDisplayDimensions, temp);


	fin.close();//close file

	delete tempColor;
}

void FileReader::readUIFile(string fileName)
{
	string input;
	ifstream fin;
	Vector2 temp = Vector2(0, 0);
	string tempStr = "";
	Colors * tempColor = new Colors(0, 0, 0);

	// Open the text file
	fin.open(fileName);

	fin >> input;//Header

	// Get the File name of the font
	fin >> input;//Name
	fin >> input;//File Path
	Game::getStaticInstance()->mUIFont = new Fonts(ASSET_PATH_TWO + input);

	fin.ignore();// go to next line

	//Get the Font color
	fin >> input;//Name
	fin >> input;//get the r
	tempColor->setR((stof(input)));//set the r

	fin >> input;//get the g
	tempColor->setG((stof(input)));//set the g

	fin >> input;//get the b
	tempColor->setB((stof(input)));//set the b
	
	//Set the member font colors value to the temp ones
	Game::getStaticInstance()->mUIFontColor->setR(tempColor->getR());
	Game::getStaticInstance()->mUIFontColor->setG(tempColor->getG());
	Game::getStaticInstance()->mUIFontColor->setB(tempColor->getB());

	fin.ignore();

	//Get the Initial Score
	fin >> input;//Name
	fin >> input;//get the multiplier

	//nothing as of right now

	fin.ignore();

	//Get the Score Multiplier
	fin >> input;//Name
	fin >> input;//get the multiplier
	
	Game::getStaticInstance()->setScoreMultiplier(stoi(input));

	fin.ignore();

	//Get the Score Increment Amount
	fin >> input;//Name
	fin >> input;//get the additive amount

	Game::getStaticInstance()->setScoreAddAmt(stoi(input));

	fin.close();

	// Delete the temporary color pointer
	delete tempColor;
}

void FileReader::readGameFile(string fileName)
{
	string input;
	ifstream fin;
	Vector2 temp = Vector2(0, 0);
	string tempStr = "";
	Colors * tempColor = new Colors(0, 0, 0);

	// Open the text file
	fin.open(fileName);

	fin >> input;//Header

	//Get the Left Camera Offset
	fin >> input;//Name
	fin >> input;//get the left offset

	Game::getStaticInstance()->mCameraLeftOffset = stoi(input);

	fin.ignore(); //go to next line

	//Get the Right Camera Offset
	fin >> input;//Name
	fin >> input;//get the right offset

	Game::getStaticInstance()->mCameraRightOffset = stoi(input);

	fin.ignore(); //go to next line

	fin >> input;//Header

	//Get the Gravity Scale
	fin >> input;//Name
	fin >> input;//get the gravity scale

	Game::getStaticInstance()->mGravityScale= stod(input);

	fin.ignore(); //go to next line

	//Get the Jump Force
	fin >> input;//Name
	fin >> input;//get the jump force

	Game::getStaticInstance()->mJumpForce = stod(input);

	fin.ignore(); //go to next line

	fin >> input;//Header

	//Get the Player Walk speed
	fin >> input;//Name
	fin >> input;//get the player walk speed

	Game::getStaticInstance()->mPlayerWalkSpeed = stod(input);

	fin.ignore(); //go to next line

	//Get the Goomba Walk speed
	fin >> input;//Name
	fin >> input;//get the goomba walk speed

	Game::getStaticInstance()->mGoombaWalkSpeed = stod(input) * Game::getStaticInstance()->getDifficulty();

	fin.ignore(); //go to next line

	//Get the Koopa Spin speed
	fin >> input;//Name
	fin >> input;//get the koopa spin speed

	Game::getStaticInstance()->mKoopaSpinSpeed = stod(input) * Game::getStaticInstance()->getDifficulty();

	fin.ignore(); //go to next line

	//Get the Piranha Move speed
	fin >> input;//Name
	fin >> input;//get the piranha move speed

	Game::getStaticInstance()->mPiranhaPlantSpeed = stod(input) * Game::getStaticInstance()->getDifficulty();

	fin.ignore(); //go to next line

	//Get the Piranha Wait time
	fin >> input;//Name
	fin >> input;//get the piranha wait time

	Game::getStaticInstance()->mPiranhaWaitTime = stod(input) / (double)Game::getStaticInstance()->getDifficulty();

	fin.close();

	// Delete the temporary color pointer
	delete tempColor;
}





// This function opens and reads the text file that contains the level layouts
void FileReader::readLevelsFile(string fileName) 
{
	string input;
	int lineNumber = 0;
	ifstream fin;

	fin.open(fileName);

	while (!fin.eof()) 
	{
		lineNumber++;
		getline(fin, input);

		// Create a unit within the unit manager as the for loop iterates through...
		for (int i = 0; i < (int) input.length(); i++) 
		{
			switch (input[i])
			{
			case 'p'://Create the Player object		
				Game::getStaticInstance()->mUnitManager->createPlayer(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber));

				// Add the walk, jump and death animations for the default sprite and the ones for the powerups.
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerJumpAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerDeathAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerJumpAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerRedAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerRedJumpAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerGreenAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mSuperPlayerGreenJumpAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerRedAnimation);
				Game::getStaticInstance()->mUnitManager->addPlayerAnimation(*Game::getStaticInstance()->mPlayerGreenAnimation);
				break;
			case '#'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mDefaultBlockAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('#');
				break;
			case 'V'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mDeepGrassAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('V');
				break;
			case 'X'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mCastleBlockAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('X');
				break;
			case 'v'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mGrassAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('v');
				break;
			case 'Z'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mLeftCornerSlopeAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('Z');
				break;
			case 'h'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mRightCornerSlopeAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('h');
				break;
			case 'c'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mRightSlopeAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('c');
				break;
			case 'l'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mLeftSlopeAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('l');
				break;
			case 't'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mTopSlopeAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('t');
				break;
			case 'D'://Creates the Wood Block object
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mWoodBlockAnimation);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(WOOD_BLOCK);
				break;
			case '!'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mPoleAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('!');
				break;
			case '<'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mLeftPlatformAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('<');
				break;
			case '>'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mRightPlatformAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('>');
				break;
			case 'N'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mMiddlePlatformAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('N');
				break;
			case 'K'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), *Game::getStaticInstance()->mLargePlatformAnimation);
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('K');
				break;
			case 'O'://Creates the Coin pickup object.
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mCoinAnimation);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(COIN);
				break;
			case '?'://Creates the Question block object
				Game::getStaticInstance()->mUnitManager->createQuestionBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setEffect(true);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mQuestionBlockAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mQuestionBlockEmptyAnimation);
				break;
			case 'S'://Create the object that will spawn the mushroom when hit
				Game::getStaticInstance()->mUnitManager->createMushroom(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mSuperMushroomAnimation);
				break;
			case 's'://Create the Dry bones enemy
				Game::getStaticInstance()->mUnitManager->createDryBones(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 18));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesLeftAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesRightAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mDryBonesDownAnimation);
				break;
			case 'b'://Create the brick blocks
				Game::getStaticInstance()->mUnitManager->createBrickBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBrickBlockAnimation);
				break;
			case 'E'://Create the end block, the object that lets you finish a level
				Game::getStaticInstance()->mUnitManager->createEndBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mEndBlockAnimation);
				break;
			case 'e'://Creates the generic prop object with identity e
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 32), *Game::getStaticInstance()->mBackgroundEndImage);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('e');
				break;
			case 'g'://Creates the goomba enemy
				Game::getStaticInstance()->mUnitManager->createGoomba(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mGoombaAnimation);
				break;
			case 'k'://Creates the Koopa enemy
				Game::getStaticInstance()->mUnitManager->createKoopa(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaRightAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaShellAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mKoopaShellSpinAnimation);
				break;
			case 'H'://Creates another prop of a different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mBigHillAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('H');
				break;
			case 'C'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mCloudAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('C');
				break;
			case 'd'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mDonutBushAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('d');
				break;
			case '='://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mDonutHillOneAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('=');
				break;
			case 'z'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mDonutHillTwoAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('z');
				break;
			case '_'://Creates a Pipe horizontally
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mHorizontalPipeAnimation);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIPE);
				break;
			case '|'://Creates a Pipe vertically
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mPipeAnimation);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIPE);
				break;
			case 'L'://Creates a lava object
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mLavaAnimation);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(LAVA);
				break;
			case 'F'://Creates the fireball that moves and can hit player
				Game::getStaticInstance()->mUnitManager->createFireball(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mFireballUpAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mFireballDownAnimation);
				break;
			case 'T'://Creates the Thwomp object
				Game::getStaticInstance()->mUnitManager->createThwomp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mThwompAnimation);
				break;
			case 'P'://Creates the Piranha plant object
				Game::getStaticInstance()->mUnitManager->createPiranhaPlant(Vector2(BLOCK_SPACING * i + 16, BLOCK_SPACING * lineNumber - 64));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mPiranhaAnimation);
				break;
			case 'o'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 4));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mSmalllOrangeBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('o');
				break;
			case 'B'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mTallBlueBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('B');
				break;
			case '6'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mBlueFloatingBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('6');
				break;
			case '7'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mGreenFloatingBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('7');
				break;
			case '8'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeRedFloatingBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('8');
				break;
			case '9'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mSmallRedFloatingBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('9');
				break;
			case 'G'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 3));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeGreenBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('G');
				break;
			case 'R'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 5, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 5.6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mMediumRedBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('R');
				break;
			case '2'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 8, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 7));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLongGreenBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('2');
				break;
			case 'W'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i)+ 60, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 10));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeWhiteBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('W');
				break;
			case '3'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 7, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeRedBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('3');
				break;
			case '4'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 7, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mLargeBlueBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('4');
				break;
			case '5'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(*Game::getStaticInstance()->mTallGreenBoxAnimation);
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('5');
				break;
			case 'f'://Creates a prop of identity 
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), *Game::getStaticInstance()->mBushAnimation);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('f');
				break;
			case 'w'://Creates the Starmen object
				Game::getStaticInstance()->mUnitManager->createStarmen(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mStarmenAnimation);
				break;
			case 'Q'://Creates the BoomBoom object
				Game::getStaticInstance()->mUnitManager->createBoomBoom(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomWalkAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomDefenseAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomJumpAnimation);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, *Game::getStaticInstance()->mBoomBoomSquishedAnimation);
				break;
			default:
				break;
			}
		}
	}

	fin.close();
}