#include "Bomba.h"
#include <iostream>

Bomba::Bomba(Ogre::SceneNode* node) : EntityIG(node){
	bombaEnt = mSM->createEntity("Barrel.mesh");
	bombaEnt->setMaterialName("bomba");

	mNode->attachObject(bombaEnt);

	mNode->setScale(10, 10, 10);
	configAnimation();
}

Ogre::SceneNode* Bomba::getNode() {
	return mNode;
}

void Bomba::frameRendered(const Ogre::FrameEvent& evt) {
	animState->addTime(evt.timeSinceLastFrame);
}

void Bomba::configAnimation() {
	Ogre::Real duracion = 4;
	float longDesplazamiento = 30;

	anim = mSM->createAnimation("animVV", duracion);

	NodeAnimationTrack* camino = anim->createNodeTrack(0);
	camino->setAssociatedNode(mNode);

	Vector3 keyframePos(0, 0, 0);
	Ogre::Real durPaso = duracion / 4.0;
	TransformKeyFrame* kf;

	float degreePerFrame = 45.0f / 4.0;
	Vector3 src(0, 0, 1); //WTF
	

	//Frame 0
	kf = camino->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 1);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);
	kf->setRotation(src.getRotationTo(Vector3(1, 0, 1)));

	kf = camino->createNodeKeyFrame(durPaso * 2);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 3);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);
	kf->setRotation(src.getRotationTo(Vector3(-1, 0, 1)));

	kf = camino->createNodeKeyFrame(durPaso * 4);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	animState = mSM->createAnimationState("animVV");
	animState->setLoop(true);
	animState->setEnabled(true);

	mNode->setInitialState();
}

bool Bomba::keyPressed(const OgreBites::KeyboardEvent& evt) {

	if (evt.keysym.sym == SDLK_t) {
		sendEvent(T_EVENT, nullptr);

		return true;
	}
	return false;
}

void Bomba::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::T_EVENT: {
		animState->setEnabled(false);
		break;
	}
	default:
		break;
	}
}
