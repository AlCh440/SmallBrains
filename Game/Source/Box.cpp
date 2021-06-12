#include "App.h"
#include "Box.h"
#include "Textures.h"
#include "Render.h"
#include "Collisions.h"
#include "player.h"

#include "Log.h"
#include "iostream"

Box::Box(bool startEnabled) : Module(startEnabled)
{
	posX = -200;
	posY = -200;
	box = { 27, 144, 24, 24 };
	
}

// Destructor
Box::~Box()
{

}

bool Box::Start()
{ 
	spriteSheet = app->tex->Load("Assets/Textures/tileSheet.png");

	collBox = app->collisions->AddCollider({ posX, posY, 24, 24 }, Collider::Type::BOXMIDDLE, this);
	collBoxLeft = app->collisions->AddCollider({ (int)posX - 24, (int)posY, 24, 24 }, Collider::Type::BOX, this);
	collBoxRight = app->collisions->AddCollider({ (int)posX + 24, (int)posY, 24, 24 }, Collider::Type::BOX, this);
	collBoxUp = app->collisions->AddCollider({ posX, posY - 24, 24, 24 }, Collider::Type::BOX, this);
	collBoxDown = app->collisions->AddCollider({ posX, posY + 24, 24, 24 }, Collider::Type::BOX, this);

	return true;
}

// Set new window title
bool Box::Update(float dt)
{

	app->render->DrawTexture(spriteSheet, this->posX, this->posY, &box );

	collBox->SetPos(posX, posY );
	collBoxLeft->SetPos(posX - 24, posY);
	collBoxRight->SetPos(posX + 24, posY);
	collBoxUp->SetPos(posX, posY - 24);
	collBoxDown->SetPos(posX, posY + 24);
	
	return true;

}

// Called before quitting
bool Box::CleanUp()
{

	return true;
}

void Box::MoveBox(int direction)
{
	if (direction == 4) posX++;
	else if (direction == 1) posY--;
	else if (direction == 2) posY++;
	else if (direction == 3) posX--;
	move = true;
}

int Box::GetPos_X()
{
	return posX;
}

int Box::GetPos_Y()
{
	return posY;
}

void Box::SetPos_X(int pos)
{
	posX = pos;
}

void Box::SetPos_Y(int pos)
{
	posY = pos;
}

void Box::OnCollision(Collider* c1, Collider* c2)
{
	if ((c2->type == Collider::Type::PLAYER) && (c1->type == Collider::Type::BOXMIDDLE))
	{
		MoveBox(app->player->playerDirection());

		
	}

	if ((c1->type == Collider::Type::BOX) && (!c2->type == Collider::Type::PLAYER))
	{
		if (c1 == collBoxDown)
		{
			if (collBoxUp->Intersects({ (int)app->player->positionX, (int)app->player->positionY, 24, 24 }))
			{
				app->player->playerCanMove[1] = false;
			}
		}
		else if (c1 == collBoxUp)
		{
			if (collBoxDown->Intersects({ (int)app->player->positionX, (int)app->player->positionY, 24, 24 }))
			{
				app->player->playerCanMove[0] = false;
			}
		}
		else if (c1 == collBoxLeft)
		{
			if (collBoxRight->Intersects({ (int)app->player->positionX, (int)app->player->positionY, 24, 24 }))
			{
				app->player->playerCanMove[2] = false;
			}
		}
		else if (c1 == collBoxRight)
		{
			if (collBoxLeft->Intersects({ (int)app->player->positionX, (int)app->player->positionY, 24, 24 }))
			{
				app->player->playerCanMove[3] = false;
			}
		}

	}
	
}
