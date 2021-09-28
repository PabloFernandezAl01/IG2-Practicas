#include "RotorDron.h"

RotorDron::RotorDron(Ogre::SceneManager* sm, Ogre::SceneNode* node, int numAs, int index) {
	indexRotorDron = index;
	
	mNode = node->createChildSceneNode("mRotorDronNode" + std::to_string(indexRotorDron));

	numAspas = numAs;

	Ogre::Entity* esfera = sm->createEntity("sphere.mesh");
	mEsferaNode = mNode->createChildSceneNode("mEsferaNode" + std::to_string(indexRotorDron));
	mEsferaNode->attachObject(esfera);

	mHelicesNode = mNode->createChildSceneNode("mHelicesNode" + std::to_string(indexRotorDron));

	aspasMolino = new AspasMolino(sm, mHelicesNode, numAspas, indexRotorDron);

	//Oculta los adornos
	for (int i = 0; i < numAspas; i++) {
		sm->getSceneNode("mAdorno" + std::to_string(i+ indexRotorDron * numAspas))->setVisible(false);
	}

	transformRotorDron();
}

void RotorDron::transformRotorDron() {
	mEsferaNode->setScale(1.5, 1.5, 1.5);

	aspasMolino->getmNode()->setScale(0.7, 0.7, 0.7);
	aspasMolino->getmNode()->translate(0, 150, 0);
	aspasMolino->getmNode()->pitch(Ogre::Degree(-90));
}

void RotorDron::giraAspas(float ang) {
	aspasMolino->giraAspasMolino(ang);
}

Ogre::SceneNode* RotorDron::getmNode() {
	return mNode;
}
