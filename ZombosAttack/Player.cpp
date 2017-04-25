#include "Player.h"

Player::Player(const float& speed, const unsigned int& health) :
	Character(speed, health) { // calls base constructor
	gun = nullptr;
}

Player::~Player() {
//	if (gun != nullptr) // delte checks implicitly
		delete gun; // gun is on the heap
}

void Player::attachGun(const string &image, const sf::Vector2f &origin, float shotDelay,
	float bulletSpeed, int damage, sf::RenderWindow *window) {
	gun = new Gun(image, origin, shotDelay, bulletSpeed, damage, window);
	gun->attachPlayer((sf::Sprite *)this);
}
/*
	Moves player, updates gun location, bullet locations and draws 
	all bullets on this gun.
*/
void Player::update(const sf::RenderWindow& window) {
	move();
	Helpers::lockObjectInWindow(/*pointer to player*/*this, window);
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
