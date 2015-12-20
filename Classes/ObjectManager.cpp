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
		Sprite *colaMachine = Sprite::createWithSpriteFrameName("cocacola.png");
		colaMachine->setPosition(400,400);
		objects.insert(0, colaMachine);

		Sprite *expMachine = Sprite::createWithSpriteFrameName("expendedora.png");
		expMachine->setPosition(0, 400);
		objects.insert(1, expMachine);

		Sprite *conducto = Sprite::createWithSpriteFrameName("conducto.png");
		conducto->setPosition(0, 400);
		objects.insert(2, conducto);

		Sprite *rejilla = Sprite::createWithSpriteFrameName("rejilla.png");
		rejilla->setPosition(0, 400);
		objects.insert(3, rejilla);

		Sprite *puertaMadera1 = Sprite::createWithSpriteFrameName("puertaFrente1.png"); //planta 0 escaleras
		puertaMadera1->setPosition(0, 400);
		objects.insert(4, puertaMadera1);

		Sprite *puertaMadera2 = Sprite::createWithSpriteFrameName("puertaFrente2.png"); //planta 1 escaleras
		puertaMadera2->setPosition(0, 400);
		objects.insert(5, puertaMadera2);

		Sprite *puertaCanto1 = Sprite::createWithSpriteFrameName("puertaCanto1.png"); //planta 0 derecha
		puertaCanto1->setPosition(0, 400);
		objects.insert(6, puertaCanto1);

		Sprite *puertaCanto2 = Sprite::createWithSpriteFrameName("puertaCanto2.png"); //planta 0 medio
		puertaCanto2->setPosition(0, 400);
		objects.insert(7, puertaCanto2);

		Sprite *puertaCanto3 = Sprite::createWithSpriteFrameName("puertaCanto3.png"); //planta 0 izq.
		puertaCanto3->setPosition(0, 400);
		objects.insert(8, puertaCanto3);

		Sprite *puertaCanto4 = Sprite::createWithSpriteFrameName("puertaCanto4.png"); //sotano
		puertaCanto4->setPosition(0, 400);
		objects.insert(9, puertaCanto4);

		Sprite *puertaCanto5 = Sprite::createWithSpriteFrameName("puertaCanto5.png"); //planta 1 derecha
		puertaCanto5->setPosition(0, 400);
		objects.insert(10, puertaCanto5);

		Sprite *puertaCanto6 = Sprite::createWithSpriteFrameName("puertaCanto6.png");//planta 1 izq.
		puertaCanto6->setPosition(0, 400);
		objects.insert(11, puertaCanto6);

		Sprite *ascensor = Sprite::createWithSpriteFrameName("ascensor.png");
		ascensor->setPosition(0, 400);
		objects.insert(12, ascensor);

		Sprite *puertaMetal1 = Sprite::createWithSpriteFrameName("puertaSotano1.png");//planta 0
		puertaMetal1->setPosition(0, 400);
		objects.insert(13, puertaMetal1);

		Sprite *puertaMetal2 = Sprite::createWithSpriteFrameName("puertaSotano2.png"); //sotano
		puertaMetal2->setPosition(0, 400);
		objects.insert(14, puertaMetal2);

		Sprite *conductoAbierto = Sprite::createWithSpriteFrameName("conductoConRejilla.png");
		conductoAbierto->setPosition(0, 400);
		objects.insert(15, conductoAbierto);

		break;
	}

	for (int i = 0; i < objects.size(); i++)
		objects.at(i)->retain();
}

/*
CREACIRCULOSCOLISION
Asigna a todos los objetos creados un circulo con un radio dependiendo de su tamaño que serviran para colisiones.
*/
void ObjectManager::createCollisionCircles()
{
	
	for (int i = 0; i < objects.size(); i++) {
		DrawNode* circle;
		circle = DrawNode::create();
		circle->drawCircle(objects.at(i)->getPosition(), objects.at(i)->getContentSize().width / 3.5, 1.0, 30, false, Color4F(1, 0, 0, 1));
		circlesObjects.insert(i, circle);
	}
}
