#include "Dron.h"

Dron::Dron(Ogre::SceneNode* node, int nAs, int nBr) : EntityIG(node){
	Ogre::Entity* e = mSM->createEntity("sphere.mesh");
	esfera = mNode->createChildSceneNode("mNodeEsferaDron");

	esfera->attachObject(e);

	numAspas = nAs; numBrazos = nBr;

	float ang = 0;
	arrayBrazos = new BrazoDron * [numBrazos];
	for (int i = 0; i < numBrazos; i++) {
		SceneNode* auxNode = mNode->createChildSceneNode();
		arrayBrazos[i] = new BrazoDron(auxNode, numAspas, i);
		arrayBrazos[i]->getmNode()->yaw(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		arrayBrazos[i]->getmNode()->translate(600, 0, 0, Ogre::Node::TS_LOCAL);
		ang += (360 / numBrazos);
	}

	arrayBrazos[0]->getCilindroNode()->scale(1, 2, 1);
	arrayBrazos[0]->getmNode()->translate(200, 0, 0, Ogre::Node::TS_LOCAL);

	esfera->setScale(3, 3, 3);
}

void Dron::giraAspas(float ang) {
	for (int i = 0; i < numBrazos; i++) {
		if (i % 2 == 0) ang = -ang;
		arrayBrazos[i]->giraAspas(ang);
	}
}

Ogre::SceneNode* Dron::getNode() {
	return mNode;
}
