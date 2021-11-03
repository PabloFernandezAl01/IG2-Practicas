#include "Simbad.h"
#include <iostream>

Simbad::Simbad(Ogre::SceneNode* node) : EntityIG(node){
	simbadEnt = mSM->createEntity("Sinbad.mesh");

	runBase = simbadEnt->getAnimationState("RunBase");
	runTop = simbadEnt->getAnimationState("RunTop");
	dance = simbadEnt->getAnimationState("Dance");

	AnimationStateSet* aux = simbadEnt->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	while (it != aux->getAnimationStateIterator().end()) {
		auto s = it->first; 
		std::cout << s << "\n";
		++it;
	}

	mSinbadNode = mNode->createChildSceneNode();
	mSinbadNode->attachObject(simbadEnt);
	mSinbadNode->setScale(10, 10, 10);

	runBase->setLoop(true);
	runBase->setEnabled(true);

	runTop->setLoop(true);
	runTop->setEnabled(true);

	dance->setLoop(true);
	dance->setEnabled(false);

	swordL = mSM->createEntity("Sword.mesh");
	swordR = mSM->createEntity("Sword.mesh");
}

Ogre::SceneNode* Simbad::getNode() {
	return mSinbadNode;
}

void Simbad::frameRendered(const Ogre::FrameEvent& evt) {

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

	//mNode->getParent()->pitch(Ogre::Degree(0.5));
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

bool Simbad::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_c) {
		
		runBase->setLoop(!runBase->getLoop());
		runTop->setLoop(!runTop->getLoop());

		dance->setLoop(!dance->getLoop());

		return true;
	}

	return false;
}
