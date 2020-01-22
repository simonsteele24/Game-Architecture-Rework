#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <map>
#include <string>
#include <fstream>

using namespace std;

class LanuageManager
{
public:
	// Constructors
	LanuageManager();
	LanuageManager(string languageFilePath);
	
	// Destructors
	~LanuageManager();

	// Mutators
	void loadLanguage(string languageFilePath);
	string getWord(string nameOfWord);

private:

	// Language map
	map<string, string> mLanguageTable;

};

#endif // !LANGUAGEMANAGER_H

