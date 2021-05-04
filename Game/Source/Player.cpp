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




Player::Player() //													Modifty the pushbacks and speed!!!!!!!!!!!!!!!!!!!!!!!!!
{
	// Still

	StillRightAnim.PushBack({ 5, 212, 64, 102 });

	StillRightAnim.loop = false;
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
	upAnim.speed = 0.008f;

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
	downAnim.speed = 0.008f;

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
	leftAnim.speed = 0.008f;

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
	rightAnim.speed = 0.008f;

	// Move down
	
	

	// move left
	
	
	currentAnimation = &StillRightAnim;
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


	position_x = 6.0f;
	position_y = 2.0f;
	playerSteps = 0;
	direction = 1;
	stepCount = 0;
	//collider = app->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

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
	if (app->levelManager->Getlvl() == 1)
	{
		if (move)
		{
			if ((app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN) && (position_x - 24 >= 0))
			{
				direction = 3; // Left
				move = false;
				leftAnim.Reset();
				currentAnimation = &leftAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) && (position_x + 24 <= 264))
			{
				direction = 4; // Right
				move = false;
				rightAnim.Reset();
				currentAnimation = &rightAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN) && (position_y - 24 >= 0))
			{
				direction = 1; // Up
				move = false;
				upAnim.Reset();
				currentAnimation = &upAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN) && (position_y + 48 <= 264))
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
				position_y -= 0.1f;
			}
			else if (direction == 2)
			{
				position_y += 0.1f;
			}
			else if (direction == 3)
			{
				position_x -= 0.1f;
			}
			else if (direction == 4)
			{
				position_x += 0.1f;

			}
		}
		else if (moveAction >= step)
		{
			move = true;
			moveAction = 0;
		}

		app->collisions->AddCollider({ (int)position_x, (int)position_y, 24, 24 }, Collider::Type::PLAYER, this);

		//app->collisions->AddCollider({ (int)position_x + 24, (int)position_y, 24, 24 }, Collider::Type::NEAR, this);
		//app->collisions->AddCollider({ (int)position_x - 24, (int)position_y, 24, 24 }, Collider::Type::NEAR, this);
		//app->collisions->AddCollider({ (int)position_x, (int)position_y - 24, 24, 24 }, Collider::Type::NEAR, this);
		//app->collisions->AddCollider({ (int)position_x, (int)position_y + 24, 24, 24 }, Collider::Type::NEAR, this);

		//collider->SetPos(position.x, position.y);	

		currentAnimation->Update();

		app->render->DrawTexture(spriteSheet, position_x, position_y, &currentAnimation->GetCurrentFrame());



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


void Player::OnCollision(Collider* c1, Collider* c2)
{
	{
	}
}																		