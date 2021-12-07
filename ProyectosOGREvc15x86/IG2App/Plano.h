#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreCameraMan.h>
#include <OgreMeshManager.h>
#include "EntityIG.h"
#include <OgreTimer.h>
#include <iostream>
#include <OgreMovablePlane.h>
#include <OgreRenderTargetListener.h>
#include <OgreRenderTexture.h>
#include <OgreTextureManager.h>
#include <OgreHardwarePixelBuffer.h>
#include <OgreSubEntity.h>
#include <OgreTechnique.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include "Carita.h"
using namespace Ogre;

class Plano : public EntityIG, public Ogre::Viewport::Listener, public RenderTargetListener {

public:
	Plano(Ogre::SceneNode* node, std::string entName, std::string materialName = "", Carita* cF = nullptr);

	Ogre::SceneNode* getNode();
	void receiveEvent(MessageType msgType, EntityIG* entidad);
	void frameRendered(const Ogre::FrameEvent& evt);
	void setReflejo(Ogre::Camera* cam);
	void setEspejo(Camera* cam);
private:
	Ogre::Entity* plano = nullptr;
	std::string entName_;
	Ogre::Camera* camRef = nullptr;
	Ogre::MovablePlane* mpRef = nullptr;


	Ogre::Camera* camRefEspejo = nullptr;
	Ogre::MovablePlane* mpRefEspejo = nullptr;

	Ogre::Real timeToChangeMaterial;
	bool canCount = false;
	Carita* carafeliz=nullptr;
	
};

