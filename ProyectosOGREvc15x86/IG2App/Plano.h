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
	Plano(Ogre::SceneNode* node, std::string entName, std::string materialName);

	Ogre::SceneNode* getNode();
	void receiveEvent(MessageType msgType, EntityIG* entidad);
private:
	Ogre::Entity* plano = nullptr;
	std::string entName_;
};

