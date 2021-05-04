#ifndef __LEVELMANAGER_H__ 
#define __LEVELMANAGER_H__ 

#include "Module.h"

class LevelManager : public Module
{
private:

	int level;

public:

	int boxes_lvl = 0;
	bool boxes_done[3] = { false, false, false };

	LevelManager();

	~LevelManager();

	bool Update(float dt);

	void lvlChange(int change, char op);

	void Lose();

	void LevelComplete();

	int Getlvl();

	int steps = 0;

	int win = 0;

	int max_steps = 0;

	int backgroundLvl1[11][11] =
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 4, 3, 3, 3, 4, 2, 2, 2, 2, 2},
		{2, 4, 1, 1, 1, 4, 2, 2, 2, 2, 2},
		{2, 4, 1, 1, 1, 4, 2, 4, 3, 4, 2},
		{2, 3, 1, 1, 1, 3, 3, 3, 1, 4, 2},
		{2, 2, 4, 3, 1, 1, 1, 1, 1, 4, 2},
		{2, 2, 4, 1, 1, 1, 4, 1, 1, 4, 2},
		{2, 2, 4, 1, 1, 1, 4, 3, 3, 3, 2},
		{2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};

};

#endif