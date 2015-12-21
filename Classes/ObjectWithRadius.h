#ifndef _OBJECTWITHRADIUS_H__
#define _OBJECTWITHRADIUS_H__

#include "cocos2d.h"


USING_NS_CC;

class ObjectWithRadius : public cocos2d::Sprite
{
public:

	float objectRadius;
	
	ObjectWithRadius();
	~ObjectWithRadius();
	static ObjectWithRadius* create(std::string nombre);

	void initOptions();

	DrawNode *enemySmallCircle;
	DrawNode *enemyBigCircle;

	
private:


};

#endif // _MYSPRITE_HPP_
