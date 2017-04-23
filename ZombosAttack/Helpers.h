#pragma once
#include <SFML\Graphics.hpp>

class Helpers
{
public:
	static bool isInsideWindow(const sf::Transformable& object, const sf::RenderWindow& window);
	static void lockObjectInWindow(sf::Transformable& object, const sf::RenderWindow& window);

private:
	static bool isUpOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);
	static bool isDownOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);
	static bool isRightOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);
	static bool isLeftOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);
};

