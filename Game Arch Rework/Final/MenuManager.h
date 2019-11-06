#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Vector2.h"
#include <vector>
#include "Text.h"

const string textNumOne = " 1          ";
const string textNumTwo = " 2          ";
const string textNumThree = " 3          ";
const string textNumFour = " 4          ";

class MenuManager
{
public:
	MenuManager();
	~MenuManager();

	bool getMenu() { return mInMenu; }

	void sendInput(int mNum);
	void draw();
	void updateMenuUI();

private:

	// Vector2's
	vector<Text*> mStart;
	vector<Text*> mSettings;
	vector<Text*> mDifficulty;
	vector<Text*> mSound;
	vector<Text*> mLanguage;


	int mCurrentMenuElement = 0;

	bool mInMenu;
	bool mInPause;

	int mFontSize = 20;
	int mFontSize2 = 30;
	int mFontSize3 = 40;

	float mColorValDefault = 255.0f;
};

#endif // !MENUMANAGER_H
