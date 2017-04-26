#include "Enemy.h"

Enemy::Enemy(const float& speed, const unsigned short& health, const unsigned short& damage, sf::Texture &texture)
	: Character(speed, health) // call to base constructor
{
	this->mDamage = damage;
	this->setTexture(texture);
	this->baseHealth = health;
}

Enemy::~Enemy(){/*Empty*/}

unsigned short Enemy::getDamage() const
{
	return mDamage;
}

int Enemy::getBaseHealth() const
{
	return this->baseHealth;
}

void Enemy::updateDirection(const Player& target)
{
	sf::Vector2f direction;
	direction.x = target.getPosition().x - this->getPosition().x;
	direction.y = target.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	if (magnitude != 0) // prevents divide by 0 error
	{
		mVelocity.x = direction.x / magnitude * mSpeed;
		mVelocity.y = direction.y / magnitude * mSpeed;
	}
	else
	{
		mVelocity.x = 0;
		mVelocity.y = 0;
	}
}

void Enemy::move(const Player& target)
{
	updateDirection(target);
	Character::move();
}