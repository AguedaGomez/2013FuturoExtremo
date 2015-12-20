#ifndef __ENEMIES_MANAGER_H__
#define __ENEMIES_MANAGER_H__

#include "cocos2d.h"
#include "Enemy.h"

class EnemiesManager : public cocos2d::Ref
{
public:
	EnemiesManager();
	~EnemiesManager();

	static EnemiesManager* create();

	Vector<Enemy*> enemies;
	void createEnemies(int nivel);

	void updateEnemies();

	void destroyEnemies();

};

#endif 

