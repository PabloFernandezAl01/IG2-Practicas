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

class Bomba : public EntityIG {

public:
	Bomba(Ogre::SceneNode* node);
	Ogre::SceneNode* getNode();

	void frameRendered(const Ogre::FrameEvent& evt);
	void configAnimation();

private:
	Ogre::Entity* bombaEnt = nullptr;
	Ogre::SceneNode* bombaNode = nullptr;

	Animation* anim = nullptr;
	AnimationState* animState = nullptr;

};

