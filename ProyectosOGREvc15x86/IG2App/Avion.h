#pragma once
#include "IG2ApplicationContext.h"
#include "AspasMolino.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

class Avion {
public:
	Avion(Ogre::SceneManager* sM, Ogre::SceneNode* node);
	void giraAspasAvion(float ang);

private:
	void transformAvion();


	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* cuerpoNode = nullptr;
	Ogre::SceneNode* alaINode = nullptr;
	Ogre::SceneNode* alaDNode = nullptr;
	Ogre::SceneNode* frenteNode = nullptr;
	Ogre::SceneNode* pilotoNode = nullptr;

	AspasMolino* aspasMolinoI = nullptr;
	AspasMolino* aspasMolinoD = nullptr;
};

