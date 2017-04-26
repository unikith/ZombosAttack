#include "HighScoreBoard.h"

HighScoreBoard::HighScoreBoard(int *score)
{
	for (int i = 0; i < NUMBER_OF_SCORES; i++) // initializes empty scores in case less than slots in scoreboard are loaded
	{
		this->mScoreBoard[i].score = 0;
		this->mScoreBoard[i].initials = "aaa";
	}
	loadScores();
	this->score = score;
	gameOverTexture.loadFromFile("gameOver.png");
	gameOver.setTexture(gameOverTexture);
	scoresTableTexture.loadFromFile("scoreBoard.png");
	scoresTable.setTexture(scoresTableTexture);
	typeInitialsTexture.loadFromFile("initial.png");
	typeInitials.setTexture(typeInitialsTexture);
	//runWindow();
}

HighScoreBoard::~HighScoreBoard()
{
	saveScores();
}

void HighScoreBoard::runWindow()
{
	create(sf::VideoMode(700, 700), "Menu", sf::Style::Close);
	//set positions
	gameOver.setPosition(0, -75);
	scoresTable.setPosition(75, 225);
	typeInitials.setPosition(0, 600);
	string str;
	sf::Text text; //initials text
	sf::Text playerScore;
	sf::Text scores[NUMBER_OF_SCORES];
	sf::Font zombieFont;
	zombieFont.loadFromFile("ZOMBIE.ttf");
	text.setFont(zombieFont);
	text.setPosition(400, 630);
	scoresTable.setScale(1, 1);
	//scoreboard scores
	for (int i = 0; i < NUMBER_OF_SCORES; ++i) {
		scores[i].setFont(zombieFont);
		scores[i].setColor(sf::Color::Black);
		scores[i].setCharacterSize(50);
		scores[i].setPosition(150, 295 + 48 * i);
		scores[i].setString(mScoreBoard[i].initials + " " + std::to_string(mScoreBoard[i].score));
	}
	//player score stuff
	playerScore.setFont(zombieFont);
	playerScore.setPosition(350, 540);
	playerScore.setCharacterSize(50);
	playerScore.setColor(sf::Color::Black);

	playerScore.setString(std::to_string(*score));
	int letterCount = 0;
	while (this->isOpen())
	{
		sf::Event event;
		while (pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered) {
				if (static_cast<char>(event.text.unicode) == 8) {
					if (letterCount > 0) {
						str.pop_back();
						text.setString(str);
						letterCount--;
					}
				} 
				else if (static_cast<char>(event.text.unicode) == 13) {
					evaluateScore(*score, str);
					close();
				}
				else if(letterCount < 3) {
					str += static_cast<char>(event.text.unicode);
					text.setString(str);
					letterCount++;
				} 
				
			} else if (event.type == sf::Event::Closed)
			{
				close();
			}
		}
		clear();
		draw(gameOver);
		draw(scoresTable);
		draw(typeInitials);
		draw(text);
		draw(playerScore);
		for (int i = 0; i < NUMBER_OF_SCORES; i++) {
			draw(scores[i]);
		}
		display();
	}

}
void HighScoreBoard::runWindowFromMenu()
{
	create(sf::VideoMode(900, 650), "Menu", sf::Style::Close);
	//set positions
	scoresTable.setPosition(0,0);
	scoresTable.setScale(1.7, 2.11);
	//typeInitials.setPosition(0, 600);
	string str;
	sf::Text text; //initials text
	sf::Text playerScore;
	sf::Text scores[NUMBER_OF_SCORES];
	sf::Font zombieFont;
	zombieFont.loadFromFile("ZOMBIE.ttf");
	text.setFont(zombieFont);
	text.setPosition(400, 630);
	//scoreboard scores
	for (int i = 0; i < NUMBER_OF_SCORES; ++i) {
		scores[i].setFont(zombieFont);
		scores[i].setColor(sf::Color::Black);
		scores[i].setCharacterSize(50);
		scores[i].setPosition(150, 190 + 100 * i);
		scores[i].setString(mScoreBoard[i].initials + " " + std::to_string(mScoreBoard[i].score));
	}
	//player score stuff
	//playerScore.setFont(zombieFont);
	//playerScore.setPosition(350, 540);
	//playerScore.setCharacterSize(50);
	//playerScore.setColor(sf::Color::Black);

	playerScore.setString(std::to_string(*score));
	int letterCount = 0;
	while (this->isOpen())
	{
		sf::Event event;
		while (pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered) {		
				if (static_cast<char>(event.text.unicode) == 13) {
					close();
				}
			}
			else if (event.type == sf::Event::Closed)
			{
				close();
			}
		}
		clear();
		draw(scoresTable);
		draw(text);
		for (int i = 0; i < NUMBER_OF_SCORES; i++) {
			draw(scores[i]);
		}
		display();
	}

}
bool HighScoreBoard::evaluateScore(int newScore, const string & initials)
{
	bool isInserted = false;
	int position = checkNewScore(newScore);
	if (position != -1)
	{
		for (int i = NUMBER_OF_SCORES - 1; i >= position; i--)
		{
			mScoreBoard[i + 1] = mScoreBoard[i];
		}
		mScoreBoard[position].score = newScore;
		mScoreBoard[position].initials = initials;
		isInserted = true;
	}
	return isInserted;
}

void HighScoreBoard::loadScores()
{
	this->mScoreFile.open(SCORE_FILE_NAME);
	char buffer[100] = { '\0' };
	int count = 0;
	while (mScoreFile.getline(buffer, 100, ',') && count < NUMBER_OF_SCORES)
	{
	//	mScoreFile.getline(buffer, 100, ',');
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
		mScoreFile << mScoreBoard[i].initials << ',' << mScoreBoard[i].score << "\n";
	}
	mScoreFile.close();
}

int HighScoreBoard::checkNewScore(int newScore)
{
	int position = -1;
	for (int i = NUMBER_OF_SCORES; i >= 0; i--)
	{
		if (this->mScoreBoard[i].score < newScore)
		{
			position = i;
		}
	}
	return position;
}
