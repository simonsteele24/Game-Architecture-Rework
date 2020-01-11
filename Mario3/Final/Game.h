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
const string THEME_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\maintheme.flac";
const string AUDIO_JUMP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\jump.wav";
const string AUDIO_COIN_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\coin.wav";

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
const string NAME_OF_THEME = "Theme";
const string NAME_OF_AUDIO_JUMP = "Jump";
const string NAME_OF_AUDIO_COIN = "Coin";

//Player 
const string NAME_OF_PLAYER = "Player";
const string NAME_OF_PLAYER_JUMP = "Player Jump";
const string NAME_OF_PLAYER_RED = "Player Red";
const string NAME_OF_PLAYER_RED_JUMP = "Player Red";
const string NAME_OF_PLAYER_GREEN = "Player Green";
const string NAME_OF_PLAYER_GREEN_JUMP = "Player Green Jump";
const string NAME_OF_PLAYER_DEATH_ANIMATION = "MiniMario Death";
const string NAME_OF_SUPER_PLAYER = "Super Player";
const string NAME_OF_SUPER_PLAYER_JUMP = "Super Player Jump";
const string NAME_OF_SUPER_PLAYER_RED = "Super Player Red";
const string NAME_OF_SUPER_PLAYER_RED_JUMP = "Super Player Red Jump";
const string NAME_OF_SUPER_PLAYER_GREEN = "Super Player Red";
const string NAME_OF_SUPER_PLAYER_GREEN_JUMP = "Super Player Green Jump";


//Environmental 
const string NAME_OF_BIG_HILL = "Big Hill";
const string NAME_OF_CLOUD = "Cloud";
const string NAME_OF_PIPE = "Pipe";
const string NAME_OF_HORIZONTAL_PIPE = "Horizontal Pipe";
const string NAME_OF_WOOD_BLOCK = "Wood Block";
const string NAME_OF_DEFAULT_BLOCK = "Default Block";
const string NAME_OF_BRICK_BLOCK = "Brick Block";
const string NAME_OF_QUESTION_BLOCK = "Question Block";
const string NAME_OF_EMPTY_QUESTION_BLOCK = "Empty Question Block";
const string NAME_OF_END_BLOCK = "End Block";
const string NAME_OF_TALL_BLUE_BOX_ANIMATION = "Tall Blue Box";
const string NAME_OF_LARGE_GREEN_BOX_ANIMATION = "Large Green Box";
const string NAME_OF_MEDIUM_RED_BOX_ANIMATION = "Medium Red Box";
const string NAME_OF_LONG_GREEN_BOX_ANIMATION = "Long Green Box";
const string NAME_OF_LARGE_WHITE_BOX_ANIMATION = "Large White Box";
const string NAME_OF_LARGE_RED_BOX_ANIMATION = "Large Red Box";
const string NAME_OF_LARGE_BLUE_BOX_ANIMATION = "Large Blue Box";
const string NAME_OF_TALL_GREEN_BOX_ANIMATION = "Tall Green Box";
const string NAME_OF_SMALL_ORANGE_BOX_ANIMATION = "Small Orange Box";
const string NAME_OF_BLUE_FLOATING_BOX_ANIMATION = "Blue Floating Box";
const string NAME_OF_GREEN_FLOATING_BOX_ANIMATION = "Green Floating Box";
const string NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION = "Large Red Floating Box";
const string NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION = "Small Red Floating Box";
const string NAME_OF_BUSH_ANIMATION = "Bush";
const string NAME_OF_LAVA_ANIMATION = "Lava";
const string NAME_OF_FIREBALL_UP_ANIMATION = "Fireball Up";
const string NAME_OF_FIREBALL_DOWN_ANIMATION = "Fireball Down";
const string NAME_OF_DONUT_BUSH_ANIMATION = "Donut Bush";
const string NAME_OF_DONUT_HILL_ONE = "Donut Hill One";
const string NAME_OF_DONUT_HILL_TWO = "Donut Hill Two";
const string NAME_OF_DEEP_GRASS_ANIMATION = "Deep Grass";
const string NAME_OF_GRASS_ANIMATION = "Grass";
const string NAME_OF_SLOPE_LEFT_CORNER = "Grass Left Corner";
const string NAME_OF_SLOPE_RIGHT_CORNER = "Grass Right Corner";
const string NAME_OF_SLOPE_LEFT = "Grass Left";
const string NAME_OF_SLOPE_RIGHT = "Grass Right";
const string NAME_OF_SLOPE_TOP = "Grass Top";
const string NAME_OF_PLATFORM_LEFT = "Platform Left";
const string NAME_OF_PLATFORM_MIDDLE = "Platform Middle";
const string NAME_OF_PLATFORM_RIGHT = "Platform Right";
const string NAME_OF_LARGE_PLATFORM = "Large Platform";
const string NAME_OF_POLE = "Pole";
const string NAME_OF_CASTLE_BLOCK = "Castle Block";

//Enemies
const string NAME_OF_GOOMBA = "Goomba";
const string NAME_OF_KOOPA = "Koopa";
const string NAME_OF_KOOPA_RIGHT_ANIMATION = "Koopa Right";
const string NAME_OF_KOOPA_SHELL_SPIN_ANIMATION = "Koopa Spin";
const string NAME_OF_KOOPA_SHELL_ANIMATION = "Koopa Stationary";
const string NAME_OF_DRY_BONES_LEFT_ANIMATION = "Dry Bones Left";
const string NAME_OF_DRY_BONES_RIGHT_ANIMATION = "Dry Bones Right";
const string NAME_OF_DRY_BONES_DOWN_ANIMATION = "Dry Bones Down";
const string NAME_OF_PIRANHA = "Piranha";
const string NAME_OF_THWOMP_ANIMATION = "Thwomp";
const string NAME_OF_BOOMBOOM_ANIMATION = "BoomBoom";
const string NAME_OF_BOOMBOOM_SQUISHED_ANIMATION = "BoomBoom Squished";
const string NAME_OF_BOOMBOOM_DEFENSE_ANIMATION = "BoomBoom Defense";
const string NAME_OF_BOOMBOOM_JUMP_ANIMATION = "BoomBoom Jump";


//Collectables
const string NAME_OF_COIN = "Coin";
const string NAME_OF_SUPER_MUSHROOM = "Super Mushroom";
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
	void restartLevel();
	void setDifficulty(int newDifficulty);

	// UI Mutators
	void setScoreMultiplier(int multiplier);
	void setScoreAddAmt(int scoreAmt);
	void addToCoinAmount();
	void addToScore(int scoreAmt);
	void deductLife();

	// Game Status
	void setStateOfApplication(bool status);

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

	// Animations

	// Player
	Animation * mPlayerAnimation;
	Animation * mPlayerJumpAnimation;
	Animation * mPlayerRedAnimation;
	Animation * mPlayerRedJumpAnimation;
	Animation * mPlayerGreenAnimation;
	Animation * mPlayerGreenJumpAnimation;
	Animation * mPlayerDeathAnimation;
	Animation * mSuperPlayerAnimation;
	Animation * mSuperPlayerJumpAnimation;
	Animation * mSuperPlayerRedAnimation;
	Animation * mSuperPlayerRedJumpAnimation;
	Animation * mSuperPlayerGreenAnimation;
	Animation * mSuperPlayerGreenJumpAnimation;

	// Props
	Animation * mBigHillAnimation;
	Animation * mCloudAnimation;
	Animation * mPipeAnimation;
	Animation * mHorizontalPipeAnimation;
	Animation * mBushAnimation;
	Animation * mDonutBushAnimation;
	Animation * mDonutHillOneAnimation;
	Animation * mDonutHillTwoAnimation;

	// Enemies
	Animation * mGoombaAnimation;
	Animation * mKoopaAnimation;
	Animation * mKoopaRightAnimation;
	Animation * mKoopaShellAnimation;
	Animation * mKoopaShellSpinAnimation;
	Animation * mPiranhaAnimation;
	Animation * mBoomBoomWalkAnimation;
	Animation * mBoomBoomDefenseAnimation;
	Animation * mBoomBoomJumpAnimation;
	Animation * mBoomBoomSquishedAnimation;

	// Blocks
	Animation * mWoodBlockAnimation;
	Animation * mDefaultBlockAnimation;
	Animation * mBrickBlockAnimation;
	Animation * mQuestionBlockAnimation;
	Animation * mQuestionBlockEmptyAnimation;
	Animation * mEndBlockAnimation;
	Animation * mSmalllOrangeBoxAnimation;
	Animation * mTallBlueBoxAnimation;
	Animation * mLargeGreenBoxAnimation;
	Animation * mMediumRedBoxAnimation;
	Animation * mLongGreenBoxAnimation;
	Animation * mLargeWhiteBoxAnimation;
	Animation * mLargeRedBoxAnimation;
	Animation * mLargeBlueBoxAnimation;
	Animation * mTallGreenBoxAnimation;
	Animation * mBlueFloatingBoxAnimation;
	Animation * mGreenFloatingBoxAnimation;
	Animation * mLargeRedFloatingBoxAnimation;
	Animation * mSmallRedFloatingBoxAnimation;
	Animation * mLavaAnimation;
	Animation * mThwompAnimation;
	Animation * mDryBonesLeftAnimation;
	Animation * mDryBonesRightAnimation;
	Animation * mDryBonesDownAnimation;
	Animation * mFireballUpAnimation;
	Animation * mFireballDownAnimation;
	Animation * mGrassAnimation;
	Animation * mDeepGrassAnimation;
	Animation * mLeftCornerSlopeAnimation;
	Animation * mRightCornerSlopeAnimation;
	Animation * mLeftSlopeAnimation;
	Animation * mRightSlopeAnimation;
	Animation * mTopSlopeAnimation;
	Animation * mLeftPlatformAnimation;
	Animation * mMiddlePlatformAnimation;
	Animation * mRightPlatformAnimation;
	Animation * mLargePlatformAnimation;
	Animation * mPoleAnimation;
	Animation * mCastleBlockAnimation;


	// Interactables/Powerups
	Animation * mCoinAnimation;
	Animation * mSuperMushroomAnimation;
	Animation * mStarmenAnimation;

	// Booleans
	bool mIsDisplaying;
	bool mInApplication;
	bool mInGame;

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

	// Strings

	// Filereaders
	FileReader mReader;
	SaveStateManager mSaveState;
	LanuageManager mLanguageManager;
	MenuManager * mMenuManager;
	LevelManager mLevelManager;
};

#endif // !GAME_H