#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include "EnemiesManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"



USING_NS_CC;



class GameScene: public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Sprite *background;
	Sprite *futureBAnimation;
	Hero *hero;
	CollisionManager *collisionManager;

	void update(float dt);

public:
	static cocos2d::Scene* createScene();
	Sprite *_playerSprite;
	EnemiesManager *enemiesManager;
	ObjectManager *objectManager;
	int nivel;

	virtual bool init();

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);

	void setBackground();
	void futureBuilding();
	void initEnemiesManager();
	void initObjectManager();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);



	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

};

#endif 

