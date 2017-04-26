#pragma once
#include <SFML\Graphics.hpp>

/// \ static class used to wrap helper functions
class Helpers
{
public:
	/// \ brief : determines whether or not a transformable object is within the input window
	/// \ params : object is any transformable and window is the main window
	/// \ precons : object and window are initiated objects
	/// \ return : true if in window, flase otherwise
	static bool isInsideWindow(const sf::Transformable& object, const sf::RenderWindow& window);

	/// \ brief : corrects x and y position seperatly if ooutside window to keep the object in the window
	/// \ params : object is a transformable to lock into the window, window is where the object is locked
	/// \ precons : object and window are initiated objects
	/// \ return : none
	static void lockObjectInWindow(sf::Transformable& object, const sf::RenderWindow& window);

private:
	/// \ brief : returns if object is above the window
	/// \ params : object is a transformable that is checked against window
	/// \ precons : object and window are initiated objects
	/// \ return : returns true if object is above window and false otherwise
	static bool isUpOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);

	/// \ brief : returns if object is below the window
	/// \ params : object is a transformable that is checked against window
	/// \ precons : object and window are initiated objects
	/// \ return :  returns true if object is below window and false otherwise
	static bool isDownOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);

	/// \ brief : returns if object is right of the window
	/// \ params : object is a transformable that is checked against window
	/// \ precons : object and window are initiated objects
	/// \ return :  returns true if object is right of window and false otherwise returns true if object is above window and false otherwise
	static bool isRightOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);

	/// \ brief : returns if object is left of the window
	/// \ params : object is a transformable that is checked against window
	/// \ precons : object and window are initiated objects
	/// \ return :  returns true if object is left of window and false otherwise
	static bool isLeftOfWindow(const sf::Transformable& object, const sf::RenderWindow& window);
};

