#include "Font.h"



// This functions is the default constructor
Fonts::Fonts()
{
	// Initialize everything to default values
	mFontSize = 0;
	mFilePath = "";
	mCurrentFont = sf::Font();
}





// This constructor takes in the font file path and the file size
Fonts::Fonts(string fontFilePath, int fontSize)
{

	mFontSize = fontSize;
	mFilePath = fontFilePath;
	mCurrentFont = sf::Font();
	mCurrentFont.loadFromFile(fontFilePath);
}





// This constructor takes in the font file
Fonts::Fonts(string fontFilePath)
{
	mFontSize = 5;
	mFilePath = fontFilePath;
	mCurrentFont = sf::Font();
	//load font and if it doesn't load, then throw the cout error
	if (!mCurrentFont.loadFromFile(fontFilePath))
	{
		cout << "ERROR";
	}
	else 
	{
		mCurrentFont.loadFromFile(fontFilePath);
	}
}





// This is the destructor
Fonts::~Fonts()
{
}





// This function gets the size member variable
int Fonts::getSize()
{
	return mFontSize;
}





// This function changes the font size and loads the new version of the font
void Fonts::setSize(int newSize)
{
	mFontSize = newSize;
}