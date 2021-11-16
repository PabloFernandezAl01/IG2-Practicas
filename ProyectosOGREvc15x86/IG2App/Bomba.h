#pragma once
#include "EntityIG.h"
#include "IG2ApplicationContext.h"
#include "AspasMolino.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"
#include <OgreTimer.h>
#include <OgreAnimationState.h>
#include <OgreAnimation.h>
#include <OgreKeyFrame.h>
#include <OgreParticleSystem.h>
#include <OgreParticleSystemManager.h>
#include <OgreParticleSystemRenderer.h>

class Bomba : public EntityIG {

public:
	Bomba(Ogre::SceneNode* node);
	Ogre::SceneNode* getNode();

	void frameRendered(const Ogre::FrameEvent& evt);
	void configAnimation();
	bool teclaPulsada(const OgreBites::KeyboardEvent& evt);
	void receiveEvent(MessageType msgType, EntityIG* entidad);

	void createParticleSystem();

private:
	Ogre::Entity* bombaEnt = nullptr;

	Ogre::SceneNode* nodoIntermedio = nullptr;

	Animation* anim = nullptr;
	AnimationState* animState = nullptr;

	ParticleSystem* pSystem = nullptr;
};

