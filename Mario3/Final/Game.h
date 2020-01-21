#ifndef GAME_H
#define GAME_H

// Standard Library includes
#include <vector>
#include <fstream>

// Graphics Library includes
#include <System.h>
#include <InputSystem.h>
#include <EventListener.h>
#include <EventSystem.h>

// Local Project includes
#include "GraphicsBufferManager.h"
#include "UnitManager.h"
#include "TextManager.h"
#include "InputTranslator.h"
#include "FileReader.h"
#include "SaveStateManager.h"
#include "LanguageManager.h"
#include "AudioManager.h"
#include "MenuManager.h"
#include "LevelManager.h"

// Game Performance-related constant variables
const double MAX_TIME_BETWEEN_FRAMES = 16.7;
const int FRAMES_PER_SECOND_DIVISOR = 1000;

// Asset-related constant variables
const string TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModFile.txt";
const string UI_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModUIFile.txt";
const string LEVEL_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Level_";
const string SAVE_STATE_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\SaveState.txt";
const string GAME_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModGameFiles.txt";
const string ENGLISH_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\English.txt";
const string PIRATE_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Pirate.txt";
const string VULCAN_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Vulcan.txt";
const string ASSET_PATH_TWO = "..\\..\\Mario3\\Assets\\";


//UI
const string NAME_OF_SCORE_WORD = "SCORE";
const string NAME_OF_COINS_WORD = "COINS";
const string NAME_OF_LIVES_WORD = "LIVES";
const string NAME_LEVEL_COMPLETION_WORD = "LEVELCOMPLETION";
const string NAME_OF_GAME = "NAMEOFGAME";
const string NAME_OF_START = "NAMEOFSTART";
const string NAME_OF_LOAD_GAME_WORD = "LOADGAME";
const string NAME_OF_SETTINGS_WORD = "SETTINGS";
const string NAME_OF_QUIT_WORD = "QUIT";
const string NAME_OF_DIFFICULTY_WORD = "DIFFICULTY";
const string NAME_OF_SOUND_WORD = "SOUND";
const string NAME_OF_LANGUAGE_WORD = "LANGUAGE";
const string NAME_OF_BACK_WORD = "BACK";
const string NAME_OF_EASY_WORD = "EASY";
const string NAME_OF_MEDIUM_WORD = "MEDIUM";
const string NAME_OF_HARD_WORD = "HARD";
const string NAME_OF_ON_WORD = "ON";
const string NAME_OF_OFF_WORD = "OFF";
const string NAME_OF_ENGLISH_WORD = "ENGLISH";
const string NAME_OF_PIRATE_WORD = "PIRATE";
const string NAME_OF_VULCAN_WORD = "VULCAN";
const string NAME_OF_SCORE_TEXT = "Score Label";
const string NAME_OF_SCORE_AMOUNT_TEXT = "Score Amount";
const string NAME_OF_COIN_TEXT = "Coin Text";
const string NAME_OF_LIVES_TEXT = "Lives Text";
const string NAME_OF_GAME_STATUS_TEXT = "Status Text";
const string NAME_OF_BACKGROUND_BUFFER = "Background";
const string NAME_OF_BACKGROUND_TEAR_BUFFER = "Tear Background";
const string NAME_OF_BACKGROUND_END_BUFFER = "End Background";


//Audio
const string THEME_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\maintheme.flac";
const string CASTLE_THEME_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\castletheme.flac";
const string AUDIO_JUMP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\jump.wav";
const string AUDIO_COIN_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\coin.wav";
const string AUDIO_POWERUP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\powerup.wav";
const string AUDIO_STOMP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\stomp.wav";
const string AUDIO_KICK_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\kick.wav";
const string AUDIO_LOST_LIFE_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\lostlife.wav";

const string NAME_OF_THEME = "Theme";
const string NAME_OF_CASTLE_THEME = "CastleTheme";
const string NAME_OF_AUDIO_JUMP = "Jump";
const string NAME_OF_AUDIO_COIN = "Coin";
const string NAME_OF_AUDIO_POWERUP = "Powerup";
const string NAME_OF_AUDIO_STOMP = "Stomp";
const string NAME_OF_AUDIO_KICK = "Kick";
const string NAME_OF_AUDIO_LOST_LIFE = "LostLife";

//Player 
const string NAME_OF_PLAYER = "Player";
const string NAME_OF_PLAYER_JUMP = "Player_Jump";
const string NAME_OF_PLAYER_RED = "Player_Red";
const string NAME_OF_PLAYER_RED_JUMP = "Player Red";
const string NAME_OF_PLAYER_GREEN = "Player_Green";
const string NAME_OF_PLAYER_GREEN_JUMP = "Player_Green_Jump";
const string NAME_OF_PLAYER_DEATH_ANIMATION = "Player_Death";
const string NAME_OF_SUPER_PLAYER = "Super_Player";
const string NAME_OF_SUPER_PLAYER_JUMP = "Super_Player_Jump";
const string NAME_OF_SUPER_PLAYER_RED = "Super_Player_Red";
const string NAME_OF_SUPER_PLAYER_RED_JUMP = "Super_Player_Red_Jump";
const string NAME_OF_SUPER_PLAYER_GREEN = "Super_Player_Red";
const string NAME_OF_SUPER_PLAYER_GREEN_JUMP = "Super_Player_Green_Jump";


//Environmental 
const string NAME_OF_BIG_HILL = "Big_Hill";
const string NAME_OF_CLOUD = "Cloud";
const string NAME_OF_PIPE = "Pipe";
const string NAME_OF_HORIZONTAL_PIPE = "Horizontal_Pipe";
const string NAME_OF_WOOD_BLOCK = "Wood_Block";
const string NAME_OF_DEFAULT_BLOCK = "Default_Block";
const string NAME_OF_BRICK_BLOCK = "Brick_Block";
const string NAME_OF_QUESTION_BLOCK = "Question_Block";
const string NAME_OF_EMPTY_QUESTION_BLOCK = "Empty_Question_Block";
const string NAME_OF_END_BLOCK = "End_Block";
const string NAME_OF_TALL_BLUE_BOX_ANIMATION = "Tall_Blue_Box";
const string NAME_OF_LARGE_GREEN_BOX_ANIMATION = "Large_Green_Box";
const string NAME_OF_MEDIUM_RED_BOX_ANIMATION = "Medium_Red_Box";
const string NAME_OF_LONG_GREEN_BOX_ANIMATION = "Long_Green_Box";
const string NAME_OF_LARGE_WHITE_BOX_ANIMATION = "Large_White_Box";
const string NAME_OF_LARGE_RED_BOX_ANIMATION = "Large_Red_Box";
const string NAME_OF_LARGE_BLUE_BOX_ANIMATION = "Large_Blue_Box";
const string NAME_OF_TALL_GREEN_BOX_ANIMATION = "Tall_Green_Box";
const string NAME_OF_SMALL_ORANGE_BOX_ANIMATION = "Small_Orange_Box";
const string NAME_OF_BLUE_FLOATING_BOX_ANIMATION = "Blue_Floating_Box";
const string NAME_OF_GREEN_FLOATING_BOX_ANIMATION = "Green_Floating_Box";
const string NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION = "Large_Red_Floating_Box";
const string NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION = "Small_Red_Floating_Box";
const string NAME_OF_BUSH_ANIMATION = "Bush";
const string NAME_OF_LAVA_ANIMATION = "Lava";
const string NAME_OF_FIREBALL_UP_ANIMATION = "Fireball_Up";
const string NAME_OF_FIREBALL_DOWN_ANIMATION = "Fireball_Down";
const string NAME_OF_DONUT_BUSH_ANIMATION = "Donut_Bush";
const string NAME_OF_DONUT_HILL_ONE = "Donut_Hill_One";
const string NAME_OF_DONUT_HILL_TWO = "Donut_Hill_Two";
const string NAME_OF_DEEP_GRASS_ANIMATION = "Deep_Grass";
const string NAME_OF_GRASS_ANIMATION = "Grass";
const string NAME_OF_SLOPE_LEFT_CORNER = "Grass_Left_Corner";
const string NAME_OF_SLOPE_RIGHT_CORNER = "Grass_Right_Corner";
const string NAME_OF_SLOPE_LEFT = "Grass_Left";
const string NAME_OF_SLOPE_RIGHT = "Grass_Right";
const string NAME_OF_SLOPE_TOP = "Grass_Top";
const string NAME_OF_PLATFORM_LEFT = "Platform_Left";
const string NAME_OF_PLATFORM_MIDDLE = "Platform_Middle";
const string NAME_OF_PLATFORM_RIGHT = "Platform_Right";
const string NAME_OF_LARGE_PLATFORM = "Large_Platform";
const string NAME_OF_POLE = "Pole";
const string NAME_OF_CASTLE_BLOCK = "Castle_Block";

//Enemies
const string NAME_OF_GOOMBA = "Goomba";
const string NAME_OF_KOOPA = "Koopa";
const string NAME_OF_KOOPA_RIGHT_ANIMATION = "Koopa_Right";
const string NAME_OF_KOOPA_SHELL_SPIN_ANIMATION = "Koopa_Spin";
const string NAME_OF_KOOPA_SHELL_ANIMATION = "Koopa_Stationary";
const string NAME_OF_DRY_BONES_LEFT_ANIMATION = "Dry_Bones_Left";
const string NAME_OF_DRY_BONES_RIGHT_ANIMATION = "Dry_Bones_Right";
const string NAME_OF_DRY_BONES_DOWN_ANIMATION = "Dry_Bones_Down";
const string NAME_OF_PIRANHA = "Piranha";
const string NAME_OF_THWOMP_ANIMATION = "Thwomp";
const string NAME_OF_BOOMBOOM_ANIMATION = "BoomBoom";
const string NAME_OF_BOOMBOOM_SQUISHED_ANIMATION = "BoomBoom_Squished";
const string NAME_OF_BOOMBOOM_DEFENSE_ANIMATION = "BoomBoom_Defense";
const string NAME_OF_BOOMBOOM_JUMP_ANIMATION = "BoomBoom_Jump";


//Collectables
const string NAME_OF_COIN = "Coin";
const string NAME_OF_SUPER_MUSHROOM = "Super_Mushroom";
const string NAME_OF_STARMEN = "Starmen";

//Level and Other
const int BLOCKS_PER_FLOOR = 160;
const double LENGTH_OF_LEVEL = 5000.0;
const int DEFAULT_DIFFICULTY = 1;
const int MAX_LEVELS = 5;
const int BLOCK_SPACING = 32;
const double THWOMP_UPWARD_SPEED = 3.0f;
const int DRYBONES_COOLDOWN_TIME = 500;
const double FIREBALL_FORCE = -10.0f;
const int MAX_COINS_FOR_LIVES = 100;
const int EASY_VALUE = 1;
const int MEDIUM_VALUE = 2;
const int HARD_VALUE = 3;
const int DEFAULT_LIVES = 4;
const int THEME_PITCH = 10;
const int THEME_VOLUME = 10;
const Vector2 SCORE_TEXT_POSITION = Vector2(60, 0);
const Vector2 SCORE_AMOUNT_POSITION = Vector2(200, 0);
const Vector2 COIN_TEXT_POSITION = Vector2(500, 0);
const Vector2 LIVES_TEXT_POSITION = Vector2(650, 0);
const Vector2 GAME_STATUS_TEXT_POSITION = Vector2(400, 300);

struct AnimationInformation
{
	int spritesPerRow;
	int spritesPerColumn;
	Vector2 mDisplayDimensions;
	Vector2 mSpriteDimensions;

	AnimationInformation()
	{

	}

	AnimationInformation(int _spritesPerRow, int _spritesPerColumn, Vector2 _mDisplayDimensions, Vector2 _mSpriteDimensions)
	{
		spritesPerRow = _spritesPerRow;
		spritesPerColumn = _spritesPerColumn;
		mDisplayDimensions = _mDisplayDimensions;
		mSpriteDimensions = _mSpriteDimensions;
	}
};

// Class Prototypes
class Animation;
class Unit;

class Game : public EventListener
{
public:

	// Friends
	friend class FileReader;
	friend class SaveStateManager;
	friend class MenuManager;
	friend class LevelManager;
	friend class Animation;
	friend class Unit;

	// Initializers
	void init();
	void initializeSystems();
	static void initStaticInstance();

	// Cleanups
	void cleanup();
	static void destroyStaticInstance();

	// Mutators
	void addBackgroundImage(string nameOfImage, GraphicsBuffer * newBackground);
	void doLoop();
	void flipDisplay();
	void render();
	void handleEvent(const Event& theEvent);
	void changeFPS(double newFPS);
	void saveGame();
	void loadGame();
	void loadLanguage(string fileName);
	void loadLevel();
	void restartLevel(bool stillHasPowerup);
	void setDifficulty(int newDifficulty);
	void setPlayerPowerup(bool _powerup);

	// UI Mutators
	void setScoreMultiplier(int multiplier);
	void setScoreAddAmt(int scoreAmt);
	void addToCoinAmount();
	void addToScore(int scoreAmt);
	void deductLife(bool playerStillHasLife);

	// Game Status
	void setStateOfApplication(bool status);
	void gameOver();

	// Accessors
	static Game* getStaticInstance();
	GraphicsBuffer* getBackground();
	System * getCurrentSystem();
	UnitManager * getUnitManager();
	TextManager* getTextManager();
	AudioManager* getAudioManager();
	Vector2 getDisplayDimensions();
	Vector2 getPlayerBounds();
	bool getStateOfGame();
	bool getStateOfApplication();
	Colors getUIColor();
	int getDifficulty();

	//Member data/ Data driven info
	int getScoreAddAmt();
	int getScoreMultiplier();
	int getTotalScore();
	double getCameraLeftOffset() { return mCameraLeftOffset; }
	double getCameraRightOffset() { return mCameraRightOffset; }
	double getGravityScale() { return mGravityScale; }
	double getJumpForce() { return mJumpForce; }
	double getPlayerWalkSpd() { return mPlayerWalkSpeed; }
	double getGoombaWalkSpd() { return mGoombaWalkSpeed; }
	double getKoopaSpinSpd() { return mKoopaSpinSpeed; }
	double getPiranhaMoveSpd() { return mPiranhaPlantSpeed; }
	double getPiranhaWaitTime() { return mPiranhaWaitTime; }
	bool getLevelStart() { return mLevelStart; }
	bool getPlayerPowerupState() { return mPlayerStillHasPowerup; }

	map <string, AnimationInformation> mAnimationLinks;

	double time = 0.0;

private:

	// Constructors
	Game(EventSystem* pEventSystem);

	// Destructors
	~Game();

	// Static instances
	static Game* mpGameObject;

	// Managers
	GraphicsBufferManager mBufferManager;
	UnitManager * mUnitManager;
	TextManager * mTextManager;
	AudioManager * mAudioManager;

	// Systems
	System * mCurrentSystem;

	// Input Systems
	InputSystem * mCurrentInputSystem;

	// Input Translators
	InputTranslator * mTranslator;

	// Graphics Buffers
	GraphicsBuffer * mBackgroundImage;
	Animation * mBackgroundEndImage;

	// Fonts
	Fonts* mUIFont;

	//Colors
	Colors* mUIFontColor;

	// Vector2's
	
	// Player, Game
	Vector2 mDisplayDimensions;

	// Blocks
	Vector2 mDefaultBlockDimensions;

	// Booleans
	bool mIsDisplaying;
	bool mInApplication;
	bool mInGame;
	bool mLost;
	bool mSaving;
	bool mPlayerStillHasPowerup;

	// Integers
	int mFramesPerSecond;
	int mScoreMultiplier;
	int mScoreAddAmt;
	int mNumOfCoins;
	int mLives;
	int mScore;
	int mDifficulty;

	// Doubles
	double mBackgroundScalingValue;
	double mBackgroundEndScalingValue;
	double mCameraLeftOffset;
	double mCameraRightOffset;
	double mGravityScale;
	double mJumpForce;
	double mPlayerWalkSpeed;
	double mGoombaWalkSpeed;
	double mKoopaSpinSpeed;
	double mPiranhaPlantSpeed;
	double mPiranhaWaitTime;
	double mFadeAwayTime;

	// Boolean
	bool mLevelStart;

	// Filereaders
	FileReader mReader;
	SaveStateManager mSaveState;
	LanuageManager mLanguageManager;
	MenuManager * mMenuManager;
	LevelManager mLevelManager;
};

#endif // !GAME_H