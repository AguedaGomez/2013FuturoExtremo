#ifndef __ENEMIES_MANAGER_H__
#define __ENEMIES_MANAGER_H__

#include "cocos2d.h"

class EnemiesManager
{
public:
	EnemiesManager();
	~EnemiesManager();

	void creaEnemigos(int nivel);

	void actualizaEnemigos();

	void destruyeEnemigos();

};

#endif 

