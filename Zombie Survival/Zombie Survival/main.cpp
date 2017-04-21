#include <SFML\Graphics.hpp>
#include "Controller.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	sf::Texture texture, player_t;
	//Setup Background
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);
	//Setup Player
	player_t.loadFromFile("Circle.png");
	Player p1(.5, 100);
	p1.attachGun("Rectangle.png", sf::Vector2f(0, 78), 1, .1, &window);
	p1.setTexture(player_t); //custom setTexture, sets origin as well.
	//Setup Controller
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
		p1.update();
        window.clear();
		window.draw(background);
		p1.draw(window); //custom player draw function
        window.display();
    }

    return 0;
}