#include "Molino.h"

Molino::Molino(Ogre::SceneManager* sM, int numAspas) {
	mNode = sM->getRootSceneNode()->createChildSceneNode("mNodeMolino");
	mNodoFicticio = mNode->createChildSceneNode("mNodoFicticio");

	Ogre::Entity* techo = sM->createEntity("sphere.mesh");
	Ogre::Entity* cuerpo = sM->createEntity("Barrel.mesh");

	mTecho = mNode->createChildSceneNode("mTecho");
	mTecho->attachObject(techo);

	mCuerpo = mNode->createChildSceneNode("mCuerpo");
	mCuerpo->attachObject(cuerpo);

	//aspas = new AspasMolino(sM, mNodoFicticio, numAspas);

	transformMolino();
}

void Molino::giraAspasMolino(float ang) {
	aspas->giraAspasMolino(ang);
}

void Molino::mueveCilindroCentral(int x) {
	aspas->getmNode()->getChild("mCilindroCentralNode")->translate(0, 0, x);
}

void Molino::giraAspas(float ang) {
	mNodoFicticio->yaw(Ogre::Degree(ang));
}

void Molino::transformMolino() {
	mTecho->translate(0, 120, 0);
	mCuerpo->setScale(40, 40, 40);

	aspas->getmNode()->setScale(0.7, 0.7, 0.7);
	aspas->getmNode()->translate(0, 110, 110);
}
