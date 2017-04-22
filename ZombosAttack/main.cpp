#include <SFML\Graphics.hpp>
#include "Controller.h"
#include "Enemy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	sf::Texture texture, player_t, enemy_t;
	//Setup Background
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);
	//Setup Player
	player_t.loadFromFile("Circle.png");
	Player p1(.9, 100);
	p1.attachGun("Rectangle.png", sf::Vector2f(0, 78), .25, .1, 1, &window);
	p1.setTexture(player_t); //custom setTexture, sets origin as well.
	p1.setScale(.075f, .075f);
	//Setup Controller
	Controller p1Controller(&p1);

	Enemy e1(.125, 5, 6), e2(.2, 5, 6);
	enemy_t.loadFromFile("Peace-Symbol-Transparent.png");
	e1.setTexture(enemy_t);
	e2.setTexture(enemy_t);
	e1.setScale(.05f, .05f);
	e2.setScale(.05f, .05f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			p1Controller.runEvent(event);
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
        }
		e1.move(p1);
		e2.move(p1);
        window.clear();
		window.draw(background);
		p1.update(); //draws gun, bullts, updates player, gun
		p1.draw(window); //custom player draw function
		window.draw(e1);
		window.draw(e2);
        window.display();
    }

    return 0;
}