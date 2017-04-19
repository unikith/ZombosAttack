#pragma once
#include <iostream>
#include "Character.h"

class Player : public Character
{
	friend class Controller;
public:
	Player(const float& speed, const unsigned int& health);
};

