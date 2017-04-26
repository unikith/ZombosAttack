#pragma once

#define TWO_DIRECTIONAL_CORRECTION 0.70710678118f // used to make player move at the same speed 
													// if moving in two directions

#include "Player.h" // Controller binds to a player via a pointer

class Controller
{
public:
	//Functions
	/// \ brief : binds a controller object to a player via a pointer, 
	/// \			allows custom controls to be input for a player
	/// \ params : player to bind controls to, keys for each control
	/// \ precons : p points to a valid player object
	/// \ return : a contoller object is created
	Controller(Player *pNewPlayer, sf::Keyboard::Key up = sf::Keyboard::W,
		sf::Keyboard::Key down = sf::Keyboard::S,
		sf::Keyboard::Key left = sf::Keyboard::A,
		sf::Keyboard::Key right = sf::Keyboard::D,
		sf::Keyboard::Key shoot = sf::Keyboard::Space);

	/// \ brief : takes an input event and if it matches a set control it runs the
	/// \			correct action
	/// \ params : an event input from the keyboard
	/// \ precons : the player pointer points to a valid player object
	/// \ return : if control had an effect
	bool runEvent(const sf::Event& event);

private:
	//Members
	/// \ pointer to the player that controller interacts with
	Player *mpPlayer;

	/// \ key binding for each command
	sf::Keyboard::Key mUp;
	sf::Keyboard::Key mDown;
	sf::Keyboard::Key mLeft;
	sf::Keyboard::Key mRight;
	sf::Keyboard::Key mShoot;

	/// \ booleans for whether or not the key is being held
	bool bUp;	//If holding key down bool
	bool bDown;
	bool bLeft;
	bool bRight;

	//Functions
	/// \ brief : checks key presses and enacts them summarily
	/// \ params : an event input from the keyboard
	/// \ precons : the player pointer points to a valid player object
	/// \ return : if control had an effect
	bool keyPressed(const sf::Event& event);

	/// \ brief : checks key releases and enacts them summarily
	/// \ params : an event input from the keyboard
	/// \ precons : the player pointer points to a valid player object
	/// \ return : if control had an effect
	bool keyReleased(const sf::Event& event);

	/// \ brief : takes the up key press and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void startUp();

	/// \ brief : takes the down key press and runs movement logic on it
	/// \ params :none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void startDown();

	/// \ brief : takes the left key press and runs movement logic on it
	/// \ params :none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void startLeft();

	/// \ brief : takes the right key press and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void startRight();

	/// \ brief : Sets shooting bool to true
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void startShoot();

	/// \ brief : takes the up key release and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void stopUp();

	/// \ brief : takes the down key release and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void stopDown();

	/// \ brief : takes the left key release and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void stopLeft();

	/// \ brief : takes the right key release and runs movement logic on it
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void stopRight();

	/// \ brief : sets shooting bool to false
	/// \ params : none
	/// \ precons : the player pointer points to a valid player object
	/// \ return : none
	void stopShooting();
};