#ifndef TEXT_H
#define TEXT_H

// Graphics-Lib includes
#include <Font.h>
#include <Color.h>
#include <Vector2.h>

class Text
{
public:

	// Friends
	friend class TextManager;
	friend class MenuManager;

	// Mutators
	void drawText();
	int checkDigits(string amountToCheck);
	void changeMessage(string newMessage);
	void addScore(int amountAdd);
	void setTextPosition(Vector2 newPos);
	void changeFontSize(int newSize);
	void setTextToActive();
	void setTextToInactive();

	// Constructors
	Text();
	Text(string newName, Fonts & newFont, Colors newColor, string newMessage, Vector2 newPosition);

	// Destructors
	~Text();

	// Acessors
	string getName();
	int getScore() { return mScoreAmt; }

private:

	// Integers
	int mFontSize;
	int mHealth;
	int mTimer;

	// Booleans
	bool mIsActive;

	// Strings
	string mMessage;
	string mName;
	string mLevel;
	string mScore;
	Fonts mFonts;
	int mScoreAmt;

	// Colors
	Colors mTextColor;

	// Vector2's
	Vector2 mTextPosition;

};

#endif // !TEXT_H

