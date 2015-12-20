#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "EnemiesManager.h"


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

/*
	INIT
	Inicia todo lo que hace falta para la escena, sólo una vez y sólo al ser creada.

*/

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
	futureBuilding();
	nivel = 0;

	/*Se crea un objeto que maneja todos los enemigos
	con un bucle se recorre el vector que contiene todos los enemigos
	para que aparezcan en escena
	*/
	enemiesManager = EnemiesManager::create();
	enemiesManager->createEnemies(nivel);
	enemiesManager->retain();
	for (int i = 0; i < enemiesManager->enemies.size(); i++) {
		addChild(enemiesManager->enemies.at(i), 1);
		addChild(enemiesManager->enemies.at(i)->circle, 1);
	}
	
	

	futureBuilding();
	hero = Hero::create();
	hero->initOptions();
	hero->placeHero(Director::getInstance()->getVisibleSize());
	addChild(hero, 1);
	//inciar la variable de de las teclas
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	
	//Eventos/Callbacks de teclado
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	//Scroll 
	this->runAction(Follow::create(hero, Rect::ZERO));

	//Lamada a update en intervalos de tiempo
	this->schedule(schedule_selector(GameScene::update),0); 


	return true;
}

/*
	SETBACKGROUND
	Establece el Fondo
*/
void GameScene::setBackground() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Carga el fondo
	background = Sprite::create("fondo.png");
	background->setPosition(Point((visibleSize.width - background->getContentSize().width / 2), (visibleSize.height / 2)- 120));
	addChild(background, 0);
}



/* 
	FUTUREBUILDING
Carga y reproduce animacion cartel
*/
void GameScene::futureBuilding() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	SpriteFrameCache *frameCache = SpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("futureB.plist");
	SpriteBatchNode  *spritesheet = SpriteBatchNode::create("futureB.png");
	this->addChild(spritesheet);

	Vector<SpriteFrame*> futurebFrames;
	futurebFrames.reserve(12);
	for (int i = 1; i <= 12; i++) {
		String *filename = String::createWithFormat("cartel_%d.png", i);
		SpriteFrame *frame = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
		futurebFrames.pushBack(frame);
	}

	Animation *lightAnim = Animation::createWithSpriteFrames(futurebFrames, 0.1);
	Sprite *fb = Sprite::createWithSpriteFrameName("cartel_1.png");

	fb->setPosition(ccp(visibleSize.width-fb->getContentSize().width+180, visibleSize.height*0.5+120-125));

	Action *action = RepeatForever::create(Animate::create(lightAnim));

	fb->runAction(action);
	spritesheet->addChild(fb);
}

/*
	ONKEYPRESSED
	Comportamiento de las teclas al pulsarlas
*/
void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	auto _pressedKey = keyCode;

	switch (_pressedKey){
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			goToPauseScene(this);
			break;	
	}
	
}

/*
	ONKEYRELEASED
	Comportamiento al levantar las teclas
*/
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

	auto _pressedKey = keyCode;

	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		
	}
}

/*
	GOTOPAUSESCENE
	Crea la escena de pausa y hace un push
*/
void GameScene::goToPauseScene(Ref *pSender)
{
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}

/*	
	GOTOGAMEOVERSCENE
	crea la escena de muerte y hace un replace
	
*/
void GameScene::goToGameOverScene(Ref *pSebder)
{
	auto scene = GameOverScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

/*
	UPDATE ahora mismo se llama cada frame
		-Mueve el personaje si hemos pulsado la tecla
*/
void GameScene::update(float dt) {

	Size visibleSize = Director::getInstance()->getVisibleSize();

	hero->updateHero(visibleSize, background->getContentSize().width);

	enemiesManager->updateEnemies();
	
}
