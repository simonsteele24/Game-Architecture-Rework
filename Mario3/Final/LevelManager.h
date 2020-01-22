#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager
{
public:
	// Constructors
	LevelManager();

	// Destructors
	~LevelManager();

	// Mutators
	void loadNextLevel();
	void loadCurrentLevel();
	void setLevelNumber(int newNum);

	// Acessors
	int getLevelNumber();

private:

	// Integers
	int mLevelNum;

};

#endif // !LEVELMANAGER_H

