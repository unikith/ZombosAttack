#pragma once
#include <iostream>
#include "Character.h"

class Player : public Character
{
	friend class Controller;
public:
	Player(float speed);
	void move();

private:
};

