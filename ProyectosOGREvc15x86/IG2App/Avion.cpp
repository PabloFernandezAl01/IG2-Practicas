#include "Avion.h"

Avion::Avion(Ogre::SceneNode* node) : EntityIG(node){

	Ogre::Entity*  esfera = mSM->createEntity("sphere.mesh");
	esfera->setMaterialName("rojo");
	cuerpoNode = mNode->createChildSceneNode();
	cuerpoNode->attachObject(esfera);

	alaIEnt = mSM->createEntity("cube.mesh");
	alaDEnt = mSM->createEntity("cube.mesh");
	alaIEnt->setMaterialName("ajedrez");
	alaDEnt->setMaterialName("ajedrez");

	alaINode = mNode->createChildSceneNode();
	alaDNode = mNode->createChildSceneNode();

	alaINode->attachObject(alaIEnt);
	alaDNode->attachObject(alaDEnt);

	Ogre::Entity* frente = mSM->createEntity("Barrel.mesh");
	frente->setMaterialName("naranja");
	frenteNode = mNode->createChildSceneNode();
	frenteNode->attachObject(frente);

	Ogre::Entity* ninja = mSM->createEntity("ninja.mesh");
	ninja->setMaterialName("amarillo");
	pilotoNode = mNode->createChildSceneNode();
	pilotoNode->attachObject(ninja);

	nodoFicticioAlaI = mNode->createChildSceneNode();
	nodoFicticioAlaD = mNode->createChildSceneNode();

	aspasMolinoI = new AspasMolino(nodoFicticioAlaI, 5, 20);
	aspasMolinoD = new AspasMolino(nodoFicticioAlaD, 5, 21);

	transformAvion();

	myTimer = new Ogre::Timer();
	timeMoving = 0;
	timeRotating = 0;
	rndDirection = -1;
}

void Avion::giraAspasAvion(float ang) {
	aspasMolinoI->giraAspasMolino(ang);
	aspasMolinoD->giraAspasMolino(ang);
}

Ogre::SceneNode* Avion::getNode() {
	return mNode;
}

bool Avion::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_k) {

		mNode->getParent()->pitch(Ogre::Degree(4));
		return true;
	}
	else if (evt.keysym.sym == SDLK_l) {

		mNode->getParent()->yaw(Ogre::Degree(-4));
		return true;
	}
	else if (evt.keysym.sym == SDLK_r) {

		this->sendEvent(MessageType::R_EVENT, this);
		return true;
	}
	return false;
}

void Avion::frameRendered(const Ogre::FrameEvent& evt) {
	if (canMove) {
		timeMoving += evt.timeSinceLastFrame;
		if (timeMoving > 2) {
			timeRotating += evt.timeSinceLastFrame;

			if (timeRotating > 3) {
				timeRotating = 0;
				timeMoving = 0;

				int r = rand() % 2;
				if (r == 0) rndDirection = -1;
				else rndDirection = 1;
			}
			else mNode->getParent()->yaw(Ogre::Degree(rndDirection));
		}
		else mNode->getParent()->pitch(Ogre::Degree(0.5));
	}
}

void Avion::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::R_EVENT: {
		alaIEnt->setMaterialName("rojo");
		alaDEnt->setMaterialName("rojo");

		canMove = false;
		break;
	}
	default:
		break;
	}
}

void Avion::transformAvion() {
	cuerpoNode->setScale(1.5, 1.5, 1.5);

	//Ala izquierda
	alaINode->setScale(1.5, 0.2, 0.8);
	alaINode->translate(-210, 0, 0);

	//Ala derecha
	alaDNode->setScale(1.5, 0.2, 0.8);
	alaDNode->translate(210, 0, 0);

	//Piloto
	pilotoNode->yaw(Ogre::Degree(180));

	//Frente node
	frenteNode->setScale(14, 3, 14);
	frenteNode->translate(0, 0, 150);
	frenteNode->pitch(Ogre::Degree(90));

	//Aspa izquierda
	aspasMolinoI->getmNode()->setScale(0.2, 0.2, 0.2);
	aspasMolinoI->getmNode()->translate(-220, 0, 42);
	aspasMolinoI->giraAspasMolino(20);

	//Aspa derecha
	aspasMolinoD->getmNode()->setScale(0.2, 0.2, 0.2);
	aspasMolinoD->getmNode()->translate(220, 0, 42);
	aspasMolinoD->giraAspasMolino(20);
}
