#include "Simbad.h"
#include <iostream>

Simbad::Simbad(Ogre::SceneNode* node) : EntityIG(node){
	simbadEnt = mSM->createEntity("Sinbad.mesh");

	runBase = simbadEnt->getAnimationState("RunBase");
	runTop = simbadEnt->getAnimationState("RunTop");
	dance = simbadEnt->getAnimationState("Dance");
	idleBase = simbadEnt->getAnimationState("IdleBase");
	idleTop = simbadEnt->getAnimationState("IdleTop");

	AnimationStateSet* aux = simbadEnt->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	while (it != aux->getAnimationStateIterator().end()) {
		auto s = it->first; 
		std::cout << s << "\n";
		++it;
	}

	mNode->attachObject(simbadEnt);
	mNode->translate(-400, 50, 400); //Evitar mover a simbad porque si no se rompe el ejercicio 42
	//mNode->translate(0, 350, 0);
	mNode->setScale(10, 10, 10);

	runBase->setLoop(true);
	runBase->setEnabled(true);

	runTop->setLoop(true);
	runTop->setEnabled(true);

	dance->setLoop(true);
	dance->setEnabled(false);

	idleBase->setLoop(true);
	idleBase->setEnabled(true);

	swordL = mSM->createEntity("Sword.mesh");
	swordR = mSM->createEntity("Sword.mesh");

	time = 0;

	configAnimation();
}

Ogre::SceneNode* Simbad::getNode() {
	return mNode;
}

void Simbad::frameRendered(const Ogre::FrameEvent& evt) {
	if (counting) {
		time += evt.timeSinceLastFrame;
		if (time >= 5) {
			counting = false;
			sendEvent(MessageType::EXPLOTA_BOMBA, this);
		}
	}

	if (!dead) {
		animState->addTime(evt.timeSinceLastFrame);

		if (runBase->getEnabled() && runTop->getEnabled()) {

			if (runBase->hasEnded() && runTop->hasEnded()) {
				runBase->setEnabled(false);
				runTop->setEnabled(false);

				dance->setEnabled(true);
				dance->setLoop(true);
			}
			else {
				runBase->addTime(evt.timeSinceLastFrame);
				runTop->addTime(evt.timeSinceLastFrame);
			}
		}

		if (dance->getEnabled()) {
			if (dance->hasEnded()) {
				dance->setEnabled(false);

				runBase->setEnabled(true);
				runTop->setEnabled(true);

				runBase->setLoop(true);
				runTop->setLoop(true);
			}
			else dance->addTime(evt.timeSinceLastFrame);

		}
	}
	else {
		idleBase->addTime(evt.timeSinceLastFrame);
		idleTop->addTime(evt.timeSinceLastFrame);
	}

	//Ejercicio 44
	/*mNode->getParent()->pitch(Ogre::Degree(0.5));
	runBase->addTime(evt.timeSinceLastFrame);
	runTop->addTime(evt.timeSinceLastFrame);*/
}

void Simbad::arma(bool s) {
	side = s;

	if (side) simbadEnt->attachObjectToBone("Handle.L", swordL);
	else simbadEnt->attachObjectToBone("Handle.R", swordR);
}

void Simbad::arma() {
	simbadEnt->attachObjectToBone("Handle.L", swordL);
	simbadEnt->attachObjectToBone("Handle.R", swordR);
}

void Simbad::cambiaEspada() {
	if (side) {
		simbadEnt->detachObjectFromBone(swordL);
		simbadEnt->attachObjectToBone("Handle.R", swordR);
		side = false;
	}
	else {
		simbadEnt->detachObjectFromBone(swordR);
		simbadEnt->attachObjectToBone("Handle.L", swordL);
		side = true;
	}
}

void Simbad::configAnimation() {
	Ogre::Real duracion = 10;
	float longDesplazamiento = 800;

	anim = mSM->createAnimation("animSimbad", duracion);

	NodeAnimationTrack* camino = anim->createNodeTrack(0);
	camino->setAssociatedNode(mNode);

	Vector3 keyframePos(-400, 50, 400);
	Ogre::Real durPaso = duracion / 5.0; // Duracion del paso=  duracion en segundos/ numero de keyframes-1
	TransformKeyFrame* kf;

	Vector3 src(0, 0, 1);

	//Frame 0
	kf = camino->createNodeKeyFrame(durPaso * 0);
	kf->setRotation(src.getRotationTo(Vector3(0, 0, 1)));

	//Frame 1
	kf = camino->createNodeKeyFrame(durPaso * 1);
	kf->setRotation(src.getRotationTo(Vector3(1, 0, -1)));

	//Frame 2
	kf = camino->createNodeKeyFrame(durPaso * 2);
	keyframePos = Vector3(1, 0, -1) * longDesplazamiento;
	kf->setRotation(src.getRotationTo(Vector3(1, 0, -1)));
	kf->setTranslate(keyframePos);

	//Frame 3
	kf = camino->createNodeKeyFrame(durPaso * 3);
	kf->setRotation(src.getRotationTo(Vector3(-1, 0, 1)));
    kf->setTranslate(keyframePos);

	//Frame 4
	kf = camino->createNodeKeyFrame(durPaso * 4);
	keyframePos = Vector3(0, 0, 0); //Si quieres volver al punto donde empiezas pones 0 0 0 por que es en local no la posicion real de simbad 
	kf->setRotation(src.getRotationTo(Vector3(-1, 0, 1)));
	kf->setTranslate(keyframePos);

	//Frame 5
	kf = camino->createNodeKeyFrame(durPaso * 5);
	kf->setRotation(src.getRotationTo(Vector3(0, 0, 1)));
	kf->setTranslate(keyframePos);

	animState = mSM->createAnimationState("animSimbad");
	animState->setLoop(true);
	animState->setEnabled(true);

	mNode->setInitialState();
}

void Simbad::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::E_EVENT: {
		dead = true;

		idleBase->setEnabled(true);

		animState->setEnabled(false);
		runBase->setEnabled(false);
		runTop->setEnabled(false);
		dance->setEnabled(false);

		mNode->pitch(Ogre::Degree(-90));
		mNode->translate(0, -40, 0);

		counting = true;
		break;
	}
	default:
		break;
	}
}

bool Simbad::teclaPulsada(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_c) {
		runBase->setLoop(!runBase->getLoop());
		runTop->setLoop(!runTop->getLoop());

		dance->setLoop(!dance->getLoop());

		return true;
	}

	return false;
}
