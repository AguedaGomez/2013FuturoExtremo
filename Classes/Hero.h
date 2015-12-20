#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d::ui;

class Hero : public cocos2d::Sprite
{
public:

	bool _isMoving;
	bool _combatMode;
	int levelRed;
	int levelGreen;
	int levelBlue;
	bool red;
	bool green;
	bool blue;
	

	Hero();
	~Hero();

	static Hero* create();

	void initOptions();

	void addEvents();

	void placeHero(Size vS);
	void updateHero(Size vS, double backgroundWidth);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

private:
	Vec2 _heroVector;
	EventKeyboard::KeyCode _pressedKey;

};

#endif 

