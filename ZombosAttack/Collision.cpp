#include <SFML\Graphics.hpp>
#include "Collision.h"

Collision::Collision()
{
}

bool Collision::CheckCol(sf::Sprite& o1, sf::Sprite &o2)
{
	bool result = false;
	sf::FloatRect bb1, bb2;
	bb1 = o1.getGlobalBounds();
	bb2 = o2.getGlobalBounds();
	
	if (bb1.intersects(bb2))
	{
		std::cout << "Something Happened!" << std::endl;
		result = true;
	}
	return result;
}
