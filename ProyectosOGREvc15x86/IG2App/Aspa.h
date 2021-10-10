#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"

using namespace Ogre;

class Aspa : public EntityIG {
public:
	Aspa(int index, Ogre::SceneNode* node);

	Ogre::SceneNode* getNode();
private:
	void transformaAspa();

	int aspaIndex;
	Ogre::SceneNode* tableroNode = nullptr;
	Ogre::SceneNode* adornoNode = nullptr;
};

