#ifndef __LEVELMANAGER_H__ 
#define __LEVELMANAGER_H__ 

#include "Module.h"
#include "Audio.h"

struct SDL_Texture;
struct SDL_Texture;

class LevelManager : public Module
{
public:

	int level;
	int framesCounter;


	int boxes_lvl = 0;

	LevelManager(bool startEnabled);

	~LevelManager();

	bool Start() override;

	bool Update(float dt) override;

	void lvlChange(int change);

	void Logo();

	void girlIntro();
	void carIntro_01();
	void carIntro_02();
	void efectsIntro();
	void backgroundIntro_01();
	void backgroundIntro_02();

	void endGame();
	
	void pauseMenu();

	void Lose();

	void LevelComplete();

	int Getlvl();

	int win = 0;
	int max_steps = 0;
	bool introMusic;
	int path_01;
	int path_02;
	int path_03;
	int pathMenu;
	int movementCount;
	bool lvlPassed;
	bool pause;
	bool unableMusic;
	int futureLvl;

	int maxlvl1;
	int maxlvl2;
	int maxlvl3;
	int maxlvl4;
	int maxlvl5;
	int maxlvl6;

	SDL_Texture* smallbrainsIntro;
	SDL_Texture* intro_01;
	SDL_Texture* intro_02;
	SDL_Texture* intro_03;
	SDL_Texture* menu;
	SDL_Texture* menuBackground;
	SDL_Texture* levelSelector;
	SDL_Texture* companyLogo;
	SDL_Texture* inGameMenu;

	int positionXCar_01;
	int positionYCar_01;
	int positionXCar_02;
	int positionYCar_02;

	SDL_Rect girl_01;
	SDL_Rect girl_02;
	SDL_Rect girl_03;
	SDL_Rect girl_04;
	SDL_Rect girl_05;
	SDL_Rect girl_06;
	SDL_Rect girl_07;
	SDL_Rect girl_08;
	SDL_Rect girl_09;

	SDL_Rect cars_01;
	SDL_Rect cars_02;
	SDL_Rect cars_03;
	SDL_Rect cars_04;
	SDL_Rect cars_05;

	SDL_Rect background_01;
	SDL_Rect background_02;
	SDL_Rect background_03;
	SDL_Rect background_04;
	
	SDL_Rect efects_01;
	SDL_Rect efects_02;
	SDL_Rect efects_03;
	SDL_Rect efects_04;
	SDL_Rect efects_05;
	SDL_Rect efects_06;

	SDL_Rect menu_title;
	SDL_Rect menu_01;
	SDL_Rect menu_02;
	SDL_Rect menu_03;

	SDL_Rect arrow;
	SDL_Rect menuSelector_01;
	SDL_Rect name;
	SDL_Rect menuSelector_02;
	SDL_Rect pasword;
	SDL_Rect cloud;
	SDL_Rect lvlIcon_01;
	SDL_Rect lvlIcon_02;
	SDL_Rect lvlIcon_03;
	SDL_Rect lvlIcon_04;
	SDL_Rect lvlIcon_05;
	SDL_Rect lvlIcon_06;

	SDL_Rect menuBackground_01;
	SDL_Rect menuBackground_02;

	SDL_Rect stageCounter;
	SDL_Rect stageMenu_01;
	SDL_Rect stageMenu_02;
	SDL_Rect stageMenu_03;
	SDL_Rect stageMenu_04;
	SDL_Rect stageLevel_01;
	SDL_Rect stageLevel_02;
	SDL_Rect stageLevel_03;
	SDL_Rect stageLevel_04;
	SDL_Rect stageLevel_05;
	SDL_Rect stageLevel_06;
	SDL_Rect stagePause;
	SDL_Rect stageWin;
	SDL_Rect stageLose;
	SDL_Rect stageEnd_01;
	SDL_Rect stageEnd_02;

	int score = 000;
	int scoreFont = -1;
	char scoreText[150] = { "\0" };
	char maxText[150] = { "\0" };
	char lvl[10] = { "\0" };
	std::string score_01;

	bool lvl1Passed;
	bool lvl2Passed;
	bool lvl3Passed;
	bool lvl4Passed;
	bool lvl5Passed;
	bool lvl6Passed;

	int backgroundLvl1[11][11] =
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 2, 4, 3, 3, 3, 3, 3, 4, 2, 2},
		{2, 2, 4, 1, 1, 5, 5, 5, 4, 2, 2},
		{2, 2, 4, 1, 1, 1, 3, 3, 3, 4, 2},
		{2, 4, 3, 3, 1, 1, 1, 1, 1, 4, 2},
		{2, 4, 1, 1, 1, 4, 1, 3, 1, 4, 2},
		{2, 4, 1, 1, 1, 4, 1, 1, 1, 4, 2},
		{2, 4, 1, 1, 1, 4, 3, 3, 3, 3, 2},
		{2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};


	int backgroundLvl2[11][11] =
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 4, 3, 3, 3, 4, 2, 2, 2, 2, 2},
		{2, 4, 1, 1, 1, 4, 2, 4, 3, 4, 2},
		{2, 4, 1, 1, 1, 4, 2, 4, 5, 4, 2},
		{2, 3, 1, 1, 1, 3, 3, 3, 5, 4, 2},
		{2, 2, 4, 3, 1, 1, 1, 1, 5, 4, 2},
		{2, 2, 4, 1, 1, 1, 4, 1, 1, 4, 2},
		{2, 2, 4, 1, 1, 1, 4, 3, 3, 3, 2},
		{2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};

	int backgroundLvl3[11][11] =
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 2, 4, 3, 3, 4, 2, 2, 2, 2},
	{2, 2, 4, 3, 1, 1, 4, 2, 2, 2, 2},
	{2, 2, 4, 1, 1, 1, 4, 2, 2, 2, 2},
	{2, 2, 4, 4, 1, 1, 3, 4, 2, 2, 2},
	{2, 2, 4, 3, 1, 1, 1, 4, 2, 2, 2},
	{2, 2, 4, 5, 1, 1, 1, 4, 2, 2, 2},
	{2, 2, 4, 5, 5, 5, 5, 4, 2, 2, 2},
	{2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};

	int backgroundLvl4[11][11] =
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 4, 3, 3, 3, 3, 3, 4, 2, 2},
	{2, 2, 4, 1, 1, 1, 1, 1, 3, 3, 4},
	{2, 4, 3, 1, 3, 3, 3, 1, 1, 1, 4},
	{2, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4},
	{2, 4, 1, 5, 5, 4, 1, 1, 1, 4, 3},
	{2, 3, 4, 5, 5, 4, 1, 1, 1, 4, 2},
	{2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};

	int backgroundLvl5[11][11] = 
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 4, 3, 3, 4, 2, 2, 2, 2, 2},
	{2, 2, 4, 1, 1, 3, 3, 4, 2, 2, 2},
	{2, 2, 4, 1, 1, 1, 1, 4, 2, 2, 2},
	{2, 4, 3, 4, 1, 4, 1, 3, 4, 2, 2},
	{2, 4, 5, 3, 1, 3, 1, 1, 4, 2, 2},
	{2, 4, 5, 1, 1, 1, 3, 1, 4, 2, 2},
	{2, 4, 5, 1, 1, 1, 1, 1, 4, 2, 2},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};

	int backgroundLvl6[11][11] = 
	{ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 2, 2, 4, 3, 3, 3, 3, 4, 2},
	{2, 2, 4, 3, 3, 1, 1, 1, 1, 4, 2},
	{2, 4, 3, 5, 1, 1, 3, 3, 1, 3, 4},
	{2, 4, 5, 5, 1, 1, 1, 1, 1, 1, 4},
	{2, 4, 5, 5, 1, 1, 1, 1, 1, 4, 3},
	{2, 3, 3, 3, 3, 3, 4, 1, 1, 4, 2},
	{2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

	};
};


#endif