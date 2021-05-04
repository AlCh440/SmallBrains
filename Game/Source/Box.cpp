#include "App.h"
#include "Box.h"
#include "Textures.h"
#include "Render.h"

#include "Log.h"


Box::Box() : Module()
{
	pos_x = 0;
	pos_y = 0;
}

// Destructor
Box::~Box()
{
}

bool Box::Start()
{ 
	spriteSheet = app->tex->Load("Assets/Textures/TileSheet.png");

	return true;
}

// Set new window title
bool Box::Update(float dt)
{
	app->render->DrawTexture(spriteSheet, pos_x, pos_y);

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
	pos_x = pos;
}

void Box::SetPos_Y(int pos)
{
	pos_y = pos;
}