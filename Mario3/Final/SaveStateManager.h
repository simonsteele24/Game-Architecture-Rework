#ifndef SAVESTATEMANAGER_H
#define SAVESTATEMANAGER_H

// Standard Library includes
#include <string>

using namespace std;

class SaveStateManager
{
public:
	SaveStateManager();
	~SaveStateManager();

	bool readFile(string fileName);
	bool saveFile(string fileToSaveTo);

private:

};

#endif // !SAVESTATEMANAGER_H

