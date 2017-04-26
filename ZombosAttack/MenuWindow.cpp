#include "MenuWindow.h"



MenuWindow::MenuWindow()
{
	//Set up basics
	create(sf::VideoMode(600, 600), "Menu");
	mode = ModeNone;
	backgroundTexture.loadFromFile("menu.png");
	background.setTexture(backgroundTexture);
	playButton.setTexture("playButton.png");
	highScoreButton.setTexture("highScoreButton.png");
	exitButton.setTexture("exitButton.png");

	playButton.setPosition(100, 290);
	highScoreButton.setPosition(100, 400);
	exitButton.setPosition(100, 510);
	//runMenu();
}
MenuWindow::~MenuWindow()
{
}
void MenuWindow::runMenu() {
	create(sf::VideoMode(600, 600), "Menu");
	while (isOpen()) {
		sf::Event event;
		while (pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				if (playButton.isMouseInside(*this)) {
					mode = Mode::MainGameMode;
					close();
				}
				else if (exitButton.isMouseInside(*this)) {
					mode = Mode::ExitGameMode;
					close();
				}
				else if (highScoreButton.isMouseInside(*this)) {
					mode = Mode::HighScoreBoardMode;
					close();
				}
			}
			if (event.type == sf::Event::Closed)
			{
				close();
			}
		}
		clear();
		playButton.update(*this);
		highScoreButton.update(*this);
		exitButton.update(*this);
		draw(background);
		draw(playButton);
		draw(highScoreButton);
		draw(exitButton);
		display();
	}
}
