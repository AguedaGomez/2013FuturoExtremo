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

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//inciar la variable de de las teclas
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	_heroVector = Vec2::ZERO; 
	_isMoving = false;
	_combatMode = false;

	//imagen personaje 
	//auto polygonInfo = AutoPolygon::generatePolygon("pers.png");
	characterSprite = Sprite::create("pers.png");
	characterSprite->setPosition(Point((visibleSize.width/2),(visibleSize.height/2)));
	addChild(characterSprite,1);

	//Eventos/Callbacks de teclado
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	


	//Lamada a update en intervalos de tiempo
	this->schedule(schedule_selector(GameScene::update),0); 
	return true;
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	auto _pressedKey = keyCode;

	switch (_pressedKey){
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			goToPauseScene(this);
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			_isMoving = true;
			_heroVector = Vec2(-HERO_STEP_MOVE, 0);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			_isMoving = true;
			_heroVector = Vec2(HERO_STEP_MOVE, 0);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			_combatMode = true;
			log("Coltrane esta en modo combate");
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			_combatMode = false;
			log("Coltrane esta en modo normal");
			break;
	}
	
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

	auto _pressedKey = keyCode;

	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_heroVector = Vec2::ZERO;
	}
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

void GameScene::update(float dt) {

	//Size visibleSize = Director::getInstance()->getVisibleSize();

	if (_isMoving) {
		//characterSprite->runAction(moveby);
		Vec2 newPos = Vec2(characterSprite->getPosition().x + _heroVector.x, characterSprite->getPosition().y + _heroVector.y);

		characterSprite->setPosition(newPos);
	}

	
}