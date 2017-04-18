#include <SFML\Graphics.hpp>
#include "Controller.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	sf::Texture texture, player_t;
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);

	player_t.loadFromFile("Illuminati.png");
	Player p1(.5);
	p1.setTexture(player_t);

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

        window.clear();
		window.draw(background);
		window.draw(p1);
        window.display();
    }

    return 0;
}