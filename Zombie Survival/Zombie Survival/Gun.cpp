#include "Gun.h"

Gun::Gun(const string & image, const sf::Vector2f& origin, float fireSpeed,
	float bulletSpeed, sf::Window *window) {
	texture.loadFromFile(image); //Loads the texture for gun from string path
	this->setTexture(texture);
	this->setOrigin(origin); //Sets the center back of the gun to the origin
	this->fireSpeed = fireSpeed;
	this->bulletSpeed = bulletSpeed;
	this->angleDeg = 0;
	this->angleRad = 0;
	this->window = window;
}
/*
	Grabs the player's sprite (used for position/radius)
*/
void Gun::attachPlayer(sf::Sprite *p) {
	this->pSprite = p;
}
/*
	Updates the gun's rotation/position with respects to the player it is
	attached to and mouse location.
*/
void Gun::update() {
	float radius = pSprite->getLocalBounds().width / 2; //Assumes player is a circle
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f difVector = (sf::Vector2f)mousePos - pSprite->getPosition();
	if (difVector.x != 0)  //To avoid divide by zero
		angleRad = atan2(difVector.y, difVector.x);
	else if(difVector.y < 0)
		angleRad = -PI / 2;
	else 
		angleRad = PI / 2;
	angleDeg = angleRad * 180 / PI;
	setRotation(angleDeg);
	setPosition(pSprite->getPosition().x + radius*cos(angleRad),
		pSprite->getPosition().y + radius*sin(angleRad));
}
