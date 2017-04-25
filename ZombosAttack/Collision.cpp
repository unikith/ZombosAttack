#include <SFML\Graphics.hpp>
#include "Collision.h"

Collision::Collision(std::vector<Enemy*>* arr, std::vector<Bullet*>* bulletsArr, Player* player)
{
	this->enemyArray = arr;
	this->bullets = bulletsArr;
	p1 = player;
}

bool Collision::CheckCol(sf::Sprite& s1, sf::Sprite& s2)
{
	bool result = false;

	sf::Vector2f direction;
	direction.x = s1.getPosition().x - s2.getPosition().x;
	direction.y = s1.getPosition().y - s2.getPosition().y;

	float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	float totalWidth = (s1.getGlobalBounds().width + s2.getGlobalBounds().width) / 2;

	if (distance < totalWidth)
	{
		std::cout << "something happened!" << std::endl;
		result = true;
	}

	return result;
}

void Collision::update()
{
	sf::Sprite enemy, player, bullet;

	for (int i = 0; i < enemyArray->size(); i++) //runs through every enemy
	{

		enemy = *(*enemyArray)[i];
		player = *p1;

		if (this->CheckCol(enemy, player))
		{
			playerAndEnemyCollision(i);
		}
		bool killed = false; // enemy is removed from the vector if killed, this bool prevents errors caused by this
		for (int j = 0; j < bullets->size() && !killed; j++) // checks all bullets against current enemy
		{
			bullet = *(*bullets)[j];
			if (this->CheckCol(enemy, bullet))
			{
				killed = bulletsAndEnemyCollision(i, j);
			}
		} //!j < bullets->size()
	} // !i < enemyArray->size()
}

void Collision::playerAndEnemyCollision(int enemyIndex)
{
	p1->damageForN((*enemyArray)[enemyIndex]->getDamage());
	if (p1->getHeath() <= 0)
	{
		// call game over
	}
}

bool Collision::bulletsAndEnemyCollision(int &enemyIndex, int &bulletIndex)
{
	bool killed = false;
	(*enemyArray)[enemyIndex]->damageForN(p1->getGun()->getDamage());// damages enemy for bullet damage
	delete (*bullets)[bulletIndex];
	bullets->erase(bullets->begin() + bulletIndex);
	--bulletIndex;

	if ((*enemyArray)[enemyIndex]->getHeath() <= 0) // kills enemy
	{
		delete (*enemyArray)[enemyIndex];
		enemyArray->erase(enemyArray->begin() + enemyIndex);
		--enemyIndex;
		killed = true;
	}
	return killed;
}