#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "RotorDron.h"
#include "EntityIG.h"

class BrazoDron : public EntityIG{
public:
	BrazoDron(Ogre::SceneNode* node, int numAspas, int index);

	void transformBrazoDron();
	void giraAspas(float ang);
	Ogre::SceneNode* getmNode();
	Ogre::SceneNode* getCilindroNode();
	RotorDron* getRotorDron();

private:
	Ogre::SceneNode* cilindro = nullptr;

	RotorDron* rotorDron = nullptr;
	int indexBrazo;

};

