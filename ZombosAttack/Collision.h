#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Collision
{
public:
	Collision();
	bool CheckCol(sf::Sprite& o1, sf::Sprite &o2);
	//bool CheckCol(const sf::Sprite &object1, const sf::Sprite &object2);
protected:
};