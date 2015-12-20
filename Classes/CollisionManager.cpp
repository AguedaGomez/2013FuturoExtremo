#include "GameScene.h"
#include "CollisionManager.h"

USING_NS_CC;

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

CollisionManager * CollisionManager::create()
{
	CollisionManager * ob = new CollisionManager();
	if (ob) {
		ob->autorelease();
		return ob;
	}
	CC_SAFE_DELETE(ob);
	return nullptr;
}

void CollisionManager::initCollisions(Hero * hero, Vector<Enemy*> enemies /*Vector<DrawNode*> objects*/)
{
	this->hero = hero;
	this->enemies = enemies;
	//this->objectsCircles = objects;
}

void CollisionManager::updateCollisions()
{
	bool enemyAtacking = false;

	if (hero->_combatMode && hero->_isHitting) {
		heroHitsEnemies();
		heroHitsObject();
	}
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies.at(i)->_atacking)
			enemyAtacking = true;
	}
	if (enemyAtacking) {
		enemiesHitHero();
	}
	if (hero->_combatMode == false) {
		heroTouchObject();
	}
}

void CollisionManager::enemiesHitHero()
{

	//log("ENEMIESHITHERO");

	float hX = hero->getPositionX();
	float hY = hero->getPositionY();
	float eX;
	float eY;
	
	for (int i = 0; i < enemies.size(); i++) {
		eX = enemies.at(i)->getPositionX();
		eY = enemies.at(i)->getPositionY();
		
		if ((ccpDistance(Vec2(hX, hY), Vec2(eX, eY)) < (enemies.at(i)->enemyBigRadius + hero->heroSmallRadius))&&(enemies.at(i)->_atacking)) {
			log("ENEMIGO PEGA A NICK");
		}
		/*if (hero->heroSmallCircle->getBoundingBox().intersectsCircle(enemies.at(i)->getPosition(), enemies.at(i)->enemyBigRadius)) {
			log("ENEMIGO PEGA A NICK 2da forma");
		}
		/*if (hero->heroSmallCircle->getBoundingBox().intersectsRect(enemies.at(i)->getBoundingBox())); {
			log("ENEMIGO PEGA A NICK 3a forma"); 
		}*/
	}
}

void CollisionManager::heroHitsEnemies()
{
	if (hero->_isHitting) {
		float hX = hero->getPositionX();
		float hY = hero->getPositionY();
		float eX;
		float eY;
		log("Nick lanza un golpe");
		for (int i = 0; i < enemies.size(); i++) {
			eX = enemies.at(i)->getPositionX();
			eY = enemies.at(i)->getPositionY();
			if (ccpDistance(Vec2(hX, hY), Vec2(eX, eY)) < (enemies.at(i)->enemySmallRadius + hero->heroBigRadius)) {
				log("NICK golpea a enemigo%d", enemies.at(i));
			}
		}
	}
	hero->_isHitting = false;
}

void CollisionManager::heroTouchObject()
{
}

void CollisionManager::heroHitsObject()
{
}


