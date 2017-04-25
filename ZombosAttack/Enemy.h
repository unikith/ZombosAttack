#pragma once
#include "Player.h"

#include <cmath>

class Enemy : public Character
{
public:
	// Functions
	/// \ breif : arguement constructor, calls character constructor
	/// \ params : speed and health are from base class character, damage is 
	/// \			used for collisions with the player and texture is the 
	/// \			display image
	/// \ precons : none
	/// \ return : none
	Enemy(const float& speed, const unsigned short& health, const unsigned short& damage, sf::Texture &texture);

	/// \ breif : calls character destructor
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	~Enemy();
	
	/// \ breif : returns damage member
	/// \ params : none
	/// \ precons : none
	/// \ return : damage member
	unsigned short getDamage() const;

	/// \ breif : finds new direction of motion, towards player, and moves the object
	/// \ params : target is the player the enemy moves towards
	/// \ precons : target is a valid player object
	/// \ return : none
	void move(const Player& target);
protected:
	// Members
	/// \ used in collisions with the player to decremenet player health
	unsigned short mDamage;

	/// \ 


private: 
	// Funcitons
	/// \ breif : updates mVelocity(in base class) so that the enemny is moving
	/// \		in the direction of the input player
	/// \ params : target is the player that enemy moves toward
	/// \ precons : target is a valid player object
	/// \ return : none
	void updateDirection(const Player& target);
	
};

