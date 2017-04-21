#include <SFML\Graphics.hpp>
#include "Controller.h"
#include "Enemy.h"

using std::cout;
using std::endl;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	sf::Texture texture, player_t, enemy_t;
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);

	player_t.loadFromFile("Illuminati.png");
	Player p1(.9f, 5);
	p1.setTexture(player_t);
	p1.setScale(sf::Vector2f(.05f, .05f));

	enemy_t.loadFromFile("Peace-Symbol-Transparent.png");
	Enemy e1(.45f, 5, 4);
	e1.setPosition(sf::Vector2f(500.0f, 50.00f));
	e1.setScale(sf::Vector2f(.05f, .05f));
	e1.setTexture(enemy_t);

	Enemy e2(.45f, 5, 4);
	e2.setPosition(sf::Vector2f(100.0f, 50.00f));
	e2.setScale(sf::Vector2f(.05f, .05f));
	e2.setTexture(enemy_t);

	Controller p1Controller(&p1);

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
		p1.move();
		e1.updateDirection(p1);
		e1.move();
		e2.updateDirection(p1);
		e2.move();

        window.clear();
		window.draw(background);
		window.draw(p1);
		window.draw(e1);
		window.draw(e2);
        window.display();
    }

    return 0;
}