#pragma once
#include <ctime>
#include "Enemy.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

typedef enum side {
	UP = 0, DOWN, LEFT, RIGHT
}Side;

class EnemySpawner
{
public:
	EnemySpawner(const string & textureFile, const double& spawnAcceleration, const double& spawnDelay, Player *p, const sf::Sprite& background);
	~EnemySpawner();
	void update(const sf::Sprite& background, sf::RenderWindow& window);
	void spawn(const sf::Vector2f& entrancePos, const sf::Sprite& background);
	vector<Enemy *>& getEnemies() { return this->mEnemies; }

private:
	vector<Enemy *> mEnemies;
	double mSpawnDelay;
	double mSpawnAcceleration;
	clock_t  mLastSpawnTime;
	int upCount;
	int downCount;
	int leftCount;
	int rightCount;
	int totalCount;
	sf::Texture enemyTexture;
	Player *p;
	
	sf::Vector2f determineSpawnPoint(const sf::Sprite& background);
};

