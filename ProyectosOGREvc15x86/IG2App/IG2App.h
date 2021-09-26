#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include "Molino.h"
#include "BrazoDron.h"
#include "Dron.h"

class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener 
{
public:
  explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()  
  virtual ~IG2App() { };   // delete -> shutdown()  
 
protected:
  virtual void setup();
  virtual void shutdown();
  virtual void setupScene();

  virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
      
  Ogre::SceneManager* mSM = nullptr;
  OgreBites::TrayManager* mTrayMgr = nullptr;    
  Ogre::SceneNode* mLightNode = nullptr;
  Ogre::SceneNode* mCamNode = nullptr;
  Ogre::SceneNode* mSinbadNode = nullptr;
  OgreBites::CameraMan* mCamMgr = nullptr;

  //Practica 0
  Ogre::SceneNode* mSwordNode = nullptr;
  Ogre::SceneNode* mHelmetNode = nullptr;
  Ogre::SceneNode* mOgreHeadNode = nullptr;
  Ogre::SceneNode* mFacialNode = nullptr;
  Ogre::SceneNode* mStageNode = nullptr;
  Ogre::SceneNode* mColumnsNode = nullptr;
  Ogre::SceneNode* mBathLower = nullptr;
  Ogre::SceneNode* mBathUpper = nullptr;

  //Practica 1.1
  Ogre::SceneNode* mHourNode[12];
  Ogre::SceneNode* clock = nullptr;
  Ogre::SceneNode* spheres = nullptr;
  Ogre::SceneNode* hoursNeedle = nullptr;
  Ogre::SceneNode* minutesNeedle = nullptr;
  Ogre::SceneNode* secondsNeedle = nullptr;

  //Practica 1.2
  Molino* molino = nullptr;
  RotorDron* rotorDron = nullptr;
  BrazoDron* brazoDron = nullptr;
  Dron* dron = nullptr;
 
private:
    void simbadScene(); //Practica 0
    void sphereClockScene(); //Practica 1.0
    void molinoScene(); //Pratica 1.1
};

#endif
