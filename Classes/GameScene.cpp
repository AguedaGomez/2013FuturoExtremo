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
	placeHeroPROVISIONAL();


	//inciar la variable de de las teclas
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	_heroVector = Vec2::ZERO; 
	_isMoving = false;
	_combatMode = false;

	//Eventos/Callbacks de teclado
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

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
	auto background = Sprite::create("fondo.png");
	background->setPosition(Point((visibleSize.width - background->getContentSize().width / 2), (visibleSize.height / 2)));
	addChild(background, 0);
}

/*
	PLACEHEROPROVISIONAL
	Coloca al personaje principal_ esta funcion no va aqui, luego tendrá su propia clase
*/
void GameScene::placeHeroPROVISIONAL() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Carga el personaje
	_playerSprite = Sprite::create("pj.png");
	_playerSprite->setPosition(Point(visibleSize.width / 2, ((visibleSize.height / 2) - _playerSprite->getContentSize().height / 2 + 5))); //El +5 es para cuadrarlo justo sobre el suelo
	addChild(_playerSprite, 1);
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

/*
	ONKEYRELEASED
	Comportamiento al levantar las teclas
*/
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

	auto _pressedKey = keyCode;

	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_heroVector = Vec2::ZERO;
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

	//Size visibleSize = Director::getInstance()->getVisibleSize();

	if (_isMoving) {
		
		Vec2 newPos = Vec2(_playerSprite->getPosition().x + _heroVector.x, _playerSprite->getPosition().y + _heroVector.y);

		_playerSprite->setPosition(newPos);
	}

	
}
