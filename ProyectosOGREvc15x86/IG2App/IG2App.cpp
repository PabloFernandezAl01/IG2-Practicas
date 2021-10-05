#include "IG2App.h"

#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>

using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
  if (evt.keysym.sym == SDLK_ESCAPE)
  {
      getRoot()->queueEndRendering();
  }
  else if (evt.keysym.sym == SDLK_g) {
	  //clock->roll(Ogre::Degree(-1)); //Practica 1.1
	  //aspasMolino->giraAspasMolino(1);

	  //molino->giraAspasMolino(2);
	  //rotorDron->giraAspas(2);
	  
	  //brazoDron->giraAspas(2);

	  //dron->giraAspas(5);
  }
  else if (evt.keysym.sym == SDLK_h) {
	  //spheres->roll(Ogre::Degree(-1)); //Practica 1.1
	  //molino->giraAspas(-2);

	  mueveDron();
  }
  else if (evt.keysym.sym == SDLK_c) {
	  //molino->mueveCilindroCentral(-1);
  }
  else if (evt.keysym.sym == SDLK_j) {
	  rotaDron();
  }
  return true;
}

void IG2App::shutdown()
{
  mShaderGenerator->removeSceneManager(mSM);  
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);  

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
  // do not forget to call the base first
  IG2ApplicationContext::setup();

  mSM = mRoot->createSceneManager();  

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(mSM);

  mSM->addRenderQueueListener(mOverlaySystem);

  mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);  
  mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(mTrayMgr);

  addInputListener(this);   
  setupScene();
}

void IG2App::setupScene(void)
{
  // create the camera
  Camera* cam = mSM->createCamera("Cam");
  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);
  //cam->setPolygonMode(Ogre::PM_WIREFRAME); 

  mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
  mCamNode->attachObject(cam);

  mCamNode->setPosition(0, 0, 1000);
  mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
  //mCamNode->setDirection(Ogre::Vector3(0, 0, -1));  
  
  // and tell it to render into the main window
  Viewport* vp = getRenderWindow()->addViewport(cam);
  vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

  //------------------------------------------------------------------------

  // without light we would just get a black screen 

  Light* luz = mSM->createLight("Luz");
  luz->setType(Ogre::Light::LT_DIRECTIONAL);
  luz->setDiffuseColour(0.75, 0.75, 0.75);

  mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
  //mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode->attachObject(luz);

  mLightNode->setDirection(Ogre::Vector3(0, -1, -1));  //vec3.normalise();
  //lightNode->setPosition(0, 0, 1000);
 
  //------------------------------------------------------------------------

  mCamMgr = new OgreBites::CameraMan(mCamNode);
  addInputListener(mCamMgr);
  mCamMgr->setStyle(OgreBites::CS_ORBIT);

  //mCamMgr->setTarget(mSinbadNode);  
  //mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

  //------------------------------------------------------------------------

  // finally something to render

   planetScene();
   //molinoScene();
}


//Practica 0
void IG2App::simbadScene() {
	//Simbad
	Ogre::Entity* ent = mSM->createEntity("Sinbad.mesh");

	mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
	mSinbadNode->attachObject(ent);
	mSinbadNode->setScale(20, 20, 20);

	//mSinbadNode->setPosition(400, 100, -300);
	//mSinbadNode->yaw(Ogre::Degree(-45));
	//mSinbadNode->showBoundingBox(true);
	//mSinbadNode->setVisible(false);


	//Sword
	//Ogre::Entity* ent1 = mSM->createEntity("Sword.mesh");

	//mSwordNode = mSM->getRootSceneNode()->createChildSceneNode("nSword");
	//mSwordNode->attachObject(ent1);
	//mSwordNode->setScale(30, 30, 30);
	//mSwordNode->yaw(Ogre::Degree(45)); //Giro la espada para que la luz le incida en todo su contorno


	//Helmet
	/*Ogre::Entity* ent2 = mSM->createEntity("DamagedHelmet.mesh");

	mHelmetNode = mSM->getRootSceneNode()->createChildSceneNode("nHelmet");
	mHelmetNode->attachObject(ent2);
	mHelmetNode->setScale(30, 30, 30);
	mHelmetNode->yaw(Ogre::Degree(90));*/


	//Cabeza de Ogre
	/*Ogre::Entity* ent3 = mSM->createEntity("ogrehead.mesh");

	mOgreHeadNode = mSM->getRootSceneNode()->createChildSceneNode("nOgreHead");
	mOgreHeadNode->attachObject(ent3);
	mOgreHeadNode->setScale(10, 10, 10);*/

	//Facial
   /* Ogre::Entity* ent4 = mSM->createEntity("facial.mesh");

	mFacialNode = mSM->getRootSceneNode()->createChildSceneNode("nFacial");
	mFacialNode->attachObject(ent4);
	mFacialNode->setScale(5, 5, 5);*/

	//Escenario

	Ogre::Entity* ent5 = mSM->createEntity("Columns.mesh");

	mColumnsNode = mSM->getRootSceneNode()->createChildSceneNode("nColumns");
	mColumnsNode->attachObject(ent5);


	Ogre::Entity* ent6 = mSM->createEntity("RomanBathLower.mesh");

	mBathLower = mSM->getRootSceneNode()->createChildSceneNode("nBathLower");
	mBathLower->attachObject(ent6);


	Ogre::Entity* ent7 = mSM->createEntity("RomanBathUpper.mesh");

	mBathUpper = mSM->getRootSceneNode()->createChildSceneNode("nBathUpper");
	mBathUpper->attachObject(ent7);
}

//Practica 1.0
void IG2App::sphereClockScene() {
	clock = mSM->getRootSceneNode()->createChildSceneNode("Clock");
	spheres = clock->createChildSceneNode("Spheres");

	float ang = 90;
	float x, y;

	//Esferas
	for (int i = 0; i < 12; i++) {
		std::string name = "Hora" + std::to_string(i+1);
		Ogre::Entity* ent = mSM->createEntity("sphere.mesh");
		mHourNode[i] = spheres->createChildSceneNode(name);
		mHourNode[i]->attachObject(ent);

		x = 300 * Ogre::Math::Cos(Ogre::Math::DegreesToRadians(ang));
		y = 300 * Ogre::Math::Sin(Ogre::Math::DegreesToRadians(ang));
		ang += (360 / 12);

		mHourNode[i]->setPosition(Vector3(x, y, 0));

		mSM->getSceneNode(name)->setScale(0.4, 0.4, 0.4);

		if(i % 2 == 0) mSM->getSceneNode(name)->setScale(0.2, 0.2, 0.2);
		else mSM->getSceneNode(name)->setScale(0.4, 0.4, 0.4);
	}

	//Agujas
	Ogre::Entity* ent1 = mSM->createEntity("cube.mesh");
	Ogre::Entity* ent2 = mSM->createEntity("cube.mesh");
	Ogre::Entity* ent3 = mSM->createEntity("cube.mesh");
	hoursNeedle = clock->createChildSceneNode("HoursNeedle");
	minutesNeedle = clock->createChildSceneNode("MinutesNeedle");
	secondsNeedle = clock->createChildSceneNode("SecondsNeedle");

	hoursNeedle->attachObject(ent1);
	minutesNeedle->attachObject(ent2);
	secondsNeedle->attachObject(ent3);

	/*
	* Yaw, pitch y roll -> eje TS::LOCAL
	* setScale -> eje TS::LOCAL
	* translate y setPosition -> TS::PARENT
	*/

	hoursNeedle->setScale(Vector3(0.15, 2.5, 0.1));
	hoursNeedle->setPosition(Vector3(100, 0, 0));
	hoursNeedle->roll(Ogre::Degree(-90));

	minutesNeedle->setScale(Vector3(0.1, 2.2, 0.1));
	minutesNeedle->setPosition(Vector3(0, 90, 0));

	secondsNeedle->setScale(Vector3(0.08, 1.8, 0.1));
	secondsNeedle->setPosition(Vector3(-45, -45, 0));
	secondsNeedle->roll(Ogre::Degree(-225));

}

//Practica 1.1
void IG2App::molinoScene() {
	//aspasMolino = new AspasMolino(mSM, mSM->getRootSceneNode(), 12, 0);
	//molino = new Molino(mSM, 6);
	//rotorDron = new RotorDron(mSM, 6);
	//brazoDron = new BrazoDron(mSM, 6);
	//dron = new Dron(mSM, mSM->getRootSceneNode(),  12, 8);
}

void IG2App::planetScene() {
	planetaNode = mSM->getRootSceneNode()->createChildSceneNode("mPlanetaNode");

	auto esferaP = mSM->createEntity("sphere.mesh");
	esferaPlaneta = planetaNode->createChildSceneNode("mEsferaPlaneta");
	esferaPlaneta->attachObject(esferaP);

	ficticioDronNode = planetaNode->createChildSceneNode("mFicticioDronNode");

	dronPlaneta = new Dron(mSM, ficticioDronNode, 12, 8);

	dronPlaneta->getNode()->setScale(0.05, 0.05, 0.05);
	dronPlaneta->getNode()->translate(0, 320, 0);
	esferaPlaneta->setScale(3, 3, 3);	
}

void IG2App::mueveDron() {
	//ficticioDronNode->roll(Ogre::Degree(-4));

	dronPlaneta->getNode()->translate(0, -320, 0, SceneNode::TS_LOCAL);
	dronPlaneta->getNode()->roll(Ogre::Degree(-4));
	dronPlaneta->getNode()->translate(0, 320, 0, SceneNode::TS_LOCAL);
}
void IG2App::rotaDron() {
	//ficticioDronNode->yaw(Ogre::Degree(-4));

	dronPlaneta->getNode()->yaw(Ogre::Degree(-4));
}

