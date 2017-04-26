//#include "Collision.h"
//#include "Controller.h"
//#include "EnemySpawner.h"
//#include "Helpers.h"
//#include <sstream>

#include "GameLoop.h"
#include "HighScoreBoard.h"
#include "MenuWindow.h"

int main()
{
	// seed random numbers by time
	srand(time(NULL));
	int playerScore = 0;
	MenuWindow mainMenu;
	GameLoop gl;
	HighScoreBoard hb(&playerScore);
	sf::SoundBuffer buffer_dead;
	sf::Sound sound_dead;
	do
	{
		mainMenu.runMenu();
		switch (mainMenu.getMode())
		{
		case MainGameMode:
			gl.runLoop(playerScore);
			//dead
			buffer_dead.loadFromFile("dead.wav");
			sound_dead.setBuffer(buffer_dead);
			sound_dead.play();
			hb.runWindow();
			hb.saveScores();
			hb.runWindowFromMenu();
			break;
		case HighScoreBoardMode:
			hb.runWindowFromMenu();
			break;
		case ExitGameMode:
			hb.saveScores();
			break;
		default:
			break;
		}
		playerScore = 0;
	} while (mainMenu.getMode() != ExitGameMode);

    return 0;
}