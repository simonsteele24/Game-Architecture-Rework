#include "LanguageManager.h"

LanuageManager::LanuageManager()
{
}

LanuageManager::LanuageManager(string languageFilePath) 
{
	loadLanguage(languageFilePath);
}

LanuageManager::~LanuageManager()
{
}

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

string LanuageManager::getWord(string nameOfWord) 
{
	return mLanguageTable[nameOfWord];
}