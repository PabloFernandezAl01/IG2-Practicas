#include "Aspa.h"
#include <iostream>

Aspa::Aspa(int index, Ogre::SceneNode* node) : EntityIG(node){
	aspaIndex = index;

	Ogre::Entity* tab = mSM->createEntity("cube.mesh");
	tab->setMaterialName("marron");
	Ogre::Entity* adorno = mSM->createEntity("Barrel.mesh");
	adorno->setMaterialName("rojo");

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
