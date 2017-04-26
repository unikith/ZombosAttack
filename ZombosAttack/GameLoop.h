#pragma once
#include "Collision.h"
#include "Controller.h"
#include "EnemySpawner.h"
#include "Helpers.h"
#include <sstream>
class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void runLoop(int & playerScore);
};

