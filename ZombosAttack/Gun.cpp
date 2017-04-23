#include "Gun.h"

Gun::Gun(const string & image, const sf::Vector2f& origin, float fireSpeed,
	float bulletSpeed, int damage, sf::RenderWindow *window) {
	texture.loadFromFile(image); //Loads the texture for gun from string path
	this->setTexture(texture);
	this->setOrigin(origin); //Sets the center back of the gun to the origin
	this->fireSpeed = fireSpeed;
	this->bulletSpeed = bulletSpeed;
	this->damage = damage;
	this->angleDeg = 0;
	this->angleRad = 0;
	this->window = window;
	this->shooting = false;
	this->bulletTexture.loadFromFile("Circle.png"); //CHANGE
	this->setScale(.5, .5); //Hard coded scale
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
	float radius = pSprite->getGlobalBounds().width / 2; //Assumes player is a circle
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
	sf::Vector2f gunPos(pSprite->getPosition().x + radius*cos(angleRad),
		pSprite->getPosition().y + radius*sin(angleRad));
	setPosition(gunPos);
	if (shooting) {
		shoot(sf::Vector2f(gunPos.x + getGlobalBounds().width * cos(angleRad),
			gunPos.y + getGlobalBounds().width * sin(angleRad)), difVector);
	}
	for (int i = 0; i < bullets.size(); ++i) {
		window->draw(*bullets[i]);
		bullets[i]->move();
	}
}
void Gun::shoot(sf::Vector2f& spawnPoint, sf::Vector2f& direction) {
	Bullet* b = new Bullet(bulletSpeed, direction, bulletTexture);
	b->setPosition(spawnPoint);
	bullets.push_back(b);
}