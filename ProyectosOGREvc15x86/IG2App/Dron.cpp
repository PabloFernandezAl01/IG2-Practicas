#include "Dron.h"

Dron::Dron(Ogre::SceneManager* sM, Ogre::SceneNode* node, int nAs, int nBr) {
	mNode = node->createChildSceneNode("mNodeDron");

	Ogre::Entity* e = sM->createEntity("sphere.mesh");
	esfera = mNode->createChildSceneNode("mNodeEsferaDron");

	esfera->attachObject(e);

	numAspas = nAs; numBrazos = nBr;

	float ang = 0;
	arrayBrazos = new BrazoDron * [numBrazos];
	for (int i = 0; i < numBrazos; i++) {
		arrayBrazos[i] = new BrazoDron(sM, mNode, numAspas, i);
		arrayBrazos[i]->getmNode()->yaw(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		arrayBrazos[i]->getmNode()->translate(400, 0, 0, Ogre::Node::TS_LOCAL);
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
