#include <SFML\Graphics.hpp>
#include "Controller.h"
#include "Enemy.h"
#include "Helpers.h"
#include "EnemySpawner.h"
#include "KeyValues.h"
#include "Collision.h"

int main()
{
	srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	sf::Texture texture, player_t, enemy_t;
	//Setup Background
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);
	//Setup Player
	player_t.loadFromFile("Circle.png");
	Player p1(.9, 100);
	EnemySpawner spawner("Peace-Symbol-Transparent.png", 10, 10, &p1, background);
	p1.attachGun("Rectangle.png", sf::Vector2f(0, 78), 250, 10, 1, &window);
	p1.setTexture(player_t); //custom setTexture, sets origin as well.
	p1.setScale(.05f, .05f);

	Collision collider();
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
		
        window.clear();
		window.draw(background);
		p1.update(window); //draws gun, bullts, updates player, gun
		p1.draw(window); //custom player draw function
		spawner.update(background, window);
        window.display();
    }

    return 0;
}