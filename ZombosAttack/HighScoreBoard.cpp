#include "HighScoreBoard.h"

HighScoreBoard::HighScoreBoard()
{
	for (int i = 0; i < NUMBER_OF_SCORES; i++) // initializes empty scores in case less than slots in scoreboard are loaded
	{
		this->mScoreBoard[i].score = 0;
		this->mScoreBoard[i].initials = 'aaa';
	}
	loadScores();
}

HighScoreBoard::~HighScoreBoard()
{
	saveScores();
}

bool HighScoreBoard::evaluateScore(int newScore)
{
	bool isInserted = false;
	int position = checkNewScore(newScore);
	if (position != -1)
	{
		for (int i = NUMBER_OF_SCORES - 1; i > position; i--)
		{
			mScoreBoard[i + 1] = mScoreBoard[i];
		}
		mScoreBoard[position].score = newScore;
		//mScoreBoard[position].initials = promptInitials();
		isInserted = true;
	}
	return isInserted;
}

void HighScoreBoard::loadScores()
{
	this->mScoreFile.open(SCORE_FILE_NAME);
	char buffer[100] = { '\0' };
	int count = 0;
	while (!mScoreFile.eof() && count < NUMBER_OF_SCORES)
	{
		mScoreFile.getline(buffer, 100, ',');
		if (buffer[0] != '\0') // didn't read an empty line
		{
			this->mScoreBoard[count].initials = buffer;

			mScoreFile.getline(buffer, 100);
			this->mScoreBoard[count].score = std::stoi(buffer);
			count++;
		}
	}
	mScoreFile.close();
}

void HighScoreBoard::saveScores()
{
	this->mScoreFile.open(SCORE_FILE_NAME);
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		mScoreFile << mScoreBoard[i].initials << ',' << mScoreBoard[i].score;
	}
	mScoreFile.close();
}

int HighScoreBoard::checkNewScore(int newScore)
{
	int position = -1;
	for (int i = NUMBER_OF_SCORES; i > 0; i--)
	{
		if (this->mScoreBoard[i].score < newScore)
		{
			position = i;
		}
	}
	return position;
}
