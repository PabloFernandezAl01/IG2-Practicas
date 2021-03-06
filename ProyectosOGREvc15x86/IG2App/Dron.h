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
class IG2App;

class Dron : public EntityIG {
public:
	Dron(Ogre::SceneNode* node, int numAspas, int numBrazos, const std::vector<Dron*>& miniDrones = std::vector<Dron*>(), const std::vector<Ogre::SceneNode*>& nodosDron = std::vector<Ogre::SceneNode*>());

	void giraAspas(float ang);
	Ogre::SceneNode* getNode();

	bool teclaPulsada(const OgreBites::KeyboardEvent& evt);
	void frameRendered(const Ogre::FrameEvent& evt);

	void receiveEvent(MessageType msgType, EntityIG* entidad);
	BrazoDron** getArrayBrazos();
	int getNumBrazos();

private:

	void dronCollision();

	Ogre::SceneNode* esfera = nullptr;
	Ogre::Entity* esferaEnt = nullptr;

	int numAspas, numBrazos;

	BrazoDron** arrayBrazos = nullptr;

	std::vector<Dron*> miniDrones;
	std::vector<Ogre::SceneNode*> nodosDron;

	Ogre::Timer* myTimer;
	Ogre::Real timeMoving;
	Ogre::Real timeRotating;
	int rndDirection;

	int timeToMove, timeToRotate;

	bool canMove = true;
};

