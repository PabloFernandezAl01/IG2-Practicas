#include "BrazoDron.h"

BrazoDron::BrazoDron(Ogre::SceneNode* node, int numAspas, int index) : EntityIG(node){
	indexBrazo = index;

	Ogre::Entity* c = mSM->createEntity("Barrel.mesh");
	c->setMaterialName("bumpy");
	cilindro = mNode->createChildSceneNode();

	cilindro->attachObject(c);

	rotorDron = new RotorDron(mNode, numAspas, indexBrazo);
	transformBrazoDron();
}

void BrazoDron::transformBrazoDron() {
	cilindro->setScale(20, 60, 20);
	cilindro->roll(Ogre::Degree(-90));
	cilindro->translate(-250, 0, 0);
}

void BrazoDron::giraAspas(float ang) {
	rotorDron->giraAspas(ang);
}

Ogre::SceneNode* BrazoDron::getmNode() {
	return mNode;
}

Ogre::SceneNode* BrazoDron::getCilindroNode()
{
	return cilindro;
}

RotorDron* BrazoDron::getRotorDron()
{
	return rotorDron;
}
