#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Vector2.h"
#include <vector>
#include "Text.h"

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
	vector<Text*> mSound;
	vector<Text*> mLanguage;

	// Integers
	int mCurrentMenuElement;

	// Booleans
	bool mInMenu;
	bool mInPause;
};

#endif // !MENUMANAGER_H
