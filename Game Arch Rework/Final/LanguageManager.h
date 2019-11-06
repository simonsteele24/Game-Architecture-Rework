#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <map>
#include <string>
#include <fstream>

using namespace std;

class LanuageManager
{
public:
	LanuageManager();
	LanuageManager(string languageFilePath);
	~LanuageManager();

	void loadLanguage(string languageFilePath);
	string getWord(string nameOfWord);

private:

	map<string, string> mLanguageTable;

};

#endif // !LANGUAGEMANAGER_H

