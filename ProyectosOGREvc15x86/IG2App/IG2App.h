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
#include "Avion.h"
#include "Plano.h"
#include "EntityIG.h"
#include "Simbad.h"
#include "Bomba.h"
#include <vector>
#include <OgreParticleSystem.h>
#include <OgreParticleSystemManager.h>
#include <OgreParticleSystemRenderer.h>
#include <OgreBillboard.h>
#include <OgreBillboardParticleRenderer.h>

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
  AspasMolino* aspasMolino = nullptr;
  Molino* molino = nullptr;
  RotorDron* rotorDron = nullptr;
  BrazoDron* brazoDron = nullptr;
  Dron* dron = nullptr;

  //Entrega 2
  Ogre::SceneNode* ficticioDronNode = nullptr;
  Ogre::SceneNode* dronNode = nullptr;

  Ogre::SceneNode* ficticioAvionNode = nullptr;
  Ogre::SceneNode* avionNode = nullptr;

  Ogre::SceneNode* esferaPlaneta = nullptr;
  Dron* dronPlaneta = nullptr;
  Avion* avion = nullptr;

  Plano* plano = nullptr;
  Ogre::SceneNode* planoNode = nullptr;

  Plano* planoAmarillo = nullptr;
  Ogre::SceneNode* planoAmarilloNode = nullptr;

  Plano* planoRojo = nullptr;
  Ogre::SceneNode* planoRojoNode = nullptr;

  Ogre::Light* luzFocoDron = nullptr;
  Ogre::Light* luzFocoAvion = nullptr;

  Simbad* simbad = nullptr;
  Ogre::SceneNode* ficticioSimbadNode = nullptr;
  Ogre::SceneNode* simbadNode = nullptr;

  std::vector<Dron*> miniDrones;
  std::vector<Ogre::SceneNode*> nodosFicticios;
  std::vector<Ogre::SceneNode*> nodosDron;

  Dron* dronControl = nullptr;
  Ogre::SceneNode* dronControlNode = nullptr;
  Ogre::SceneNode* ficticioDronControlNode = nullptr;

  //Entrega 3
  Bomba* bomba = nullptr;
  Ogre::SceneNode* bombaNode = nullptr;

  Ogre::Entity* caritaFelizEnt = nullptr;
  Ogre::SceneNode* caritaFelizNode = nullptr;

  BillboardSet* bbSet = nullptr;
  
  ParticleSystem* pSystem = nullptr;
  Ogre::SceneNode* nieblaNode = nullptr;

private:
    void simbadScene(); //Practica 0
    void sphereClockScene(); //Practica 1.0
    void molinoScene(); //Pratica 1.1
    void planetScene(); //Entrega 2
    void avionScene(); //Ejercicio 21
    void escenaConFondo();
    void cazaDrones();
    void escenaAgua(); //Ejercicio 47
};

#endif
