#include "App.h"
#include "FadeToBlack.h"

#include "Window.h"
#include "Render.h"
#include "Player.h"
#include "Collisions.h"
#include "LevelManager.h"
#include "BoxManager.h"
#include "SDL/include/SDL_render.h"
#include "Log.h"



FadeToBlack::FadeToBlack(bool startEnabled) : Module(startEnabled)
{
	
}

FadeToBlack::~FadeToBlack()
{

}

bool FadeToBlack::Awake(pugi::xml_node&)
{
	return true;
}

bool FadeToBlack::Start()
{
	LOG("Preparing Fade Screen");

	screenRect = { 0, 0, (int)(app->win->width * app->win->scale), (int)(app->win->height * app->win->scale) };

	SDL_SetRenderDrawBlendMode(app->render->renderer, SDL_BLENDMODE_BLEND);
	return true;
}

bool FadeToBlack::Update(float dt)
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) return true;

	if (currentStep == Fade_Step::TO_BLACK)
	{
		++frameCount;
		if (frameCount >= maxFadeFrames)
		{
			app->levelManager->lvlChange(futureLevel);

			currentStep = Fade_Step::FROM_BLACK;
			if (futureLevel == 5)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl1();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
			}
			else if (futureLevel == 6)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl2();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = 48;
				app->player->positionY = 72;
			}
			else if (futureLevel == 7)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl3();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 3);
			}
			else if (futureLevel == 8)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl4();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 4);
			}
			else if (futureLevel == 9)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl5();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 3);
				app->player->positionY = (24 * 2);
			}
			else if (futureLevel == 10)
			{
				app->boxManager->Enable();
				app->boxManager->InitializeLvl6();
				app->player->Enable();
				app->collisions->Enable();
				app->player->positionX = (24 * 9);
				app->player->positionY = (24 * 4);
			}
			app->levelManager->framesCounter = 0;
		}
	}
	else
	{
		--frameCount;
		if (frameCount <= 0)
		{
			currentStep = Fade_Step::NONE;
		}
	}

	return true;
}

bool FadeToBlack::PostUpdate()
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) return true;

	float fadeRatio = (float)frameCount / (float)maxFadeFrames;

	// Render the black square with alpha on the screen
	SDL_SetRenderDrawColor(app->render->renderer, 0, 0, 0, (Uint8)(fadeRatio * 255.0f));
	SDL_RenderFillRect(app->render->renderer, &screenRect);

	return true;
}

bool FadeToBlack::Fade(Module* moduleToDisable, Module* moduleToEnable, float frames)
{
	bool ret = false;

	// If we are already in a fade process, ignore this call
	if (currentStep == Fade_Step::NONE)
	{
		currentStep = Fade_Step::TO_BLACK;
		frameCount = 0;
		maxFadeFrames = frames;

		// L10: DONE 1: Keep track of the modules received in FadeToBlack()
		this->moduleToDisable = moduleToDisable;
		this->moduleToEnable = moduleToEnable;

		ret = true;
	}

	return ret;
}

bool FadeToBlack::FadeNoModules(float frames, int level)
{
	bool ret = false;

	// If we are already in a fade process, ignore this call
	if (currentStep == Fade_Step::NONE)
	{
		currentStep = Fade_Step::TO_BLACK;
		frameCount = 0;
		maxFadeFrames = frames;
		futureLevel = level;

		


		ret = true;
	}
	return ret;
}

bool FadeToBlack::CleanUp()
{
	return true;
}
