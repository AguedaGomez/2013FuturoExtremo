#include "GameScene.h"
#include "ObjectManager.h"

USING_NS_CC;

ObjectManager::ObjectManager() {}

ObjectManager::~ObjectManager() {}

ObjectManager * ObjectManager::create()
{
	ObjectManager * ob = new ObjectManager();
	if (ob) {
		ob->autorelease();
		return ob;
	}
	CC_SAFE_DELETE(ob);
	return NULL;
}


/*
CARGASPRITESNIVEL
Crea todos los sprites del nivel que no estan en el fondo y los coloca en su sitio.
Los mete en un array para luego poder recorrerlos(opcional)
*/
void ObjectManager::loadLevelObjects(int nivel)
{
	switch (nivel) {
	case 0:
		//Sprite *colaMachine = Sprite::createWithSpriteFrameName("nombre.png");
		//colaMachine->setPosition(x,y);
		//objects.at(0) = colaMachine;
		break;
	}
}
/*
CREACIRCULOSCOLISION
Asigna a todos los objetos creados un circulo con un radio dependiendo de su tamaño que serviran para colisiones.
*/
void ObjectManager::createCollisionCircles()
{
	//for ( int i = 0; i < objects.size(); i++ ) {
	//circlesObjects.at(i) = DrawNode::create()->drawCircle(objects.at(i)->getPosition(), this->getContentSize().width/3.5,1.0,30,false, Color4F(1, 0, 0, 1))

}
