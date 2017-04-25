#pragma once
#include "Character.h"
#include "Gun.h"

#include <iostream>

using std::string;

/// \ the object controlled by the person playing the game
class Player : public Character
{
	/// \ allows controller to access movement attributes
	friend class Controller;
public:

	/// \ breif : arguement constructor, calls base constructor 
	/// \ params : speed is used for movement per cycle, health is how many hits player can take
	/// \ precons : none
	/// \ return :  none
	Player(const float& speed, const unsigned int& health);

	/// \ breif : calls base destructor
	/// \ params : none
	/// \ precons : none
	/// \ return :  none
	~Player();

	/// \ breif : Moves player, updates gun location, bullet locations and draws 
	/// \		all bullets on this gun.
	/// \ params : window to draw on
	/// \ precons : window is initialised and gun is attached
	/// \ return : none
	void update(const sf::RenderWindow& window);

	/// \ breif : creates and binds a gun to the player
	/// \ params : guns image file, origin is point of roation, shot delay is minimum time 
	/// \			between shots, bullet speed is how fast bullets from this gun moves
	/// \			damage is how much health is taken from enemies that collide with bullets 
	/// \			from the gun, and window is used to determine mouse position for gun
	/// \ precons : window is instantiated, image is the name of a valid file
	/// \ return : none
	void attachGun(const string &image, const sf::Vector2f &origin, float shotDelay,
		float bulletSpeed, int damage, sf::RenderWindow *window);

	/// \ breif : draws the player it's gun into the input window
	/// \ params : window  to draw into
	/// \ precons : window is instantiated
	/// \ return : none
	void draw(sf::RenderWindow &window);

	/// \ breif : custom set texture that sets origin to center of sprite
	/// \ params : texture to give to player
	/// \ precons : texture is valid
	/// \ return : none
	void setTexture(const sf::Texture &texture);

	/// \ breif : returns a pointer to player's gun
	/// \ params : none
	/// \ precons : nnoe
	/// \ return : a pointer to the gun if attahced and null otherwise
	Gun * getGun() { return this->gun; }
	
private:
	/// \ the players gun, a pointer to the gun on the heap
	Gun *gun;
};
