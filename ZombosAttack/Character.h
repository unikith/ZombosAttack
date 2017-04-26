#pragma once
#include <SFML/Graphics.hpp>

/// \ Base class for enemy and character inheirets sprite 
/// \ so that it can be transformed and drawn in sfml
class Character : public sf::Sprite 
{
public:
	/// \ brief : simple copy constructor that can be called from derived constructors
	/// \ params : copy is an already constructed character object
	/// \ precons : copy is a valid character object or is derived from character
	/// \ return : none
	Character(const Character & copy);

	/// \ brief : default and arguement constructor
	/// \ params : speed is used for movement per cycle, health is used to tract
	/// \				how many hits the character can take
	/// \ precons : copy is a valid character object or is derived from character
	/// \ return : none
	Character(const float& speed = 1, const short& health = 5);

	/// \ brief : virtual destructor that allows proper destruction of derived objects
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	virtual ~Character();

	/// \ brief : uses velocity as a vector to move the character
	/// \ params : none 
	/// \ precons : none 
	/// \ return : none
	virtual void move();

	/// \ brief : returns speed member
	/// \ params : none
	/// \ precons : none
	/// \ return : speed member
	float getSpeed() const;

	/// \ brief : returns health member
	/// \ params : none
	/// \ precons : none
	/// \ return : health member
	short getHealth() const;

	/// \ brief : adds n to the health member
	/// \ params : a positive integer
	/// \ precons : none
	/// \ return : none
	void healForN(const unsigned short n);

	/// \ brief : removes n from the health member
	/// \ params : a positive integer
	/// \ precons : none
	/// \ return : none
	void damageForN(const unsigned short n);

protected:
	/// \ used for movement, has direction and magnitude of motion
	sf::Vector2f mVelocity;
	/// \ how fast the character moves per cycle
	float mSpeed;
	/// \ how many hits the character can take
	short mHealth;
};
