#include "Controller.h"

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

bool Controller::runEvent(const sf::Event& event) 
{
	bool result = true;
	if (event.type == sf::Event::KeyPressed) 
	{
		result = this->keyPressed(event);
	}
	else if (event.type == sf::Event::KeyReleased) {
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
	if (event.key.code == up) 
	{
		result = this->startUp(event);
	}
	else if (event.key.code == down) 
	{
		result = this->startDown(event);
	}
	else if (event.key.code == left) 
	{
		result = startLeft(event);
	}
	else if (event.key.code == right) {
		result = startRight(event);
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
	if (event.key.code == up) 
	{
		return stopUp(event);
	}
	else if (event.key.code == down) 
	{
		return stopDown(event);
	}
	else if (event.key.code == left) 
	{
		return stopLeft(event);
	}
	else if (event.key.code == right) 
	{
		return stopRight(event);
	}
	else
	{
		result = false;
	}
	return result;
}

bool Controller::startUp(const sf::Event& event)
{
	bool result = false;
	if (p->movement.y == 0)
	{
		result = true;
		if (p->movement.x == 0)
			p->movement.y = -p->speed;
		else
		{
			p->movement.y = -p->speed * TWO_DIRECTIONAL_CORRECTION;
			p->movement.x *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	return result;
}

bool Controller::startDown(const sf::Event& event)
{
	bool result = false;
	if (p->movement.y == 0)
	{
		result = true;
		if (p->movement.x == 0)
		{
			p->movement.y = p->speed;
		}
		else
		{
			p->movement.y = p->speed * TWO_DIRECTIONAL_CORRECTION;
			p->movement.x *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	return result;
}

bool Controller::startLeft(const sf::Event& event)
{
	bool result = false;
	if (p->movement.x == 0) 
	{
		result = true;
		if (p->movement.y == 0)
		{
			p->movement.x = -p->speed;
		}
		else 
		{
			p->movement.x = -p->speed * TWO_DIRECTIONAL_CORRECTION;
			p->movement.y *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	return result;
}

bool Controller::startRight(const sf::Event& event)
{
	bool result = false;
	if (p->movement.x == 0)
	{
		result = true;
		if (p->movement.y == 0)
		{
			p->movement.x = p->speed;
		}
		else
		{
			p->movement.x = p->speed * TWO_DIRECTIONAL_CORRECTION;
			p->movement.y *= TWO_DIRECTIONAL_CORRECTION;
		}
	}
	return result;
}

bool Controller::stopUp(const sf::Event& event)
{
	bool result = false;
	if (p->movement.y < 0)
	{
		result = true;
		if (p->movement.x != 0)
		{
			p->movement.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.y = 0;
	}
	return result;
}

bool Controller::stopDown(const sf::Event& event)
{
	bool result = false;
	if (p->movement.y > 0)
	{
		result = true;
		if (p->movement.x != 0)
		{
			p->movement.x /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.y = 0;
	}
	return result;
}
bool Controller::stopLeft(const sf::Event& event)
{
	bool result = false;
	if (p->movement.x < 0)
	{
		result = true;
		if (p->movement.y != 0)
		{
			p->movement.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.x = 0;
	}
	return result;
}
bool Controller::stopRight(const sf::Event& event)
{
	bool result = false;
	if (p->movement.x > 0)
	{
		result = true;
		if (p->movement.y != 0)
		{
			p->movement.y /= TWO_DIRECTIONAL_CORRECTION;
		}
		p->movement.x = 0;
	}
	return result;
}