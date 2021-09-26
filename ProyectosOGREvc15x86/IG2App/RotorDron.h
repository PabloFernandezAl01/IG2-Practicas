#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "AspasMolino.h"

class RotorDron {
public:
	RotorDron(Ogre::SceneManager* sm, Ogre::SceneNode* mNode,  int numAspas, int iRD);
	void transformRotorDron();
	void giraAspas(float ang);

	Ogre::SceneNode* getmNode();
private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* mEsferaNode = nullptr;
	Ogre::SceneNode* mHelicesNode = nullptr;

	AspasMolino* aspasMolino = nullptr;

	int numAspas;
	int indexRotorDron;
};

