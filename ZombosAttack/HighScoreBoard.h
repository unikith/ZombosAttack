#pragma once

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

class HighScoreBoard
{
public:
	// Functions
	HighScoreBoard();
	~HighScoreBoard();

	bool evaluateScore(int newScore);
private:
	// Members
	fstream mScoreFile;
	Board_Entry mScoreBoard[NUMBER_OF_SCORES];

	// Functions
	void loadScores();
	void saveScores();

	int checkNewScore(int newScore);
	//string promptInitials();
};

