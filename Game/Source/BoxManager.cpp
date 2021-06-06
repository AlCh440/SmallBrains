#include "BoxManager.h"
#include "Box.h"
#include "app.h"
#include "LevelManager.h"
#include "input.h"
#include "SDL/include/SDL.h"


BoxManager::BoxManager(bool startEnabled) : Module(startEnabled)
{
	box_01 = new Box(true);
	box_02 = new Box(true);
	box_03 = new Box(true);
}

BoxManager::~BoxManager()
{

}

bool BoxManager::Start()
{

	
	return true;
}

bool BoxManager::Update(float dt)
{
		playLvl(dt);
	

	return true;
}

void BoxManager::playLvl(float dt)
{
	box_01->Update(dt);
	box_02->Update(dt);
	box_03->Update(dt);
}

bool BoxManager::CleanUp()
{
	delete(box_01);
	delete(box_02);
	delete(box_03);

	return true;
}

void BoxManager::OnCollision(Collider* c1, Collider* c2)
{
}

void BoxManager::InitializeLvl1()
{
	box_01->Start();
	box_01->SetPos_X(24 * 4);
	box_01->SetPos_Y(24 * 7);


	box_02->Start();
	box_02->SetPos_X(24 * 5);
	box_02->SetPos_Y(24 * 5);

	box_03->Start();
	box_03->SetPos_X(24 * 7);
	box_03->SetPos_Y(24 * 6);
}

void BoxManager::InitializeLvl2()
{
	box_01->Start();
	box_01->SetPos_X(72);
	box_01->SetPos_Y(72);


	box_02->Start();
	box_02->SetPos_X(96);
	box_02->SetPos_Y(72);

	box_03->Start();
	box_03->SetPos_X(72);
	box_03->SetPos_Y(96);
}

void BoxManager::InitializeLvl3()
{
	box_01->Start();
	box_01->SetPos_X(24 * 5);
	box_01->SetPos_Y(24 * 4);


	box_02->Start();
	box_02->SetPos_X(24 * 5);
	box_02->SetPos_Y(24 * 5);

	box_03->Start();
	box_03->SetPos_X(24 * 6);
	box_03->SetPos_Y(24 * 6);

	box_04->Start();
	box_04->SetPos_X(24 * 5);
	box_04->SetPos_Y(24 * 7);
}

void BoxManager::InitializeLvl4()
{
	box_01->Start();
	box_01->SetPos_X(24*4);
	box_01->SetPos_Y(24*4);


	box_02->Start();
	box_02->SetPos_X(24*6);
	box_02->SetPos_Y(24*5);

	box_03->Start();
	box_03->SetPos_X(24* 8);
	box_03->SetPos_Y(24* 5);

	box_04->Start();
	box_04->SetPos_X(24 * 9);
	box_04->SetPos_Y(24 * 5);
}

void BoxManager::InitializeLvl5()
{
	box_01->Start();
	box_01->SetPos_X(72);
	box_01->SetPos_Y(72);


	box_02->Start();
	box_02->SetPos_X(96);
	box_02->SetPos_Y(72);

	box_03->Start();
	box_03->SetPos_X(72);
	box_03->SetPos_Y(96);
}

void BoxManager::InitializeLvl6()
{
	box_01->Start();
	box_01->SetPos_X(72);
	box_01->SetPos_Y(72);


	box_02->Start();
	box_02->SetPos_X(96);
	box_02->SetPos_Y(72);

	box_03->Start();
	box_03->SetPos_X(72);
	box_03->SetPos_Y(96);
}
