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
	string input2;
	ifstream fin;
	Vector2 temp = Vector2(0, 0);
	Vector2 temp2 = Vector2(0, 0);
	string tempStr = "";
	Colors * tempColor = new Colors(0, 0, 0);

	Game::getStaticInstance()->mDefaultBlockDimensions = Vector2(32, 32);

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

	fin >> input2;

	while (input2 != "Space")
	{
		// Get the Player Spritesheet
		fin >> input;
		fin >> input;
		Game::getStaticInstance()->mBufferManager.addBuffer(ASSET_PATH_TWO + input, input2);

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
		Game::getStaticInstance()->mAnimationLinks[input2] = AnimationInformation((int)temp.mX, (int)temp.mY, Game::getStaticInstance()->mDisplayDimensions, temp2);

		fin.ignore();
		fin >> input2;
	}

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
				break;
			case '#'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].mSpriteDimensions.mX * i, (Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].mSpriteDimensions.mX * lineNumber) - 7), Animation(NAME_OF_DEFAULT_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEFAULT_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEFAULT_BLOCK].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('#');
				break;
			case 'V'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_DEEP_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DEEP_GRASS_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DEEP_GRASS_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('V');
				break;
			case 'X'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_CASTLE_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CASTLE_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CASTLE_BLOCK].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('X');
				break;
			case 'v'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_GRASS_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GRASS_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GRASS_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('v');
				break;
			case 'Z'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_SLOPE_LEFT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT_CORNER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT_CORNER].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('Z');
				break;
			case 'h'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_SLOPE_RIGHT_CORNER, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT_CORNER), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT_CORNER].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('h');
				break;
			case 'c'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_SLOPE_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_RIGHT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_RIGHT].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('c');
				break;
			case 'l'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_SLOPE_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_LEFT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_LEFT].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('l');
				break;
			case 't'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_SLOPE_TOP, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SLOPE_TOP), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SLOPE_TOP].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('t');
				break;
			case 'D'://Creates the Wood Block object
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_WOOD_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_WOOD_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_WOOD_BLOCK].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(WOOD_BLOCK);
				break;
			case '!'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_POLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_POLE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_POLE].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('!');
				break;
			case '<'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_PLATFORM_LEFT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_LEFT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_LEFT].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('<');
				break;
			case '>'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_PLATFORM_RIGHT, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_RIGHT), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_RIGHT].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('>');
				break;
			case 'N'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_PLATFORM_MIDDLE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PLATFORM_MIDDLE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PLATFORM_MIDDLE].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('N');
				break;
			case 'K'://Creates a tile object
				Game::getStaticInstance()->mUnitManager->createTile(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 8), Animation(NAME_OF_LARGE_PLATFORM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_PLATFORM), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_PLATFORM].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getTile(Game::getStaticInstance()->mUnitManager->getTileSize() - 1)->setTileIdentity('K');
				break;
			case 'O'://Creates the Coin pickup object.
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_COIN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_COIN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_COIN].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(COIN);
				break;
			case '?'://Creates the Question block object
				Game::getStaticInstance()->mUnitManager->createQuestionBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setEffect(true);
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_QUESTION_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_QUESTION_BLOCK].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_EMPTY_QUESTION_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_EMPTY_QUESTION_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_EMPTY_QUESTION_BLOCK].mSpriteDimensions));
				break;
			case 'S'://Create the object that will spawn the mushroom when hit
				Game::getStaticInstance()->mUnitManager->createMushroom(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_SUPER_MUSHROOM, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SUPER_MUSHROOM), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SUPER_MUSHROOM].mSpriteDimensions));
				break;
			case 's'://Create the Dry bones enemy
				Game::getStaticInstance()->mUnitManager->createDryBones(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 18));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_LEFT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_LEFT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_LEFT_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_RIGHT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_RIGHT_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_DRY_BONES_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DRY_BONES_DOWN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DRY_BONES_DOWN_ANIMATION].mSpriteDimensions));
				break;
			case 'b'://Create the brick blocks
				Game::getStaticInstance()->mUnitManager->createBrickBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BRICK_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BRICK_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BRICK_BLOCK].mSpriteDimensions));
				break;
			case 'E'://Create the end block, the object that lets you finish a level
				Game::getStaticInstance()->mUnitManager->createEndBlock(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_END_BLOCK, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_END_BLOCK), Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_END_BLOCK].mSpriteDimensions));
				break;
			case 'e'://Creates the generic prop object with identity e
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 32), *Game::getStaticInstance()->mBackgroundEndImage);
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('e');
				break;
			case 'g'://Creates the goomba enemy
				Game::getStaticInstance()->mUnitManager->createGoomba(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_GOOMBA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GOOMBA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GOOMBA].mSpriteDimensions));
				break;
			case 'k'://Creates the Koopa enemy
				Game::getStaticInstance()->mUnitManager->createKoopa(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_RIGHT_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_RIGHT_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_RIGHT_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_SHELL_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_KOOPA_SHELL_SPIN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_KOOPA_SHELL_SPIN_ANIMATION].mSpriteDimensions));
				break;
			case 'H'://Creates another prop of a different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_BIG_HILL, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BIG_HILL), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BIG_HILL].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('H');
				break;
			case 'C'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_CLOUD, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_CLOUD), Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_CLOUD].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('C');
				break;
			case 'd'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_DONUT_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_BUSH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_BUSH_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('d');
				break;
			case '='://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_DONUT_HILL_ONE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_ONE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_ONE].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('=');
				break;
			case 'z'://Creates another prop of different identity
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_DONUT_HILL_TWO, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_DONUT_HILL_TWO), Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_DONUT_HILL_TWO].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('z');
				break;
			case '_'://Creates a Pipe horizontally
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_HORIZONTAL_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_HORIZONTAL_PIPE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_HORIZONTAL_PIPE].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIPE);
				break;
			case '|'://Creates a Pipe vertically
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_PIPE, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIPE), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIPE].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(PIPE);
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setZIndex(0);
				break;
			case 'L'://Creates a lava object
				Game::getStaticInstance()->mUnitManager->createUnit(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_LAVA_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LAVA_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LAVA_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getUnit(Game::getStaticInstance()->mUnitManager->getSize() - 1)->setUnitType(LAVA);
				break;
			case 'F'://Creates the fireball that moves and can hit player
				Game::getStaticInstance()->mUnitManager->createFireball(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_FIREBALL_UP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_UP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_UP_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_FIREBALL_DOWN_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_FIREBALL_DOWN_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_FIREBALL_DOWN_ANIMATION].mSpriteDimensions));
				break;
			case 'T'://Creates the Thwomp object
				Game::getStaticInstance()->mUnitManager->createThwomp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_THWOMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_THWOMP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_THWOMP_ANIMATION].mSpriteDimensions));
				break;
			case 'P'://Creates the Piranha plant object
				Game::getStaticInstance()->mUnitManager->createPiranhaPlant(Vector2(BLOCK_SPACING * i + 16, BLOCK_SPACING * lineNumber - 64));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_PIRANHA, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_PIRANHA), Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_PIRANHA].mSpriteDimensions));
				break;
			case 'o'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 4));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_SMALL_ORANGE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_ORANGE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_ORANGE_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('o');
				break;
			case 'B'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_TALL_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_BLUE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_BLUE_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('B');
				break;
			case '6'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_BLUE_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BLUE_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BLUE_FLOATING_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('6');
				break;
			case '7'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_GREEN_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_GREEN_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_GREEN_FLOATING_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('7');
				break;
			case '8'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('8');
				break;
			case '9'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 2, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('9');
				break;
			case 'G'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 3));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_GREEN_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('G');
				break;
			case 'R'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 5, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 5.6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_MEDIUM_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_MEDIUM_RED_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_MEDIUM_RED_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('R');
				break;
			case '2'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 8, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 7));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LONG_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LONG_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LONG_GREEN_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('2');
				break;
			case 'W'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i)+ 60, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 10));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_WHITE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_WHITE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_WHITE_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('W');
				break;
			case '3'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 7, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_RED_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_RED_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_RED_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('3');
				break;
			case '4'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2((Game::getStaticInstance()->mDefaultBlockDimensions.mX * i) - 7, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber) - 6));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_LARGE_BLUE_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_LARGE_BLUE_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_LARGE_BLUE_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('4');
				break;
			case '5'://Creates a platform of identity 
				Game::getStaticInstance()->mUnitManager->createPlatform(Vector2(Game::getStaticInstance()->mDefaultBlockDimensions.mX * i, (Game::getStaticInstance()->mDefaultBlockDimensions.mY * lineNumber)));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setAnimation(Animation(NAME_OF_TALL_GREEN_BOX_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_TALL_GREEN_BOX_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_TALL_GREEN_BOX_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getPlatform(Game::getStaticInstance()->mUnitManager->getPlatformSize() - 1)->setPlatformIdentity('5');
				break;
			case 'f'://Creates a prop of identity 
				Game::getStaticInstance()->mUnitManager->createProp(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8), Animation(NAME_OF_BUSH_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BUSH_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BUSH_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->getProp(Game::getStaticInstance()->mUnitManager->getPropSize() - 1)->setPropIdentity('f');
				break;
			case 'w'://Creates the Starmen object
				Game::getStaticInstance()->mUnitManager->createStarmen(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_STARMEN, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_STARMEN), Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_STARMEN].mSpriteDimensions));
				break;
			case 'Q'://Creates the BoomBoom object
				Game::getStaticInstance()->mUnitManager->createBoomBoom(Vector2(BLOCK_SPACING * i, BLOCK_SPACING * lineNumber - 8));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_DEFENSE_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_DEFENSE_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_JUMP_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_JUMP_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_JUMP_ANIMATION].mSpriteDimensions));
				Game::getStaticInstance()->mUnitManager->addAnimation(Game::getStaticInstance()->mUnitManager->getSize() - 1, Animation(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION, Game::getStaticInstance()->mBufferManager.getBuffer(NAME_OF_BOOMBOOM_SQUISHED_ANIMATION), Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].spritesPerRow, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].spritesPerColumn, Game::getStaticInstance()->mDisplayDimensions, Game::getStaticInstance()->mAnimationLinks[NAME_OF_BOOMBOOM_SQUISHED_ANIMATION].mSpriteDimensions));
				break;
			default:
				break;
			}
		}
	}

	fin.close();
}