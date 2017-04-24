#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include "KeyValues.h"

class Bullet : public sf::Sprite
{
	friend class Gun;
public:
	Bullet(float speed, sf::Vector2f direction, sf::Texture &texture);
	~Bullet();
	void move();
private:
	sf::Vector2f velocity;
	float speed;
};

