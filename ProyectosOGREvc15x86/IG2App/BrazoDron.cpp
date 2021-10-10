#include "BrazoDron.h"

BrazoDron::BrazoDron(Ogre::SceneNode* node, int numAspas, int index) : EntityIG(node){
	indexBrazo = index;

	Ogre::Entity* c = mSM->createEntity("Barrel.mesh");
	cilindro = mNode->createChildSceneNode("mNodeCilindroBrazoDron" + std::to_string(indexBrazo));

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
