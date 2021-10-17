#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "BrazoDron.h"
#include "RotorDron.h"
#include "EntityIG.h"
#include <OgreTimer.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Dron : public EntityIG {
public:
	Dron(Ogre::SceneNode* node, int numAspas, int numBrazos);

	void giraAspas(float ang);
	Ogre::SceneNode* getNode();

	bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
private:
	Ogre::SceneNode* esfera = nullptr;

	int numAspas, numBrazos;

	BrazoDron** arrayBrazos = nullptr;

	Ogre::Timer* myTimer;
	Ogre::Real timeMoving;
	Ogre::Real timeRotating;
	int rndDirection;
};

