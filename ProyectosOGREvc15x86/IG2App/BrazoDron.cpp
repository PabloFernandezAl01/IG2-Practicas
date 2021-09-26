#include "BrazoDron.h"

BrazoDron::BrazoDron(Ogre::SceneManager* sM, Ogre::SceneNode* node, int numAspas, int iB) {
	mNode = node->createChildSceneNode("mNodeBrazoDron" + std::to_string(iB));

	Ogre::Entity* c = sM->createEntity("Barrel.mesh");
	cilindro = mNode->createChildSceneNode("mNodeCilindroBrazoDron" + std::to_string(iB));

	cilindro->attachObject(c);

	rotorDron = new RotorDron(sM, mNode, numAspas, iB);
	transformBrazoDron();
}

void BrazoDron::transformBrazoDron() {
	cilindro->setScale(20, 60, 20);
	cilindro->roll(Ogre::Degree(-90));

	rotorDron->getmNode()->translate(250, 0, 0);
}

void BrazoDron::giraAspas(float ang) {
	rotorDron->giraAspas(ang);
}

Ogre::SceneNode* BrazoDron::getmNode()
{
	return mNode;
}
