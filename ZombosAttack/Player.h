#pragma once

#include <iostream>
#include "Character.h"
#include "Gun.h"

using std::string;

class Player : public Character //Maybe inherits from circle and player
{
	friend class Controller;
public:
	Player(const float& speed, const unsigned int& health);
	~Player();
	void update();
	void attachGun(const string &image, const sf::Vector2f &origin, float fireSpeed,
		float bulletSpeed, int damage, sf::RenderWindow *window);
	void draw(sf::RenderWindow &window);
	void setTexture(const sf::Texture &texture);
private:
	Gun *gun;
};
