#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

scene::EMD2_ANIMATION_TYPE emat_iterate(scene::EMD2_ANIMATION_TYPE emat)
{
    switch (emat)
    {
	    case scene::EMAT_STAND:
		return scene::EMAT_RUN;
	    case scene::EMAT_RUN:
		return scene::EMAT_ATTACK;
	    case scene::EMAT_ATTACK:
		return scene::EMAT_PAIN_A;
	    case scene::EMAT_PAIN_A:
		return scene::EMAT_PAIN_B;
	    case scene::EMAT_PAIN_B:
		return scene::EMAT_PAIN_C;
	    case scene::EMAT_PAIN_C:
		return scene::EMAT_STAND;
	default:
		return scene::EMAT_BOOM;

    }
}

int main()
{
    scene::EMD2_ANIMATION_TYPE ematcurrent = scene::EMAT_STAND;
    IrrlichtDevice* device = createDevice( video::EDT_OPENGL, dimension2d<u32>(640,480), 16, false, false, false, 0);

    if (!device)
        return 1;
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", rect<s32>(10,10,260,22), true);
    IAnimatedMesh* mesh = smgr->getMesh("/usr/share/irrlicht/media/sydney.md2");
    if (!mesh)
    {
         device->drop();
	 return 1;
    }
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

    if (node)
    {
	    node->setMaterialFlag(EMF_LIGHTING, false);
	    node->setMD2Animation(emat_iterate(ematcurrent));
	    node->setMaterialTexture( 0, driver->getTexture("/usr/share/irrlicht/media/sydney.bmp") );
    }

    smgr->addCameraSceneNode(0, vector3df(0,30,-40),vector3df(0,5,0) );

    while(device->run())
    {
	    driver->beginScene(true, true, SColor(255,100,101,140) );
	    smgr->drawAll();
	    guienv->drawAll();

	    driver->endScene();
    }
    device->drop();

    return 0;
}

