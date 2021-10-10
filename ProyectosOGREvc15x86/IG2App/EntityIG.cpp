#include "EntityIG.h"

EntityIG::EntityIG(Ogre::SceneNode* node) {
	//appListeners = std::vector<EntityIG*>(0, nullptr);

	mNode = node;
	mSM = mNode->getCreator();
}

void EntityIG::addListener(EntityIG* ent) {
	//appListeners.push_back(ent);
}
