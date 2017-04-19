#include "Controller.h"
/// \ breif : binds a controller object to a player via a pointer, 
/// \			allows custom controls to be input for a player
/// \ parameters : player to bind controls to, keys for each control
/// \ precons : p points to a valid player object
/// \ return : a contoller object is created
Controller::Controller(Player *p, sf::Keyboard::Key up,
					sf::Keyboard::Key down, sf::Keyboard::Key left,
					sf::Keyboard::Key right) 
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
	this->p = p;
}

/// \ breif : takes an input event and if it matches a set control it runs the
/// \			correct action
/// \ parameters : an event input from the keyboard
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::runEvent(const sf::Event& event) 
{
	bool result = true;
	if (event.type == sf::Event::KeyPressed) 
	{
		result = this->keyPressed(event);
	}
	else if (event.type == sf::Event::KeyReleased) 
	{
		result = keyReleased(event);
	}
	else
	{
		result = false;
	}
	return result;
}

/// \ breif : checks key presses and enacts them summarily
/// \ parameters : an event input from the keyboard
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::keyPressed(const sf::Event& event)
{
	bool result = true;
	if (event.key.code == up) 
	{
		this->startUp();
	}
	else if (event.key.code == down) 
	{
		this->startDown();
	}
	else if (event.key.code == left) 
	{
		startLeft();
	}
	else if (event.key.code == right)
	{
		startRight();
	}
	else
	{
		result = false;
	}

	return result;
}

/// \ breif : checks key releases and enacts them summarily
/// \ parameters : an event input from the keyboard
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::keyReleased(const sf::Event& event)
{
	bool result = true;
	if (event.key.code == up) 
	{
		return stopUp();
	}
	else if (event.key.code == down) 
	{
		return stopDown();
	}
	else if (event.key.code == left) 
	{
		return stopLeft();
	}
	else if (event.key.code == right) 
	{
		return stopRight();
	}
	else
	{
		result = false;
	}
	return result;
}

/// \ breif : takes the up key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startUp()
{	
	if (p->movement.x == 0) // if no x axis movement
		p->movement.y = -p->speed;
	else // if moveing in x and y
	{
		p->movement.y = -p->speed * TWO_DIRECTIONAL_CORRECTION;
		p->movement.x *= TWO_DIRECTIONAL_CORRECTION;
	}
	
}

/// \ breif : takes the down key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startDown()
{
	if (p->movement.x == 0) // if no x axis movement
	{
		p->movement.y = p->speed;
	}
	else // if moveing in x and y
	{
		p->movement.y = p->speed * TWO_DIRECTIONAL_CORRECTION;
		p->movement.x *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the left key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startLeft()
{
	if (p->movement.y == 0) // if no y axis movement
	{
		p->movement.x = -p->speed;
	}
	else // if moveing in x and y
	{
		p->movement.x = -p->speed * TWO_DIRECTIONAL_CORRECTION;
		p->movement.y *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the right key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startRight()
{
	if (p->movement.y == 0) // if no y axis movement
	{
		p->movement.x = p->speed;
	}
	else // if moveing in x and y
	{
		p->movement.x = p->speed * TWO_DIRECTIONAL_CORRECTION;
		p->movement.y *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the up key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::stopUp()
{
	bool result = false;
	if (p->movement.y < 0) // if moving up
	{
		result = true;
		if (p->movement.x != 0) // moving in two directions
		{
			p->movement.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.y = 0;
	}
	return result;
}

/// \ breif : takes the down key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::stopDown()
{
	bool result = false;
	if (p->movement.y > 0) // if moving down
	{
		result = true;
		if (p->movement.x != 0) // moving in two directions
		{
			p->movement.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.y = 0;
	}
	return result;
}

/// \ breif : takes the left key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::stopLeft()
{
	bool result = false;
	if (p->movement.x < 0) // if moving left
	{
		result = true;
		if (p->movement.y != 0) // moving in two directions
		{
			p->movement.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.x = 0;
	}
	return result;
}

/// \ breif : takes the right key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect 
bool Controller::stopRight()
{
	bool result = false;
	if (p->movement.x > 0) // if moving right
	{
		result = true;
		if (p->movement.y != 0) // moving in two directions
		{
			p->movement.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.x = 0;
	}
	return result;
}