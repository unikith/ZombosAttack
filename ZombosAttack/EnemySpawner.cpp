#include "EnemySpawner.h"



EnemySpawner::EnemySpawner(const string & textureFile, const double& spawnAcceleration, 
							const double& spawnDelay, Player *p, const sf::Sprite& background)
{
	mSpawnAcceleration = spawnAcceleration;
	mSpawnDelay = spawnDelay;
	this->enemyTexture.loadFromFile(textureFile);
	this->p = p;
	mLastSpawnTime = clock();
	this->totalCount = 0;
	spawn(sf::Vector2f(0, background.getGlobalBounds().height / 2), background); // left
	spawn(sf::Vector2f(background.getGlobalBounds().width, background.getGlobalBounds().height / 2), background); // right
	spawn(sf::Vector2f(background.getGlobalBounds().width / 2, 0), background); // up 
	spawn(sf::Vector2f(background.getGlobalBounds().width / 2, background.getGlobalBounds().height), background); // down
	upCount = 1;
	downCount = 1;
	leftCount = 1;
	rightCount = 1;
}


EnemySpawner::~EnemySpawner()
{
}


void EnemySpawner::update(const sf::Sprite& background, sf::RenderWindow& window)
{
	clock_t currentTime = clock();
	if (currentTime - mLastSpawnTime >= mSpawnDelay)
	{
		sf::Vector2f entrancePos = this->determineSpawnPoint(background);
		spawn(entrancePos, background);
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

void EnemySpawner::spawn(const sf::Vector2f& entrancePos, const sf::Sprite& background)
{
	Enemy* e = new Enemy(ENEMY_SPEED, ENEMY_HEALTH, ENEMY_DAMAGE, enemyTexture);
	e->setPosition(entrancePos);
	e->setScale(ENEMY_SCALE, ENEMY_SCALE);
	e->setOrigin(e->getGlobalBounds().width / 2, e->getGlobalBounds().height / 2);
	this->mEnemies.push_back(e);
	totalCount++;
}

sf::Vector2f EnemySpawner::determineSpawnPoint(const sf::Sprite& background)
{
	short selection = rand() % 100;
	int upProb, downProb, leftProb, rightProb;

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
	else {
		entrancePos.x = background.getGlobalBounds().width;
		entrancePos.y = rand() % int(background.getGlobalBounds().height);
		rightCount++;
	}

	return entrancePos;
}