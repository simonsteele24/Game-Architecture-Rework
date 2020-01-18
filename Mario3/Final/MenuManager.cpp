#include "MenuManager.h"
#include "Game.h"

//Constructor that inits the entire menu manager
MenuManager::MenuManager()
{
	mInMenu = true;

	//Start Vector data
	mStart.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_GAME), Vector2(100, 100)));
	mStart[mStart.size() - 1]->changeFontSize(mFontSize3);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_START), Vector2(250, 200)));
	mStart[mStart.size() - 1]->changeFontSize(mFontSize);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LOAD_GAME_WORD), Vector2(250, 300)));
	mStart[mStart.size() - 1]->changeFontSize(mFontSize);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD), Vector2(250, 400)));
	mStart[mStart.size() - 1]->changeFontSize(mFontSize);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_QUIT_WORD), Vector2(250, 500)));
	mStart[mStart.size() - 1]->changeFontSize(mFontSize);
	mStart[mStart.size() - 1]->setTextToActive();

	//Settings Vector data
	mSettings.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD), Vector2(100, 100)));
	mSettings[mSettings.size() - 1]->changeFontSize(mFontSize);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_DIFFICULTY_WORD), Vector2(250, 200)));
	mSettings[mSettings.size() - 1]->changeFontSize(mFontSize2);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD), Vector2(250, 300)));
	mSettings[mSettings.size() - 1]->changeFontSize(mFontSize2);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD), Vector2(250, 400)));
	mSettings[mSettings.size() - 1]->changeFontSize(mFontSize2);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), Vector2(250, 500)));
	mSettings[mSettings.size() - 1]->changeFontSize(mFontSize2);
	mSettings[mSettings.size() - 1]->setTextToActive();


	//Difficulty Vector data
	mDifficulty.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_DIFFICULTY_WORD), Vector2(100, 100)));
	mDifficulty[mDifficulty.size() - 1]->changeFontSize(mFontSize3);
	mDifficulty[mDifficulty.size() - 1]->setTextToActive();

	mDifficulty.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_EASY_WORD), Vector2(250, 200)));
	mDifficulty[mDifficulty.size() - 1]->changeFontSize(mFontSize2);
	mDifficulty[mDifficulty.size() - 1]->setTextToActive();

	mDifficulty.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_MEDIUM_WORD), Vector2(250, 300)));
	mDifficulty[mDifficulty.size() - 1]->changeFontSize(mFontSize2);
	mDifficulty[mDifficulty.size() - 1]->setTextToActive();

	mDifficulty.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_HARD_WORD), Vector2(250, 400)));
	mDifficulty[mDifficulty.size() - 1]->changeFontSize(mFontSize2);
	mDifficulty[mDifficulty.size() - 1]->setTextToActive();

	mDifficulty.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumFour +Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), Vector2(250, 500)));
	mDifficulty[mDifficulty.size() - 1]->changeFontSize(mFontSize2);
	mDifficulty[mDifficulty.size() - 1]->setTextToActive();


	//Sound Vector data
	mSound.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD), Vector2(100, 100)));
	mSound[mSound.size() - 1]->changeFontSize(mFontSize3);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ON_WORD), Vector2(250, 200)));
	mSound[mSound.size() - 1]->changeFontSize(mFontSize2);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_OFF_WORD), Vector2(250, 300)));
	mSound[mSound.size() - 1]->changeFontSize(mFontSize2);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), Vector2(250, 400)));
	mSound[mSound.size() - 1]->changeFontSize(mFontSize2);
	mSound[mSound.size() - 1]->setTextToActive();


	//Language Vector data
	mLanguage.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD), Vector2(100, 100)));
	mLanguage[mLanguage.size() - 1]->changeFontSize(mFontSize3);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ENGLISH_WORD), Vector2(250, 200)));
	mLanguage[mLanguage.size() - 1]->changeFontSize(mFontSize2);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_PIRATE_WORD), Vector2(250, 300)));
	mLanguage[mLanguage.size() - 1]->changeFontSize(mFontSize2);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_VULCAN_WORD), Vector2(250, 400)));
	mLanguage[mLanguage.size() - 1]->changeFontSize(mFontSize2);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text("Start", *Game::getStaticInstance()->mUIFont, Colors(mColorValDefault, mColorValDefault, mColorValDefault), textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), Vector2(250, 500)));
	mLanguage[mLanguage.size() - 1]->changeFontSize(mFontSize2);
	mLanguage[mLanguage.size() - 1]->setTextToActive();
}

//Destructor that clears memory and appropraitely deallocates
MenuManager::~MenuManager()
{
	for (int i = 0, max = mStart.size(); i < max; i++) 
	{
		delete mStart[i];
	}
	for (int i = 0, max = mSettings.size(); i < max; i++)
	{
		delete mSettings[i];
	}
	for (int i = 0, max = mDifficulty.size(); i < max; i++)
	{
		delete mDifficulty[i];
	}
	for (int i = 0, max = mSound.size(); i < max; i++)
	{
		delete mSound[i];
	}
	for (int i = 0, max = mLanguage.size(); i < max; i++)
	{
		delete mLanguage[i];
	}

	mStart.clear();
	mSettings.clear();
	mDifficulty.clear();
	mLanguage.clear();
}







//This function checks if the vector contents are active, if they are, draw
void MenuManager::draw() 
{
	switch (mCurrentMenuElement)
	{
	case 0:
		for (int i = 0; i < (int)mStart.size(); i++) 
		{
			if (mStart[i]->mIsActive) 
			{
				mStart[i]->drawText();
			}
		}
		break;
	case 1:
		for (int i = 0; i < (int)mSettings.size(); i++)
		{
			if (mSettings[i]->mIsActive) 
			{
				mSettings[i]->drawText();
			}
		}
		break;
	case 2:
		for (int i = 0; i < (int)mDifficulty.size(); i++)
		{
			if (mDifficulty[i]->mIsActive)
			{
				mDifficulty[i]->drawText();
			}
		}
		break;
	case 3:
		for (int i = 0; i < (int)mSound.size(); i++)
		{
			if (mSound[i]->mIsActive)
			{
				mSound[i]->drawText();
			}
		}
		break;
	case 4:
		for (int i = 0; i < (int)mLanguage.size(); i++)
		{
			if (mLanguage[i]->mIsActive)
			{
				mLanguage[i]->drawText();
			}
		}
		break;
	default:
		break;
	}
}




//depending on the input, do a certain action.
void MenuManager::sendInput(int num) 
{
	switch (num)
	{
	case 1:
		if (mCurrentMenuElement == 0) 
		{
			mInMenu = false;
			Game::getStaticInstance()->mLevelStart = true;
			Game::getStaticInstance()->mLevelManager.loadNextLevel();
		}
		else if (mCurrentMenuElement == 1) 
		{
			mCurrentMenuElement++;
		}
		else if (mCurrentMenuElement == 2) 
		{
			Game::getStaticInstance()->setDifficulty(EASY_VALUE);
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 3)
		{
			Game::getStaticInstance()->mAudioManager->unmuteSounds();
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 4)
		{
			Game::getStaticInstance()->loadLanguage(ENGLISH_TEXT_FILE_PATH);
			updateMenuUI();
		}
		break;
	case 2:
		if (mCurrentMenuElement == 0) 
		{
			mInMenu = false;
			Game::getStaticInstance()->loadGame();
		}
		else if (mCurrentMenuElement == 3)
		{
			Game::getStaticInstance()->mAudioManager->muteSounds();
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 1) 
		{
			mCurrentMenuElement = 3;
		}
		else if (mCurrentMenuElement == 2)
		{
			Game::getStaticInstance()->setDifficulty(MEDIUM_VALUE);
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 4)
		{
			Game::getStaticInstance()->loadLanguage(PIRATE_TEXT_FILE_PATH);
			mCurrentMenuElement = 1;
			updateMenuUI();
		}
		break;
	case 3:
		if (mCurrentMenuElement == 1)
		{
			mCurrentMenuElement = 4;
		}
		else if (mCurrentMenuElement == 0) 
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 2)
		{
			Game::getStaticInstance()->setDifficulty(HARD_VALUE);
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 3)
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 4)
		{
			Game::getStaticInstance()->loadLanguage(VULCAN_TEXT_FILE_PATH);
			mCurrentMenuElement = 1;
			updateMenuUI();
		}
		break;
	case 4:
		if (mCurrentMenuElement == 0) 
		{
			Game::getStaticInstance()->mInApplication = false;
			Game::getStaticInstance()->mInGame = false;
		}
		else if (mCurrentMenuElement == 1) 
		{
			mCurrentMenuElement = 0;
		}
		else if (mCurrentMenuElement == 2) 
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 4) 
		{
			mCurrentMenuElement = 1;
		}
		break;
	default:
		break;
	}
}




//This fuinction updates the appropriate languages
void MenuManager::updateMenuUI() 
{
	mStart[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_GAME));

	mStart[1]->changeMessage(textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_START));

	mStart[2]->changeMessage(textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LOAD_GAME_WORD));

	mStart[3]->changeMessage(textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD));

	mStart[4]->changeMessage(textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_QUIT_WORD));

	
	mSettings[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD));

	mSettings[1]->changeMessage(textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_DIFFICULTY_WORD));

	mSettings[2]->changeMessage(textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD));

	mSettings[3]->changeMessage(textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD));

	mSettings[4]->changeMessage(textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));



	mDifficulty[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_DIFFICULTY_WORD));

	mDifficulty[1]->changeMessage(textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_EASY_WORD));

	mDifficulty[2]->changeMessage(textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_MEDIUM_WORD));

	mDifficulty[3]->changeMessage(textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_HARD_WORD));

	mDifficulty[4]->changeMessage(textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));

	
	mSound[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD));

	mSound[1]->changeMessage(textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ON_WORD));

	mSound[2]->changeMessage(textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_OFF_WORD));

	mSound[3]->changeMessage(textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));


	mLanguage[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD));

	mLanguage[1]->changeMessage(textNumOne + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ENGLISH_WORD));

	mLanguage[2]->changeMessage(textNumTwo + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_PIRATE_WORD));

	mLanguage[3]->changeMessage(textNumThree + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_VULCAN_WORD));

	mLanguage[4]->changeMessage(textNumFour + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));
}
