#pragma once
#include "Bullet.h"
#include "Helpers.h"
//#include "KeyValues.h"

#include <ctime>
#include <iostream>
//#include <math.h>
//#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>

#define PI 3.14159265

using std::string;

class Gun : public sf::Sprite {
public:
	/// \ brief : arguement constructor
	/// \ params : image is the file the gun texture is read from, origin is the point of rotation,
	/// \			shotDelay, bulletSpeed, and damage are attributes related to bullet spawning, 
	/// \			window where gun and bullets are drawn to
	/// \ precons : window is valid
	/// \ return : none
	Gun(const string & image, const sf::Vector2f& origin, float shotDelay, 
		float bulletSpeed, int damage, sf::RenderWindow *window);

	~Gun();
	/// \ brief : bind the player and the gun together
	/// \ params : p is a sprite that is the base class for player
	/// \ precons : none
	/// \ return : none
	void attachPlayer(sf::Sprite *p);

	/// \ brief : rotates gun to mouse, moves bullets, and shoots if necessary
	/// \ params : none
	/// \ precons : attached to player
	/// \ return : none
	void update();

	/// \ brief : sets shooting bool to input value 
	/// \ params : ifShooting is the input value
	/// \ precons : none
	/// \ return : none
	void setShooting(bool ifShooting) { this->shooting = ifShooting; }

	/// \ brief : returns shooting member
	/// \ params : none
	/// \ precons : none
	/// \ return : shooting member
	bool getShooting() const { return shooting; }

	/// \ brief : returns a pointer to the bullet vector
	/// \ params : none
	/// \ precons : none
	/// \ return : a pointer to the bullets vector member
	std::vector<Bullet *> & getBullets() { return this->bullets; }

	/// \ brief : returns the damage member
	/// \ params : none
	/// \ precons : none
	/// \ return : the damage member
	int getDamage() const { return this->damage; }

private:
	sf::RenderWindow *window; //Needed to find mouse position in the window 
	sf::Sprite *pSprite; //Player's sprite
	sf::Texture texture; //Texture of the gun
	/// \ texture of the bullet
	sf::Texture bulletTexture;
	float mShotDelay;
	float bulletSpeed; //Speed of the Bullets
	int damage; //Damage of Bullets
	double angleRad; //Rotation of gun in rads
	double angleDeg; //Rotation of gun in degrees
	/// \ whether or not the gun has its trigger pulled
	bool shooting;
	clock_t mLastShotTime;
	/// \ used to store shot bullets
	std::vector<Bullet*> bullets;
	sf::SoundBuffer buffer_bullet;
	sf::Sound sound_bullet;
	
	/// \ brief : spawns a bullet in the direction of input direction
	/// \ params : spawnpoint is initial position, direction is velocity vectore
	/// \ precons : none
	/// \ return : none
	void shoot(sf::Vector2f& spawnPoint, sf::Vector2f& direction);
};
	