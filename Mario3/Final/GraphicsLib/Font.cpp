#include "Font.h"



// This functions is the default constructor
Fonts::Fonts()
{
	// Initialize everything to default values
	mFontSize = 0;
	mFilePath = "";
}





// This constructor takes in the font file path and the file size
Fonts::Fonts(string fontFilePath, int fontSize)
{

	mFontSize = fontSize;
	mFilePath = fontFilePath;
}





// This constructor takes in the font file
Fonts::Fonts(string fontFilePath)
{
	mFontSize = 5;
	mFilePath = fontFilePath;
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