#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "BrazoDron.h"
#include "RotorDron.h"
#include "EntityIG.h"

class Dron : public EntityIG{
public:
	Dron(Ogre::SceneNode* node, int numAspas, int numBrazos);

	void giraAspas(float ang);
	Ogre::SceneNode* getNode();
private:
	Ogre::SceneNode* esfera = nullptr;

	int numAspas, numBrazos;

	BrazoDron** arrayBrazos = nullptr;
};

