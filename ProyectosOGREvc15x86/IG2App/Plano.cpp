#include "Plano.h"

Plano::Plano(Ogre::SceneNode* node) : EntityIG(node){

	//Plano
	Ogre::MeshManager::getSingleton().createPlane("mPlane1080x800",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		1080, 800, 100, 80, true, 1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	plano = mSM->createEntity("mPlane1080x800");
	mPlanoNode = node->createChildSceneNode();
	mPlanoNode->attachObject(plano);
}

Ogre::SceneNode* Plano::getmPlanoNode() {
	return mPlanoNode;
}
