#pragma once
#include "Player.h"
#include <cmath>
class Enemy : public Character
{
public:
	Enemy(const float& speed, const unsigned int& health); 
	Enemy(const Enemy & copy);
	~Enemy();
	void updateDirection(const Player& target);
};

