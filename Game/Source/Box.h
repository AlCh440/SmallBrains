#ifndef __BOX_H__
#define __BOX_H__
#include "Module.h"
#include "Textures.h"


class Box : public Module 
{
public:

	Box();

	virtual ~Box();


	// Called before the first frame
	bool Start() override;

	// Called each loop iteration
	bool Update(float dt) override; 

	// Called before quitting
	virtual bool CleanUp() override;

	int GetPos_X();
	int GetPos_Y();

	void SetPos_X(int pos);
	void SetPos_Y(int pos);

	int pos_x;
	int pos_y;

	SDL_Texture* spriteSheet;
};

#endif 