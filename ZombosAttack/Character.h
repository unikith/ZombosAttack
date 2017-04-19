#pragma once
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite 
{
public:
	Character(const Character & copy);
	Character(const float& speed = 1, const unsigned int& health = 5);
	virtual ~Character();
	void move();

protected:
	sf::Vector2f mVelocity;
	float mSpeed;
	unsigned int mHealth;
};
