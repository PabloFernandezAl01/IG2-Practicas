#include "Avion.h"

Avion::Avion(Ogre::SceneNode* node) : EntityIG(node){

	//mNode = node->createChildSceneNode("mNodeAvion");

	Ogre::Entity* esfera = mSM->createEntity("sphere.mesh");
	cuerpoNode = mNode->createChildSceneNode("mCuerpoAvion");
	cuerpoNode->attachObject(esfera);

	Ogre::Entity* alaI = mSM->createEntity("cube.mesh");
	Ogre::Entity* alaD = mSM->createEntity("cube.mesh");

	alaINode = mNode->createChildSceneNode("mAlaINode");
	alaDNode = mNode->createChildSceneNode("mAlaDNode");

	alaINode->attachObject(alaI);
	alaDNode->attachObject(alaD);

	Ogre::Entity* frente = mSM->createEntity("Barrel.mesh");
	frenteNode = mNode->createChildSceneNode("mFrenteNode");
	frenteNode->attachObject(frente);

	Ogre::Entity* ninja = mSM->createEntity("ninja.mesh");
	pilotoNode = mNode->createChildSceneNode("mPilotoNode");
	pilotoNode->attachObject(ninja);

	nodoFicticioAlaI = mNode->createChildSceneNode();
	nodoFicticioAlaD = mNode->createChildSceneNode();

	aspasMolinoI = new AspasMolino(nodoFicticioAlaI, 5, 13);
	aspasMolinoD = new AspasMolino(nodoFicticioAlaD, 5, 14);

	transformAvion();
}

void Avion::giraAspasAvion(float ang) {
	aspasMolinoI->giraAspasMolino(ang);
	aspasMolinoD->giraAspasMolino(ang);
}

void Avion::transformAvion() {
	cuerpoNode->setScale(1.5, 1.5, 1.5);

	//Ala izquierda
	alaINode->setScale(4, 0.2, 0.8);
	alaINode->translate(-150, 0, 0);

	//Ala derecha
	alaDNode->setScale(4, 0.2, 0.8);
	alaDNode->translate(150, 0, 0);

	//Piloto
	pilotoNode->yaw(Ogre::Degree(180));

	//Frente node
	frenteNode->setScale(14, 3, 14);
	frenteNode->translate(0, 0, 150);
	frenteNode->pitch(Ogre::Degree(90));

	//Aspa izquierda
	aspasMolinoI->getmNode()->setScale(0.3, 0.3, 0.3);
	aspasMolinoI->getmNode()->translate(-250, 0, 42);
	aspasMolinoI->giraAspasMolino(20);

	//Aspa derecha
	aspasMolinoD->getmNode()->setScale(0.3, 0.3, 0.3);
	aspasMolinoD->getmNode()->translate(250, 0, 42);
	aspasMolinoD->giraAspasMolino(20);
}
