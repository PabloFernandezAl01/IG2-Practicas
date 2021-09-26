#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "BrazoDron.h"
#include "RotorDron.h"

class Dron {
public:
	Dron(Ogre::SceneManager* sM, int numAspas, int numBrazos);

	void giraAspas(float ang);
private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* esfera = nullptr;

	int numAspas, numBrazos;

	BrazoDron** arrayBrazos = nullptr;
};

