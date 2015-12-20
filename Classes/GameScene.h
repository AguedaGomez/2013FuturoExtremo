#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include "EnemiesManager.h"
#include "ui/CocosGUI.h"


USING_NS_CC;


const int HERO_STEP_MOVE = 2;

class GameScene: public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Sprite *background;
	Sprite *futureBAnimation;
	Hero *hero;
	
	void update(float dt);

public:
	static cocos2d::Scene* createScene();
	Sprite *_playerSprite;
	EnemiesManager *enemiesManager;
	LoadingBar *loadingBarRed;
	LoadingBar *loadingBarGreen;
	LoadingBar *loadingBarBlue;
	int nivel;

	virtual bool init();

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);
	void hud();
	void setBackground();
	void futureBuilding();
	void checkEnergy();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);



	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

};

#endif 

