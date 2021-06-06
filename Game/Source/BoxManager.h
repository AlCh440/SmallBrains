#ifndef __BOXMANAGER_H__
#define __BOXMANAGER_H__

#include "Module.h"
#include "Collider.h"
#include "PugiXml/src/pugixml.hpp"
#include "Box.h"

class BoxManager : public Module
{
public:

	BoxManager(bool startEnabled);

	virtual ~BoxManager();

	bool Start() override;

	bool Update(float dt) override;

	void playLvl(float dt);

	// Called before quitting
	bool CleanUp() override;

	void OnCollision(Collider* c1, Collider* c2) override;

	void InitializeLvl1();
	void InitializeLvl2();
	void InitializeLvl3();
	void InitializeLvl4();
	void InitializeLvl5();
	void InitializeLvl6();


	Box* box_01;
	Box* box_02;
	Box* box_03;
	Box* box_04;

};

#endif 
