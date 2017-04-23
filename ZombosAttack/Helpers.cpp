#include "Helpers.h"

bool Helpers::isInsideWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	sf::Vector2f pos = object.getPosition();
	if (pos.x > window.getSize().x || pos.x < 0
		|| pos.y > window.getSize().y || pos.y < 0)
	{
		return false;
	}

	return true;
}