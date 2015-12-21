#include "GameScene.h"
#include "Hero.h"

USING_NS_CC;

Hero::Hero() {}

Hero::~Hero() {}

Hero* Hero::create()
{
	Hero* pSprite = new Hero();

	if (pSprite->initWithFile("NickColtrane_estatic.png"))
	{
		pSprite->autorelease();

		pSprite->initOptions();

		pSprite->addEvents();

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void Hero::initOptions()
{
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	_heroVector = Vec2::ZERO;
	_isMoving = false;
	_combatMode = false;
	green = false;
	blue = false;
	levelRed = 4;
	levelBlue = 4;
	levelGreen = 4;
}

void Hero::addEvents()
{
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

/*
PLACEHERO
Coloca al personaje principal en su posicion inicial
*/
void Hero::placeHero(Size vS) {

	Size visibleSize = vS;
	heroSmallRadius = this->getContentSize().width / 2.5;
	heroBigRadius = this->getContentSize().width;
	heroSmallCircle = DrawNode::create();
	heroSmallCircle->drawCircle(this->getPosition(), heroSmallRadius, 1.0, 20, false, Color4F(1, 0, 0, 1));
	heroBigCircle = DrawNode::create();
	heroBigCircle->drawCircle(this->getPosition(), heroBigRadius, 1.0, 20, false, Color4F(0, 1, 0, 1));
	this->setPosition(Point(visibleSize.width / 2, ((visibleSize.height / 2) - this->getContentSize().height / 2 -100))); //El +5 es para cuadrarlo justo sobre el suelo
	heroSmallCircle->setPosition(this->getPosition());
	heroBigCircle->setPosition(this->getPosition());

	//heroCircle->retain();
	log("TEST: radio del circuloPequeñoHeroe %f", this->getContentSize().width / 3.5);

}

/*
ONKEYPRESSED
Comportamiento de las teclas al pulsarlas
*/
void Hero::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	auto _pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_isMoving = true;
		_heroVector = Vec2(-HERO_STEP_MOVE, 0);
		this->setScaleX(-1.0);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_isMoving = true;
		_heroVector = Vec2(HERO_STEP_MOVE, 0);
		this->setScaleX(1.0);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		_combatMode = true;
		log("Coltrane esta en modo combate");
		this->setTexture("NickColtrane_combat.png");
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		_combatMode = false;
		log("Coltrane esta en modo normal");
		this->setTexture("NickColtrane_estatic.png");
		break;
	case EventKeyboard::KeyCode::KEY_Q:
		red = true;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		blue = true;
		break;
	case EventKeyboard::KeyCode::KEY_E:
		green = true;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		if (this->_combatMode) {
			if (red) {
				red = false;
				levelRed--;

			}
			else if (blue) {
				blue = false;
				levelBlue--;

			}
			else if (green) {
				green = false;
				levelGreen--;

			}
			this->_isHitting = true;
		}
		break;
	}

}

/*
ONKEYRELEASED
Comportamiento al levantar las teclas
*/
void Hero::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {

	auto _pressedKey = keyCode;
	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_SPACE:
		this->_isHitting = false;
		break;
	}
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
		_isMoving = false;
		_heroVector = Vec2::ZERO;
		this->_isHitting = false;
	}
}

/*
UPDATE ahora mismo se llama cada frame
-Mueve el personaje si hemos pulsado la tecla
*/
void Hero::updateHero(Size vS, double backgroundWidth) {

	Size visibleSize = vS;

	if (this->_isMoving) {

		Vec2 newPos = Vec2(this->getPosition().x + _heroVector.x, this->getPosition().y + _heroVector.y);
		if (newPos.x >= (visibleSize.width - backgroundWidth + this->getBoundingBox().size.width / 2 + 10) &&
			newPos.x <= (visibleSize.width - this->getBoundingBox().size.width / 2 - 10)) {
			this->setPosition(newPos);
		}
		
		heroSmallCircle->setPosition(this->getPosition());
		heroBigCircle->setPosition(this->getPosition());


	}
	

	//log("posicion del hero: %i X %i Y   / posicion del circulo: %i X %i Y"),this->getPosition().x, this->getPosition().y,heroCircle->getPosition().x, heroCircle->getPosition().y;

}