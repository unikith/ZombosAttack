#pragma once
#define TWO_DIRECTIONAL_CORRECTION 0.70710678118f
#include "Player.h"

class Controller 
{
public:
	Controller(Player *pNewPlayer, sf::Keyboard::Key up = sf::Keyboard::W,
		sf::Keyboard::Key down = sf::Keyboard::S,
		sf::Keyboard::Key left = sf::Keyboard::A,
		sf::Keyboard::Key right = sf::Keyboard::D);
	bool runEvent(const sf::Event& event);
private:
	Player *mpPlayer;
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mDown; 
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mRight;

	bool keyPressed(const sf::Event& event);
	bool keyReleased(const sf::Event& event);

	void startUp();
	void startDown();
	void startLeft();
	void startRight();

	bool stopUp();
	bool stopDown();
	bool stopLeft();
	bool stopRight();
};
