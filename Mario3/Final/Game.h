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
#include "Constants.h"

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
	void addAnimationInformation(string newName, AnimationInformation newInformation) { mAnimationLinks[newName]; }

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
	AnimationInformation getAnimationInfomation(string index) { return mAnimationLinks[index]; }

private:

	map <string, AnimationInformation> mAnimationLinks;

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
	Vector2 mDisplayDimensions;
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

	// UI Managers
	LanuageManager mLanguageManager;
	MenuManager * mMenuManager;

	// Level Managers
	LevelManager mLevelManager;
};

#endif // !GAME_H