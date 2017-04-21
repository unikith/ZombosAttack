#include "Character.h"

//Constructors and destructor
Character::Character(const Character & copy)
{
	mHealth = copy.mHealth;
	mSpeed = copy.mSpeed;
}
Character::~Character() {/*empty*/ }
Character::Character(const float& speed, const unsigned int& health)
{
	mHealth = health;
	mSpeed = speed;
}
// Character Functions
void Character::move()
{
	sf::Sprite::move(mVelocity.x, mVelocity.y);
}