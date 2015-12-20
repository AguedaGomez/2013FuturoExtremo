#include "GameScene.h"
#include "EnemiesManager.h"
#include "Enemy.h"

USING_NS_CC;

EnemiesManager::EnemiesManager() {}

EnemiesManager::~EnemiesManager() {}

EnemiesManager * EnemiesManager::create()
{
	EnemiesManager* ob = new EnemiesManager();
	if (ob) {
		ob->autorelease();
		return ob;
	}

	CC_SAFE_DELETE(ob);
	return NULL;
}



/*
CREAENEMIGOS
Crea todos los enemigos del nivel y los coloca en su sitio
Ademas los mete en un Array para poder recorrerlos
*/
void EnemiesManager::createEnemies(int nivel)
{
	Enemy *enemy;
	switch (nivel) {
	case 0:
		//iniciar todos los enemigos y colocarlos
		for (int i = 0; i < 2; i++) {
			enemies.insert(i, Enemy::create());
			enemies.at(i)->retain();
		}
		enemies.at(0)->posIni = -1000; //enemigo descansillo
		enemies.at(0)->placeEnemy(-1000, 878); //878 hace que quede sobre el suelo cuando están en la segunda planta.
		enemies.at(1)->posIni = 0; //enemigo pasillo de habitaciones
		enemies.at(1)->placeEnemy(0, 878);
		break;
	}


}
/*
	ACTUALIZAENEMIGOS
	actualiza su posicion y si estan en combate, pues lo que toque
*/
void EnemiesManager::updateEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
		enemies.at(i)->updateEnemy();
}
/*
DESTRUYEENEMIGOS ( OPCIONAL )
Los elimina de pantalla cuando pasa un tiempo Ó tambien podemos dejarlos ahi muertos
*/
void EnemiesManager::destroyEnemies()
{
}
