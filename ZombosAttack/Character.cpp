#include "Character.h"

Character::Character(const Character & copy)
{
	mHealth = copy.mHealth;
	mSpeed = copy.mSpeed;
	this->mVelocity = sf::Vector2f(0.0f, 0.0f);
}

 Character::~Character(){/*empty*/}

Character::Character(const float& speed, const unsigned short& health)
{
	mHealth = health;
	mSpeed = speed;
}

float Character::getSpeed() const
{
	return mSpeed;
}
unsigned short Character::getHealth() const
{
	return mHealth;
}

void Character::healForN(const unsigned short n)
{
	mHealth += n;
}

void Character::damageForN(const unsigned short n)
{
	mHealth -= n;
}

void Character::move()
{
	sf::Sprite::move(mVelocity.x, mVelocity.y);
}