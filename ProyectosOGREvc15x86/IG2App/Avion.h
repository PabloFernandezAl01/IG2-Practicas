#pragma once
#include "IG2ApplicationContext.h"
#include "AspasMolino.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"
#include <OgreTimer.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Avion : public EntityIG{
public:
	Avion(Ogre::SceneNode* node);
	void giraAspasAvion(float ang);
	Ogre::SceneNode* getNode();

	bool keyPressed(const OgreBites::KeyboardEvent& evt);
	void frameRendered(const Ogre::FrameEvent& evt);

	void receiveEvent(MessageType msgType, EntityIG* entidad);
	AspasMolino* getAspaMolinoI() { return aspasMolinoI; }
	AspasMolino* getAspaMolinoD() { return aspasMolinoD; }

private:
	void transformAvion();

	Ogre::SceneNode* cuerpoNode = nullptr;
	Ogre::SceneNode* alaINode = nullptr;
	Ogre::SceneNode* alaDNode = nullptr;
	Ogre::SceneNode* frenteNode = nullptr;
	Ogre::SceneNode* pilotoNode = nullptr;

	Ogre::SceneNode* nodoFicticioAlaI = nullptr;
	Ogre::SceneNode* nodoFicticioAlaD = nullptr;
	Ogre::Entity* alaIEnt = nullptr;
	Ogre::Entity* alaDEnt = nullptr;

	AspasMolino* aspasMolinoI = nullptr;
	AspasMolino* aspasMolinoD = nullptr;

	Ogre::Timer* myTimer;
	Ogre::Real timeMoving;
	Ogre::Real timeRotating;
	int rndDirection;
};

