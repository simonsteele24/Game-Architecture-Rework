#include "Game.h"
#include "Unit.h"
#include "Animation.h"

Game * Game::mpGameObject = nullptr;

// This function is the default constructor for this class
Game::Game(EventSystem* pEventSystem)
	:EventListener(pEventSystem)
{

	// Listen to all events that need to be listened for
	pEventSystem->addListener((EventType)QUIT_GAME, this);
	pEventSystem->addListener((EventType)MOVE_PLAYER, this);
	pEventSystem->addListener((EventType)SHOOT_BULLET, this);
	pEventSystem->addListener((EventType)MAKE_PLAYER_JUMP, this);
	pEventSystem->addListener((EventType)MOVE_PLAYER_RIGHT, this);
	pEventSystem->addListener((EventType)MOVE_PLAYER_LEFT, this);
	pEventSystem->addListener((EventType)SAVE_GAME, this);
	pEventSystem->addListener((EventType)LOAD_GAME, this);
	pEventSystem->addListener((EventType)LOAD_LANGUAGE, this);

	// Set Frames per second to zero
	mFramesPerSecond = 0;

	// Create the system object
	mCurrentSystem = new System();

	// Create the input system object
	mCurrentInputSystem = new InputSystem();
	mAudioManager = new AudioManager(pEventSystem);

	// Set in-game to false
	mInGame = false;
	mInApplication = true;
	mLost = false;
	mFadeAwayTime = 20;

	// Set the defaut difficulty for the game
	mDifficulty = DEFAULT_DIFFICULTY;
	mLives = DEFAULT_LIVES - mDifficulty;
}





// This function is the destructor for this class
Game::~Game()
{
	if ( mIsDisplaying ) 
	{
		cleanup();
	}

	delete mCurrentInputSystem;
	delete mCurrentSystem;
}





// This function gets the current instance of the static class
Game * Game::getStaticInstance() 
{
	assert( mpGameObject != nullptr );
	return mpGameObject;
}





// This function gets the background image of the game
GraphicsBuffer * Game::getBackground()
{
	return mBackgroundImage;
}





// This function initializes the instance of the static class
void Game::initStaticInstance() 
{
	mpGameObject = new Game(EventSystem::getStaticInstance());
}





// This function destroys the current instance of the static class
void Game::destroyStaticInstance() 
{
	delete mpGameObject;
}





// This function initializes all of the allegro systems
void Game::init()
{
	// Create the new unit manager
	mUnitManager = new UnitManager();

	// Create the new input translator
	mTranslator = new InputTranslator(EventSystem::getStaticInstance());

	// Initialize all systems
	initializeSystems();
	mCurrentInputSystem->init();

	// Create the Text Manager
	mTextManager = new TextManager();

	//Create the UI Color
	mUIFontColor = new Colors(0, 0, 0);

	// Create the language manager
	mLanguageManager = LanuageManager(ENGLISH_TEXT_FILE_PATH);


	// Read the Sprite values text file
	mReader.readFile(TEXT_FILE_PATH);

	// Read the more specific game values text file
	mReader.readGameFile(GAME_TEXT_FILE_PATH);

	// Read the UI values text file
	mReader.readUIFile(UI_TEXT_FILE_PATH);

	// Create text of Score Label
	mTextManager->addText(NAME_OF_SCORE_TEXT.c_str(), *mUIFont, *mUIFontColor, mLanguageManager.getWord(NAME_OF_SCORE_WORD), SCORE_TEXT_POSITION);

	// Set the Score Label to active
	mTextManager->getText(NAME_OF_SCORE_TEXT)->setTextToActive();

	// Create text of Score Number/Amount
	mTextManager->addText(NAME_OF_SCORE_AMOUNT_TEXT.c_str(), *mUIFont, *mUIFontColor, "", SCORE_AMOUNT_POSITION);

	// Set the Score Amount to active
	mTextManager->getText(NAME_OF_SCORE_AMOUNT_TEXT)->setTextToActive();

	// Create text of Coin Amount
	mTextManager->addText(NAME_OF_COIN_TEXT.c_str(), *mUIFont, *mUIFontColor, mLanguageManager.getWord(NAME_OF_COINS_WORD) + " " + to_string(mNumOfCoins), COIN_TEXT_POSITION);

	// Set the Coin Amount to active
	mTextManager->getText(NAME_OF_COIN_TEXT)->setTextToActive();

	// Create text of Lives Number
	mTextManager->addText(NAME_OF_LIVES_TEXT.c_str(), *mUIFont, *mUIFontColor, mLanguageManager.getWord(NAME_OF_LIVES_WORD) + to_string(mLives), LIVES_TEXT_POSITION);

	// Set the Lives Text to active
	mTextManager->getText(NAME_OF_LIVES_TEXT)->setTextToActive();

	// Create text of Game Status
	mTextManager->addText(NAME_OF_GAME_STATUS_TEXT.c_str(), *mUIFont, *mUIFontColor, mLanguageManager.getWord(NAME_LEVEL_COMPLETION_WORD) + " ", GAME_STATUS_TEXT_POSITION);

	// Create window and initialize all systems
	mCurrentSystem->init((int)mDisplayDimensions.mX, (int)mDisplayDimensions.mY);

	// Create the blue  backgroud image
	addBackgroundImage(NAME_OF_BACKGROUND_BUFFER,mBufferManager.getBuffer(NAME_OF_BACKGROUND_BUFFER));
	// Create the black tear backgroud image
	addBackgroundImage(NAME_OF_BACKGROUND_TEAR_BUFFER,mBufferManager.getBuffer(NAME_OF_BACKGROUND_TEAR_BUFFER));

	// Set coins to zero
	mNumOfCoins = 0;
	// Set the boolean telling the program the display is running as true
	mIsDisplaying = true;

	// Initialize all possible audios
	mAudioManager->addSound(NAME_OF_THEME, Audio(NAME_OF_THEME ,THEME_FILE_PATH, THEME_PITCH, THEME_VOLUME), true);
	mAudioManager->addSound(NAME_OF_CASTLE_THEME, Audio(NAME_OF_CASTLE_THEME, CASTLE_THEME_FILE_PATH, THEME_PITCH, THEME_VOLUME), true);
	mAudioManager->addSound(NAME_OF_AUDIO_JUMP, Audio(NAME_OF_AUDIO_JUMP,  AUDIO_JUMP_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);
	mAudioManager->addSound(NAME_OF_AUDIO_COIN, Audio(NAME_OF_AUDIO_COIN, AUDIO_COIN_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);
	mAudioManager->addSound(NAME_OF_AUDIO_POWERUP, Audio(NAME_OF_AUDIO_POWERUP, AUDIO_POWERUP_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);
	mAudioManager->addSound(NAME_OF_AUDIO_STOMP, Audio(NAME_OF_AUDIO_STOMP, AUDIO_STOMP_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);
	mAudioManager->addSound(NAME_OF_AUDIO_KICK, Audio(NAME_OF_AUDIO_KICK, AUDIO_KICK_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);
	mAudioManager->addSound(NAME_OF_AUDIO_LOST_LIFE, Audio(NAME_OF_AUDIO_LOST_LIFE, AUDIO_LOST_LIFE_FILE_PATH, THEME_PITCH, THEME_VOLUME), false);

	// Play main theme song
	mAudioManager->playSound(NAME_OF_THEME);

	// Inittialize the menu
	mMenuManager = new MenuManager();
}





// This function creates a background image based 
// on a sprite given by the user
void Game::addBackgroundImage(string name, GraphicsBuffer * newBackground)
{
	if(name == NAME_OF_BACKGROUND_BUFFER)
		mBackgroundImage = newBackground;
}





// This function calls system to initialize the allegro system
void Game::initializeSystems() 
{
	mCurrentSystem->initializeSystems();
}





// This function cleans up and destroys all of the allegro systems
void Game::cleanup() 
{
	// Blocks
	delete mBackgroundEndImage;

	// Delete the Game font
	delete mUIFont;

	// Delete the UI Colors
	delete mUIFontColor;

	// Delete Game Texts
	delete mTextManager;

	// Delete Unit Manager
	delete mUnitManager;

	// Delete Menu Manager
	delete mMenuManager;

	// Delete Audio Manager
	delete mAudioManager;

	// Delete the Input Translator
	delete mTranslator;

	// Cleanup input system
	mCurrentInputSystem->cleanup();

	// Delete Display
	mCurrentSystem->cleanup();

	// Set the boolean telling the program the display is running as true
	mIsDisplaying = false;
}






// This function executes the game loop
void Game::doLoop() 
{
	mInGame = true;
	Timer gameLoop;

	while ( mInGame ) 
	{
		// Start the timer
		gameLoop.start();

		// Get Input
		mCurrentInputSystem->update();

		if (mMenuManager->getMenu() == false) 
		{
			// If the user is done with the game break
			if (mUnitManager->getPlayer() != nullptr)
			{
				if (mUnitManager->getPlayer()->getGameStatus() == true)
				{
					mTextManager->getText(NAME_OF_GAME_STATUS_TEXT)->setTextToActive();

					render();
					mInGame = false;
					setStateOfApplication(false);
					break;
				}
			}

			// Call update for all created units
			mUnitManager->update(MAX_TIME_BETWEEN_FRAMES);
		
			// Render all buffers in game
			render();

			// Call update for all audio
			mAudioManager->update();
		}
		else 
		{
			// Draw the background image for the level
			mCurrentSystem->getGraphicsSystem().drawBackground(*mBackgroundImage, (float) mBackgroundScalingValue);

			mMenuManager->draw();
			flipDisplay();
		}

		if (mSaving)
		{
			mFadeAwayTime--;
		}
		if (mFadeAwayTime <= 0)
		{
			mSaving = false;
			mFadeAwayTime = 10;
			mTextManager->getText("GameSaved")->setTextToInactive();
		}

		// Sleep until enough time has elapsed
		gameLoop.sleepUntilElapsed( MAX_TIME_BETWEEN_FRAMES );

		// Report elapsed time
		changeFPS(FRAMES_PER_SECOND_DIVISOR / gameLoop.getElapsedTime());
		cout << "Time per each frame: " << gameLoop.getElapsedTime() << " ms" << endl;

		// Stop the timer
		gameLoop.stop();

	}	
	if(mLost)
		gameOver();
}





// This function deals with the render step of the game loop
void Game::render() 
{
	// Draw the background image for the level
	mCurrentSystem->getGraphicsSystem().drawBackground(*mBackgroundImage, (float) mBackgroundScalingValue);
	
	// Draw all units onto the back buffer
	mUnitManager->draw();

	// Draw all active texts
	mTextManager->draw();

	// Flip display after everything has been drawn to the back buffer
	flipDisplay();
}





// This function flips the current display to go
// to the next frame
void Game::flipDisplay() 
{
	mCurrentSystem->flipDisplay();
}





// This function gets the current system
System * Game::getCurrentSystem() 
{
	return mCurrentSystem;
}





// This function handles an event whenever the lister 
// (this object) recieves an event its listening for
void Game::handleEvent(const Event &theEvent) 
{
	if (theEvent.getType() == QUIT_GAME) 
	{
		mInGame = false;
		mInApplication = false;
		if(mInGame == false && mLost)
			mLost = false;
	}

	if (mLevelStart == true)
	{
		if (theEvent.getType() == MAKE_PLAYER_JUMP && mInGame)
		{
			mUnitManager->getPlayer()->jump();
		}

		if (theEvent.getType() == MOVE_PLAYER && mInGame)
		{
			// Create a new version of the destroy unit event rathered from the passed in value
			const MovePlayerEvent& moveEvent = static_cast<const MovePlayerEvent&>(theEvent);

			// Move the player to that specific location
			mUnitManager->movePlayer(moveEvent.getLocation());
		}

		if (theEvent.getType() == SHOOT_BULLET && mInGame)
		{
		}

		if (theEvent.getType() == MOVE_PLAYER_LEFT)
		{
			mUnitManager->getPlayer()->movePlayerLeft();
		}

		if (theEvent.getType() == MOVE_PLAYER_RIGHT)
		{
			mUnitManager->getPlayer()->movePlayerRight();
		}
	}

	if (theEvent.getType() == SAVE_GAME) 
	{
		if (mTextManager->getText("GameSaved") == nullptr)
		{
			mTextManager->addText("GameSaved", *mUIFont, *mUIFontColor, "Game Saved", Vector2(500, 500));			
		}
		mSaving = true;
		mTextManager->getText("GameSaved")->setTextToActive();
		saveGame();
	}

	if (theEvent.getType() == LOAD_LANGUAGE) 
	{
		// Create a new version of the destroy unit event rathered from the passed in value
		const LoadLanguageEvent& languageEvent = static_cast<const LoadLanguageEvent&>(theEvent);

		mMenuManager->sendInput(stoi(languageEvent.getLocation()));
	}
}





// This function gets the current Unit Manager
UnitManager * Game::getUnitManager() 
{
	return mUnitManager;
}






// This function gets the text manager for the whole game
TextManager * Game::getTextManager()
{
	return mTextManager;
}

AudioManager * Game::getAudioManager()
{
	return mAudioManager;
}





// This function returns the display dimensions for the game
Vector2 Game::getDisplayDimensions() 
{
	return mDisplayDimensions;
}




// This function changes and displays the FPS by a certain amount
void Game::changeFPS(double newFPS) 
{
	mFramesPerSecond = (int)newFPS;
}





// This function gets the current state of the game
bool Game::getStateOfGame() 
{
	return mInGame;
}





// This function gets the UI color for the game
Colors Game::getUIColor()
{
	return *mUIFontColor;
}





// This function gets the current score resembled in game
int Game::getScoreAddAmt()
{
	return mScoreAddAmt;
}





// This function gets the score multiplier for the game
int Game::getScoreMultiplier()
{
	return mScoreMultiplier;
}





// This function gets the current total score
int Game::getTotalScore()
{
	return mScore;
}





// This function adds to the score multiplier by a given amount
void Game::setScoreMultiplier(int multiplier)
{
	mScoreMultiplier = multiplier;
}





// This function sets the score amount by a given value
void Game::setScoreAddAmt(int scoreAmt)
{
	mScoreAddAmt = scoreAmt;
}





// This function adds to the running total of coins
void Game::addToCoinAmount() 
{
	mNumOfCoins++;
	mTextManager->getText(NAME_OF_COIN_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_COINS_WORD) + " " + to_string(mNumOfCoins));

	// Has the player reached the max amount of coins for a life?
	if (mNumOfCoins % MAX_COINS_FOR_LIVES == 0) 
	{
		// If yes, then give them an extra life
		mLives++;
		mTextManager->getText(NAME_OF_LIVES_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_LIVES_WORD) + " " + to_string(mLives));
	}
}





// This function adds to the score by a given amount
void Game::addToScore(int scoreAmt)
{
	mScore += scoreAmt;
}





// This function gets the boundaries the player can move through
Vector2 Game::getPlayerBounds()
{
	return mUnitManager->getPlayer()->getDimensions();
}





// This function gets the state of the application
bool Game::getStateOfApplication() 
{
	return mInApplication;
}





// This function deducts one life from the player and restarts the game
void Game::deductLife(bool playerStillHasLife) 
{
	mLives--;

	if (mLives <= 0) 
	{
		mLost = true;
		mInApplication = false;
		mInGame = false;
	}
	else 
	{
		mTextManager->getText(NAME_OF_LIVES_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_LIVES_WORD) + to_string(mLives));
		restartLevel(playerStillHasLife);
	}
}





// This function sets the state of the application to a given state
void Game::setStateOfApplication(bool status)
{
	mInApplication = status;
}

void Game::gameOver()
{

	//Remove old Texts
	mTextManager->removeAllTexts();

	// Create Game Over Text
	mTextManager->addText("End", *mUIFont, *mUIFontColor, "Game Over", Vector2(300, 300));
	mTextManager->addText("Escape", *mUIFont, *mUIFontColor, "Escape to End", Vector2(300, 320));
	mTextManager->getText("End")->setTextToActive();
	mTextManager->getText("Escape")->setTextToActive();

	while (mLost)
	{
		mCurrentInputSystem->update();

		// Draw the background image for the level
		mCurrentSystem->getGraphicsSystem().drawBackground(*mBackgroundImage, (float)mBackgroundScalingValue);

		
		// Draw all active texts
		mTextManager->draw();

		// Flip display after everything has been drawn to the back buffer
		flipDisplay();
	}
}





// This function saves the game
void Game::saveGame() 
{
	mSaveState.saveFile(SAVE_STATE_TEXT_FILE_PATH);
}





// This function loads the game
void Game::loadGame() 
{
	mLevelStart = true;
	mSaveState.readFile(SAVE_STATE_TEXT_FILE_PATH);
}





// This function loads a given language
void Game::loadLanguage(string fileName) 
{
	mLanguageManager.loadLanguage(fileName);

	mTextManager->getText(NAME_OF_SCORE_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_SCORE_WORD));
	mTextManager->getText(NAME_OF_COIN_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_COINS_WORD) + " " + to_string(mNumOfCoins));
	mTextManager->getText(NAME_OF_LIVES_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_LIVES_WORD) + to_string(mLives));
	mTextManager->getText(NAME_OF_GAME_STATUS_TEXT)->changeMessage(mLanguageManager.getWord(NAME_LEVEL_COMPLETION_WORD) + " ");

}





// This function loads the next level
void Game::loadLevel() 
{
	if (mUnitManager->getPlayer() != nullptr) 
	{
		mPlayerStillHasPowerup = mUnitManager->getPlayer()->getPlayerSize();
	}
	mLevelManager.loadNextLevel();
}





// This function restarts the current level
void Game::restartLevel(bool stillHasPowerup)
{
	mPlayerStillHasPowerup = stillHasPowerup;
	mLevelManager.loadCurrentLevel();
}





// This function gets the difficulty of the game
int Game::getDifficulty() 
{
	return mDifficulty;
}





// This function sets the difficulty by a given value
void Game::setDifficulty(int newDifficulty) 
{
	mDifficulty = newDifficulty;
	mLives = DEFAULT_LIVES - mDifficulty;
	mTextManager->getText(NAME_OF_LIVES_TEXT)->changeMessage(mLanguageManager.getWord(NAME_OF_LIVES_WORD) + to_string(mLives));
}





// This function sets if the player powerup is still active
void Game::setPlayerPowerup(bool _powerup)
{
	mPlayerStillHasPowerup = _powerup;
}