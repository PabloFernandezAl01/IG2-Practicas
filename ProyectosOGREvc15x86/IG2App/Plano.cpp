#include "Plano.h"

Plano::Plano(Ogre::SceneNode* node, std::string entName, std::string materialName, Carita* cF) : EntityIG(node){

	entName_ = entName;
	carafeliz = cF;
	//Plano
	Ogre::MeshManager::getSingleton().createPlane(entName,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		1080, 1080, 100, 80, true, 1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	plano = mSM->createEntity(entName);
	if(materialName != "") plano->setMaterialName(materialName);

	mNode->attachObject(plano);

	timeToChangeMaterial = 0;

	if (entName_ == "mPlane1080x1080") {
		camRef = mSM->createCamera("camRef");
	}
	else if (entName_ == "mPlaneEspejo1080x800") {
		camRefEspejo = mSM->createCamera("camRefEspejo");
	}
	
}

Ogre::SceneNode* Plano::getNode() {
	return mNode;
}

void Plano::receiveEvent(MessageType msgType, EntityIG* entidad) {
	switch (msgType)
	{
	case MessageType::T_EVENT: {
		if (entName_ == "mPlane1080x1080") canCount = true;
		break;
	}
	default:
		break;
	}
}

void Plano::frameRendered(const Ogre::FrameEvent& evt) {
	if (canCount) {

		timeToChangeMaterial += evt.timeSinceLastFrame;
		if (timeToChangeMaterial >= 5) {
			plano->setMaterialName("piedras");
			canCount = false;
		}
	}
}

void Plano::setReflejo(Ogre::Camera* cam) {
	cam->getParentSceneNode()->attachObject(camRef);

	mpRef = new Ogre::MovablePlane(Ogre::Vector3::UNIT_Y, 0);
	mNode->attachObject(mpRef);

	camRef->setNearClipDistance(1);
	camRef->setFarClipDistance(10000);
	camRef->enableReflection(mpRef);
	camRef->enableCustomNearClipPlane(mpRef);

	TexturePtr rttRef = TextureManager::getSingleton().createManual(
		"rttReflejo", // ojo, nombre único -> (*)
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		TEX_TYPE_2D,
		(Real)cam->getViewport()->getActualWidth(), // ejemplo
		(Real) cam->getViewport()->getActualHeight(), // ejemplo
		0, PF_R8G8B8, TU_RENDERTARGET);

	RenderTexture* renderTexture = rttRef->getBuffer()->getRenderTarget();
	if (carafeliz != nullptr)renderTexture->addListener(carafeliz);
	Viewport* vpt = renderTexture->addViewport(camRef);
	vpt->setClearEveryFrame(true);
	vpt->setBackgroundColour(ColourValue::Black);

	TextureUnitState* tu = plano->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0)->
		createTextureUnitState("rttReflejo"); // <- (*)
	tu->setColourOperation(LBO_ADD); // black background
	// LBO_ADD / LBO_ALPHA_BLEND / LBO_REPLACE
	tu->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);

	tu->setProjectiveTexturing(true, camRef);
}

void Plano::setEspejo(Camera* cam) {
	cam->getParentSceneNode()->attachObject(camRefEspejo);

	mpRefEspejo = new Ogre::MovablePlane(Ogre::Vector3::UNIT_Y, 0);
	mNode->attachObject(mpRefEspejo);

	camRefEspejo->setNearClipDistance(1);
	camRefEspejo->setFarClipDistance(10000);
	camRefEspejo->enableReflection(mpRefEspejo);
	camRefEspejo->enableCustomNearClipPlane(mpRefEspejo);

	TexturePtr rttRef = TextureManager::getSingleton().createManual(
		"rttReflejoEspejo", // ojo, nombre único -> (*)
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		TEX_TYPE_2D,
		(Real)cam->getViewport()->getActualWidth(), // ejemplo
		(Real)cam->getViewport()->getActualHeight(), // ejemplo
		0, PF_R8G8B8, TU_RENDERTARGET);

	RenderTexture* renderTexture = rttRef->getBuffer()->getRenderTarget();
	Viewport* vpt = renderTexture->addViewport(camRefEspejo);
	vpt->setClearEveryFrame(true);
	vpt->setBackgroundColour(ColourValue::Black);

	TextureUnitState* tu = plano->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0)->
		createTextureUnitState("rttReflejoEspejo"); // <- (*)
	tu->setColourOperation(LBO_REPLACE); // black background
	// LBO_ADD / LBO_ALPHA_BLEND / LBO_REPLACE
	tu->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);

	tu->setProjectiveTexturing(true, camRefEspejo);
}
