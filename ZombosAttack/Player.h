#pragma once

#include <iostream>
#include "Character.h"
#include "Gun.h"
#include "Helpers.h"

using std::string;

class Player : public Character //Maybe inherits from circle and player
{
	friend class Controller;
public:
	Player(const float& speed, const unsigned int& health);
	~Player();
	void update(const sf::RenderWindow& window);
	void attachGun(const string &image, const sf::Vector2f &origin, float shotDelay,
		float bulletSpeed, int damage, sf::RenderWindow *window);
	void draw(sf::RenderWindow &window);
	void setTexture(const sf::Texture &texture);
	
private:
	Gun *gun;
};
