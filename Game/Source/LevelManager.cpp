#include "App.h"
#include "LevelManager.h"
#include "Player.h"
#include "Input.h"
#include "Module.h"
#include "Tiles.h"
#include "BoxManager.h"
#include "Audio.h"

#include <SDL\include\SDL.h>

LevelManager::LevelManager()
{
	level = -1;
	framesCounter = 0;
	introMusic = true;
}


LevelManager::~LevelManager()
{

}

bool LevelManager::Start()
{
	introMenu = app->tex->Load("Assets/Textures/super_soukoban_intro");
	return true;
}

bool LevelManager::Update(float dt)
{
	if (introMusic)
	{
		introMenu = app->tex->Load("Assets/Textures/super_soukoban_intro.png");
		smallbrainsIntro = app->tex->Load("Assets/Textures/small_brains_intro.png");

		app->audio->PlayMusic("Assets/Audio/Music/01_Opening_A. Suda.ogg", 1.0f);
	}
	introMusic = false;

	if (level == -1)
	{
		app->render->DrawTexture(smallbrainsIntro, 0, 0);
		if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) lvlChange(0);
	}
	else if (level == 0) 
	{
		app->render->DrawTexture(introMenu, 16, 0);
		framesCounter++;
		if (framesCounter > 15000) lvlChange(1);

	}
	else if (level == 1)
	{
		app->tiles->DrawArray(*backgroundLvl1, 11, 11);
		if (app->player->stepCount == 20)
		{
			lvlChange(-1);
			app->player->stepCount = 0;
		}
	}



	return true;
}

void LevelManager::lvlChange(int change)
{
	level = change;
	if (level == 1) 
	{
		//Sett boxes !!!
		app->boxManager->InitializeLvl1();
		//Sett player position !!!
	}
}



void LevelManager::Lose()
{
	win = 2;
	if (app->input->GetKey(SDL_SCANCODE_SPACE)== KEY_DOWN) {
		app->levelManager->lvlChange(2);
		//app->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);

		boxes_lvl = 0;
		win = 0;
		
	}

}

void LevelManager::LevelComplete()
{
	if (level == 1)
	{
		if (boxes_lvl == 2 * 3) {
			win = 1;
			if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
			{
				//App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);
				lvlChange(3);
				boxes_lvl = 0;
				win = 0;
				
			}

		}
	}
	else if (level == 2)
	{
		if (boxes_lvl == 2 * 11) {
			win = 1;
			if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) 
			{
				//app->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);
				lvlChange(3);
				boxes_lvl = 0;
				win = 0;
				
			}
		}
	}
	if (level == 3)
	{
		if (boxes_lvl == 2 * 12) {
			win = 1;
			if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
				//App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);
				lvlChange(3);
				boxes_lvl = 0;
				win = 0;
				
			}
		}
		
	}



}

int LevelManager::Getlvl() {
	return level;
}
