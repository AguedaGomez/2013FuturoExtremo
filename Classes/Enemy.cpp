#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
Enemy* Enemy::create()
{
	Enemy * pSprite = new Enemy();
	log("Se ha creado enemigo");

	if (pSprite->initWithFile("enemigo1Apagado.png")) {

		pSprite->autorelease();
		pSprite->initOptions();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}
/*INITOPTIONS
Inicializa los atributos que necesita el enemigo
*/
void Enemy::initOptions()
{
	enemyBigRadius = this->getContentSize().width / 2;
	enemySmallRadius = this->getContentSize().width / 3;
	enemySmallCircle = DrawNode::create();
	enemySmallCircle->drawCircle(this->getPosition(), enemySmallRadius, 1.0, 30, false, Color4F(1, 0, 0, 1));
	enemyBigCircle = DrawNode::create();
	enemyBigCircle->drawCircle(this->getPosition(), enemyBigRadius, 1.0, 30, false, Color4F(0, 1, 0, 1));
	//log("TEST:  radio del circulo pequeñoEnemigo %f ",  this->getContentSize().width / 3.5);
	log("Enemigo esta en modo neutral");
	mood = 3;
	left = false;
	this->schedule(schedule_selector(Enemy::selectionActionMood), 2.0);	
}

/*
SELECTIONACTIONMOOD
Si el enemigo esta en modo 3 (pelear con nick), se crea un numero aleatorio en el que puede pegar
o moverse hacia atras o hacia delante
*/
void Enemy::selectionActionMood(float dt)
{
	if (mood == 3) {
		_agressive = true;
		auto moveToRight = MoveTo::create(1, Vec2(this->getPositionX() + 20, this->getPositionY()));
		auto moveToLeft = MoveTo::create(1, Vec2(this->getPositionX() - 20, this->getPositionY()));
		auto seq = Sequence::create(moveToRight, moveToLeft, nullptr);
		combatAction = cocos2d::RandomHelper::random_int(1, 2);
		//log("%d", combatAction);

		switch (combatAction) {
		case 1:
			//animacion en reposo
			_atacking = true;
			//log("pegando");
			break;
		case 2:
			// secuencia de movimiento hacia atras y hacia delante
			_atacking = false;
			this->runAction(seq);
			break;
		}
	}


}

void Enemy::placeEnemy(int x, int y)
{
	this->setPosition(Vec2(x,y));
}

/*
UPDATEENEMY
cada frame, se comprueba en qué modo está el enemigo.
modo 1: está en modo neutral. Pasea de un lado al otro
modo 2: está en modo agresivo. Nick ha entrado en el rango de visión del enemigo y va a por él
Se actualiza también la posición de los círculos asociados con el enemigo para poder hacer colisiones
*/
void Enemy::updateEnemy()
{
	switch (mood) {
	case 1:
		if (this->getPositionX() < posIni)
			left = false;
		else if ((this->getPositionX() - posIni) > 300)
			left = true;
		if (left) {
			this->setScaleX(1.0);
			this->setPositionX(this->getPositionX() - 3);
		}

		else {
			this->setScaleX(-1.0);
			this->setPositionX(this->getPositionX() + 3);
		}
		break;
	case 2:
		//perseguir a nick hasta que entre en rango de combate
		break;

	}

	enemySmallCircle->setPosition(this->getPosition());
	enemyBigCircle->setPosition(this->getPosition());
}
	

