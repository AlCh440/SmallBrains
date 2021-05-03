#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "Module.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Player : public Module
{
public:


	Player();

	// Destructor
	virtual ~Player();

	// Called before render is available
	//bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	//bool PreUpdate();

	// Called each loop iteration
	bool Update();

	// Called each loop iteration
	bool PostUpdate();


	// Called before quitting
	//virtual bool CleanUp();
	/*

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;
	*/

	// Position of the player in the map
	int position_x;
	int position_y;

	// The speed in which we move the player (pixels per frame)       NEED TO CALCULATE
	int step = 1;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
	Animation leftAnim;
	Animation rightAnim;

	// The player's collider
	Collider* collider = nullptr;

	// A counter of the player Steps
	int playerSteps;

	// Sound effects indices								???????????????????????????????????
};

#endif