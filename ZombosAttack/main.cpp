//#include "Collision.h"
//#include "Controller.h"
//#include "EnemySpawner.h"
//#include "Helpers.h"
//#include <sstream>

#include "GameLoop.h"

int main()
{
	// seed random numbers by time
	srand(time(NULL));
	int playerScore = 0;

	GameLoop gl;
	gl.runLoop(playerScore);

    return 0;
}