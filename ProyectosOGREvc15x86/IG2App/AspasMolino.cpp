#include "AspasMolino.h"
#include <iostream>

AspasMolino::AspasMolino(Ogre::SceneNode* node, int numAs, int index) : EntityIG(node){
	indexAspasMolino = index;

	Ogre::Entity* cilindro = mSM->createEntity("Barrel.mesh");
	cilindro->setMaterialName("terrain");

	cilindroCentralNode = mNode->createChildSceneNode();
	cilindroCentralNode->attachObject(cilindro);
	cilindroCentralNode->setScale(10, 8, 10);
	cilindroCentralNode->pitch(Ogre::Degree(90));

	aspasNode = mNode->createChildSceneNode();
	numAspas = numAs;

	float ang = 0;
	arrayAspas = new Aspa* [numAspas];
	for (int i = 0; i < numAspas; i++) {

		SceneNode* auxNode = aspasNode->createChildSceneNode();

		arrayAspas[i] = new Aspa(i + indexAspasMolino * numAspas, auxNode);
		arrayAspas[i]->getNode()->roll(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		//arrayAspas[i]->getNode()->getChild("mAdorno" + std::to_string(i + indexAspasMolino * numAspas))->roll(Ogre::Degree(-ang), Ogre::Node::TS_LOCAL);
		ang += (360 / numAspas);
	}
}

void AspasMolino::giraAspasMolino(float ang) {

	aspasNode->roll(Ogre::Degree(ang), Ogre::Node::TS_PARENT);

	/*for (int i = 0; i < numAspas; i++) {
		auto adorno = mSM->getSceneNode("mAdorno" + std::to_string(i + indexAspasMolino * numAspas));
		adorno->roll(Ogre::Degree(-ang), Ogre::Node::TS_LOCAL);
	}*/
}

Ogre::SceneNode* AspasMolino::getCilindroCentral() {
	return cilindroCentralNode;
}

Ogre::SceneNode* AspasMolino::getmNode() {
	return mNode;
}

void AspasMolino::frameRendered(const Ogre::FrameEvent& evt) {
	giraAspasMolino(2);
}
