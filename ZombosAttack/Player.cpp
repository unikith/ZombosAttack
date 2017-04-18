#include "Player.h"

Player::Player(float speed)
{
	this->speed = speed;
}

void Player::move()
{
	sf::Sprite::move(movement.x, movement.y);
}