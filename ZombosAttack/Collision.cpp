#include <SFML\Graphics.hpp>
#include "Collision.h"

Collision::Collision(std::vector<Enemy*>* arr, std::vector<Bullet*>* bulletsArr, Player* player)
{
	this->enemyArray = arr;
	this->bullets = bulletsArr;
	p1 = player;
}

bool Collision::CheckCol(sf::FloatRect& bb1, sf::FloatRect &bb2)
{
	bool result = false;
	if (bb1.intersects(bb2))
	{
		std::cout << "something happened!" << std::endl;
		result = true;
	}
	return result;
}

void Collision::update()
{
	sf::FloatRect bbEnemy, bbPlayer, bbBullet;
	int i = 0, i2 = 0;
	bbPlayer = p1->getGlobalBounds();
	while (i < enemyArray->size())
	{
		i2 = 0;
		bbEnemy = (*enemyArray)[i]->getGlobalBounds();

		this->CheckCol(bbEnemy, bbPlayer);

		while (i2 < bullets->size())
		{
			bbBullet = (*bullets)[i2]->getGlobalBounds();
			this->CheckCol(bbEnemy, bbBullet);
			i2++;
		}
		i++;
	}
}