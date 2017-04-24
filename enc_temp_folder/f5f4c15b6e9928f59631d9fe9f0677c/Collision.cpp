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

	float totalWidth = s1.getGlobalBounds().width / 2 + s2.getGlobalBounds().width / 2;

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

	for (int i = 0; i < enemyArray->size(); i++)
	{

		enemy = *(*enemyArray)[i];
		player = *p1;

		if (this->CheckCol(enemy, player))
		{
			playerAndEnemyCollision(i);
		}

		for (int j = 0; j < bullets->size(); j++)
		{
			bullet = *(*bullets)[j];
			if (this->CheckCol(enemy, bullet))
			{
				bulletsAndEnemyCollision(i, j);
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

void Collision::bulletsAndEnemyCollision(int &enemyIndex, int &bulletIndex)
{
	(*enemyArray)[enemyIndex]->damageForN(p1->getGun()->getDamage());
	delete (*bullets)[bulletIndex];
	bullets->erase(bullets->begin() + bulletIndex);
	--bulletIndex;

	if ((*enemyArray)[enemyIndex]->getHeath() <= 0)
	{
		delete (*enemyArray)[enemyIndex];
		enemyArray->erase(enemyArray->begin() + enemyIndex);
		--enemyIndex;
	}
}