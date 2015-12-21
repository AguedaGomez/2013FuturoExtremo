#include "GameScene.h"
#include "ObjectManager.h"
#include "ObjectWithRadius.h"

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
		ObjectWithRadius *colaMachine = ObjectWithRadius::create("cocacola.png");
		colaMachine->setPosition(-480,166);
		//log("Radio de la maquina de cocacola = %f",colaMachine->objectRadius);
		objects.insert(0, colaMachine);

		ObjectWithRadius *expMachine = ObjectWithRadius::create("expendedora.png");
		expMachine->setPosition(-620, 166);
		objects.insert(1, expMachine);

		ObjectWithRadius *conducto = ObjectWithRadius::create("conducto.png");
		conducto->setPosition(-1065, 309);
		objects.insert(2, conducto);

		ObjectWithRadius *rejilla = ObjectWithRadius::create("rejilla.png");
		rejilla->setPosition(-1065, 309);
		objects.insert(3, rejilla);

		ObjectWithRadius *puertaMadera1 = ObjectWithRadius::create("puertaFrente1.png"); //planta 0 escaleras
		puertaMadera1->setPosition(-1356, 171);
		objects.insert(4, puertaMadera1);

		ObjectWithRadius *puertaMadera2 = ObjectWithRadius::create("puertaFrente2.png"); //planta 1 escaleras
		puertaMadera2->setPosition(-1359, 893);
		objects.insert(5, puertaMadera2);

		ObjectWithRadius *puertaCanto1 = ObjectWithRadius::create("puertaCanto1.png"); //planta 0 derecha
		puertaCanto1->setPosition(-76, 171);
		objects.insert(6, puertaCanto1);

		ObjectWithRadius *puertaCanto2 = ObjectWithRadius::create("puertaCanto2.png"); //planta 0 medio
		puertaCanto2->setPosition(-1604, 171);
		objects.insert(7, puertaCanto2);

		ObjectWithRadius *puertaCanto3 = ObjectWithRadius::create("puertaCanto3.png"); //planta 0 izq.
		puertaCanto3->setPosition(-3070, 171);
		objects.insert(8, puertaCanto3);

		ObjectWithRadius *puertaCanto4 = ObjectWithRadius::create("puertaCanto4.png"); //sotano
		puertaCanto4->setPosition(-1356, -549);
		objects.insert(9, puertaCanto4);

		ObjectWithRadius *puertaCanto5 = ObjectWithRadius::create("puertaCanto5.png"); //planta 1 derecha
		puertaCanto5->setPosition(-854, 891);
		objects.insert(10, puertaCanto5);

		ObjectWithRadius *puertaCanto6 = ObjectWithRadius::create("puertaCanto6.png");//planta 1 izq.
		puertaCanto6->setPosition(-1405, 891);
		objects.insert(11, puertaCanto6);

		ObjectWithRadius *ascensor = ObjectWithRadius::create("ascensor.png");
		ascensor->setPosition(233, 183);
		objects.insert(12, ascensor);

		ObjectWithRadius *puertaMetal1 = ObjectWithRadius::create("puertaSotano1.png");//planta 0
		puertaMetal1->setPosition(-3406, 179);
		objects.insert(13, puertaMetal1);

		ObjectWithRadius *puertaMetal2 = ObjectWithRadius::create("puertaSotano2.png"); //sotano
		puertaMetal2->setPosition(-3406, -540);
		objects.insert(14, puertaMetal2);

		ObjectWithRadius *conductoAbierto = ObjectWithRadius::create("conductoConRejilla.png");
		conductoAbierto->setPosition(-1087, -472);
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
		
		circle->drawCircle(objects.at(i)->getPosition(), objects.at(i)->objectRadius, 1.0, 30, false, Color4F(1, 0, 0, 1));
		circlesObjects.insert(i, circle);
		
		
	}
}
