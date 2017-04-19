#include "Controller.h"
/// \ breif : binds a controller object to a player via a pointer, 
/// \			allows custom controls to be input for a player
/// \ parameters : player to bind controls to, keys for each control
/// \ precons : p points to a valid player object
/// \ return : a contoller object is created
Controller::Controller(Player *pNewPlayer, sf::Keyboard::Key up,
					sf::Keyboard::Key down, sf::Keyboard::Key left,
					sf::Keyboard::Key right) 
{
	this->mUp = up;
	this->mDown = down;
	this->mLeft = left;
	this->mRight = right;
	this->mpPlayer = pNewPlayer;
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
	if (event.key.code == mUp) 
	{
		this->startUp();
	}
	else if (event.key.code == mDown) 
	{
		this->startDown();
	}
	else if (event.key.code == mLeft) 
	{
		startLeft();
	}
	else if (event.key.code == mRight)
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
	if (event.key.code == mUp) 
	{
		return stopUp();
	}
	else if (event.key.code == mDown) 
	{
		return stopDown();
	}
	else if (event.key.code == mLeft) 
	{
		return stopLeft();
	}
	else if (event.key.code == mRight) 
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
	if (mpPlayer->mVelocity.x == 0) // if no x axis mVelocity
		mpPlayer->mVelocity.y = -mpPlayer->mSpeed;
	else // if moveing in x and y
	{
		mpPlayer->mVelocity.y = -mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
		mpPlayer->mVelocity.x *= TWO_DIRECTIONAL_CORRECTION;
	}
	
}

/// \ breif : takes the down key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startDown()
{
	if (mpPlayer->mVelocity.x == 0) // if no x axis mVelocity
	{
		mpPlayer->mVelocity.y = mpPlayer->mSpeed;
	}
	else // if moveing in x and y
	{
		mpPlayer->mVelocity.y = mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
		mpPlayer->mVelocity.x *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the left key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startLeft()
{
	if (mpPlayer->mVelocity.y == 0) // if no y axis movement
	{
		mpPlayer->mVelocity.x = -mpPlayer->mSpeed;
	}
	else // if moveing in x and y
	{
		mpPlayer->mVelocity.x = -mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
		mpPlayer->mVelocity.y *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the right key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
void Controller::startRight()
{
	if (mpPlayer->mVelocity.y == 0) // if no y axis movement
	{
		mpPlayer->mVelocity.x = mpPlayer->mSpeed;
	}
	else // if moveing in x and y
	{
		mpPlayer->mVelocity.x = mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
		mpPlayer->mVelocity.y *= TWO_DIRECTIONAL_CORRECTION;
	}
}

/// \ breif : takes the up key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
/// \ return : if control had an effect
bool Controller::stopUp()
{
	bool result = false;
	if (mpPlayer->mVelocity.y < 0) // if moving up
	{
		result = true;
		if (mpPlayer->mVelocity.x != 0) // moving in two directions
		{
			mpPlayer->mVelocity.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.y = 0;
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
	if (mpPlayer->mVelocity.y > 0) // if moving down
	{
		result = true;
		if (mpPlayer->mVelocity.x != 0) // moving in two directions
		{
			mpPlayer->mVelocity.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.y = 0;
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
	if (mpPlayer->mVelocity.x < 0) // if moving left
	{
		result = true;
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0;
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
	if (mpPlayer->mVelocity.x > 0) // if moving right
	{
		result = true;
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0;
	}
	return result;
}