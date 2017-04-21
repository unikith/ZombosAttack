#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#define PI 3.14159265

using std::string;

class Gun : public sf::Sprite {
public:
	Gun(const string & image, const sf::Vector2f& origin, float fireSpeed, 
		float bulletSpeed, sf::Window *window);
	void attachPlayer(sf::Sprite *p);
	void update();
private:
	sf::Window *window; //Needed to find mouse position in the window
	sf::Sprite *pSprite; //Player's sprite
	sf::Texture texture; //Texture of the gun
	float fireSpeed; //Seconds per shot
	float bulletSpeed; //Speed of the Bullets
	double angleRad; //Rotation of gun in rads
	double angleDeg; //Rotation of gun in degrees
	//Bullet bullet;
};
	