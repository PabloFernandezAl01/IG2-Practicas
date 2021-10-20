#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntityIG(node){
	Ogre::Entity* ent = mSM->createEntity("Sinbad.mesh");

	mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
	mSinbadNode->attachObject(ent);
	mSinbadNode->setScale(20, 20, 20);
}
