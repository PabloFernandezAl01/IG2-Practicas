#pragma once
#include "IG2ApplicationContext.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <vector>

enum MessageType {R_EVENT};

class EntityIG : public OgreBites::InputListener
{
public:

	EntityIG(Ogre::SceneNode* node);
	static std::vector<EntityIG*> appListeners;

	static void addListener(EntityIG* ent);

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt)
	{
		return false;
	};

	virtual void sendEvent(MessageType msgType, EntityIG* entidad);
	virtual void receiveEvent(MessageType msgType, EntityIG* entidad) {};

protected:

	Ogre::SceneNode* mNode;
	Ogre::SceneManager* mSM;

	virtual void frameRendered(const Ogre::FrameEvent& evt) {};

};

