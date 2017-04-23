#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Bullet.h"
#include "Helpers.h"
#include <ctime>

#define PI 3.14159265

using std::string;

class Gun : public sf::Sprite {
public:
	Gun(const string & image, const sf::Vector2f& origin, float shotDelay, 
		float bulletSpeed, int damage, sf::RenderWindow *window);
	void attachPlayer(sf::Sprite *p);
	void update();
	void setShooting(bool ifShooting) { this->shooting = ifShooting; }
	bool getShooting() const { return shooting; }
private:
	void shoot(sf::Vector2f& spawnPoint, sf::Vector2f& direction);
	sf::RenderWindow *window; //Needed to find mouse position in the window
	sf::Sprite *pSprite; //Player's sprite
	sf::Texture texture; //Texture of the gun
	sf::Texture bulletTexture;
	float mShotDelay;
	float bulletSpeed; //Speed of the Bullets
	int damage; //Damage of Bullets
	double angleRad; //Rotation of gun in rads
	double angleDeg; //Rotation of gun in degrees
	bool shooting;
	clock_t mLastShotTime;
	std::vector<Bullet*> bullets;
};
	