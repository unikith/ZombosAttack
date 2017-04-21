#include "Character.h"
//Constructors and destructor
Character::Character(const Character & copy)
{
	mHealth = copy.mHealth;
	mSpeed = copy.mSpeed;
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
unsigned short Character::getHeath() const
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
	if (mHealth < 0)
	{
		mHealth = 0;
	}
}

// Character Functions
void Character::move()
{
	sf::Sprite::move(mVelocity.x, mVelocity.y);
}