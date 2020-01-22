#include "MenuManager.h"
#include "Game.h"

//Constructor that inits the entire menu manager
MenuManager::MenuManager()
{
	mInMenu = true;

	mCurrentMenuElement = 0;

	//Start Vector data
	mStart.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_GAME), TITLE_TEXT_POSITION));
	mStart[mStart.size() - 1]->changeFontSize(HEADER_THREE_FONT_SIZE);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_START), MENU_TEXT_ONE_POSITION));
	mStart[mStart.size() - 1]->changeFontSize(HEADER_ONE_FONT_SIZE);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LOAD_GAME_WORD), MENU_TEXT_TWO_POSITION));
	mStart[mStart.size() - 1]->changeFontSize(HEADER_ONE_FONT_SIZE);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD), MENU_TEXT_THREE_POSITION));
	mStart[mStart.size() - 1]->changeFontSize(HEADER_ONE_FONT_SIZE);
	mStart[mStart.size() - 1]->setTextToActive();

	mStart.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_FOUR + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_QUIT_WORD), MENU_TEXT_FOUR_POSITION));
	mStart[mStart.size() - 1]->changeFontSize(HEADER_ONE_FONT_SIZE);
	mStart[mStart.size() - 1]->setTextToActive();

	//Settings Vector data
	mSettings.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD), TITLE_TEXT_POSITION));
	mSettings[mSettings.size() - 1]->changeFontSize(HEADER_ONE_FONT_SIZE);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD), MENU_TEXT_ONE_POSITION));
	mSettings[mSettings.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD), MENU_TEXT_TWO_POSITION));
	mSettings[mSettings.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSettings[mSettings.size() - 1]->setTextToActive();

	mSettings.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), MENU_TEXT_THREE_POSITION));
	mSettings[mSettings.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSettings[mSettings.size() - 1]->setTextToActive();

	//Sound Vector data
	mSound.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD), TITLE_TEXT_POSITION));
	mSound[mSound.size() - 1]->changeFontSize(HEADER_THREE_FONT_SIZE);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ON_WORD), MENU_TEXT_ONE_POSITION));
	mSound[mSound.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_OFF_WORD), MENU_TEXT_TWO_POSITION));
	mSound[mSound.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSound[mSound.size() - 1]->setTextToActive();

	mSound.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), MENU_TEXT_THREE_POSITION));
	mSound[mSound.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mSound[mSound.size() - 1]->setTextToActive();


	//Language Vector data
	mLanguage.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD), TITLE_TEXT_POSITION));
	mLanguage[mLanguage.size() - 1]->changeFontSize(HEADER_THREE_FONT_SIZE);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ENGLISH_WORD), MENU_TEXT_ONE_POSITION));
	mLanguage[mLanguage.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_PIRATE_WORD), MENU_TEXT_TWO_POSITION));
	mLanguage[mLanguage.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_VULCAN_WORD), MENU_TEXT_THREE_POSITION));
	mLanguage[mLanguage.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
	mLanguage[mLanguage.size() - 1]->setTextToActive();

	mLanguage.push_back(new Text(NAME_OF_MENU_TEXT, *Game::getStaticInstance()->mUIFont, Colors(TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT, TEXT_COLOR_DEFAULT), MENU_TEXT_PROMPT_FOUR + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD), MENU_TEXT_FOUR_POSITION));
	mLanguage[mLanguage.size() - 1]->changeFontSize(HEADER_TWO_FONT_SIZE);
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
		for (int i = 0; i < (int)mSound.size(); i++)
		{
			if (mSound[i]->mIsActive)
			{
				mSound[i]->drawText();
			}
		}
		break;
	case 3:
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
			mCurrentMenuElement = 2;
		}
		else if (mCurrentMenuElement == 2)
		{
			Game::getStaticInstance()->mAudioManager->unmuteSounds();
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 3)
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
		else if (mCurrentMenuElement == 2)
		{
			Game::getStaticInstance()->mAudioManager->muteSounds();
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 1) 
		{
			mCurrentMenuElement = 3;
		}
		else if (mCurrentMenuElement == 3)
		{
			Game::getStaticInstance()->loadLanguage(PIRATE_TEXT_FILE_PATH);
			mCurrentMenuElement = 1;
			updateMenuUI();
		}
		break;
	case 3:
		if (mCurrentMenuElement == 1)
		{
			mCurrentMenuElement = 0;
		}
		else if (mCurrentMenuElement == 0) 
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 2)
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 3)
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
		else if (mCurrentMenuElement == 2) 
		{
			mCurrentMenuElement = 1;
		}
		else if (mCurrentMenuElement == 3) 
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

	mStart[1]->changeMessage(MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_START));

	mStart[2]->changeMessage(MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LOAD_GAME_WORD));

	mStart[3]->changeMessage(MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD));

	mStart[4]->changeMessage(MENU_TEXT_PROMPT_FOUR + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_QUIT_WORD));

	
	mSettings[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SETTINGS_WORD));

	mSettings[1]->changeMessage(MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD));

	mSettings[2]->changeMessage(MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD));

	mSettings[3]->changeMessage(MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));

	
	mSound[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_SOUND_WORD));

	mSound[1]->changeMessage(MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ON_WORD));

	mSound[2]->changeMessage(MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_OFF_WORD));

	mSound[3]->changeMessage(MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));


	mLanguage[0]->changeMessage(Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_LANGUAGE_WORD));

	mLanguage[1]->changeMessage(MENU_TEXT_PROMPT_ONE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_ENGLISH_WORD));

	mLanguage[2]->changeMessage(MENU_TEXT_PROMPT_TWO + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_PIRATE_WORD));

	mLanguage[3]->changeMessage(MENU_TEXT_PROMPT_THREE + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_VULCAN_WORD));

	mLanguage[4]->changeMessage(MENU_TEXT_PROMPT_FOUR + Game::getStaticInstance()->mLanguageManager.getWord(NAME_OF_BACK_WORD));
}
