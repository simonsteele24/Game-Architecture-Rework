#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	void loadNextLevel();
	void loadCurrentLevel();

	int getLevelNumber();
	void setLevelNumber(int newNum);

private:

	int mLevelNum;

};

#endif // !LEVELMANAGER_H

