#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Vector2.h"
#include <vector>
#include "Text.h"

// Constants
const string textNumOne = " 1          ";
const string textNumTwo = " 2          ";
const string textNumThree = " 3          ";
const string textNumFour = " 4          ";

class MenuManager
{
public:

	// Constructors
	MenuManager();

	// Destructors
	~MenuManager();

	// Acessors
	bool getMenu() { return mInMenu; }

	// Mutators
	void sendInput(int mNum);
	void draw();
	void updateMenuUI();

private:

	// Vectors
	vector<Text*> mStart;
	vector<Text*> mSettings;
	vector<Text*> mDifficulty;
	vector<Text*> mSound;
	vector<Text*> mLanguage;

	// Integers
	int mCurrentMenuElement = 0;
	int mFontSize = 20;
	int mFontSize2 = 30;
	int mFontSize3 = 40;

	// Floats
	float mColorValDefault = 255.0f;

	// Booleans
	bool mInMenu;
	bool mInPause;
};

#endif // !MENUMANAGER_H
