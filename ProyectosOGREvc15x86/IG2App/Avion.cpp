#include "Avion.h"
#include <iostream>

Avion::Avion(Ogre::SceneNode* node) : EntityIG(node){

	nodoIntermedio = mNode->createChildSceneNode();

	Ogre::Entity*  esfera = mSM->createEntity("sphere.mesh");
	esfera->setMaterialName("rojo");
	cuerpoNode = nodoIntermedio->createChildSceneNode();
	cuerpoNode->attachObject(esfera);

	alaIEnt = mSM->createEntity("cube.mesh");
	alaDEnt = mSM->createEntity("cube.mesh");
	alaIEnt->setMaterialName("ajedrez");
	alaDEnt->setMaterialName("ajedrez");

	alaINode = nodoIntermedio->createChildSceneNode();
	alaDNode = nodoIntermedio->createChildSceneNode();

	alaINode->attachObject(alaIEnt);
	alaDNode->attachObject(alaDEnt);

	Ogre::Entity* frente = mSM->createEntity("Barrel.mesh");
	frente->setMaterialName("naranja");
	frenteNode = nodoIntermedio->createChildSceneNode();
	frenteNode->attachObject(frente);

	Ogre::Entity* ninja = mSM->createEntity("ninja.mesh");
	ninja->setMaterialName("amarillo");
	pilotoNode = nodoIntermedio->createChildSceneNode();
	pilotoNode->attachObject(ninja);

	nodoFicticioAlaI = nodoIntermedio->createChildSceneNode();
	nodoFicticioAlaD = nodoIntermedio->createChildSceneNode();

	aspasMolinoI = new AspasMolino(nodoFicticioAlaI, 5, 20);
	aspasMolinoD = new AspasMolino(nodoFicticioAlaD, 5, 21);

	transformAvion();

	myTimer = new Ogre::Timer();
	timeMoving = 0;
	timeRotating = 0;
	rndDirection = -1;
	explosionTime = 0;

	create10PointsBillBoard();
	createRibbonTrail();
	createExplosionSystem();
}

void Avion::giraAspasAvion(float ang) {
	aspasMolinoI->giraAspasMolino(ang);
	aspasMolinoD->giraAspasMolino(ang);
}

Ogre::SceneNode* Avion::getNode() {
	return mNode;
}

bool Avion::teclaPulsada(const OgreBites::KeyboardEvent& evt) {
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
	else if (evt.keysym.sym == SDLK_e) {
		this->sendEvent(MessageType::E_EVENT, this);
		return true;
	}
	return false;
}

void Avion::frameRendered(const Ogre::FrameEvent& evt) {
	//cazaDrones(evt);
	escenaAgua(evt);
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
	case MessageType::E_EVENT: {
		explosionSystem->setEmitting(true); //Hacemos que se active elsistema de particulas de la explosion 
		pSystem->setEmitting(false); //Quitamos la estela 
		nodoIntermedio->setVisible(false); //Invisibilizamos el nodo intermedio 
		bbSet->setVisible(false); //Quitamos el cartel del bilboard
		isExploding = true; //Booleano de control de la explosion

		canMove = false; //Deshabilitamos el movimeinto para el avion 
		break;
	}
	default:
		break;
	}
}

void Avion::create10PointsBillBoard() {
	bbSet = mSM->createBillboardSet("10Points", 1);
	bbSet->setDefaultDimensions(150, 150);
	bbSet->setMaterialName("10Points");

	mNode->attachObject(bbSet);
	bb = bbSet->createBillboard(Vector3(150, 50, -200));
}

void Avion::createRibbonTrail() {
	pSystem = mSM->createParticleSystem("estela", "Estela");
	pSystem->setEmitting(true);
	mNode->attachObject(pSystem); //Para que siga al avion lo unimos a su nodo central 
}

void Avion::createExplosionSystem() {
	explosionSystem = mSM->createParticleSystem("explosion", "Explosion"); //Lo que hace que cambie de color es el colour interpolator 
	explosionSystem->setEmitting(false);
	mNode->attachObject(explosionSystem);
}

void Avion::cazaDrones(const Ogre::FrameEvent& evt) {
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

void Avion::escenaAgua(const Ogre::FrameEvent& evt) {
	//Si se ha pulsado la e este bool debe de estar a true 
	//Todo el codigo  es para que la explosion dure un segundo y se desvanezca 
	if (isExploding) {
		explosionTime += evt.timeSinceLastFrame;
		if (explosionTime > 1) {
			isExploding = false; //Bool de control para contar desactivado
			explosionSystem->setEmitting(false); //Desaparicion de la bomba 
		}
	}

	if(canMove) mNode->getParent()->yaw(Ogre::Degree(-0.5));
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
