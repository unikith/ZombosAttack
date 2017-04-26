#pragma once
#include <SFML\Graphics.hpp>

#define NUMBER_OF_SCORES 5
#define NUMBER_OF_INITIALS 3
#define SCORE_FILE_NAME "highScores.csv"
#include <fstream>
#include <string>

using std::fstream;
using std::string;

typedef struct board_entry
{
	int score;
	string initials;
}Board_Entry;

class HighScoreBoard : public sf::RenderWindow
{
public:
	// Functions
	HighScoreBoard(int *score);
	~HighScoreBoard();

	void runWindow();
	void saveScores();
private:
	// Members
	fstream mScoreFile;
	Board_Entry mScoreBoard[NUMBER_OF_SCORES];
	sf::Texture gameOverTexture;
	sf::Sprite gameOver;
	sf::Texture scoresTableTexture;
	sf::Sprite scoresTable;
	sf::Texture typeInitialsTexture;
	sf::Sprite typeInitials;
	int *score;

	// Functions
	void loadScores();

	bool evaluateScore(int newScore, const string & initials);
	int checkNewScore(int newScore);
};

