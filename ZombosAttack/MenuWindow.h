#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Button.h"
#include <SFML/Audio.hpp>

using std::string;

class MenuWindow : public sf::RenderWindow
{
public:
	MenuWindow();
	~MenuWindow();
	void runMenu();
	Mode getMode() const { return mode; }
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Button playButton;
	Button highScoreButton;
	Button exitButton;
	Mode mode;
	sf::SoundBuffer buffer_menu;
	sf::Sound sound_menu;

};

