#ifndef _ENEMY_H__
#define _ENEMY_H__

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public cocos2d::Sprite
{
public:
	bool _agressive;
	bool _atacking;

	float enemySmallRadius;
	float enemyBigRadius;


	Enemy();
	~Enemy();
	static Enemy* create();

	void initOptions();
	void updateEnemy();
	void selectionActionMood(float dt);
	void placeEnemy(int x, int y);

	DrawNode *enemySmallCircle;
	DrawNode *enemyBigCircle;
	int posIni;
	bool atack;

	
private:
	int mood;
	int combatAction;
	bool left;

};

#endif // _MYSPRITE_HPP_
