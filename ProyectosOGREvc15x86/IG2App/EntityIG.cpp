#include "EntityIG.h"

std::vector<EntityIG*> EntityIG::appListeners;

EntityIG::EntityIG(Ogre::SceneNode* node) {
	mNode = node;
	mSM = mNode->getCreator();
}

void EntityIG::addListener(EntityIG* ent) {
	appListeners.push_back(ent);
}

void EntityIG::sendEvent(MessageType msgType, EntityIG* entidad) {
	for (EntityIG* e : appListeners) e->receiveEvent(msgType, entidad);
}
