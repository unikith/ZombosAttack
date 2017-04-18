#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character : public sf::Sprite {
public:
	
protected:
	sf::Vector2f movement;
	float speed;
	unsigned int health;
};
