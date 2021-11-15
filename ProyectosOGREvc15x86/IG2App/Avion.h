#pragma once
#include "IG2ApplicationContext.h"
#include "AspasMolino.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"
#include <OgreTimer.h>
#include <OgreBillboard.h>
#include <OgreBillboardSet.h>
#include <OgreParticleSystem.h>
#include <OgreParticleSystemManager.h>
#include <OgreParticleSystemRenderer.h>
#include <OgreBillboardChain.h>
#include <OgreRibbonTrail.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Avion : public EntityIG{
public:
	Avion(Ogre::SceneNode* node);
	void giraAspasAvion(float ang);
	Ogre::SceneNode* getNode();

	bool teclaPulsada(const OgreBites::KeyboardEvent& evt);
	void frameRendered(const Ogre::FrameEvent& evt);

	void receiveEvent(MessageType msgType, EntityIG* entidad);
	AspasMolino* getAspaMolinoI() { return aspasMolinoI; }
	AspasMolino* getAspaMolinoD() { return aspasMolinoD; }

	void create10PointsBillBoard();
	void createRibbonTrail();
	void createExplosionSystem();

	void cazaDrones(const Ogre::FrameEvent& evt);
	void escenaAgua(const Ogre::FrameEvent& evt);

private:
	void transformAvion();

	Ogre::SceneNode* nodoIntermedio = nullptr;
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
	Ogre::Real explosionTime;
	int rndDirection;

	bool canMove = true;
	bool isExploding = false;

	BillboardSet* bbSet = nullptr;
	Billboard* bb = nullptr;

	ParticleSystem* pSystem = nullptr;
	ParticleSystem* explosionSystem = nullptr;
};

