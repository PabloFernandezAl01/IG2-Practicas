#include "RotorDron.h"

RotorDron::RotorDron(Ogre::SceneManager* sm, int numAs) {
	mNode = sm->getRootSceneNode()->createChildSceneNode("mRotorDronNode");

	numAspas = numAs;

	Ogre::Entity* esfera = sm->createEntity("sphere.mesh");
	mEsferaNode = mNode->createChildSceneNode("mEsferaNode");
	mEsferaNode->attachObject(esfera);

	mHelicesNode = mNode->createChildSceneNode("mHelicesNode");

	aspasMolino = new AspasMolino(sm, mHelicesNode, 6);

	//Oculta los adornos
	for (int i = 0; i < numAspas; i++) {
		sm->getSceneNode("mAdorno" + std::to_string(i))->setVisible(false);
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
