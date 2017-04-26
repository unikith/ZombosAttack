#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include "KeyValues.h"

class Bullet : public sf::Sprite
{
	friend class Gun;
public:
	/// \ brief : argument constructor
	/// \ params : speed of bullet, direciton of bullet, print texture
	/// \ precons : none
	/// \ return : none
	Bullet(float speed, sf::Vector2f direction, sf::Texture &texture);

	/// \ brief : destructor
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	~Bullet();

	/// \ brief : moves bullet based upon velocity
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	void move();
private:
	/// \ used for speed and direction of motion
	sf::Vector2f velocity;
	float speed;
};

