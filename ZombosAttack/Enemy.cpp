#include "Enemy.h"

// constructor and desstructor
Enemy::Enemy(const float& speed, const unsigned int& health) : Character(speed, health){/*Empty*/}

Enemy::Enemy(const Enemy & copy) : Character(copy){/*Empty*/}

Enemy::~Enemy(){/*Empty*/}

void Enemy::updateDirection(const Player& target)
{
	sf::Vector2f direction;
	direction.x = target.getPosition().x - this->getPosition().x;
	direction.y = target.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	mVelocity.x = direction.x / magnitude * mSpeed;
	mVelocity.y = direction.y / magnitude * mSpeed;
}