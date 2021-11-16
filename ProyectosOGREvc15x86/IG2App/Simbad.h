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

class Simbad : public EntityIG
{
public:
	Simbad(Ogre::SceneNode* node);
	Ogre::SceneNode* getNode();

	void frameRendered(const Ogre::FrameEvent& evt);
	void arma(bool side);
	void arma();
	void cambiaEspada();
	void configAnimation();
	void receiveEvent(MessageType msgType, EntityIG* entidad);

	bool teclaPulsada(const OgreBites::KeyboardEvent& evt);
private:
	Ogre::Entity* simbadEnt = nullptr;

	Ogre::Entity* swordL = nullptr;
	Ogre::Entity* swordR = nullptr;

	bool side = false;
	bool dead = false;
	bool counting = false;
	Ogre::Real time;

	AnimationState* runBase = nullptr;
	AnimationState* runTop = nullptr;
	AnimationState* dance = nullptr;
	AnimationState* idleBase = nullptr;
	AnimationState* idleTop = nullptr;

	Animation* anim = nullptr;
	AnimationState* animState = nullptr;
};
