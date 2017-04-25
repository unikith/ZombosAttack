#pragma once
#include "Bullet.h"
#include "Enemy.h"

#include <iostream>
//#include <SFML\Graphics.hpp>
#include <vector>

class Collision
{
public:
	/// \ breif : arguement constructor
	/// \ params : arr is a vector of enemies pointers, bulletsArr is a vector
	/// \ of bullets pointers, player is a pointer to a player object
	/// \ precons : player is a valid pointer
	/// \ return : none
	Collision(std::vector<Enemy*>* arr, std::vector<Bullet*>* bulletsArr, Player* player);

	/// \ breif : checks to see if the sprites collide
	/// \ params : two circular sprites
	/// \ precons : both sprites are circles
	/// \ return :  true if the sprites collide, false otherwise
	bool CheckCol(sf::Sprite& s1, sf::Sprite& s2);

	//bool CheckCol(const sf::Sprite &object1, const sf::Sprite &object2);

	/// \ breif : checks the bullet and enemy vectors and the player to see if there are any
	/// \		relevant collisions
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	void update();

	/// \ breif : runs the logic for and enemy and player collision
	/// \ params : the index of the enemy in the vector
	/// \ precons : enemy index is a valid index for the enemy vector
	/// \ return : none
	void playerAndEnemyCollision(int enemyIndex);

	/// \ breif : runs the logic for a bullet and enemy collision
	/// \ params : the index for the bullet and enemy in the vectors
	/// \ precons : enemy and bullet index are valid indices for the respective vector
	/// \ return : true if enemy was killed, false otherwise
	bool bulletsAndEnemyCollision(int &enemyIndex, int &bulletIndex);

private:
	/// \ entities to check for collision, bullets and enemies are on the heap
	std::vector<Enemy*>* enemyArray;
	std::vector<Bullet*>* bullets;
	Player* p1;
};