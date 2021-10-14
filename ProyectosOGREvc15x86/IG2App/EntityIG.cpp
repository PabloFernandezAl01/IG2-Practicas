#include "EntityIG.h"

std::vector<EntityIG*> EntityIG::appListeners;

EntityIG::EntityIG(Ogre::SceneNode* node) {
	mNode = node;
	mSM = mNode->getCreator();
}

void EntityIG::addListener(EntityIG* ent) {
	appListeners.push_back(ent);
}
