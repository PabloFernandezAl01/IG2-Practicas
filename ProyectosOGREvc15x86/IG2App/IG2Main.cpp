
#include "IG2App.h"

int main(int argc, char *argv[])     
{
    //Comentario de prueba
	IG2App app;
  try {
    app.initApp();
    app.getRoot()->startRendering();
  }
  catch (Ogre::Exception& e) {
    Ogre::LogManager::getSingleton().logMessage("An exception has occured: " + e.getFullDescription() + "\n");
  }
  app.closeApp();
  return 0;
}