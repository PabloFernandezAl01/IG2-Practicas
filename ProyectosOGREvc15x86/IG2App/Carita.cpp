#include "Carita.h"
#include "EntityIG.h"
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

Carita::Carita(Ogre::SceneNode* mCaraNode) :EntityIG(mCaraNode) {

	Ogre::Entity*  caritaFelizEnt = mSM->createEntity("sphere.mesh");
	caritaFelizEnt->setMaterialName("cabeza");

	mNode->attachObject(caritaFelizEnt);
	mNode->setScale(0.2, 0.2, 0.2);
	mNode->translate(505, 20, -405);
}

void Carita::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt) {
	
}

void Carita::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt) {

}
