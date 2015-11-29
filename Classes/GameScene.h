#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

const int HERO_STEP_MOVE = 1;

class GameScene: public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Vec2 _heroVector;
	bool _isMoving;
	bool _combatMode;
	Sprite *characterSprite;

	void update(float dt);

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);



	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	
};

#endif 

