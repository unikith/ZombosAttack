#pragma once
#define TWO_DIRECTIONAL_CORRECTION 0.70710678118
#include "Player.h"

class Controller {
public:
	Controller(Player *p, sf::Keyboard::Key up = sf::Keyboard::W,
		sf::Keyboard::Key down = sf::Keyboard::S,
		sf::Keyboard::Key left = sf::Keyboard::A,
		sf::Keyboard::Key right = sf::Keyboard::D);
	bool runEvent(const sf::Event& event);
private:
	Player *p;
	sf::Keyboard::Key up;
	sf::Keyboard::Key down; 
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;

	bool keyPressed(const sf::Event& event);
	bool keyReleased(const sf::Event& event);

	bool startUp(const sf::Event& event);
	bool startDown(const sf::Event& event);
	bool startLeft(const sf::Event& event);
	bool startRight(const sf::Event& event);

	bool stopUp(const sf::Event& event);
	bool stopDown(const sf::Event& event);
	bool stopLeft(const sf::Event& event);
	bool stopRight(const sf::Event& event);
};
