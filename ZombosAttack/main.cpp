#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>
#include <SFML\System\FileInputStream.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1489, 644), "Zombos Attack!");

	// loads sbackground image and saves into the sprite background
	sf::Texture backgroundTexture;
	if(backgroundTexture.loadFromFile("Background.png", sf::IntRect(0, 0, 1489, 644)))
		sf::Sprite background(backgroundTexture);
	

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		//window.draw(background);
        window.display();
    }

    return 0;
}