#include "Aspa.h"

Aspa::Aspa(Ogre::SceneManager* sm, Ogre::SceneNode* node, int index) {
	aspaIndex = index;

	mNode = node->createChildSceneNode("mNodeAspa" + std::to_string(aspaIndex));

	Ogre::Entity* tab = sm->createEntity("cube.mesh");
	Ogre::Entity* adorno = sm->createEntity("Barrel.mesh");

	tableroNode = mNode->createChildSceneNode("mTablero" + std::to_string(aspaIndex));
	tableroNode->attachObject(tab);

	adornoNode = mNode->createChildSceneNode("mAdorno" + std::to_string(aspaIndex));
	adornoNode->attachObject(adorno);

	transformaAspa();
}

Ogre::SceneNode* Aspa::getNode() {
	return mNode;
}

void Aspa::transformaAspa() {
	tableroNode->setScale(2.5, 0.5, 0.2);
	tableroNode->translate(120, 0, 0);

	adornoNode->setScale(2.5, 6, 2.5);
	adornoNode->translate(225, 0, 20);
}
