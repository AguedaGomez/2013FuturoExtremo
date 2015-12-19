#ifndef _ENEMY_H__
#define _ENEMY_H__

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public cocos2d::Sprite
{
public:
	

	Enemy();
	~Enemy();
	static Enemy* create();

	void initOptions();
	void updateEnemy();
	void selectionActionMood(float dt);

	DrawNode *circle;
	int posIni;
	bool atack;

	
private:
	int mood;
	int combatAction;
	bool left;

};

#endif // _MYSPRITE_HPP_
