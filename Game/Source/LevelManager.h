#ifndef __LEVELMANAGER_H__ 
#define __LEVELMANAGER_H__ 

#include "Module.h"
#include "Audio.h"

struct SDL_Texture;

class LevelManager : public Module
{
private:

	int level;
	int framesCounter;

public:

	int boxes_lvl = 0;

	LevelManager();

	~LevelManager();

	bool Start() override;

	bool Update(float dt) override;

	void lvlChange(int change);

	void Lose();

	void LevelComplete();

	int Getlvl();

	int win = 0;
	int max_steps = 0;
	bool introMusic;

	SDL_Texture* introMenu;
	SDL_Texture* smallbrainsIntro;

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