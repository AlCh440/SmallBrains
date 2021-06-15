#include "App.h"
#include "LevelManager.h"
#include "Player.h"
#include "Input.h"
#include "Module.h"
#include "Tiles.h"
#include "BoxManager.h"
#include "Audio.h"
#include "font.h"

#include <SDL\include\SDL.h>
#include <iostream>

//fade to black 25 frames!!!
LevelManager::LevelManager(bool startEnabled) : Module(startEnabled)
{
	level = 0;
	framesCounter = 0;
	introMusic = true;
	path_01 = 0;
	path_02 = 0;
	path_03 = 0; 

	girl_01 = { 1, 1, 256, 224 };
	girl_02 = { 258, 1, 256, 224 };
	girl_03 = { 1, 226, 256, 224 };
	girl_04 = { 258, 226, 256, 224 };
	girl_05 = { 1, 451, 256, 224 };
	girl_06 = { 258, 451, 256, 224 };
	girl_07 = { 1, 676, 256, 224 };
	girl_08 = { 258, 676, 256, 224 };
	girl_09 = { 515, 676, 256, 224 };

	cars_01 = { 1, 1, 256, 224 };
	cars_02 = { 258, 1, 256, 224 };
	cars_03 = { 515, 1, 256, 224 };
	cars_04 = { 1, 226, 256, 224 };
	cars_05 = { 258, 226, 256, 224 };

	background_01 = { 1, 1, 256, 224 };
	background_02 = { 258, 1, 256, 224 };
	background_03 = { 1, 676, 256, 224 };
	background_04 = { 258, 676, 256, 224 };

	efects_01 = { 1, 226, 256, 224 };
	efects_02 = { 258, 226, 256, 224 };
	efects_03 = { 515, 226, 256, 224 };
	efects_04 = { 1, 451, 256, 224 };
	efects_05 = { 258, 451, 256, 224 };
	efects_06 = { 515, 676, 256, 224 };

	menu_title = { 1, 1, 215, 130 };
	menu_01 = { 1, 132, 112, 47 };
	menu_02 = { 114, 132, 112, 47 };
	menu_03 = { 227, 132, 112, 47 };

	arrow = { 1, 1, 9, 9 };
	menuSelector_01 = { 1, 11, 118, 70 };
	name = { 1, 81, 102, 22 };
	menuSelector_02 = { 1, 104, 161, 82 };
	pasword = { 1, 187, 118, 22 };
	cloud = { 1, 210, 57, 36 };
	lvlIcon_01 = { 163, 105, 15, 15 };
	lvlIcon_02 = { 179, 105, 15, 15 };
	lvlIcon_03 = { 195, 105, 15, 15 };
	lvlIcon_04 = { 211, 105, 15, 15 };
	lvlIcon_05 = { 227, 105, 15, 15 };
	lvlIcon_06 = { 243, 105, 15, 15 };

	menuBackground_01 = { 1, 1, 256, 518 };
	menuBackground_02 = { 1, 520, 256, 224 };

	stageCounter = { 1, 1, 60, 35 };
	stageMenu_01 = { 1, 38, 106, 58 };
	stageMenu_02 = { 108, 38, 106, 58 };
	stageMenu_03 = { 215, 38, 106, 58 };
	stageMenu_04 = { 322, 38, 106, 58 };
	stageLevel_01 = { 429, 38, 16, 8 };
	stageLevel_02 = { 446, 38, 16, 8 };
	stageLevel_03 = { 429, 47, 16, 8 };
	stageLevel_04 = { 446, 47, 16, 8 };
	stageLevel_05 = { 429, 56, 16, 8 };
	stageLevel_06 = { 446, 56, 16, 8 };
	stagePause = { 1, 97, 114, 58 };
	stageWin = { 1, 156, 120, 64 };
	stageLose = { 122, 156, 120, 64 };
	stageEnd_01 = { 1, 221, 120, 34 };
	stageEnd_02 = { 122, 221, 120, 34 } ;
}


LevelManager::~LevelManager()
{

}

bool LevelManager::Start()
{
	smallbrainsIntro = app->tex->Load("Assets/Textures/small_brains_intro.png");
	menu = app->tex->Load("Assets/Textures/menu.png");
	menuBackground = app->tex->Load("Assets/Textures/menuBackground.png");
	levelSelector = app->tex->Load("Assets/Textures/levelSelector.png");

	intro_01 = app->tex->Load("Assets/Textures/cutscene_sprites/cut_background.png");
	intro_02 = app->tex->Load("Assets/Textures/cutscene_sprites/cut_car.png");
	intro_03 = app->tex->Load("Assets/Textures/cutscene_sprites/cut_girl.png");

	companyLogo = app->tex->Load("Assets/Textures/company_logo.png");
	inGameMenu = app->tex->Load("Assets/Textures/in_game_menu.png");

	

	positionXCar_01 = 0;
	positionYCar_01 = 130;
	positionXCar_02 = 0;
	positionYCar_02 = 130;
	lvlPassed = false;

	maxlvl1 = 90;
	maxlvl2 = 120;
	maxlvl3 = 50;
	maxlvl4 = 140;
	maxlvl5 = 65;
	maxlvl6 = 60;

	char lookupTable[] = { "0123456789" };
	scoreFont = app->fonts->Load("Assets/Font/counter_font.png", lookupTable, 1);

	return true;
}

bool LevelManager::Update(float dt)
{
	if (level == 0)
	{
		app->render->DrawTexture(smallbrainsIntro, 0, 0);
		if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) lvlChange(1);
	}
	else if (level == 1) 
	{
		Logo();
		framesCounter++;
		if (framesCounter > 60)
		{	
			framesCounter = 0;
			lvlChange(2);
		}
	}
	else if (level == 2)
	{

		app->audio->PlayMusic("Assets/Audio/WAV/01_Opening_A_Suda.wav", 1.0f);

		backgroundIntro_01();
		girlIntro();
		efectsIntro();
		carIntro_01();
		carIntro_02();
		backgroundIntro_02();

		framesCounter++;
		if (framesCounter >= 1080 || app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		{
			lvlChange(3);
			
			framesCounter = 0;
			movementCount = 40;
		}
	}
	else if (level == 3) //menu
	{
		if (framesCounter < 50)
		{
			app->render->DrawTexture(menuBackground, -1, -1);
			app->render->DrawTexture(menu, 21, 40, &menu_title);
		}
		else if (framesCounter < 84) 
		{
			app->render->DrawTexture(menuBackground, -1, -1);
			app->render->DrawTexture(menu, 21, movementCount, &menu_title);
			movementCount--;
		}
		else
		{
			if (movementCount < 0) movementCount = 518;

			app->render->DrawTexture(menuBackground, 0, movementCount - 518, &menuBackground_01);
			app->render->DrawTexture(menuBackground, 0, movementCount, &menuBackground_01);
			movementCount--;

			app->render->DrawTexture(menu, 21, 5, &menu_title);

			if (path_01 == 0) app->render->DrawTexture(menu, 72, 140, &menu_01);
			else if (path_01 == 1) app->render->DrawTexture(menu, 72, 140, &menu_02);
			else if (path_01 == 2) app->render->DrawTexture(menu, 72, 140, &menu_03);

			if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN && path_01 > 0) path_01--;
			else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN && path_01 < 2) path_01++;
		}

		framesCounter++;
		if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) framesCounter = 90;

		if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN && path_01 == 0)
		{
			path_01 = 0;
			lvlChange(4);
		}
	}
	else if (level == 4)
	{ 
		app->render->DrawTexture(menuBackground, 0, 0, &menuBackground_02);
		app->render->DrawTexture(levelSelector, 69, 5, &menuSelector_01);
		app->render->DrawTexture(levelSelector, 77, 85, &name);
		app->render->DrawTexture(levelSelector, 48, 112, &menuSelector_02);
		app->render->DrawTexture(levelSelector, 69, 198, &pasword);
		app->render->DrawTexture(levelSelector, 192, 70, &cloud);

		if (lvl1Passed) app->render->DrawTexture(levelSelector, 49, 114, &lvlIcon_01);
		else if (lvl2Passed) app->render->DrawTexture(levelSelector, 60, 114, &lvlIcon_02);
		else if (lvl3Passed) app->render->DrawTexture(levelSelector, 76, 114, &lvlIcon_03);
		else if (lvl4Passed) app->render->DrawTexture(levelSelector, 92, 114, &lvlIcon_04);
		else if (lvl5Passed) app->render->DrawTexture(levelSelector, 108, 114, &lvlIcon_05);
		else if (lvl6Passed) app->render->DrawTexture(levelSelector, 122, 114, &lvlIcon_06);

		app->render->DrawTexture(levelSelector, 42 + 16 * path_01, 114 + 16 * path_02, &arrow);

		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN && path_02 > 0) path_02--;
		else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN && path_02 < 5) path_02++;
		else if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN && path_01 > 0) path_01--;
		else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN && path_01 < 10) path_01++;
		else if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN) lvlChange(3); 

		if (path_02 == 0 && app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
		{
			if (path_01 == 0)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl1();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
				lvlChange(5);
				path_02 = 0;
			}
			else if (path_01 == 1)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl2();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = 48;
				app->player->positionY = 72;
				lvlChange(6);
				path_02 = 0;
			}
			else if (path_01 == 2)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl3();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
				lvlChange(7);
				path_02 = 0;
			}
			else if (path_01 == 3)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl4();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 4);
				lvlChange(8);
				path_02 = 0;
			}
			else if (path_01 == 4)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl5();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 2);
				lvlChange(9);
				path_02 = 0;
			}
			else if (path_01 == 5)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl6();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 9);
				app->player->positionY = (24 * 4);
				lvlChange(10);
				path_02 = 0;
			}
			app->boxManager->unable = false;
		}
	}
	else if (level == 5) //level 1
	{
	app->tiles->DrawArray(*backgroundLvl1, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl1);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);
	
	if (score >= maxlvl1)
	{
		lvlPassed = true;
		app->player->afterGame = true;

	}
	
	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}
	else if (level == 6) // level 2
	{
	app->tiles->DrawArray(*backgroundLvl2, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl2);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);

	if (score >= maxlvl2)
	{
		app->player->afterGame = true;
		lvlPassed = true;
	}

	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}
	else if (level == 7) // level 3
	{
	app->tiles->DrawArray(*backgroundLvl3, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl3);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);

	if (score >= maxlvl3)
	{
		lvlPassed = true;
		app->player->afterGame = true;
	}

	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}
	else if (level == 8) // level 4
	{
	app->tiles->DrawArray(*backgroundLvl4, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl4);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);

	if (score >= maxlvl4)
	{
		lvlPassed = true;
		app->player->afterGame = true;
	}

	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}
	else if (level == 9) // level 5
	{
	app->tiles->DrawArray(*backgroundLvl5, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl5);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	if (score >= maxlvl5)
	{
		lvlPassed = true;
		app->player->afterGame = true;

	}
	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);

	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}
	else if (level == 10) // level 6
	{
	app->tiles->DrawArray(*backgroundLvl6, 11, 11);

	score = app->player->stepCount;
	sprintf_s(scoreText, 10, "%4d", score);

	sprintf_s(maxText, 10, "%4d", maxlvl6);
	sprintf_s(lvl, 10, "%2d", path_01 + 1);

	app->render->DrawTexture(inGameMenu, 150, 40, &stageCounter);
	app->fonts->DrawText(194, 44, scoreFont, lvl);
	app->fonts->DrawText(180, 65, scoreFont, maxText);
	app->fonts->DrawText(180, 56, scoreFont, scoreText);

	if (score >= maxlvl6)
	{
		lvlPassed = true;
		app->player->afterGame = true;
	}

	if (app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
	{
		pause = !pause;
		app->player->afterGame = true;
	}
	if (lvlPassed)
	{
		endGame();
	}
	else if (pause)
	{
		pauseMenu();
	}
	}



	return true;
}


void LevelManager::lvlChange(int change)
{
	level = change;
}

void LevelManager::Logo()
{
	if (framesCounter == 15);// time fade to black 
	else if (framesCounter >= 47 && framesCounter < 62) app->render->DrawTexture(companyLogo, 0, 0);// still
	else if (framesCounter == 62); // fade from black
}

void LevelManager::girlIntro()
{
	if (framesCounter < 8);//fade to black
	else if (framesCounter >= 8 && framesCounter < 38) app->render->DrawTexture(intro_03, 0, 0, &girl_01);
	else if (framesCounter >= 38 && framesCounter < 63) app->render->DrawTexture(intro_03, 0, 0, &girl_02);
	else if (framesCounter >= 63 && framesCounter < 89) app->render->DrawTexture(intro_03, 0, 0, &girl_01);
	else if (framesCounter >= 89 && framesCounter < 117) app->render->DrawTexture(intro_03, 0, 0, &girl_02);
	else if (framesCounter >= 117 && framesCounter < 142) app->render->DrawTexture(intro_03, 0, 0, &girl_03);
	else if (framesCounter >= 142 && framesCounter < 167) app->render->DrawTexture(intro_03, 0, 0, &girl_04);
	else if (framesCounter >= 167 && framesCounter < 192) app->render->DrawTexture(intro_03, 0, 0, &girl_03);
	else if (framesCounter >= 192 && framesCounter < 227) app->render->DrawTexture(intro_03, 0, 0, &girl_04);
	else if (framesCounter >= 227 && framesCounter < 252) app->render->DrawTexture(intro_03, 0, 0, &girl_05);
	else if (framesCounter >= 252 && framesCounter < 277) app->render->DrawTexture(intro_03, 0, 0, &girl_06);
	else if (framesCounter >= 277 && framesCounter < 302) app->render->DrawTexture(intro_03, 0, 0, &girl_05);
	else if (framesCounter >= 302 && framesCounter < 349) app->render->DrawTexture(intro_03, 0, 0, &girl_06);
	else if (framesCounter >= 349 && framesCounter < 809) app->render->DrawTexture(intro_03, 0, 0, &girl_07);
	else if (framesCounter >= 809 && framesCounter < 871) app->render->DrawTexture(intro_03, 0, 0, &girl_08);
	else if (framesCounter >= 871 && framesCounter < 888) app->render->DrawTexture(intro_03, 0, 0, &girl_09);

		
}

void LevelManager::carIntro_01()
{
	if (framesCounter >= 349 && framesCounter < 375) app->render->DrawTexture(intro_02, 0, 0, &cars_01);
	else if (framesCounter >= 375 && framesCounter < 385)
	{
		app->render->DrawTexture(intro_02, positionXCar_01, 0, &cars_01);
		positionXCar_01 += 26;
	}
	else if (framesCounter >= 389 && framesCounter < 415)
	{
		app->render->DrawTexture(intro_02, positionXCar_01, positionYCar_01, &cars_02);
		positionXCar_01 -= 10;
		positionYCar_01 -= 5;
	}
	else if (framesCounter >= 415 && framesCounter < 975) app->render->DrawTexture(intro_02, positionXCar_01, positionYCar_01, &cars_02);
	else if (framesCounter >= 975 && framesCounter < 1080) app->render->DrawTexture(intro_02, positionXCar_01, positionYCar_01, &cars_03);


}
void LevelManager::carIntro_02()
{
	if (framesCounter >= 618 && framesCounter < 648) app->render->DrawTexture(intro_02, 0, 0, &cars_04);
	else if (framesCounter >= 648 && framesCounter < 657)
	{
		app->render->DrawTexture(intro_02, positionXCar_02, 0, &cars_04);
		positionXCar_02 -= 26;
	}
	else if (framesCounter >= 676 && framesCounter < 702)
	{
		app->render->DrawTexture(intro_02, positionXCar_02, positionYCar_02, &cars_05);
		positionXCar_02 += 9;
		positionYCar_02 -= 5;
	}
	else if (framesCounter >= 702 && framesCounter < 919) app->render->DrawTexture(intro_02, 0, 0, &cars_05);
	else if (framesCounter >= 919 && framesCounter < 927)
	{
		app->render->DrawTexture(intro_02, positionXCar_02, positionYCar_02, &cars_05);
		positionYCar_02 -= 2;
	}
	else if (framesCounter >= 929 && framesCounter < 942)
	{
		app->render->DrawTexture(intro_02, positionXCar_02, positionYCar_02, &cars_05);
		positionXCar_02 -= 5;
		positionYCar_02 += 3;
	}

}

void LevelManager::efectsIntro()
{
	if (framesCounter >= 448 && framesCounter < 478) app->render->DrawTexture(intro_01, 0, 0, &efects_01);
	else if (framesCounter >= 478 && framesCounter < 538) app->render->DrawTexture(intro_01, 0, 0, &efects_02);
	else if (framesCounter >= 538 && framesCounter < 598) app->render->DrawTexture(intro_01, 0, 0, &efects_03);
	else if (framesCounter >= 748 && framesCounter < 869) app->render->DrawTexture(intro_01, 0, 0, &efects_04);
	else if (framesCounter >= 888 && framesCounter < 944) app->render->DrawTexture(intro_01, 0, 0, &efects_05);
	else if (framesCounter >= 944 && framesCounter < 1080) app->render->DrawTexture(intro_01, 0, 0, &efects_06);


}

void LevelManager::backgroundIntro_01()
{
	if (framesCounter >= 8 && framesCounter < 349)
	{
		app->render->DrawTexture(intro_01, 0, 0, &background_01);
		app->render->DrawTexture(intro_01, 0, 0, &background_03);
	}
	else if (framesCounter >= 349 && framesCounter < 1080) app->render->DrawTexture(intro_01, 0, 0, &background_02);
}

void LevelManager::backgroundIntro_02()
{
	if (framesCounter >= 927 && framesCounter < 1080) app->render->DrawTexture(intro_01, 0, 0, &background_03);
	else if (framesCounter >= 927 && framesCounter < 1080) app->render->DrawTexture(intro_02, 0, 0, &cars_02);


}

void LevelManager::endGame()
{
	if (win) app->render->DrawTexture(inGameMenu, 68, 80, &stageWin);
	else  app->render->DrawTexture(inGameMenu, 68, 80, &stageLose);

	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN && path_03 < 1) path_03++;
	else if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN && path_03 > 0) path_03--;

	if (win)
	{
		if (path_03 == 0) app->render->DrawTexture(inGameMenu, 68, 154, &stageEnd_01);
		else if (path_03 == 1) app->render->DrawTexture(inGameMenu, 68, 154, &stageEnd_02);

		if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
		{
			if (path_03 == 0)
			{
				if (path_01 == 0)
				{
					app->boxManager->InitializeLvl1();
					app->player->positionX = (24 * 3);
					app->player->positionY = (24 * 3);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 1)
				{
					app->boxManager->InitializeLvl2();
					app->player->positionX = 48;
					app->player->positionY = 72;
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 2)
				{
					app->boxManager->InitializeLvl3();
					app->player->positionX = (24 * 4);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 3)
				{
					app->boxManager->InitializeLvl4();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 4)
				{
					app->boxManager->InitializeLvl5();
					app->player->positionX = (24 * 3);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 5)
				{
					app->boxManager->InitializeLvl2();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 10);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				lvlPassed = false;
				app->player->stepCount = 0;
				score = 0;
			}
			else if (path_03 == 1)
			{
				if (path_01 == 0)
				{
					app->boxManager->InitializeLvl2();
					app->player->positionX = 48;
					app->player->positionY = 72;
					path_01 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
					lvlChange(6);
				}
				else if (path_01 == 1)
				{
					app->boxManager->InitializeLvl3();
					app->player->positionX = (24 * 4);
					app->player->positionY = (24 * 4);
					path_01 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
					lvlChange(7);
				}
				else if (path_01 == 2)
				{
					app->boxManager->InitializeLvl4();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 4);
					path_01 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
					lvlChange(8);
				}
				else if (path_01 == 3)
				{
					app->boxManager->InitializeLvl5();
					app->player->positionX = (24 * 3);
					app->player->positionY = (24 * 4);
					path_01 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
					lvlChange(9);
				}
				else if (path_01 == 4)
				{
					app->boxManager->InitializeLvl6();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 10);
					path_01 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
					lvlChange(10);
				}
				lvlPassed = false;
			}
			app->collisions->RemoveColliderType(Collider::Type::WALL);
			win = false;
		}
	}
	else
	{
		if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
		{
			{
				if (path_01 == 0)
				{
					app->boxManager->InitializeLvl1();
					app->player->positionX = (24 * 3);
					app->player->positionY = (24 * 3);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 1)
				{
					app->boxManager->InitializeLvl2();
					app->player->positionX = 48;
					app->player->positionY = 72;
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 2)
				{
					app->boxManager->InitializeLvl3();
					app->player->positionX = (24 * 4);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 3)
				{
					app->boxManager->InitializeLvl4();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 4)
				{
					app->boxManager->InitializeLvl5();
					app->player->positionX = (24 * 3);
					app->player->positionY = (24 * 4);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				else if (path_01 == 5)
				{
					app->boxManager->InitializeLvl2();
					app->player->positionX = (24 * 5);
					app->player->positionY = (24 * 10);
					path_02 = 0;
					lvlPassed = false;
					app->player->afterGame = false;
					app->tiles->BoxOnDotCount = 0;
				}
				lvlPassed = false;
				app->player->stepCount = 0;
				score = 0;
			}
		}
	}
}

void LevelManager::pauseMenu()
{
	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN && pathMenu < 3) pathMenu++;
	else if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN && pathMenu > 0) pathMenu--;

	if (pathMenu == 0)	app->render->DrawTexture(inGameMenu, 75, 90, &stageMenu_01);
	else if (pathMenu == 1)	app->render->DrawTexture(inGameMenu, 75, 90, &stageMenu_02);
	else if (pathMenu == 2) app->render->DrawTexture(inGameMenu, 75, 90, &stageMenu_03);
	else if (pathMenu == 3) app->render->DrawTexture(inGameMenu, 75, 90, &stageMenu_04);

	if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN) 
	{
		if (pathMenu == 0)
		{
			if (path_01 == 0)
			{
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();

			}
			else if (path_01 == 1)
			{
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();
				app->player->positionX = 48;
				app->player->positionY = 72;
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;

			}
			else if (path_01 == 2)
			{
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();
				app->player->positionX = (24 * 4);
				app->player->positionY = (24 * 4);
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;

			}
			else if (path_01 == 3)
			{
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();
				app->player->positionX = (24 * 5);
				app->player->positionY = (24 * 4);
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;

			}
			else if (path_01 == 4)
			{
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 4);
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;

			}
			else if (path_01 == 5)
			{
				app->boxManager->CleanUp();
				app->boxManager->Start();
				app->boxManager->InitializeLvl1();
				app->player->positionX = (24 * 5);
				app->player->positionY = (24 * 10);
				pathMenu = 0;
				lvlPassed = false;
				app->player->afterGame = false;
				app->tiles->BoxOnDotCount = 0;
			}
			pause = false;
		}
		else if (pathMenu == 1)
		{
			app->player->Disable();
			app->boxManager->Disable();
			app->tiles->Disable();
			app->collisions->Disable();
			path_01 = 0;
			path_02 = 0;
			lvlChange(4);
			pause = false;
		}
		else if (pathMenu == 3)
		{
			app->player->Disable();
			app->boxManager->Disable();
			app->tiles->Disable();
			app->collisions->Disable();
			path_01 = 0;
			path_02 = 0;
			lvlChange(3);
			pause = false;
		}
		app->player->afterGame = false;
	}
}

int LevelManager::Getlvl() {
	return level;
}
