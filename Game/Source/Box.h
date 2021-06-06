#ifndef __BOX_H__
#define __BOX_H__
#include "Module.h"
#include "Textures.h"


class Box : public Module 
{
public:

	Box(bool startEnabled);

	virtual ~Box();


	// Called before the first frame
	bool Start() override;

	// Called each loop iteration
	bool Update(float dt) override;

	// Called before quitting
	virtual bool CleanUp() override;

	void MoveBox(int direction);

	int GetPos_X();
	int GetPos_Y();

	void SetPos_X(int pos);
	void SetPos_Y(int pos);

	int posX;
	int posY;
	bool move;

	SDL_Texture* spriteSheet;
	SDL_Rect box;

	Collider* collBox = nullptr;

	Collider* collBoxLeft = nullptr;
	Collider* collBoxRight = nullptr;
	Collider* collBoxUp = nullptr;
	Collider* collBoxDown = nullptr;


	void OnCollision(Collider* c1, Collider* c2);
};

#endif 