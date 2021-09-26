#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "RotorDron.h"

class BrazoDron {
public:
	BrazoDron(Ogre::SceneManager* sM, Ogre::SceneNode* node, int numAspas, int indexBrazo);

	void transformBrazoDron();
	void giraAspas(float ang);
	Ogre::SceneNode* getmNode();
private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* cilindro = nullptr;

	RotorDron* rotorDron = nullptr;
	int indexBrazo;

};

