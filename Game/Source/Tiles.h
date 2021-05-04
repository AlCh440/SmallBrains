#ifndef __TILES_H__
#define __TILES_H__


#include "Module.h"
#include "Textures.h"
#include "Render.h"

struct SDL_Texture;
struct SDL_Rect;
struct Collider;

class Tiles : public Module
{
public:


	Tiles();

	// Destructor
	virtual ~Tiles();


	// Called before the first frame
	bool Start();

	void DrawArray(int* arr, int row, int col);

	// Called before quitting
	virtual bool CleanUp();

	SDL_Texture* spriteSheet;
	SDL_Rect floor_01;
	SDL_Rect floor_02;
	SDL_Rect wall_01;
	SDL_Rect wall_02;

};
#endif // __TILES