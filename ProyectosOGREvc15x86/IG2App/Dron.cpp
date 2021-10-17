#include "Dron.h"
#include <iostream>

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

	myTimer = new Ogre::Timer();
	timeMoving = 0;
	timeRotating = 0;
	rndDirection = -1;
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

bool Dron::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_h) {

		mNode->getParent()->roll(Ogre::Degree(-4));

		/*mNode->translate(0, -320, 0, SceneNode::TS_LOCAL);
		mNode->roll(Ogre::Degree(-4));
		mNode->translate(0, 320, 0, SceneNode::TS_LOCAL);*/

		return true;
	}
	else if (evt.keysym.sym == SDLK_j) {

		mNode->getParent()->yaw(Ogre::Degree(-4));

		//mNode->yaw(Ogre::Degree(-4));

		return true;
	}
	return false;
}

void Dron::frameRendered(const Ogre::FrameEvent& evt) {

	timeMoving += evt.timeSinceLastFrame;
	if (timeMoving > 2) {
		timeRotating += evt.timeSinceLastFrame;

		if (timeRotating > 1) {
			timeRotating = 0;
			timeMoving = 0;

			int r = rand() % 2;
			if (r == 0) rndDirection = -1;
			else rndDirection = 1;
		}
		else mNode->getParent()->yaw(Ogre::Degree(rndDirection));
	}
	else mNode->getParent()->roll(Ogre::Degree(-0.5));
}
