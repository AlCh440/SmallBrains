#include "BoxManager.h"
#include "Box.h"
#include "app.h"
#include "LevelManager.h"
#include "input.h"
#include "Tiles.h"
#include "Player.h"
#include "SDL/include/SDL.h"
#include <iostream>


BoxManager::BoxManager(bool startEnabled) : Module(startEnabled)
{
	
}

BoxManager::~BoxManager()
{

}

bool BoxManager::Start()
{
	box_01 = new Box(true);
	box_02 = new Box(true);
	box_03 = new Box(true);
	box_04 = new Box(true);
	box_05 = new Box(true);

	box_01->Start();
	box_02->Start();
	box_03->Start();
	box_04->Start();
	box_05->Start();

	return true;
}

bool BoxManager::PreUpdate()
{
	return true;
}

bool BoxManager::Update(float dt)
{
	playLvl(dt);

	if ((app->levelManager->Getlvl() == 5 || app->levelManager->Getlvl() == 6 || app->levelManager->Getlvl() == 9))
	{
		if (app->tiles->BoxOnDotCount == 3)
		{
			app->levelManager->lvlPassed = true;
			app->levelManager->win = true;
			app->player->afterGame = true;
			if (app->levelManager->path_01 == 0) app->levelManager->lvl1Passed = true;
			else if (app->levelManager->path_01 == 1) app->levelManager->lvl2Passed = true;
			else if (app->levelManager->path_01 == 2) app->levelManager->lvl3Passed = true;
			else if (app->levelManager->path_01 == 3) app->levelManager->lvl4Passed = true;
			else if (app->levelManager->path_01 == 4) app->levelManager->lvl5Passed = true;
			else if (app->levelManager->path_01 == 5) app->levelManager->lvl6Passed = true;
		}
	}
	else if (app->levelManager->Getlvl() == 8 )
	{
		if (app->tiles->BoxOnDotCount == 4)
		{
			app->levelManager->lvlPassed = true;
			app->levelManager->win = true;
			app->player->afterGame = true;
		}
	}
	else if (app->levelManager->Getlvl() == 7 || app->levelManager->Getlvl() == 10)
	{
		if (app->tiles->BoxOnDotCount == 5)
		{
			app->levelManager->lvlPassed = true;
			app->levelManager->win = true;
			app->player->afterGame = true;
		}
	}

	app->tiles->BoxOnDotCount = 0;
	
	return true;
}

void BoxManager::playLvl(float dt)
{
	box_01->Update(dt);
	box_02->Update(dt);
	box_03->Update(dt);
	if (app->levelManager->Getlvl() == 7 || app->levelManager->Getlvl() == 8 || app->levelManager->Getlvl() == 10)	box_04->Update(dt);
	if (app->levelManager->Getlvl() == 7 || app->levelManager->Getlvl() == 10) box_05->Update(dt);
}

bool BoxManager::CleanUp()
{
	box_01->CleanUp();
	delete(box_01);
	box_01 = nullptr;

	box_02->CleanUp();
	delete(box_02);
	box_02 = nullptr;

	box_03->CleanUp();
	delete(box_03);
	box_03 = nullptr;

	box_04->CleanUp();
	delete(box_04);	
	box_04 = nullptr;

	box_05->CleanUp();
	delete(box_05);
	box_05 = nullptr;

	return true;
}

void BoxManager::OnCollision(Collider* c1, Collider* c2)
{
}

void BoxManager::InitializeLvl1()
{
	
	box_01->SetPos_X(24 * 3);
	box_01->SetPos_Y(24 * 6);
	
	box_02->SetPos_X(24 * 4);
	box_02->SetPos_Y(24 * 4);

	box_03->SetPos_X(24 * 6);
	box_03->SetPos_Y(24 * 5);
}

void BoxManager::InitializeLvl2()
{
	box_01->SetPos_X(72);
	box_01->SetPos_Y(72);

	box_02->SetPos_X(96);
	box_02->SetPos_Y(72);

	box_03->SetPos_X(72);
	box_03->SetPos_Y(96);
}

void BoxManager::InitializeLvl3()
{
	box_01->SetPos_X(24 * 4);
	box_01->SetPos_Y(24 * 3);

	box_02->SetPos_X(24 * 4);
	box_02->SetPos_Y(24 * 4);

	box_03->SetPos_X(24 * 5);
	box_03->SetPos_Y(24 * 5);

	box_04->SetPos_X(24 * 4);
	box_04->SetPos_Y(24 * 6);

	box_05->SetPos_X(24 * 5);
	box_05->SetPos_Y(24 * 7);
}

void BoxManager::InitializeLvl4()
{
	box_01->SetPos_X(24*3);
	box_01->SetPos_Y(24*3);


	box_02->SetPos_X(24*5);
	box_02->SetPos_Y(24*4);

	box_03->SetPos_X(24* 7);
	box_03->SetPos_Y(24* 5);

	box_04->SetPos_X(24 * 8);
	box_04->SetPos_Y(24 * 4);
}

void BoxManager::InitializeLvl5()
{
	box_01->SetPos_X(24 * 4);
	box_01->SetPos_Y(24 * 3);


	box_02->SetPos_X(24 * 3);
	box_02->SetPos_Y(24 * 6);

	box_03->SetPos_X(24 * 6);
	box_03->SetPos_Y(24 * 7);
}

void BoxManager::InitializeLvl6()
{
	box_01->SetPos_X(24 * 4);
	box_01->SetPos_Y(24 * 4);

	box_02->SetPos_X(24 * 5);
	box_02->SetPos_Y(24 * 3);

	box_03->SetPos_X(24 * 5);
	box_03->SetPos_Y(24 * 5);

	box_04->SetPos_X(24 * 6);
	box_04->SetPos_Y(24 * 4);

	box_05->SetPos_X(24 * 7);
	box_05->SetPos_Y(24 * 5);
}
