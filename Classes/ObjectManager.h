#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "cocos2d.h"
#include "ObjectWithRadius.h"


class ObjectManager : public cocos2d::Ref
{
public:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* create();

	Vector<ObjectWithRadius*> objects;
	Vector<DrawNode*> circlesObjects;

	void loadLevelObjects(int nivel);

	void createCollisionCircles();


};

#endif 

