#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"


USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	

	
	setBackground();
	placeHeroPROVISIONAL();


	//inciar la variable de de las teclas
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	//Eventos/Callbacks de teclado
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	
	return true;
}

void GameScene::setBackground() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Carga el fondo
	auto background = Sprite::create("fondo.png");
	background->setPosition(Point((visibleSize.width - background->getContentSize().width / 2), (visibleSize.height / 2)));
	addChild(background, 0);
}

void GameScene::placeHeroPROVISIONAL() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Carga el personaje
	_playerSprite = Sprite::create("pj.png");
	_playerSprite->setPosition(Point(visibleSize.width / 2, ((visibleSize.height / 2) - _playerSprite->getContentSize().height / 2 + 5))); //El +5 es para cuadrarlo justo sobre el suelo
	addChild(_playerSprite, 1);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	goToPauseScene(this);
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	log("tecla %d liberada", keyCode);
}
void GameScene::goToPauseScene(Ref *pSender)
{
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::goToGameOverScene(Ref *pSebder)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
