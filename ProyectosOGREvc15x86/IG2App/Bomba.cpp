#include "Bomba.h"
#include <iostream>

Bomba::Bomba(Ogre::SceneNode* node) : EntityIG(node){
	nodoIntermedio = mNode->createChildSceneNode();

	bombaEnt = mSM->createEntity("Barrel.mesh");
	bombaEnt->setMaterialName("bomba");

	nodoIntermedio->attachObject(bombaEnt);

	nodoIntermedio->setScale(10, 10, 10);
	configAnimation();
	createParticleSystem();
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

	Vector3 src(0, 0, 1); //El objeto inicia en el eje Z
	
	//La animacion a parte de hacer un vaiven de arriba abajo rota 45 grados en el eje Y

	//Frame 0
	kf = camino->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	//Frame 1
	kf = camino->createNodeKeyFrame(durPaso * 1);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);
	kf->setRotation(src.getRotationTo(Vector3(1, 0, 1))); //Pasa de estar en el eje z a estar en el eje entre z y x (45 grados)

	//Frame 2
	kf = camino->createNodeKeyFrame(durPaso * 2);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	//Frame 3
	kf = camino->createNodeKeyFrame(durPaso * 3);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);
	//Reestablecer la rotacion al punto de partida 
	kf->setRotation(src.getRotationTo(Vector3(-1, 0, 1)));//Pasa de estar en el eje z a estar en el eje entre z y -x (-45 grados)

	//Frame 4
	kf = camino->createNodeKeyFrame(durPaso * 4);
	keyframePos += Ogre::Vector3::UNIT_Y * longDesplazamiento;
	kf->setTranslate(keyframePos);

	//Despues de haber creado la animacion creamos un estado de animacion a partir de ella la activamos , junto con su loop
	animState = mSM->createAnimationState("animVV");
	animState->setLoop(true);
	animState->setEnabled(true);

	mNode->setInitialState();  //Conserva los valores de escala y posicion cuando hace la animacion, sin esto , funciona pero el objeto tendria un tamaño por defecto
}

bool Bomba::teclaPulsada(const OgreBites::KeyboardEvent& evt) {

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
		animState->setEnabled(false); //Desactivar la animacion 
		break;
	}
	case MessageType::EXPLOTA_BOMBA: {
		pSystem->setEmitting(true);
		nodoIntermedio->setVisible(false);
		animState->setEnabled(false);
		break;
	}
	default:
		break;
	}
}

void Bomba::createParticleSystem() {
	pSystem = mSM->createParticleSystem("humoBomba", "HumoBomba");
	pSystem->setEmitting(false);
	mNode->attachObject(pSystem);
}
