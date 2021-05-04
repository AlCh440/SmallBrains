#include "App.h"
#include "LevelManager.h"
#include "Player.h"
#include "Input.h"
#include "Module.h"
#include "Tiles.h"

#include <SDL\include\SDL.h>

LevelManager::LevelManager()
{
	level = 1;
}


LevelManager::~LevelManager()
{

}

bool LevelManager::Update(float dt)
{
	app->tiles->DrawArray(*backgroundLvl1, 11, 11);
	return true;
}

void LevelManager::lvlChange(int change, char op)
{
	switch (op) {
	case '=':
		level = change;
		break;
	case '+':
		level += change;
		break;
	case '-':
		level -= change;
		break;
	default:
		break;
	}

}



void LevelManager::Lose()
{
	win = 2;
	if (app->input->GetKey(SDL_SCANCODE_SPACE)== KEY_DOWN) {
		app->levelManager->lvlChange(1, '-');
		//app->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);

		boxes_lvl = 0;
		win = 0;
		steps = 0;
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
				lvlChange(1, '+');
				boxes_lvl = 0;
				win = 0;
				steps = 0;
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
				lvlChange(1, '+');
				boxes_lvl = 0;
				win = 0;
				steps = 0;
			}
		}
	}
	if (level == 3)
	{
		if (boxes_lvl == 2 * 12) {
			win = 1;
			if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
				//App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneLevel_1, 90);
				lvlChange(1, '+');
				boxes_lvl = 0;
				win = 0;
				steps = 0;
			}
		}
		
	}



}

int LevelManager::Getlvl() {
	return level;
}
