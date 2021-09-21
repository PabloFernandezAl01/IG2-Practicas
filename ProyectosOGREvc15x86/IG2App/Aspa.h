#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

using namespace Ogre;

class Aspa {
public:
	Aspa(Ogre::SceneManager* sM, Ogre::SceneNode* node, int aspaIndex); 

	Ogre::SceneNode* getNode();
private:
	void transformaAspa();

	int aspaIndex = 0;
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* tableroNode = nullptr;
	Ogre::SceneNode* adornoNode = nullptr;
};

