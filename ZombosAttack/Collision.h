#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

class Collision
{
public:
	Collision(std::vector<Enemy*>* arr, std::vector<Bullet*>* bulletsArr, Player* player);
	bool CheckCol(sf::FloatRect& bb1, sf::FloatRect &bb2);
	//bool CheckCol(const sf::Sprite &object1, const sf::Sprite &object2);
	void update();
private:
	std::vector<Enemy*>* enemyArray;
	std::vector<Bullet*>* bullets;
	Player* p1;
};