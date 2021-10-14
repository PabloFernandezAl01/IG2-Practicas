#pragma once
#include "IG2ApplicationContext.h"
#include "AspasMolino.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"

class Avion : public EntityIG{
public:
	Avion(Ogre::SceneNode* node);
	void giraAspasAvion(float ang);
	Ogre::SceneNode* getNode();

private:
	void transformAvion();

	Ogre::SceneNode* cuerpoNode = nullptr;
	Ogre::SceneNode* alaINode = nullptr;
	Ogre::SceneNode* alaDNode = nullptr;
	Ogre::SceneNode* frenteNode = nullptr;
	Ogre::SceneNode* pilotoNode = nullptr;

	Ogre::SceneNode* nodoFicticioAlaI = nullptr;
	Ogre::SceneNode* nodoFicticioAlaD = nullptr;

	AspasMolino* aspasMolinoI = nullptr;
	AspasMolino* aspasMolinoD = nullptr;
};

