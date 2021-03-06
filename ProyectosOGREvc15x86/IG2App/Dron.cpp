#include "Dron.h"
#include "IG2App.h"
#include <iostream>

Dron::Dron(Ogre::SceneNode* node, int nAs, int nBr, const std::vector<Dron*>& mD, const std::vector<Ogre::SceneNode*>& nD) : EntityIG(node){
	miniDrones = mD;
	nodosDron = nD;

	esferaEnt = mSM->createEntity("sphere.mesh");

	if (mNode->getName() != "dronControlNode") esferaEnt->setMaterialName("rojo");
	else esferaEnt->setMaterialName("cabeza");
	
	esfera = mNode->createChildSceneNode();

	esfera->attachObject(esferaEnt);

	numAspas = nAs; numBrazos = nBr;

	timeToMove = rand() % 4 + 1;
	timeToRotate = rand() % 1 + 1;

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

bool Dron::teclaPulsada(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_h) {
		if (mNode->getName() != "dronControlNode") return false;
		mNode->getParent()->roll(Ogre::Degree(-4));

		/*mNode->translate(0, -320, 0, SceneNode::TS_LOCAL);
		mNode->roll(Ogre::Degree(-4));
		mNode->translate(0, 320, 0, SceneNode::TS_LOCAL);*/

		return true;
	}
	else if (evt.keysym.sym == SDLK_j) {
		if (mNode->getName() != "dronControlNode") return false;
		mNode->getParent()->yaw(Ogre::Degree(-4));

		//mNode->yaw(Ogre::Degree(-4));

		return true;
	}
	return false;
}

void Dron::frameRendered(const Ogre::FrameEvent& evt) {
	if (canMove) {
		timeMoving += evt.timeSinceLastFrame;

		if (timeMoving > timeToMove) {
			timeRotating += evt.timeSinceLastFrame;

			if (timeRotating > timeToRotate) {
				timeRotating = 0;
				timeMoving = 0;

				int r = rand() % 2;
				if (r == 0) rndDirection = -1;
				else rndDirection = 1;
			}
			else {
				mNode->getParent()->yaw(Ogre::Degree(rndDirection));
				dronCollision();
				
			}
		}
		else {
			mNode->getParent()->roll(Ogre::Degree(-0.5));
			dronCollision();
			
		}
	}
}

void Dron::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::R_EVENT: {
		esferaEnt->setMaterialName("rojo");
		
		canMove = false;
		break;
	}
	default:
		break;
	}
}

BrazoDron** Dron::getArrayBrazos() {
	return arrayBrazos;
}

int Dron::getNumBrazos() {
	return numBrazos;
}

void Dron::dronCollision() {
	
	if (mNode->getName() != "dronControlNode") return;

	for (int i = 0; i < miniDrones.size(); i++) {
		AxisAlignedBox miniDron = nodosDron[i]->_getWorldAABB();
		AxisAlignedBox dron = mSM->getSceneNode("dronControlNode")->_getWorldAABB();
		if (dron.intersects(miniDron)) {
			miniDrones.erase(miniDrones.begin() + i);
			nodosDron[i]->setVisible(false);

			if (miniDrones.size() <= 0) {
				esferaEnt->setMaterialName("rojo");
			}
		}
	}
}
