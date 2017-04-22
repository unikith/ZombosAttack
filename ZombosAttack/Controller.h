#pragma once

#define TWO_DIRECTIONAL_CORRECTION 0.70710678118f

#include "Player.h"

class Controller
{
public:
	Controller(Player *pNewPlayer, sf::Keyboard::Key up = sf::Keyboard::W,
		sf::Keyboard::Key down = sf::Keyboard::S,
		sf::Keyboard::Key left = sf::Keyboard::A,
		sf::Keyboard::Key right = sf::Keyboard::D,
		sf::Keyboard::Key shoot = sf::Keyboard::Space);
	bool runEvent(const sf::Event& event);

private:
	//Members
	Player *mpPlayer;
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mDown;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mShoot;
	bool bUp;	//If holding key down bool
	bool bDown;
	bool bLeft;
	bool bRight;
	//Functions
	bool keyPressed(const sf::Event& event);
	bool keyReleased(const sf::Event& event);
	void startUp();
	void startDown();
	void startLeft();
	void startRight();
	void startShoot();
	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();
	void stopShooting();
};