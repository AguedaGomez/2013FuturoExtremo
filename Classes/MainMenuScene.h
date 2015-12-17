#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MainMenu : public cocos2d::Layer
{
private:
	Sprite *menubackground;

	
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    


	void setMenuBackground();
	void goToGameScene(Ref *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __HELLOWORLD_SCENE_H__
