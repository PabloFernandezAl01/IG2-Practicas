#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "AspasMolino.h"
#include "EntityIG.h"

class Molino : public EntityIG{
public:
	Molino(Ogre::SceneNode* node, int numAspas);

	void giraAspasMolino(float ang);
	void mueveCilindroCentral(int x);
	void giraAspas(float ang);

private:
	Ogre::SceneNode* mTecho = nullptr;
	Ogre::SceneNode* mCuerpo = nullptr;
	Ogre::SceneNode* mNodoAspas = nullptr;
	Ogre::SceneNode* mNodoFicticio = nullptr;
	AspasMolino* aspas = nullptr;

	void transformMolino();
};

