#include "App.h"
#include "Box.h"
#include "Textures.h"
#include "Render.h"
#include "Collisions.h"

#include "Log.h"
#include "iostream"


Box::Box()
{
	pos_x = 0;
	pos_y = 0;
	box = { 27, 144, 24, 24 };
	
}

// Destructor
Box::~Box()
{

}

bool Box::Start()
{ 
	spriteSheet = app->tex->Load("Assets/Textures/tileSheet.png");

	return true;
}

// Set new window title
bool Box::Update(float dt)
{
	app->render->DrawTexture(spriteSheet, this->pos_x, this->pos_y, &box );
	return true;

}

// Called before quitting
bool Box::CleanUp()
{

	return true;
}

int Box::GetPos_X()
{
	return pos_x;
}

int Box::GetPos_Y()
{
	return pos_y;
}

void Box::SetPos_X(int pos)
{
	std::cout << "CCC";
	pos_x = pos;
}

void Box::SetPos_Y(int pos)
{
	pos_y = pos;
}

void Box::OnCollision(Collider* c1, Collider* c2)
{

}
