#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreMeshManager.h>
#include "EntityIG.h"

class Plano : public EntityIG {

public:
	Plano(Ogre::SceneNode* node);

	Ogre::SceneNode* getmPlanoNode();
private:
	Ogre::SceneNode* mPlanoNode = nullptr;
	Ogre::Entity* plano = nullptr;
};

