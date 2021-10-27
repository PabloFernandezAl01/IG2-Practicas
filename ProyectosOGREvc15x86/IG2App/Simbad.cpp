#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntityIG(node){
	Ogre::Entity* ent = mSM->createEntity("Sinbad.mesh");

	runBase = ent->getAnimationState("RunBase");
	runTop = ent->getAnimationState("RunTop");

	AnimationStateSet* aux = ent->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	while (it != aux->getAnimationStateIterator().end()) {
		auto s = it->first; 
		++it;
	}

	mSinbadNode = mNode->createChildSceneNode();
	mSinbadNode->attachObject(ent);
	mSinbadNode->setScale(10, 10, 10);

	runBase->setLoop(true);
	runBase->setEnabled(true);

	runTop->setLoop(true);
	runTop->setEnabled(true);
}

Ogre::SceneNode* Simbad::getNode() {
	return mSinbadNode;
}

void Simbad::frameRendered(const Ogre::FrameEvent& evt) {
	runBase->addTime(evt.timeSinceLastFrame);
	runTop->addTime(evt.timeSinceLastFrame);
}
