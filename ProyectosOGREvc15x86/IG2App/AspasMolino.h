#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "EntityIG.h"
#include "Aspa.h"

class AspasMolino : public EntityIG{
public:
	AspasMolino(Ogre::SceneNode* node, int numAspas, int index);
	void giraAspasMolino(float ang);
	Ogre::SceneNode* getCilindroCentral();
	Ogre::SceneNode* getmNode();

private:
	Ogre::SceneNode* cilindroCentralNode = nullptr;
	Ogre::SceneNode* aspasNode = nullptr;
	
	Aspa** arrayAspas = nullptr;
	int numAspas;
	int indexAspasMolino;
};

