#ifndef __FADETOBLACK_H__
#define __FADETOBLACK_H__

#include "App.h"
#include "Module.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class FadeToBlack : public Module
{
public:


	FadeToBlack(bool startEnabled);

	// Destructor
	virtual ~FadeToBlack();

	// Called before render is available
	bool Awake(pugi::xml_node&) override;

	// Called before the first frame
	bool Start() override;

	// Called each loop iteration
	bool Update(float dt) override;

	// Called each loop iteration
	bool PostUpdate() override;

	bool Fade(Module* moduleToDisable, Module* moduleToEnable, float frames);

	bool FadeNoModules(float frames, int level);

	// Called before quitting
	virtual bool CleanUp() override;

private:

	enum Fade_Step
	{
		NONE,
		TO_BLACK,
		FROM_BLACK
	} currentStep = Fade_Step::NONE;

	// A frame count system to handle the fade time and ratio
	Uint32 frameCount = 0;
	Uint32 maxFadeFrames = 0;
	int futureLevel;

	// The rectangle of the screen, used to render the black rectangle
	SDL_Rect screenRect;

	// The modules that should be switched after the first step
	Module* moduleToEnable = nullptr;
	Module* moduleToDisable = nullptr;
};

#endif