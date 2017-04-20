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
	this->bUp = false;
	this->bDown = false;
	this->bLeft = false;
	this->bRight = false;
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
		stopUp();
	}
	else if (event.key.code == mDown)
	{
		stopDown();
	}
	else if (event.key.code == mLeft)
	{
		stopLeft();
	}
	else if (event.key.code == mRight)
	{
		stopRight();
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
void Controller::startUp()
{
	if (!bUp) { //Enters if first press
		if (mpPlayer->mVelocity.x == 0) // if no x axis mVelocity
			mpPlayer->mVelocity.y = -mpPlayer->mSpeed;
		else // if moveing in x and y
		{
			mpPlayer->mVelocity.y = -mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
			mpPlayer->mVelocity.x *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	bUp = true;
}
/// \ breif : takes the down key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::startDown()
{
	if (!bDown) {
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
	bDown = true;
}
/// \ breif : takes the left key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::startLeft()
{
	if (!bLeft)
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
		bLeft = true;
}
/// \ breif : takes the right key press and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::startRight()
{
	if (!bRight)
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
	bRight = true;
}
/// \ breif : takes the up key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::stopUp()
{
	if (bDown && mpPlayer->mVelocity.y < 0) // if Down is being held and going up
	{
		mpPlayer->mVelocity.y *= -1; //Switch direction
	} 
	else if(!bDown) //Down not held
	{ 
		if (mpPlayer->mVelocity.x != 0) // moving in two directions
		{
			mpPlayer->mVelocity.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.y = 0; //Stops Player
	}
	bUp = false;
}
/// \ breif : takes the down key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::stopDown()
{
	if (bUp && mpPlayer->mVelocity.y > 0) //If Up is being held and going down
	{
		mpPlayer->mVelocity.y *= -1;
	}
	else if(!bUp) //Up not being held
	{
		if (mpPlayer->mVelocity.x != 0) // moving in two directions
		{
			mpPlayer->mVelocity.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.y = 0; //Stops Player
	}
	bDown = false;
}

/// \ breif : takes the left key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::stopLeft()
{
	if (bRight && mpPlayer->mVelocity.x < 0) //If Right is being held and going left
	{
		mpPlayer->mVelocity.x *= -1;
	}
	else if (!bRight) //Right not being held
	{
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0;
	}
	bLeft = false;
}
/// \ breif : takes the right key release and runs movement logic on it
/// \ parameters :
/// \ precons : the player pointer points to a valid player object
void Controller::stopRight()
{
	if (bLeft && mpPlayer->mVelocity.x > 0) //If Left is being held and going right
	{
		mpPlayer->mVelocity.x *= -1;
	}
	else if (!bLeft) //Left not being held
	{
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0;
	}
	bRight = false;
}