#include "Controller.h"

Controller::Controller(Player *pNewPlayer, sf::Keyboard::Key up,
	sf::Keyboard::Key down, sf::Keyboard::Key left,
	sf::Keyboard::Key right, sf::Keyboard::Key shoot)
{
	this->mUp = up;
	this->mDown = down;
	this->mLeft = left;
	this->mRight = right;
	this->mShoot = shoot;
	this->mpPlayer = pNewPlayer;
	this->bUp = false;
	this->bDown = false;
	this->bLeft = false;
	this->bRight = false;
}

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
	else if (event.key.code == mShoot) 
	{
		startShoot();
	}
	else
	{
		result = false;
	}
	return result;
}

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
	else if (event.key.code == mShoot)
	{
		mpPlayer->gun->setShooting(false);
	}
	else 
	{
		result = false;
	}
	return result;
}

void Controller::startUp()
{
	if (!bUp) { //Enters if first press
		if (mpPlayer->mVelocity.x == 0) // if no x axis mVelocity
			mpPlayer->mVelocity.y = -mpPlayer->mSpeed;
		else // if moving in x and y
		{
			mpPlayer->mVelocity.y = -mpPlayer->mSpeed * TWO_DIRECTIONAL_CORRECTION;
			mpPlayer->mVelocity.x *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	bUp = true;
}

void Controller::startDown()
{
	if (!bDown) { //Enters if first press
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

void Controller::startLeft()
{
	if (!bLeft) //Enters if first press
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

void Controller::startRight()
{
	if (!bRight) //Enters if first press
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

void Controller::startShoot()
{
	mpPlayer->gun->setShooting(true);
}

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

void Controller::stopDown()
{
	if (bUp && mpPlayer->mVelocity.y > 0) //If Up is being held and going down
	{
		mpPlayer->mVelocity.y *= -1; //Switch direction
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

void Controller::stopLeft()
{
	if (bRight && mpPlayer->mVelocity.x < 0) //If Right is being held and going left
	{
		mpPlayer->mVelocity.x *= -1; //Switch direction
	}
	else if (!bRight) //Right not being held
	{
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0; //Stops Player
	}
	bLeft = false;
}

void Controller::stopRight()
{
	if (bLeft && mpPlayer->mVelocity.x > 0) //If Left is being held and going right
	{
		mpPlayer->mVelocity.x *= -1; //Switch direction
	}
	else if (!bLeft) //Left not being held
	{
		if (mpPlayer->mVelocity.y != 0) // moving in two directions
		{
			mpPlayer->mVelocity.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		mpPlayer->mVelocity.x = 0; //Stops Player
	}
	bRight = false;
}

void Controller::stopShooting() 
{
	mpPlayer->gun->setShooting(false);
}
