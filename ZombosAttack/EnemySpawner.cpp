#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(const string & textureFile, const int spawnAcceleration, 
							const int spawnDelay, Player *p, const sf::Sprite& background)
{
	mSpawnAcceleration = spawnAcceleration;
	mSpawnDelay = spawnDelay;
	this->enemyTexture.loadFromFile(textureFile);
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
		sf::Vector2f entrancePos = this->determineSpawnPoint(background);
		spawn(entrancePos);
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

void EnemySpawner::spawn(const sf::Vector2f& entrancePos)
{
	Enemy* e = new Enemy(ENEMY_SPEED, ENEMY_HEALTH, ENEMY_DAMAGE, enemyTexture);
	e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2); // sets origin to middle of sprite
	e->setPosition(entrancePos);
	e->setScale(ENEMY_SCALE, ENEMY_SCALE);
	this->mEnemies.push_back(e);
	totalCount++;
}

sf::Vector2f EnemySpawner::determineSpawnPoint(const sf::Sprite& background)
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
		entrancePos.y = 0;
		upCount++;
	}
	else if (selection < downProb) {
		entrancePos.x = rand() % int(background.getGlobalBounds().width);
		entrancePos.y = background.getGlobalBounds().height;
		downCount++;
	}
	else if (selection < leftProb) {
		entrancePos.x = 0;
		entrancePos.y = rand() % int(background.getGlobalBounds().height);
		leftCount++;
	}
	else { // right side spawn
		entrancePos.x = background.getGlobalBounds().width;
		entrancePos.y = rand() % int(background.getGlobalBounds().height);
		rightCount++;
	}

	return entrancePos;
}