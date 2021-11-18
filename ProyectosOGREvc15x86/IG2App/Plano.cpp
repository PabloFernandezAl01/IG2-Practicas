#include "Plano.h"

Plano::Plano(Ogre::SceneNode* node, std::string entName, std::string materialName) : EntityIG(node){

	entName_ = entName;

	//Plano
	Ogre::MeshManager::getSingleton().createPlane(entName,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		1080, 1080, 100, 80, true, 1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	plano = mSM->createEntity(entName);
	if(materialName != "") plano->setMaterialName(materialName);

	mNode->attachObject(plano);

	timeToChangeMaterial = 0;
}

Ogre::SceneNode* Plano::getNode() {
	return mNode;
}

void Plano::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::T_EVENT: {
		if (entName_ == "mPlane1080x1080") canCount = true;
		break;
	}
	default:
		break;
	}
}

void Plano::frameRendered(const Ogre::FrameEvent& evt) {
	if (canCount) {

		timeToChangeMaterial += evt.timeSinceLastFrame;
		if (timeToChangeMaterial >= 5) {
			plano->setMaterialName("piedras");
			canCount = false;
		}
	}
}
