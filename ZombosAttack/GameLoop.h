#pragma once
#include "Collision.h"
#include "Controller.h"
#include "EnemySpawner.h"
#include "Helpers.h"
#include <sstream>
#include <SFML/Audio.hpp>
class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void runLoop(int & playerScore);
private:

	sf::SoundBuffer buffer_gamestart;
	sf::Sound sound_gamestart;
};

