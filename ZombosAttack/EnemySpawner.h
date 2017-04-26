#pragma once
#include "Enemy.h"
#include "KeyValues.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/// \ this class controls the spawning of enemies, posiiton is random, enemy members are input 
/// \ from the keyvalue store
class EnemySpawner
{
public:
	// Functions
	/// \ brief : arguement constructor, sets spawn attributes
	/// \ params : textureFile is file to read enemy textures from, spawn acceleratoin and delay
	/// \			control spawn times, p is the player that the enemies move toward, and background 
	/// \			defines edges to spawn to
	/// \ precons : window is set to backgrounds dimensions, textureFile is the name of a valid image
	/// \			file
	/// \ return : none
	EnemySpawner(const string & textureFile, const int spawnAcceleration, const int spawnDelay, 
				Player *p, const sf::Sprite& background);

	/// \ brief : destructor that deallocates enemy vector 
	/// \ params : none
	/// \ precons : none
	/// \ return : none
	~EnemySpawner();

	/// \ brief : spawns enemy if spawn delay has passed, moves and draws enemies from enemy array
	/// \ params : background to spawn to and window to draw to
	/// \ precons : window is instantiated and the size of background
	/// \ return : none
	void update(const sf::Sprite& background, sf::RenderWindow& window);

	/// \ brief : instantiates an enemy with correct values and adds it to the enemy vector
	/// \ params : entracePos is the x and y coordinate to spawn to
	/// \ precons : none
	/// \ return : none
	void spawn(sf::Vector2f entrancePos);


	/// \ brief : instantiates an enemy with correct values and adds it to the enemy vector
	/// \ params : background is used to determine the spawn point
	/// \ precons : none
	/// \ return : none
	void spawn(const sf::Sprite& background);

	/// \ brief : returns reference to mEnemies
	/// \ params : noone
	/// \ precons : none
	/// \ return : reference to mEnemies
	vector<Enemy *>& getEnemies() { return this->mEnemies; }

private:
	// Members
	/// \ holds pointers to enemies allocated on the heap
	vector<Enemy *> mEnemies;
	/// \ time delay between spawnss in milliseconds
	int mSpawnDelay;
	/// \ how much the spawn delay decreases per spawn
	int mSpawnAcceleration;
	/// \ time of last spawn in milliseconds
	clock_t  mLastSpawnTime;
	/// \ counts are used for weighted spawn location algorithm
	int upCount;
	int downCount;
	int leftCount;
	int rightCount;
	int totalCount;
	/// \ texture that enemies have
	sf::Texture enemyTexture;
	/// \ pointer to player that enemies move towwardds
	Player *p;
	
	// Functions
	/// \ brief : determines the point to which the next enemy is to spawn
	/// \ params : background to spawn to edge of, pEnemy's position is set to the determined position
	/// \ precons : none
	/// \ return : none
	void determineSpawnPoint(const sf::Sprite& background, Enemy *pEnemy);
};

