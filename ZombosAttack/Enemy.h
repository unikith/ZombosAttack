#pragma once
#include "Player.h"
#include <cmath>

class Enemy : public Character
{
public:
	Enemy(const float& speed, const unsigned short& health, const unsigned short& damage, sf::Texture &texture);
	Enemy(const Enemy & copy);
	~Enemy();
	
	unsigned short getDamage() const;

	void move(const Player& target);
private: 
	unsigned short mDamage;
	void updateDirection(const Player& target);
	
};

