#include "Molino.h"
#include <iostream>

Molino::Molino(Ogre::SceneNode* node, int numAspas) : EntityIG(node){
	mNodoFicticio = mNode->createChildSceneNode("mNodoFicticio");
	mNodoAspas = mNodoFicticio->createChildSceneNode("mNodoAspas");

	Ogre::Entity* techo = mSM->createEntity("sphere.mesh");
	Ogre::Entity* cuerpo = mSM->createEntity("Barrel.mesh");

	mTecho = mNode->createChildSceneNode("mTecho");
	mTecho->attachObject(techo);

	mCuerpo = mNode->createChildSceneNode("mCuerpo");
	mCuerpo->attachObject(cuerpo);

	aspas = new AspasMolino(mNodoAspas, numAspas, 0);

	transformMolino();
}

void Molino::giraAspasMolino(float ang) {
	aspas->giraAspasMolino(ang);
}

void Molino::mueveCilindroCentral(int x) {
	aspas->getCilindroCentral()->translate(0, 0, x);
}

void Molino::giraAspas(float ang) {
	//Primera forma (nodo ficticio)
	mNodoFicticio->yaw(Ogre::Degree(ang));

	//Segunda forma (el gran truco)
	/*auto aspasNode = aspas->getmNode();

	aspasNode->translate(0,-110,-110, SceneNode::TS_LOCAL);
	aspasNode->yaw(Ogre::Degree(ang));
	aspasNode->translate(0, 110, 110, SceneNode::TS_LOCAL);*/

}

void Molino::transformMolino() {
	mTecho->translate(0, 120, 0);
	mCuerpo->setScale(40, 40, 40);

	aspas->getmNode()->setScale(0.7, 0.7, 0.7);
	aspas->getmNode()->translate(0, 110, 110);
}
