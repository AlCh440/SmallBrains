#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "Module.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Player : public Module
{
public:


	Player(bool startEnabled);

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
	
	bool isPlayerMoving();

	int playerDirection();

	void drawPlayer();

	//Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;
	
	void DisablePlayer()
	{
		if (isEnabled)
		{
			isEnabled = false;
		}
	}
	// Position of the player in the map
	int positionX;
	int positionY;
	bool move;
	bool playerPushing[4];
	int direction;
	int moveAction;
	int step = 8;
	int framesPerSprite = 8;
	int stepCount;
	bool playerCanMove[4];
	bool afterGame;
	bool count;
	SDL_Rect playerhitbox;

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
	Animation upPushAnim;
	Animation downPushAnim;
	Animation leftPushAnim;
	Animation rightPushAnim;

	// The player's collider
	//Collider* collider = nullptr;
	Collider* collPlayer = nullptr;
	Collider* collPlayerLeft = nullptr;
	Collider* collPlayerRight = nullptr;
	Collider* collPlayerDown = nullptr;
	Collider* collPlayerUp = nullptr;

	Collider* collPlayerFarLeft = nullptr;
	Collider* collPlayerFarRight= nullptr;
	Collider* collPlayerFarUp = nullptr;
	Collider* collPlayerFarDown = nullptr;

	// The counter of the player Steps
	int playerSteps;

	// Sound effects indices								???????????????????????????????????
};

#endif