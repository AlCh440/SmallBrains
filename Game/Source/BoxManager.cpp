#include "BoxManager.h"
#include "Box.h"
#include "app.h"
#include "LevelManager.h"
#include "input.h"
#include "SDL/include/SDL.h"


#include "iostream"

BoxManager::BoxManager()
{
	box_01 = new Box();
	box_02 = new Box();
	box_03 = new Box();
}

BoxManager::~BoxManager()
{

}

bool BoxManager::Start()
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
	
	return true;
}

bool BoxManager::Update(float dt)
{
	if (app->levelManager->Getlvl() == 1)
	{
		box_01->Update(dt);
		box_02->Update(dt);
		box_03->Update(dt);
	}
	return true;
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
	
}
