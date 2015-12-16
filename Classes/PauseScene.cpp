#include "PauseScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* PauseScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PauseScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PauseScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto menuBotton = MenuItemImage::create("exit_off.png", "exit_on.png", CC_CALLBACK_1(PauseScene::goToMainMenu, this));
	auto playBotton = MenuItemImage::create("resume_off.png", "resume_on.png", CC_CALLBACK_1(PauseScene::retryGameScene, this));
	auto menu = Menu::create(menuBotton, playBotton, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	addChild(menu, 1);
	
	return true;
}

void PauseScene::resumeGameScene(Ref *pSeder)
{
	Director::getInstance()->popScene();
}

void PauseScene::goToMainMenu(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseScene::retryGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->popScene();
}

