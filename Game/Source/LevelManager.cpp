#include "App.h"
#include "LevelManager.h"
#include "Player.h"
#include "Input.h"
#include "Module.h"
#include "Tiles.h"
#include "BoxManager.h"
#include "Audio.h"

#include <SDL\include\SDL.h>

//fade to black 25 frames!!!
LevelManager::LevelManager(bool startEnabled) : Module(startEnabled)
{
	level = 0;
	framesCounter = 0;
	introMusic = true;
	pathX = 0;

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
	menuSelector_02 = { 1, 104, 161, 81 };
	//pasword = ;
	//cloud;
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

	positionXCar_01 = 0;
	positionYCar_01 = 130;
	positionXCar_02 = 0;
	positionYCar_02 = 130;
	return true;
}

bool LevelManager::Update(float dt)
{
	if (introMusic)
	{
		

		app->audio->PlayMusic("Assets/Audio/Music/01_Opening_A. Suda.ogg", 1.0f);
	}
	introMusic = false;

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
		
		backgroundIntro_01();
		girlIntro();
		efectsIntro();
		carIntro_01();
		carIntro_02();
		backgroundIntro_02();

		//call for all intros
		framesCounter++;
		if (framesCounter >= 1080 || app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		{
			lvlChange(3);
			
			framesCounter = 0;
		}
	}
	else if (level == 3) //menu
	{
		if (framesCounter > 60)
		{
			app->render->DrawTexture(menu, 21, 0, &menu_title);
			app->render->DrawTexture(menu, 72, 131, &menu_01);
		}
		app->render->DrawTexture(menuBackground, -1, -1);

		app->render->DrawTexture(menu, 21, 0, &menu_title);

		if (pathX == 0) app->render->DrawTexture(menu, 72, 131, &menu_01);
		else if (pathX == 1) app->render->DrawTexture(menu, 72, 131, &menu_02);
		else if (pathX == 2) app->render->DrawTexture(menu, 72, 131, &menu_03);

		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN && pathX > 0) pathX--;
		else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN && pathX < 2) pathX++;

		if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN && pathX == 0)
		{
			pathX = 0;
			lvlChange(4);
		}
	}
	else if (level == 4)
	{ 
		app->render->DrawTexture(levelSelector, 69, 10, &menuSelector_01);
		app->render->DrawTexture(levelSelector, 77, 90, &name);
		app->render->DrawTexture(levelSelector, 48, 130, &menuSelector_02);
		app->render->DrawTexture(levelSelector, 54 + 16 * pathX, 136 + 16 * pathY, &arrow);



		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN && pathY > 0) pathY--;
		else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN && pathY < 5) pathY++;
		else if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN && pathX > 0) pathX--;
		else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN && pathX < 10) pathX++;

		if (pathY == 0 && app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
		{
			if (pathX == 0)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl1();
				app->player->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
				lvlChange(5);

			}
			else if (pathX == 1)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl2();
				app->player->Enable();
				app->player->positionX = 48;
				app->player->positionY = 72;
				lvlChange(6);
			}
			else if (pathY == 2)
			{

			}
			else if (pathY == 3)
			{

			}
			else if (pathY == 4)
			{

			}
			else if (pathY == 5)
			{

			}
		}
	}
	else if (level == 5)
	{
	app->tiles->DrawArray(*backgroundLvl1, 11, 11);

	}
	else if (level == 6)
	{
		

		app->tiles->DrawArray(*backgroundLvl2, 11, 11);
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
	else if (framesCounter == 47);// still
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
//Cutscene 01(8 frames)
	//cutscene 02		38 63 88 / change image 3/ 117 / i 4/ 142 167 192/i 5/ 227 / i6 /252 277 from 302 to 349/ i 7/ 349(girl,car and back)
	//car movement starts at 376 to 385 // girl alone from 385 to 390
	//car 2 from 390 to 415 coffee at 448 to 478 (changes to second) 478 to 538, image 3 538 to 598
	//car blue from 618 moves at 648 till 657, 676 car appear till 702 coffee 748 till 869 girl08 from 809 till 871 and girl 09 goes 888 and black cloud
	// 919 car blue moves up till 927 change back at 929 with car moving till 942  black cloud goes at 944
	//975 thirf car animation /979 efect 6 moves 981 goes down 1013 // fade to black with 1051 till 1080  ends 1080
	// repeat

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
