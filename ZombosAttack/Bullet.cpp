#include "Bullet.h"



Bullet::Bullet(float speed, sf::Vector2f direction, sf::Texture & texture)
{
	this->speed = speed;
	this->setTexture(texture);
	this->velocity = speed * direction / 
		(sqrt(direction.x * direction.x + direction.y * direction.y));
	float radius = getLocalBounds().width / 2; //Assumes bullet is a circle
	this->setOrigin(radius, radius);
	this->setScale(.1, .1); //Scale for bullet
}
Bullet::~Bullet()
{
}
void Bullet::move() {
	sf::Sprite::move(velocity);
}