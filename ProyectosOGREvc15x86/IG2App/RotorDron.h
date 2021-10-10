#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "AspasMolino.h"
#include "EntityIG.h"

class RotorDron : public EntityIG{
public:
	RotorDron(Ogre::SceneNode* mNode,  int numAspas, int index);
	void transformRotorDron();
	void giraAspas(float ang);

	Ogre::SceneNode* getmNode();
private:
	Ogre::SceneNode* mEsferaNode = nullptr;
	Ogre::SceneNode* mHelicesNode = nullptr;

	AspasMolino* aspasMolino = nullptr;

	int numAspas;
	int indexRotorDron;
};

