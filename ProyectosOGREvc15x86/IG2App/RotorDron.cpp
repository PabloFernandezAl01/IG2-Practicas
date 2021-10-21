#include "RotorDron.h"

RotorDron::RotorDron(Ogre::SceneNode* node, int numAs, int index) : EntityIG(node){
	indexRotorDron = index;
	
	numAspas = numAs;

	Ogre::Entity* esfera = mSM->createEntity("sphere.mesh");
	esfera->setMaterialName("marron_claro");
	mEsferaNode = mNode->createChildSceneNode();
	mEsferaNode->attachObject(esfera);

	mHelicesNode = mNode->createChildSceneNode();

	aspasMolino = new AspasMolino(mHelicesNode, numAspas, indexRotorDron);

	////Oculta los adornos
	//for (int i = 0; i < numAspas; i++) {
	//	mSM->getSceneNode("mAdorno" + std::to_string(i+ indexRotorDron * numAspas))->setVisible(false);
	//}

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

AspasMolino* RotorDron::getAspasMolino()
{
	return aspasMolino;
}
