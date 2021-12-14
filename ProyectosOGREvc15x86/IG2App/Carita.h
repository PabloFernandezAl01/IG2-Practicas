#pragma once
#include "EntityIG.h"
#include "OgreRenderTargetListener.h"

class Carita :public EntityIG, public Ogre::RenderTargetListener {
public:
	Carita(Ogre::SceneNode* mCaraNode);

	void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
	void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

private:
	Ogre::Entity* caritaFelizEnt = nullptr;
};
