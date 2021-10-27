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

class Simbad : public EntityIG
{
public:
	Simbad(Ogre::SceneNode* node);
	Ogre::SceneNode* getNode();

	void frameRendered(const Ogre::FrameEvent& evt);
private:
	Ogre::SceneNode* mSinbadNode = nullptr;
	AnimationState* runBase = nullptr;
	AnimationState* runTop = nullptr;
};

