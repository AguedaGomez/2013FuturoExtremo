#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	setMenuBackground();

   

	auto botonPlay = MenuItemImage::create("play_off.png", "play_on.png", CC_CALLBACK_1(MainMenu::goToGameScene,this));

	auto menu = Menu::create(botonPlay, NULL);

    Size visibleSize = Director::getInstance()->getVisibleSize();

	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	addChild(menu, 1);

    
    return true;
}

/*
SETMENUBACKGROUND
Establece el Fondo
*/
void MainMenu::setMenuBackground() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Carga el fondo
	menubackground = Sprite::create("inicio_provisional.jpg");
	menubackground->setPosition(Point((visibleSize.width - menubackground->getContentSize().width / 2),(visibleSize.height / 2)));
	addChild(menubackground, 0);
}



void MainMenu::goToGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}