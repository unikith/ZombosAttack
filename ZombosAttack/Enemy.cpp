#include "Enemy.h"

// constructor and desstructor
Enemy::Enemy(const float& speed, const unsigned short& health, const unsigned short& damage) 
	: Character(speed, health)
{
	this->mDamage = damage;
}

Enemy::Enemy(const Enemy & copy) : Character(copy)
{
	mDamage = copy.getDamage();
}

Enemy::~Enemy(){/*Empty*/}

unsigned short Enemy::getDamage() const
{
	return mDamage;
}

void Enemy::updateDirection(const Player& target)
{
	sf::Vector2f direction;
	direction.x = target.getPosition().x - this->getPosition().x;
	direction.y = target.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	if (magnitude != 0)
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