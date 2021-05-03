#include "App.h"
#include "Player.h"
#include "Textures.h"
#include "Input.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Log.h"
#include "iostream"




Player::Player() //													Modifty the pushbacks and speed!!!!!!!!!!!!!!!!!!!!!!!!!
{
	// Still
	StillUpAnim.PushBack({ 5, 320, 64, 102 });
	StillDownAnim.PushBack({ 5, 5, 64, 93 });
	StillLeftAnim.PushBack({ 5, 104, 64, 102 });
	StillRightAnim.PushBack({ 5, 212, 64, 102 });

	// move upwards
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 5, 315, 64, 102 });
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 75, 315, 64, 102 });
	for (int i = 0; i < 2; i++) upAnim.PushBack({ 145, 315, 64, 102 });
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 145, 315, 64, 102 });
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 215, 315, 64, 102 });
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 285, 315, 64, 102 });
	for (int i = 0; i < 2; i++) upAnim.PushBack({ 355, 315, 64, 102 });
	for (int i = 0; i < 2; i++)	upAnim.PushBack({ 425, 315, 64, 102 });

	
	

	upAnim.loop = false;
	upAnim.speed = 1.0f;

	// Move down
	downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;

	// move left
	leftAnim.PushBack({ });
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;

	currentAnimation = &StillUpAnim;
	playerStill = { 5, 5, 54, 93 };
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

bool Player::PreUpdate()
{
	return true;
}

bool Player::Update(float dt)
{
	if (move)
	{
		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		{
			direction = 3; // Left
			move = false;
			currentAnimation = &leftAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		{
			direction = 4; // Right
			move = false;
			currentAnimation = &rightAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		{
			direction = 1; // Up
			move = false;
			currentAnimation = &upAnim;
		}

		if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
		{
			direction = 2; // Down
			move = false;
			currentAnimation = &downAnim;
		}
	}
	else if ((moveAction < step) && (!move))
	{
		moveAction++;
		if (direction == 1) position_y -= 1;
		else if (direction == 2) position_y += 1;
		else if (direction == 3) position_x -= 1;
		else if (direction == 4) position_x += 1;
	}
	else if (moveAction == step)
	{
		move = true;
		moveAction = 0;
	}

	// If no up/down movement detected, set the current animation back to idle

	

	//collider->SetPos(position.x, position.y);																	COLLIDEEEEEEEER

	currentAnimation->Update();
	
	app->render->DrawTexture(spriteSheet, position_x, position_y, &currentAnimation->GetCurrentFrame());
	/*if (currentAnimation == &idleAnim)
	{
		app->render->DrawTexture(spriteSheet, position_x, position_y, upAnim.frames);
	}
	else
	{
		app->render->DrawTexture(spriteSheet, position_x, position_y, &playerStill, 1.0f);
	}*/
	
	

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