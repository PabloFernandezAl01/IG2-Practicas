#include "AspasMolino.h"

AspasMolino::AspasMolino(Ogre::SceneManager* sm, int numAs) {
	mNode = sm->getRootSceneNode()->createChildSceneNode("mNodeAspasMolino");

	Ogre::Entity* cilindro = sm->createEntity("Barrel.mesh");

	cilindroCentralNode = mNode->createChildSceneNode("mCilindroCentralNode");
	cilindroCentralNode->attachObject(cilindro);
	cilindroCentralNode->setScale(8, 8, 8);
	cilindroCentralNode->pitch(Ogre::Degree(90));

	aspasNode = mNode->createChildSceneNode("mAspasNode");

	numAspas = numAs;

	float ang = 0;
	arrayAspas = new Aspa* [numAspas];
	for (int i = 0; i < numAspas; i++) {
		arrayAspas[i] = new Aspa(sm, aspasNode, i);
		arrayAspas[i]->getNode()->roll(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		arrayAspas[i]->getNode()->getChild("mAdorno" + std::to_string(i))->roll(Ogre::Degree(-ang), Ogre::Node::TS_PARENT);
		ang += (360 / numAspas);
	}
}

void AspasMolino::giraAspasMolino(float ang) {
	for (int i = 0; i < numAspas; i++) {
		arrayAspas[i]->getNode()->roll(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		arrayAspas[i]->getNode()->getChild("mAdorno" + std::to_string(i))->roll(Ogre::Degree(-ang), Ogre::Node::TS_PARENT);
	}
}
