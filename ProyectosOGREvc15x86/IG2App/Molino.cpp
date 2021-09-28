#include "Molino.h"
#include <iostream>

Molino::Molino(Ogre::SceneManager* sM, int numAspas) {
	mNode = sM->getRootSceneNode()->createChildSceneNode("mNodeMolino");
	mNodoFicticio = mNode->createChildSceneNode("mNodoFicticio");

	Ogre::Entity* techo = sM->createEntity("sphere.mesh");
	Ogre::Entity* cuerpo = sM->createEntity("Barrel.mesh");

	mTecho = mNode->createChildSceneNode("mTecho");
	mTecho->attachObject(techo);

	mCuerpo = mNode->createChildSceneNode("mCuerpo");
	mCuerpo->attachObject(cuerpo);

	aspas = new AspasMolino(sM, mNodoFicticio, numAspas, 0);

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

	Ogre::Degree ang1 = Ogre::Degree(aspas->getmNode()->getOrientation().getYaw());
	aspas->getmNode()->setPosition(0, 60, 0);
	aspas->getmNode()->yaw(Ogre::Degree(1));
	aspas->getmNode()->translate(0, 0, ang, aspas->getmNode()->TS_LOCAL);

	//Segunda forma (el gran truco)
	/*auto aspasNode = aspas->getmNode();

	aspasNode->translate(0,-110,-110, SceneNode::TS_LOCAL);
	aspasNode->yaw(Ogre::Degree(ang));
	aspasNode->translate(0, 110, 110, Ogre::Node::TS_LOCAL);*/

}

void Molino::transformMolino() {
	mTecho->translate(0, 120, 0);
	mCuerpo->setScale(40, 40, 40);

	aspas->getmNode()->setScale(0.7, 0.7, 0.7);
	aspas->getmNode()->translate(0, 110, 110);
}
