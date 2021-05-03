#include "App.h"
#include "Player.h"
#include "Textures.h"
#include "Input.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Log.h"




Player::Player() //													Modifty the pushbacks and speed!!!!!!!!!!!!!!!!!!!!!!!!!
{
	// idle animation - just one sprite
	idleAnim.PushBack({ 66, 1, 32, 14 });

	// move upwards
	upAnim.PushBack({ 100, 1, 32, 14 });
	upAnim.PushBack({ 132, 0, 32, 14 });
	upAnim.loop = false;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;

	// move left
	leftAnim.PushBack({ });
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;
}

Player::~Player()
{

}

bool Player::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	
	texture = app->tex->Load("Assets/Textures/test.png");
	currentAnimation = &idleAnim;

	position_x = 150;
	position_y = 120;

	//collider = app->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	return ret;
}

bool Player::Update()
{
	
	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		position_x -= step;
	}

	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		position_x += step;
	}

	if (app->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		position_y -= step;
	}

	if (app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		position_y += step;
	}

	
	/*	if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		} */


	// If no up/down movement detected, set the current animation back to idle
	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE)
		currentAnimation = &idleAnim;

	//collider->SetPos(position.x, position.y);																	COLLIDEEEEEEEER

	currentAnimation->Update();

	return true;
}

bool Player::PostUpdate()
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