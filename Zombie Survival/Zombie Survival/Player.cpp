#include "Player.h"

Player::Player(const float& speed, const unsigned int& health) :
	Character(speed, health) {/*Empty*/
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
	gun = nullptr;
}
Player::~Player() {
	if (gun != nullptr)
		delete gun;
}
void Player::attachGun(const string &image, const sf::Vector2f &origin, float fireSpeed,
	float bulletSpeed, sf::Window *window) {
	gun = new Gun(image, origin, fireSpeed, bulletSpeed, window);
	gun->attachPlayer((sf::Sprite *)this);
}
void Player::update() { 
	move();
	gun->update();
}
void Player::draw(sf::RenderWindow &window) {
	window.draw(*this);
	if (gun != nullptr) { //maybe get rid of for efficiency assuming player always has a gun
		window.draw(*gun);
	}
}
void Player::setTexture(const sf::Texture &texture) {
	sf::Sprite::setTexture(texture);
	setOrigin(getLocalBounds().width/2, getLocalBounds().height/2); //Set origin to middle of Sprite
}