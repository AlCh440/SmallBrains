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

	StillAnim.PushBack({ 1, 51, 24, 24 });

	StillAnim.loop = false;

	// move up
	upAnim.PushBack({ 1, 76, 24, 24 });
	upAnim.PushBack({ 26, 76, 24, 24 });
	upAnim.PushBack({ 51, 76, 24, 24 });
	upAnim.PushBack({ 76, 76, 24, 24 });
	upAnim.PushBack({ 101, 76, 24, 24 });
	upAnim.PushBack({ 126, 76, 24, 24 });
	upAnim.PushBack({ 151, 76, 24, 24 });
	upAnim.PushBack({ 176, 76, 24, 24 });
	upAnim.PushBack({ 1, 76, 24, 24 });

	upAnim.loop = false;
	upAnim.speed = 1.f;

	// move down
	downAnim.PushBack({ 1, 1, 24, 24 });
	downAnim.PushBack({ 26, 1, 24, 24 });
	downAnim.PushBack({ 51, 1, 24, 24 });
	downAnim.PushBack({ 76, 1, 24, 24 });
	downAnim.PushBack({ 101, 1, 24, 24 });
	downAnim.PushBack({ 126, 1, 24, 24 });
	downAnim.PushBack({ 151, 1, 24, 24 });
	downAnim.PushBack({ 176, 1, 24, 24 });
	downAnim.PushBack({ 1, 1, 24, 24 });

	downAnim.loop = false;
	downAnim.speed = 1.f;

	// move left
	leftAnim.PushBack({ 1, 26, 24, 24 });
	leftAnim.PushBack({ 26, 26, 24, 24 });
	leftAnim.PushBack({ 51, 26, 24, 24 });
	leftAnim.PushBack({ 76, 26, 24, 24 });
	leftAnim.PushBack({ 101, 26, 24, 24 });
	leftAnim.PushBack({ 126, 26, 24, 24 });
	leftAnim.PushBack({ 151, 26, 24, 24 });
	leftAnim.PushBack({ 176, 26, 24, 24 });
	leftAnim.PushBack({ 1, 26, 24, 24 });

	leftAnim.loop = false;
	leftAnim.speed = 1.f;

	// move right
	rightAnim.PushBack({ 1, 51, 24, 24 });
	rightAnim.PushBack({ 26, 51, 24, 24 });
	rightAnim.PushBack({ 51, 51, 24, 24 });
	rightAnim.PushBack({ 76, 51, 24, 24 });
	rightAnim.PushBack({ 101, 51, 24, 24 });
	rightAnim.PushBack({ 126, 51, 24, 24 });
	rightAnim.PushBack({ 151, 51, 24, 24 });
	rightAnim.PushBack({ 176, 51, 24, 24 });
	rightAnim.PushBack({ 1, 51, 24, 24 });

	rightAnim.loop = false;
	rightAnim.speed = 1.f;
	
	// move up pushing
	upPushAnim.PushBack({ 1, 176, 24, 24 });
	upPushAnim.PushBack({ 26, 176, 24, 24 });
	upPushAnim.PushBack({ 51, 176, 24, 24 });
	upPushAnim.PushBack({ 76, 176, 24, 24 });
	upPushAnim.PushBack({ 101, 176, 24, 24 });
	upPushAnim.PushBack({ 126, 176, 24, 24 });
	upPushAnim.PushBack({ 151, 176, 24, 24 });
	upPushAnim.PushBack({ 176, 176, 24, 24 });
	upPushAnim.PushBack({ 1, 76, 24, 24 });

	upPushAnim.loop = false;
	upPushAnim.speed = 1.f;

	// move down pushing
	downPushAnim.PushBack({ 1, 101, 24, 24 });
	downPushAnim.PushBack({ 26, 101, 24, 24 });
	downPushAnim.PushBack({ 51, 101, 24, 24 });
	downPushAnim.PushBack({ 76, 101, 24, 24 });
	downPushAnim.PushBack({ 101, 101, 24, 24 });
	downPushAnim.PushBack({ 126, 101, 24, 24 });
	downPushAnim.PushBack({ 151, 101, 24, 24 });
	downPushAnim.PushBack({ 176, 101, 24, 24 });
	downPushAnim.PushBack({ 1, 1, 24, 24 });

	downPushAnim.loop = false;
	downPushAnim.speed = 1.f;

	// move left pushing
	leftPushAnim.PushBack({ 1, 151, 24, 24 });
	leftPushAnim.PushBack({ 26, 151, 24, 24 });
	leftPushAnim.PushBack({ 51, 151, 24, 24 });
	leftPushAnim.PushBack({ 76, 151, 24, 24 });
	leftPushAnim.PushBack({ 101, 151, 24, 24 });
	leftPushAnim.PushBack({ 126, 151, 24, 24 });
	leftPushAnim.PushBack({ 151, 151, 24, 24 });
	leftPushAnim.PushBack({ 176, 151, 24, 24 });
	leftPushAnim.PushBack({ 1, 26, 24, 24 });

	leftPushAnim.loop = false;
	leftPushAnim.speed = 1.f;
	
	// move right pushing
	rightPushAnim.PushBack({ 1, 126, 24, 24 });
	rightPushAnim.PushBack({ 26, 126, 24, 24 });
	rightPushAnim.PushBack({ 51, 126, 24, 24 });
	rightPushAnim.PushBack({ 76, 126, 24, 24 });
	rightPushAnim.PushBack({ 101, 126, 24, 24 });
	rightPushAnim.PushBack({ 126, 126, 24, 24 });
	rightPushAnim.PushBack({ 151, 126, 24, 24 });
	rightPushAnim.PushBack({ 176, 126, 24, 24 });
	rightPushAnim.PushBack({ 1, 51, 24, 24 });

	rightPushAnim.loop = false;
	rightPushAnim.speed = 1.f;

	for (int i = 0; i < 4; i++)
	{
		playerCanMove[i] = true;
	}
	
	currentAnimation = &StillAnim;
	move = true;
	moveAction = 0;
	positionX = 0;
	positionY = 0;
	count = true;
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

		afterGame = false;
		count = false;
		return true;
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
			if ((app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) && (playerCanMove[2] == true))
			{
				direction = 3; // Left
				move = false;
				leftAnim.Reset();
				leftPushAnim.Reset();
				if (playerPushing[2]) currentAnimation = &leftPushAnim;
				else currentAnimation = &leftAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) && (playerCanMove[3] == true))
			{
				direction = 4; // Right
				move = false;
				rightAnim.Reset();
				rightPushAnim.Reset();
				if (playerPushing[3]) currentAnimation = &rightPushAnim;
				else currentAnimation = &rightAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) && (playerCanMove[0] == true))
			{
				direction = 1; // Up
				move = false;
				upAnim.Reset();
				upPushAnim.Reset();
				if (playerPushing[0]) currentAnimation = &upPushAnim;
				else currentAnimation = &upAnim;
				stepCount++;
			}

			if ((app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) && (playerCanMove[1] == true))
			{
				direction = 2; // Down
				move = false;
				downAnim.Reset();
				downPushAnim.Reset();
				if (playerPushing[1]) currentAnimation = &downPushAnim;
				else currentAnimation = &downAnim;
				stepCount++;
			}
		}
		else if ((moveAction < step) && (!move))
		{
			moveAction += 1;
			if (direction == 1)
			{
				positionY -= 3;
			}
			else if (direction == 2)
			{
				positionY += 3;
			}
			else if (direction == 3)
			{
				positionX -= 3;
			}
			else if (direction == 4)
			{
				positionX += 3;

			}
		}
		else if (moveAction >= step)
		{
			if (!afterGame) {
				move = true;
				moveAction = 0;
			}
		}

		currentAnimation->Update();

		drawPlayer();

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
	for (int i = 0; i < 4; i++)
	{
		playerPushing[i] = false;
	}
	return true;
}

bool Player::CleanUp()
{

	app->collisions->RemoveCollider(collPlayer);
	app->collisions->RemoveCollider(collPlayerDown);
	app->collisions->RemoveCollider(collPlayerUp);
	app->collisions->RemoveCollider(collPlayerLeft);
	app->collisions->RemoveCollider(collPlayerRight);
	app->collisions->RemoveCollider(collPlayerFarLeft);
	app->collisions->RemoveCollider(collPlayerFarRight);
	app->collisions->RemoveCollider(collPlayerFarUp);
	app->collisions->RemoveCollider(collPlayerFarDown);



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

void Player::drawPlayer() 
{
	app->render->DrawTexture(spriteSheet, positionX, positionY, &currentAnimation->GetCurrentFrame());
}

void Player::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == Collider::Type::BOXMIDDLE)
	{
		if (c1 == collPlayerLeft)
		{
			playerPushing[2] = true;
		}
		else if (c1 == collPlayerRight)
		{
			playerPushing[3] = true;
		}
		else if (c1 == collPlayerUp)
		{
			playerPushing[0] = true;
		}
		else if (c1 == collPlayerDown)
		{
			playerPushing[1] = true;
		}
	}

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
	
	if ((c1->type == Collider::Type::NEAR) && (c2->type == Collider::Type::BOXMIDDLE))
	{
		Collider* c3;
		
		if (c1 == collPlayerLeft)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][Collider::Type::FAR] && c3->Intersects({ (int)positionX - 48, (int)positionY, 24, 24 }))
				{
					playerCanMove[2] = false;
				}
			}
			
		}
		else if (c1 == collPlayerRight)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][Collider::Type::FAR] && c3->Intersects({ (int)positionX + 48, (int)positionY, 24, 24 }))
				{
					playerCanMove[3] = false;
				}
			}
		}
		else if (c1 == collPlayerUp)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][Collider::Type::FAR] && c3->Intersects({ (int)positionX, (int)positionY - 48, 24, 24 }))
				{
					playerCanMove[0] = false;
				}
			}
		}
		else if (c1 == collPlayerDown)
		{
			for (uint k = 0; k < MAX_COLLIDERS; ++k)
			{
				// skip empty colliders
				if (app->collisions->colliders[k] == nullptr)
					continue;

				c3 = app->collisions->colliders[k];

				if (app->collisions->matrix[c3->type][Collider::Type::FAR] && c3->Intersects({ (int)positionX, (int)positionY + 48, 24, 24 }))
				{
					playerCanMove[1] = false;
				}
			}
		}
	}
}																		