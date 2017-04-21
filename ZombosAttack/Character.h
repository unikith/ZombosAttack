#pragma once
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite 
{
public:
	Character(const Character & copy);
	Character(const float& speed = 1, const unsigned short& health = 5);
	virtual ~Character();
	virtual void move();

	float getSpeed() const;
	unsigned short getHeath() const;

	void healForN(const unsigned short n);
	void damageForN(const unsigned short n);

protected:
	sf::Vector2f mVelocity;
	float mSpeed;
	unsigned short mHealth;
};
