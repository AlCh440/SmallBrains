#include "App.h"

#include "Textures.h"
#include "Render.h"
#include "Font.h"

#include<string.h>
#include "Log.h"

Fonts::Fonts(bool isEnabled) : Module(isEnabled)
{
	

}

Fonts::~Fonts()
{

}

bool Fonts::Start()
{
	

	font = app->tex->Load("Assets/Font/counter_font.png");
	return true;
}

// Load new texture from file path
int Fonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if (texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = app->tex->Load(texture_path);

	if (tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for (; id < MAX_FONTS; ++id)
		if (fonts[id].texture == nullptr)
			break;

	if (id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	Font& font = fonts[id];

	font.texture = tex;
	font.rows = rows;

	// L9: DONE 1: Finish storing font data

	// totalLength ---	length of the lookup table
	// table ---------  All characters displayed in the same order as the texture
	// columns -------  Amount of chars per row of the texture
	// char_w --------	Width of each character
	// char_h --------	Height of each character

	strcpy_s(fonts[id].table, MAX_FONT_CHARS, characters);
	font.totalLength = strlen(characters);
	font.columns = fonts[id].totalLength / rows;

	uint tex_w, tex_h;
	app->tex->GetSize(tex, tex_w, tex_h);
	font.char_w = tex_w / font.columns;
	font.char_h = tex_h / font.rows;

	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void Fonts::UnLoad(int font_id)
{
	if (font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].texture != nullptr)
	{
		app->tex->UnLoad(fonts[font_id].texture);
		fonts[font_id].texture = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

void Fonts::DrawText(int x, int y, int font_id, const char* text) const
{
	if (text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].texture == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect spriteRect;
	uint len = strlen(text);

	spriteRect.w = font->char_w;
	spriteRect.h = font->char_h;

	for (uint i = 0; i < len; ++i)
	{
		// L9: DONE 2: Find the character in the table and its position in the texture, then Blit
		uint charIndex = 0;

		// Find the location of the current character in the lookup table
		for (uint j = 0; j < font->totalLength; ++j)
		{
			if (font->table[j] == text[i])
			{
				charIndex = j;
				break;
			}
		}

		// Retrieve the position of the current character in the sprite
		spriteRect.x = spriteRect.w * (charIndex % font->columns);
		spriteRect.y = spriteRect.h * (charIndex / font->columns);

		app->render->DrawTexture(font->texture, x, y, &spriteRect);

		// Advance the position where we blit the next character
		x += spriteRect.w;
	}
}

void Fonts::DrawNumber(int x, int y, char i)
{
	if (i == '48')	app->render->DrawTexture(font, x, y, &char_00);
	else if (i == '49') app->render->DrawTexture(font, x, y, &char_01);
	else if (i == '50') app->render->DrawTexture(font, x, y, &char_02);
	else if (i == '51') app->render->DrawTexture(font, x, y, &char_03);
	else if (i == '52') app->render->DrawTexture(font, x, y, &char_04);
	else if (i == '53') app->render->DrawTexture(font, x, y, &char_05);
	else if (i == '54') app->render->DrawTexture(font, x, y, &char_06);
	else if (i == '55') app->render->DrawTexture(font, x, y, &char_07);
	else if (i == '56') app->render->DrawTexture(font, x, y, &char_08);
	else if (i == '57') app->render->DrawTexture(font, x, y, &char_09);


}