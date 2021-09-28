#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include "Aspa.h"

class AspasMolino {
public:
	AspasMolino(Ogre::SceneManager* sm, Ogre::SceneNode* node, int numAspas, int index);
	void giraAspasMolino(float ang);
	Ogre::SceneNode* getCilindroCentral();
	Ogre::SceneNode* getmNode();

private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* cilindroCentralNode = nullptr;
	Ogre::SceneNode* aspasNode = nullptr;
	
	Aspa** arrayAspas = nullptr;
	int numAspas;
	int indexAspasMolino;

	Ogre::SceneManager* msM;
};

