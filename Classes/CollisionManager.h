#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

#include "cocos2d.h"

class CollisionManager : public cocos2d::Ref
{
public:
	CollisionManager();
	~CollisionManager();

	static CollisionManager* create();

	void initCollisions(Hero *hero, Vector<Enemy*> enemies,Vector<ObjectWithRadius*>objects);

	void updateCollisions();

	void enemiesHitHero();
	void heroHitsEnemies();
	void heroTouchObject();
	void heroHitsObject();

private:
	Hero *hero;
	Vector<Enemy*> enemies;
	Vector<ObjectWithRadius*> objects;


};

#endif 

