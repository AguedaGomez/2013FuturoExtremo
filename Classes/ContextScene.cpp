#include "ContextScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* ContextScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ContextScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ContextScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	
	//Eventos/Callbacks de teclado
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(ContextScene::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(ContextScene::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	

    Size visibleSize = Director::getInstance()->getVisibleSize();
	auto provisionalText = Label::createWithTTF("Pantalla de contexto", "Marker Felt.ttf", 24);
	provisionalText->setPosition(Vec2(600, 600));
	addChild(provisionalText, 0);
    return true;
}


void ContextScene::goToGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

/*
ONKEYPRESSED
Comportamiento de las teclas al pulsarlas
*/
void ContextScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	auto _pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		goToGameScene(this);
		break;
	}	
}

/*
ONKEYRELEASED
Comportamiento al levantar las teclas
*/
void ContextScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

	auto _pressedKey = keyCode;

	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}