#include "Plano.h"

Plano::Plano(Ogre::SceneNode* node, std::string entName, std::string materialName) : EntityIG(node){

	entName_ = entName;

	//Plano
	Ogre::MeshManager::getSingleton().createPlane(entName,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		1080, 800, 100, 80, true, 1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	plano = mSM->createEntity(entName);
	plano->setMaterialName(materialName);

	mNode->attachObject(plano);
}

Ogre::SceneNode* Plano::getNode() {
	return mNode;
}

void Plano::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::T_EVENT: {

		if(entName_ == "mPlane1080x800") plano->setMaterialName("piedras");
		break;
	}
	default:
		break;
	}
}
