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

class Simbad : public EntityIG
{
public:
	Simbad(Ogre::SceneNode* node);
private:
	Ogre::Entity* ent = nullptr;
	Ogre::SceneNode* mSinbadNode = nullptr;
};

