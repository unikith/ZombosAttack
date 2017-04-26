#include "Button.h"

Button::Button() {
	ifHighlighted = false;
}
Button::~Button() {

}
void Button::setTexture(const string & texture) {
	buttonTexture.loadFromFile(texture);
	Sprite::setTexture(buttonTexture);
}
void Button::update(const sf::RenderWindow & window) {
	if (!ifHighlighted && isMouseInside(window)) {
		ifHighlighted = true;
		highlight();
	}
	else if(ifHighlighted && !isMouseInside(window)){
		ifHighlighted = false;
		unHighlight();
	}

}
bool Button::isMouseInside(const sf::RenderWindow & window) {
	return isInside(sf::Mouse::getPosition(window), window);
}
bool Button::isInside(const sf::Vector2i &mousePos, const sf::RenderWindow & window) {
	sf::Vector2f pos = getPosition();
	if (mousePos.x >= pos.x && mousePos.x <= pos.x + getGlobalBounds().width
		&& mousePos.y >= pos.y && mousePos.y <= pos.y + getGlobalBounds().height) {
		return true;
	}
	return false;
}
void Button::highlight() {
	setPosition(getPosition().x - .1 * getGlobalBounds().width,
		getPosition().y - .1 * getGlobalBounds().height);
	setScale(BUTTON_BULGE, BUTTON_BULGE);
}
void Button::unHighlight() {
	setScale(1, 1);
	setPosition(getPosition().x + .1 * getGlobalBounds().width,
		getPosition().y + .1 * getGlobalBounds().height);
}