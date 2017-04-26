#include "Collision.h"
#include "Controller.h"
#include "EnemySpawner.h"
#include "Helpers.h"
#include <sstream>

int main()
{
	// seed random numbers by time
	srand(time(NULL));

	// initialized window
    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");
	// for loading textures
	sf::Texture texture, player_t;
	//Setup Background
	texture.loadFromFile("Background.png");
	sf::Sprite background;
	background.setTexture(texture);
	//Setup Player
	player_t.loadFromFile("Circle.png");
	Player p1(PLAYER_SPEED, PLAYER_HEALTH);
	int playerScore = 0;
	p1.attachGun("Rectangle.png", sf::Vector2f(0, 78), FIRE_DELAY, BULLET_SPEED, BULLET_DAMAGE, &window);
	p1.setTexture(player_t); //custom setTexture, sets origin as well.
	p1.setScale(PLAYER_SCALE, PLAYER_SCALE);
	p1.setPosition(background.getGlobalBounds().width / 2, background.getGlobalBounds().height / 2);

	// Setup Enemy Spawner
	EnemySpawner spawner("enemyCircle.png", SPAWN_ACCELERATION, ENEMY_SPAWN_DELAY, &p1, background);
	// Setup Collision Detecter
	Collision collider(&spawner.getEnemies(), &p1.getGun()->getBullets(), &p1);
	//Setup Controller
	Controller p1Controller(&p1);


    while (window.isOpen())
    {
		//Setup Text 
		sf::Font font;
		font.loadFromFile("zombie.ttf"); //Grabs font
		std::ostringstream sscore, shp;
		sscore << playerScore;
		shp << p1.getHealth();
		sf::Text score, hp;

		hp.setFont(font);
		hp.setCharacterSize(100);
		if (p1.getHealth() < PLAYER_HEALTH * 0.1)
			hp.setColor(sf::Color::Red);
		else
			hp.setColor(sf::Color::Green);
		hp.setPosition(1100, 0);
		hp.setString(shp.str());

		score.setFont(font);
		score.setCharacterSize(100);
		score.setColor(sf::Color::Magenta);
		score.setPosition(150, 0);
		score.setString(sscore.str());

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
		spawner.update(background, window); // runs spawner suite
		collider.update(playerScore); // checks all possible collisions
		window.draw(score);
		window.draw(hp);
        window.display();
    }

    return 0;
}