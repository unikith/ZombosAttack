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
	HighScoreBoard();
	~HighScoreBoard();

	void runWindow();
private:
	// Members
	fstream mScoreFile;
	Board_Entry mScoreBoard[NUMBER_OF_SCORES];

	// Functions
	void loadScores();
	void saveScores();

	bool evaluateScore(int newScore);
	int checkNewScore(int newScore);
	string promptInitials();
};

