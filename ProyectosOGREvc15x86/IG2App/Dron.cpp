#include "Dron.h"

Dron::Dron(Ogre::SceneManager* sM, int nA, int nB) {
	mNode = sM->getRootSceneNode()->createChildSceneNode("mNodeDron");

	Ogre::Entity* e = sM->createEntity("sphere.mesh");
	esfera = mNode->createChildSceneNode("mNodeEsferaDron");

	esfera->attachObject(e);

	numAspas = nA; numBrazos = nB;

	float ang = 0;
	arrayBrazos = new BrazoDron * [numBrazos];
	for (int i = 0; i < numBrazos; i++) {
		arrayBrazos[i] = new BrazoDron(sM, mNode, numAspas, i);
		arrayBrazos[i]->getmNode()->yaw(Ogre::Degree(ang), Ogre::Node::TS_PARENT);
		arrayBrazos[i]->getmNode()->translate(450, 0, 0, Ogre::Node::TS_LOCAL);
		ang += (360 / numBrazos);
	}

	esfera->setScale(3, 3, 3);
}

void Dron::giraAspas(float ang) {
	for (int i = 0; i < numBrazos; i++) {
		if (i % 2 == 0) ang = -ang;
		arrayBrazos[i]->giraAspas(ang);
	}
}
