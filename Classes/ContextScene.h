#ifndef __CONTEXT_SCENE_H__
#define __CONTEXT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class ContextScene : public cocos2d::Layer
{
private:
	
	EventKeyboard::KeyCode _pressedKey;

	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void goToGameScene(Ref *pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

    // implement the "static create()" method manually
    CREATE_FUNC(ContextScene);
};

#endif // __CONTEXT_SCENE_H__
