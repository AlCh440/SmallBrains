#include "App.h"
#include "Player.h"
#include "Textures.h"
#include "Input.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Collider.h"
#include "Box.h"
#include "LevelManager.h"
#include "Collisions.h"

#include "Log.h"
#include "iostream"



Player::Player(bool startEnabled) : Module(startEnabled) //	
{
	// Still
	playerhitbox = { (int)positionX, (int)positionY, 24, 24 };

	StillAnim.PushBack({ 1, 45, 14, 22});

	StillAnim.loop = false;

	// move up
	upAnim.PushBack({ 1, 68, 14, 22 });
	upAnim.PushBack({ 16, 68, 14, 22 });
	upAnim.PushBack({ 31, 68, 14, 22 });
	upAnim.PushBack({ 46, 68, 14, 22 });
	upAnim.PushBack({ 61, 68, 14, 22 });
	upAnim.PushBack({ 76, 68, 14, 22 });
	upAnim.PushBack({ 91, 68, 14, 22 });
	upAnim.PushBack({ 106, 68, 14, 22 });
	upAnim.PushBack({ 1, 68, 14, 22 });

	upAnim.loop = false;
	upAnim.speed = 0.2f;

	// move down
	downAnim.PushBack({ 1, 1, 14, 20 });
	downAnim.PushBack({ 16, 1, 14, 20 });
	downAnim.PushBack({ 31, 1, 14, 20 });
	downAnim.PushBack({ 46, 1, 14, 20 });
	downAnim.PushBack({ 61, 1, 14, 20 });
	downAnim.PushBack({ 76, 1, 14, 20 });
	downAnim.PushBack({ 91, 1, 14, 20 });
	downAnim.PushBack({ 106, 1, 14, 20 });
	downAnim.PushBack({ 1, 1, 14, 20 });

	downAnim.loop = false;
	downAnim.speed = 0.2f;

	// move left
	leftAnim.PushBack({ 1, 22, 14, 22 });
	leftAnim.PushBack({ 16, 22, 14, 22 });
	leftAnim.PushBack({ 31, 22, 14, 22 });
	leftAnim.PushBack({ 46, 22, 14, 22 });
	leftAnim.PushBack({ 61, 22, 14, 22 });
	leftAnim.PushBack({ 76, 22, 14, 22 });
	leftAnim.PushBack({ 91, 22, 14, 22 });
	leftAnim.PushBack({ 106, 22, 14, 22 });
	leftAnim.PushBack({ 1, 22, 14, 22 });

	leftAnim.loop = false;
	leftAnim.speed = 0.2f;

	// move right
	rightAnim.PushBack({ 1, 45, 14, 22 });
	rightAnim.PushBack({ 16, 45, 14, 22 });
	rightAnim.PushBack({ 31, 45, 14, 22 });
	rightAnim.PushBack({ 46, 45, 14, 22 });
	rightAnim.PushBack({ 61, 45, 14, 22 });
	rightAnim.PushBack({ 76, 45, 14, 22 });
	rightAnim.PushBack({ 91, 45, 14, 22 });
	rightAnim.PushBack({ 106, 45, 14, 22 });
	rightAnim.PushBack({ 1, 45, 14, 22 });

	rightAnim.loop = false;
	rightAnim.speed = 0.2f;

	for (int i = 0; i < 4; i++)
	{
		playerCanMove[i] = true;
	}
	
	currentAnimation = &StillAnim;
	move = true;
	moveAction = 0;
}

Player::~Player()
{

}

bool Player::Awake(pugi::xml_node& config)
{
	return true;
}

bool Player::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	
	spriteSheet = app->tex->Load("Assets/Textures/spriteSheet.png");


	positionX = 0.0f;
	positionY = 0.0f;
	playerSteps = 0;
	direction = 1;
	stepCount = 0;

	collPlayer = app->collisions->AddCollider({ (int)positionX, (int)positionY, 24, 24 }, Collider::Type::PLAYER, this);

	collPlayerRight = app->collisions->AddCollider({ (int)positionX + 24, (int)positionY, 24, 24 }, Collider::Type::NEAR, this);
	collPlayerLeft = app->collisions->AddCollider({ (int)positionX - 24, (int)positionY, 24, 24 }, Collider::Type::NEAR, this);
	collPlayerUp = app->collisions->AddCollider({ (int)positionX, (int)positionY - 24, 24, 24 }, Collider::Type::NEAR, this);
	collPlayerDown = app->collisions->AddCollider({ (int)positionX, (int)positionY + 24, 24, 24 }, Collider::Type::NEAR, this);

	collPlayerFarRight = app->collisions->AddCollider({ (int)positionX + 48, (int)positionY, 24, 24 }, Collider::Type::FAR, this);
	collPlayerFarLeft = app->collisions->AddCollider({ (int)positionX - 48, (int)positionY, 24, 24 }, Collider::Type::FAR, this);
	collPlayerFarUp = app->collisions->AddCollider({ (int)positionX, (int)positionY - 48, 24, 24 }, Collider::Type::FAR, this);
	collPlayerFarDown = app->collisions->AddCollider({ (int)positionX, (int)positionY + 48, 24, 24 }, Collider::Type::FAR, this);


	return ret;
}

bool Player::LevelStart(int level)
{
	if (level == 1) 
	{

	}
	return true;
}

bool Player::Update(float dt)
{	

		if (move)
		{
			if ((app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN) && (playerCanMove[2] == true))
			{
				direction = 3; // Left
				move = false;
				leftAnim.Reset();
				currentAnimation = &leftAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) && (playerCanMove[3] == true))
			{
				direction = 4; // Right
				move = false;
				rightAnim.Reset();
				currentAnimation = &rightAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) && (playerCanMove[0] == true))
			{
				direction = 1; // Up
				move = false;
				upAnim.Reset();
				currentAnimation = &upAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN) && (playerCanMove[1] == true))
			{
				direction = 2; // Down
				move = false;
				downAnim.Reset();
				currentAnimation = &downAnim;
				stepCount++;
			}
		}
		else if ((moveAction < step) && (!move))
		{
			moveAction += 1;
			if (direction == 1)
			{
				positionY -= 1.0f;
			}
			else if (direction == 2)
			{
				positionY += 1.0f;
			}
			else if (direction == 3)
			{
				positionX -= 1.0f;
			}
			else if (direction == 4)
			{
				positionX += 1.0f;

			}
		}
		else if (moveAction >= step)
		{
			move = true;
			moveAction = 0;
		}


		currentAnimation->Update();

		app->render->DrawTexture(spriteSheet, positionX + 6, positionY, &currentAnimation->GetCurrentFrame());

		collPlayer->SetPos(positionX, positionY);

		collPlayerLeft->SetPos(positionX - 24, positionY);
		collPlayerRight->SetPos(positionX + 24, positionY);
		collPlayerUp->SetPos(positionX, positionY - 24);
		collPlayerDown->SetPos(positionX, positionY + 24);

		collPlayerFarLeft->SetPos(positionX - 48, positionY);
		collPlayerFarRight->SetPos(positionX + 48, positionY);
		collPlayerFarUp->SetPos(positionX, positionY - 48);
		collPlayerFarDown->SetPos(positionX, positionY + 48);

		for (int i = 0; i < 4; i++)
		{
			playerCanMove[i] = true;
		}
	return true;
}

bool Player::PostUpdate()
{
	return true;
}

bool Player::CleanUp()
{
	return true;
}

bool Player::isPlayerMoving()
{
	return move;
}

int Player::playerDirection()
{
	return direction;
}


void Player::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == Collider::Type::WALL)
	{
		if (c1 == collPlayerLeft)
		{
			playerCanMove[2] = false;
		}
		else if (c1 == collPlayerRight)
		{
			playerCanMove[3] = false;
		}
		else if (c1 == collPlayerUp)
		{
			playerCanMove[0] = false;
		}
		else if (c1 == collPlayerDown)
		{
			playerCanMove[1] = false;
		}

	}
	
	/*if ((c1->type == Collider::Type::FAR) && (c2->type == Collider::Type::BOXMIDDLE))
	{
		Collider* c3;
		
		if (c1 == collPlayerFarLeft)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if ((c3->Intersects({ (int)positionX - 24, (int)positionY, 24, 24 })) && (c3->type == Collider::Type::BOXMIDDLE))
				{
					playerCanMove[2] = false;
				}
			}
			
		}
		else if (c1 == collPlayerFarRight)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][collPlayerRight->type] && c3->Intersects({ (int)positionX + 24, (int)positionY, 24, 24 }))
				{
					playerCanMove[3] = false;
				}
			}
		}
		else if (c1 == collPlayerFarUp)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][collPlayerUp->type] && c3->Intersects({ (int)positionX, (int)positionY - 24, 24, 24 }))
				{
					playerCanMove[0] = false;
				}
			}
		}
		else if (c1 == collPlayerFarDown)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][collPlayerDown->type] && c3->Intersects({ (int)positionX, (int)positionY + 24, 24, 24 }))
				{
					playerCanMove[1] = false;
				}
			}
		}
	}*/
}																		