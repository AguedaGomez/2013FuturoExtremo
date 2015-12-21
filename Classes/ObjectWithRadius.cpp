#include "ObjectWithRadius.h"

USING_NS_CC;

ObjectWithRadius::ObjectWithRadius()
{
}

ObjectWithRadius::~ObjectWithRadius()
{
}

ObjectWithRadius* ObjectWithRadius::create(std::string nombre)
{
	ObjectWithRadius * pSprite = new ObjectWithRadius();
	//log("Se ha creado enemigo");

	if (pSprite->initWithSpriteFrameName(nombre)) {

		pSprite->autorelease();
		pSprite->initOptions();
		return pSprite;
	}
	CC_SAFE_DELETE(pSprite);
	return NULL;
}

void ObjectWithRadius::initOptions()
{
	this->objectRadius = this->getContentSize().width / 2;
}

	

