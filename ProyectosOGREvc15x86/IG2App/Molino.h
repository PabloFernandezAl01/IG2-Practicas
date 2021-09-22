#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "AspasMolino.h"

class Molino {
public:
	Molino(Ogre::SceneManager* sM, int numAspas);
	void giraAspasMolino(float ang);
	void mueveCilindroCentral(int x);
	void giraAspas(float ang);

private:
	Ogre::SceneNode* mNode = nullptr;
	Ogre::SceneNode* mTecho = nullptr;
	Ogre::SceneNode* mCuerpo = nullptr;
	Ogre::SceneNode* mNodoFicticio = nullptr;
	AspasMolino* aspas = nullptr;

	void transformMolino();
};

