#include "Bomba.h"

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
	float longDesplazamiento = 35;

	anim = mSM->createAnimation("animVV", duracion);

	NodeAnimationTrack* camino = anim->createNodeTrack(0);
	camino->setAssociatedNode(mNode);

	Vector3 keyframePos(0, 0, 0);
	Ogre::Real durPaso = duracion / 4.0;
	TransformKeyFrame* kf;

	//Frame 0
	kf = camino->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 1);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 2);
	keyframePos = Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 3);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	kf = camino->createNodeKeyFrame(durPaso * 4);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	animState = mSM->createAnimationState("animVV");
	animState->setLoop(true);
	animState->setEnabled(true);

	mNode->setInitialState();
}
