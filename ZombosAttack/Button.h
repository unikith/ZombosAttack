#pragma once
#include "KeyValues.h"
#include <SFML\Graphics.hpp>
#include <iostream> //remove

using std::string;

class Button : public sf::Sprite {
public:
	Button();
	~Button();
	void setTexture(const string & texture);
	void update(const sf::RenderWindow & window);
	bool isMouseInside(const sf::RenderWindow & window);
private:
	//functions
	void highlight();
	void unHighlight();
	bool isInside(const sf::Vector2i &pos, const sf::RenderWindow & window);
	//members
	bool ifHighlighted;
	sf::Texture buttonTexture;
};