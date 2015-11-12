#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__

#include "cocos2d.h"

class PauseScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void resumeGameScene(Ref *pSender);
	void goToMainMenu(Ref *pSender);
	void retryGameScene(Ref *pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(PauseScene);
};

#endif 

