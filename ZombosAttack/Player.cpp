#include "Player.h"

Player::Player(const float& speed, const unsigned int& health) :
	Character(speed, health) {/*Empty*/
	gun = nullptr;
}
Player::~Player() {
	if (gun != nullptr)
		delete gun;
}
void Player::attachGun(const string &image, const sf::Vector2f &origin, float fireSpeed,
	float bulletSpeed, int damage, sf::RenderWindow *window) {
	gun = new Gun(image, origin, fireSpeed, bulletSpeed, damage, window);
	gun->attachPlayer((sf::Sprite *)this);
}
/*
	Moves player, updates gun location, bullet locations and draws 
	all bullets on this gun.
*/
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
	setOrigin(getGlobalBounds().width/2, getGlobalBounds().height/2); //Set origin to middle of Sprite
}