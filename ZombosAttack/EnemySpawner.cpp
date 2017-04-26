#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(const string & textureFileSlow, const string & textureFileFast, const int spawnAcceleration,
							const int spawnDelay, Player *p, const sf::Sprite& background)
{
	mSpawnAcceleration = spawnAcceleration;
	mSpawnDelay = spawnDelay;
	this->enemyTextureSlow.loadFromFile(textureFileSlow);
	this->enemyTextureFast.loadFromFile(textureFileFast);
	this->p = p;
	mLastSpawnTime = clock(); // sets to current time in milliseconds
	this->totalCount = 0; // incremented when spawns occur below
	spawn(sf::Vector2f(0, background.getGlobalBounds().height / 2)); // left
	spawn(sf::Vector2f(background.getGlobalBounds().width, background.getGlobalBounds().height / 2)); // right
	spawn(sf::Vector2f(background.getGlobalBounds().width / 2, 0)); // up 
	spawn(sf::Vector2f(background.getGlobalBounds().width / 2, background.getGlobalBounds().height)); // down

	// incremented here because determine spawn location is not called
	upCount = 1;
	downCount = 1;
	leftCount = 1;
	rightCount = 1;
}

EnemySpawner::~EnemySpawner()
{
	for (int i = 0; i < this->mEnemies.size(); i++) // deallocated enemies from heap
	{
		delete mEnemies[i];
	}
}


void EnemySpawner::update(const sf::Sprite& background, sf::RenderWindow& window)
{
	clock_t currentTime = clock();
	if (currentTime - mLastSpawnTime >= mSpawnDelay)
	{
		spawn(background);
		if (mSpawnDelay - mSpawnAcceleration > MIN_SPAWN_DELAY)
		{
			mSpawnDelay -= mSpawnAcceleration;
			//window.draw(*mEnemies.back());
		}
		mLastSpawnTime = currentTime;
		//cout << "l" << leftCount << endl;
		//cout << "r" << rightCount << endl;
		//cout << "u" << upCount << endl;
		//cout << "d" << downCount << endl;
	}

	for (int i = 0; i < mEnemies.size(); ++i) {
		mEnemies[i]->move(*p);
		window.draw(*mEnemies[i]);
	}
}

void EnemySpawner::spawn(const sf::Sprite& background)
{
	int health = rand() % (ENEMY_HEALTH_MAX - ENEMY_HEALTH_MIN) + ENEMY_HEALTH_MIN;
	float speed = (ENEMY_SPEED_BASE * (1 - health / (1.25 * ENEMY_HEALTH_MAX)));
	Enemy* e;
	switch (health)
	{
	case 2:
	case 3:
		e = new Enemy(speed, health, ENEMY_DAMAGE, enemyTextureFast);
		e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
		e->setScale(ENEMY_SCALE_SMALL, ENEMY_SCALE_SMALL);
		break;
	case 4:
	case 5:
		e = new Enemy(speed, health, ENEMY_DAMAGE, enemyTextureSlow);
		e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
		e->setScale(ENEMY_SCALE_LARGE, ENEMY_SCALE_LARGE);
		break;
	default:
		break;
	}
	
	//e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
	determineSpawnPoint(background, e);
	//e->setScale(ENEMY_SCALE_LARGE, ENEMY_SCALE_LARGE);
	this->mEnemies.push_back(e);
	totalCount++;
}

void EnemySpawner::spawn(sf::Vector2f entrancePos)
{
	int health = rand() % (ENEMY_HEALTH_MAX - ENEMY_HEALTH_MIN) + ENEMY_HEALTH_MIN;
	float speed = (ENEMY_SPEED_BASE * (1 - health / (1.25 * ENEMY_HEALTH_MAX)));
	Enemy* e;
	switch (health)
	{
	case 2:
	case 3:
		e = new Enemy(speed, health, ENEMY_DAMAGE, enemyTextureFast);
		e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
		e->setScale(ENEMY_SCALE_SMALL, ENEMY_SCALE_SMALL);
		break;
	case 4:
	case 5:
		e = new Enemy(speed, health, ENEMY_DAMAGE, enemyTextureSlow);
		e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
		e->setScale(ENEMY_SCALE_LARGE, ENEMY_SCALE_LARGE);
		break;
	default:
		break;
	}
	//e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
	//e->setScale(ENEMY_SCALE_LARGE, ENEMY_SCALE_LARGE);
	e->setPosition(entrancePos);
	this->mEnemies.push_back(e);
	totalCount++;
}

void EnemySpawner::determineSpawnPoint(const sf::Sprite& background, Enemy *pEnemy)
{
	short selection = rand() % 100;
	int upProb, downProb, leftProb;

	sf::Vector2f entrancePos;

	upProb = 33.333* (1.0 - double(upCount) / double(totalCount));
	downProb = upProb + 33.3333 * (1 - double(downCount) / totalCount);
	leftProb = downProb + 33.3333 * (1 - double(leftCount) / totalCount);
	//rightProb = upProb + 100 * (1 - leftCount / totalCount);
	if (selection < upProb) {
		entrancePos.x = rand() % int(background.getGlobalBounds().width);
		entrancePos.y = -pEnemy->getGlobalBounds().height / 2;
		upCount++;
	}
	else if (selection < downProb) {
		entrancePos.x = rand() % int(background.getGlobalBounds().width);
		entrancePos.y = background.getGlobalBounds().height + pEnemy->getGlobalBounds().height / 2;
		downCount++;
	}
	else if (selection < leftProb) {
		entrancePos.x = -pEnemy->getGlobalBounds().width / 2;
		entrancePos.y = rand() % int(background.getGlobalBounds().height);
		leftCount++;
	}
	else { // right side spawn
		entrancePos.x = background.getGlobalBounds().width + pEnemy->getGlobalBounds().width / 2;
		entrancePos.y = rand() % int(background.getGlobalBounds().height);
		rightCount++;
	}

	pEnemy->setPosition(entrancePos);
}