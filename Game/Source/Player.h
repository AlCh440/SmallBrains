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
	bool Awake(pugi::xml_node&) override;

	// Called before the first frame
	bool Start() override;

	// Called each loop iteration
	bool LevelStart(int level);

	// Called each loop iteration
	bool Update(float dt) override;

	// Called each loop iteration
	bool PostUpdate() override;


	// Called before quitting
	virtual bool CleanUp() override;
	

	//Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;
	

	// Position of the player in the map
	float position_x;
	float position_y;
	bool move;
	int direction;
	int moveAction;
	int step = 480;
	int framesPerSprite = 14;
	int stepCount;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* spriteSheet = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation StillAnim;
	Animation upAnim;
	Animation downAnim;
	Animation leftAnim;
	Animation rightAnim;
	SDL_Rect playerStill;

	// The player's collider
	//Collider* collider = nullptr;

	// The counter of the player Steps
	int playerSteps;

	// Sound effects indices								???????????????????????????????????
};

#endif