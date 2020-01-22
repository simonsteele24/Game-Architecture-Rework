#include "LanguageManager.h"

// This is the default constructor of the class
LanuageManager::LanuageManager()
{
}





// This constructor takes in a given string
LanuageManager::LanuageManager(string languageFilePath) 
{
	loadLanguage(languageFilePath);
}





// This is the destructor of the class
LanuageManager::~LanuageManager()
{
}





// This function loads a given language based on a given string
void LanuageManager::loadLanguage(string languageFilePath) 
{
	ifstream fileStream(languageFilePath);
	if (fileStream.good())
	{
		while (!fileStream.eof())
		{
			string key;
			string value;
			getline(fileStream, key);
			getline(fileStream, value);
			if (key != "")
			{
				mLanguageTable[key] = value;
			}
		}
	}
}





// This function gets a word from a given string
string LanuageManager::getWord(string nameOfWord) 
{
	return mLanguageTable[nameOfWord];
}