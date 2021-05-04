#include "App.h"
#include "Player.h"
#include "Textures.h"
#include "Input.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Box.h"
#include "LevelManager.h"

#include "Log.h"
#include "iostream"




Player::Player() //													Modifty the pushbacks and speed!!!!!!!!!!!!!!!!!!!!!!!!!
{
	// Still

	StillRightAnim.PushBack({ 5, 212, 64, 102 });

	StillRightAnim.loop = false;
	// move up
	upAnim.PushBack({ 5, 315, 64, 102 });
	upAnim.PushBack({ 75, 315, 64, 102 });
	upAnim.PushBack({ 145, 315, 64, 102 });
	upAnim.PushBack({ 145, 315, 64, 102 });
	upAnim.PushBack({ 215, 315, 64, 102 });
	upAnim.PushBack({ 285, 315, 64, 102 });
	upAnim.PushBack({ 355, 315, 64, 102 });
	upAnim.PushBack({ 425, 315, 64, 102 });

	upAnim.loop = false;
	upAnim.speed = 0.008f;

	// move down
	downAnim.PushBack({ 5, 5, 64, 95 });
	downAnim.PushBack({ 75, 5, 64, 95 });
	downAnim.PushBack({ 145, 5, 64, 95 });
	downAnim.PushBack({ 145, 5, 64, 95 });
	downAnim.PushBack({ 215, 5, 64, 95 });
	downAnim.PushBack({ 285, 5, 64, 95 });
	downAnim.PushBack({ 355, 5, 64, 95 });
	downAnim.PushBack({ 425, 5, 64, 95 });

	downAnim.loop = false;
	downAnim.speed = 0.008f;

	// move left
	leftAnim.PushBack({ 5, 104, 64, 102 });
	leftAnim.PushBack({ 75, 104, 64, 102 });
	leftAnim.PushBack({ 145, 104, 64, 102 });
	leftAnim.PushBack({ 145, 104, 64, 102 });
	leftAnim.PushBack({ 215, 104, 64, 102 });
	leftAnim.PushBack({ 285, 104, 64, 102 });
	leftAnim.PushBack({ 355, 104, 64, 102 });
	leftAnim.PushBack({ 425, 104, 64, 102 });

	leftAnim.loop = false;
	leftAnim.speed = 0.008f;

	// move right
	rightAnim.PushBack({ 5, 212, 64, 102 });
	rightAnim.PushBack({ 75, 212, 64, 102 });
	rightAnim.PushBack({ 145, 212, 64, 102 });
	rightAnim.PushBack({ 145, 212, 64, 102 });
	rightAnim.PushBack({ 215, 212, 64, 102 });
	rightAnim.PushBack({ 285, 212, 64, 102 });
	rightAnim.PushBack({ 355, 212, 64, 102 });
	rightAnim.PushBack({ 425, 212, 64, 102 });
	rightAnim.PushBack({ 5, 212, 64, 102 });


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
	
	spriteSheet = app->tex->Load("Assets/Textures/updatedSpritesheet.png");


	position_x = 0.0f;
	position_y = 0.0f;
	playerSteps = 0;
	direction = 1;
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
	if (move)
	{
		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		{
			direction = 3; // Left
			move = false;
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
		{
			direction = 4; // Right
			move = false;
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		{
			direction = 1; // Up
			move = false;
			upAnim.Reset();
			currentAnimation = &upAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		{
			direction = 2; // Down
			move = false;
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}
	else if ((moveAction < step) && (!move))
	{
		moveAction += 1;
		if (direction == 1)
		{
			position_y -= 0.2f;
		}
		else if (direction == 2)
		{
			position_y += 0.2f;
		}
		else if (direction == 3)
		{
			position_x -= 0.2f;
		}
		else if (direction == 4)
		{
			position_x += 0.2f;
			
		}
	}
	else if (moveAction >= step)
	{
		move = true;
		moveAction = 0;
	}
	// If no up/down movement detected, set the current animation back to idle

	

	//collider->SetPos(position.x, position.y);																	COLLIDEEEEEEEER

	currentAnimation->Update();
	
	app->render->DrawTexture(spriteSheet, position_x, position_y, &currentAnimation->GetCurrentFrame());
	
	
	

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

/*void Player::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		App->audio->PlayFx(explosionFx);

		destroyed = true;
	}
}																			COLLIDEEEEEEEEEERS!!!!!!!!!!!*/