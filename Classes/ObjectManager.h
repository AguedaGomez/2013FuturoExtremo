#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "cocos2d.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void cargaSpritesNivel(int nivel);

	void creaCirculosColision(int nivel);


};

#endif 

