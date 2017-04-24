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
	bool CheckCol(sf::Sprite& s1, sf::Sprite& s2);
	//bool CheckCol(const sf::Sprite &object1, const sf::Sprite &object2);
	void update();
	void playerAndEnemyCollision(int enemyIndex);
	void bulletsAndEnemyCollision(int &enemyIndex, int &bulletIndex);
private:
	std::vector<Enemy*>* enemyArray;
	std::vector<Bullet*>* bullets;
	Player* p1;
};