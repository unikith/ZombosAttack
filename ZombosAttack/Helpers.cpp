#include "Helpers.h"

bool Helpers::isInsideWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	bool inWindow = true;
	sf::Vector2f pos = object.getPosition();
	if (pos.x > window.getSize().x || pos.x < 0 // outside x axis bounds of window
		|| pos.y > window.getSize().y || pos.y < 0) // outside y axis bounds of window
	{
		inWindow = false;
	}

	return inWindow;
}

void Helpers::lockObjectInWindow(sf::Transformable& object, const sf::RenderWindow& window)
{
	if (isUpOfWindow(object, window))
	{
		object.setPosition(object.getPosition().x, 0); // moves to top edge of window
	}
	else if (isDownOfWindow(object, window))
	{
		object.setPosition(object.getPosition().x, window.getSize().y); // moves to bottom edge of window
	}

	if (isLeftOfWindow(object, window))
	{
		object.setPosition(0, object.getPosition().y); // moves to left edge of window
	}
	else if (isRightOfWindow(object, window))
	{
		object.setPosition(window.getSize().x, object.getPosition().y); // moves to right edge of window
	}
}


bool Helpers::isUpOfWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	return (object.getPosition().y < 0);
}

bool Helpers::isDownOfWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	return (object.getPosition().y > window.getSize().y);
}

bool Helpers::isRightOfWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	return (object.getPosition().x > window.getSize().x);
}

bool Helpers::isLeftOfWindow(const sf::Transformable& object, const sf::RenderWindow& window)
{
	return (object.getPosition().x < 0);
}