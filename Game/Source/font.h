#ifndef __MODULEFONTS_H__
#define __MODULEFONTS_H__

#include "Module.h"

#include "SDL\include\SDL_pixels.h"

#define MAX_FONTS 10
#define MAX_FONT_CHARS 256

struct SDL_Texture;

struct Font
{
	// Lookup table. All characters displayed in the same order as the texture
	char table[MAX_FONT_CHARS];

	// The font texture
	SDL_Texture* texture = nullptr;

	// Font setup data
	uint totalLength;
	uint rows, columns;
	uint char_w, char_h;
};

class Fonts : public Module
{
public:

	// Constructor
	Fonts(bool isEnabled);

	// Destructor
	~Fonts();

	bool Start() override;
	// Loads a font file from a texture
	// Returns a font index from the fonts array
	// Param texturePath	- The path to the texture file
	// Param characters		- The lookup table. All characters displayed in the same order as the texture
	// Param rows			- The amount of character rows in the texture
	int Load(const char* texturePath, const char* characters, uint rows = 1);

	// Removes a font by its index
	// Unloads the texture and removes it from the fonts array
	void UnLoad(int fontIndex);

	// Create a surface from text
	void DrawText(int x, int y, int fontIndex, const char* text) const;

	void DrawNumber(int x, int y, char i);

private:
	// An array to keep track and store all loaded fonts
	Font fonts[MAX_FONTS];

	SDL_Rect char_00;
	SDL_Rect char_01;
	SDL_Rect char_02;
	SDL_Rect char_03;
	SDL_Rect char_04;
	SDL_Rect char_05;
	SDL_Rect char_06;
	SDL_Rect char_07;
	SDL_Rect char_08;
	SDL_Rect char_09;

	SDL_Texture* font = nullptr;


};


#endif // __MODULEFONTS_H__