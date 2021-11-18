#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreMeshManager.h>
#include "EntityIG.h"
#include <OgreTimer.h>
#include <iostream>

class Plano : public EntityIG {

public:
	Plano(Ogre::SceneNode* node, std::string entName, std::string materialName = "");

	Ogre::SceneNode* getNode();
	void receiveEvent(MessageType msgType, EntityIG* entidad);
	void frameRendered(const Ogre::FrameEvent& evt);
private:
	Ogre::Entity* plano = nullptr;
	std::string entName_;

	Ogre::Real timeToChangeMaterial;
	bool canCount = false;
};

