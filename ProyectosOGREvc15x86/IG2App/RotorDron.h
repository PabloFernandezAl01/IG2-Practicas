#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "AspasMolino.h"

class RotorDron {
public:
	RotorDron(Ogre::SceneManager* sm, int numAspas);
	void transformRotorDron();
	void giraAspas(float ang);
private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* mEsferaNode = nullptr;
	Ogre::SceneNode* mHelicesNode = nullptr;

	AspasMolino* aspasMolino = nullptr;

	int numAspas;
};

