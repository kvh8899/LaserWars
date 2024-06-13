#include "Player.h"
#include <iostream>

Player::Player(float start_x, float start_y, int health, std::string fileName, float speed_mult, Weapon* weapon):
	Entity(start_x, start_y, fileName, speed_mult) {
	this->setHealth(health);
	this->entity_type = "player";
	if (weapon == NULL){
		this->weapon = new Weapon(
			start_x, 
			start_y, 
			WeaponTypes::get_weapon_sprite(WeaponTypes::WeaponTypesEnum::Cannon), 
			speed_mult,
			0.3,
			WeaponTypes::WeaponTypesEnum::Cannon
		);
	}
	else {
		this->weapon = weapon;
	}

	this->weapons = {};
	this->weapons.push_back(this->weapon);
}

Player::~Player()
{
	for (auto& attachment : this->weapons) {
		delete attachment;
	}
}

void Player::set_is_faint(bool is_faint) {
	this->is_faint = is_faint;
}

bool Player::get_is_faint() const {
	return this->is_faint;
}

int Player::getHealth() const
{
	return this->health;
}

void Player::setHealth(int damage)
{
	this->health = this->health - damage;
}

void Player::handleControls(sf::Event event)
{
	this->handleMovement(event);
}

void Player::handleMovement(sf::Event event) {
	if (
		event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::D
		) {
		this->moveRight();
		this->getSprite()->setScale(0.75, 1);
		for (auto& attachment : this->weapons) {
			attachment->moveRight();
			float x = this->getSprite()->getPosition().x;
			float y = this->getSprite()->getPosition().y;
			attachment->getSprite()->setPosition(x - 3, y);
		}
	}

	if (
		event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::A
		) {
		this->moveLeft();
		this->getSprite()->setScale(0.75, 1);
		for (auto& attachment : this->weapons) {
			attachment->moveLeft();
			attachment->stopMovingLeft();
			float x = this->getSprite()->getPosition().x;
			float y = this->getSprite()->getPosition().y;
			attachment->getSprite()->setPosition(x - 10, y);
		}
	}

	if (event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::A) {
		this->stopMovingLeft();
		this->getSprite()->setScale(1, 1);
		for (auto& attachment : this->weapons) {
			attachment->stopMovingLeft();
			float x = this->getSprite()->getPosition().x;
			float y = this->getSprite()->getPosition().y;
			attachment->getSprite()->setPosition(x, y);
		}
	}

	if (event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::D) {
		this->stopMovingRight();
		this->getSprite()->setScale(1, 1);
		for (auto& attachment : this->weapons) {
			attachment->stopMovingRight();
			float x = this->getSprite()->getPosition().x;
			float y = this->getSprite()->getPosition().y;
			attachment->getSprite()->setPosition(x, y);
		}
	}

	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::S)
	{
		this->moveDown();
		for (auto& attachment : this->weapons) {
			attachment->moveDown();
		}
	}

	if (event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::S)
	{
		this->stopMovingDown();
		for (auto& attachment : this->weapons) {
			attachment->stopMovingDown();
		}
	}

	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::W)
	{
		this->moveUp();
		for (auto& attachment : this->weapons) {
			attachment->moveUp();
		}
	}

	if (event.type == sf::Event::KeyReleased &&
		event.key.code == sf::Keyboard::W)
	{
		this->stopMovingUp();
		for (auto& attachment : this->weapons) {
			attachment->stopMovingUp();
		}
	}

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
		for (auto& weapon : this->weapons) {
			weapon->set_is_firing(true);
		}
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		for (auto& weapon : this->weapons) {
			weapon->set_is_firing(false);
		}
	}
}

void Player::shoot_primary_weapon(sf::Event event, std::vector<Laser*> * global_lasers) {
	
	for (auto& weapon : this->weapons) {
		weapon->fire_weapon(global_lasers, this->get_velocity_x(), this->get_velocity_y());
	}

}	

void Player::set_velocity_x(float velocity_x)
{
	this->velocity_x = velocity_x;
	for (auto& attachment : this->weapons) {
		attachment->set_velocity_x(velocity_x);
	}
}

void Player::set_velocity_y(float velocity_y)
{
	this->velocity_y = velocity_y;
	for (auto& attachment : this->weapons) {
		attachment->set_velocity_y(velocity_y);
	}
}

void Player::draw_entity(sf::RenderWindow* window)
{
	window->draw(*(this->getSprite()));
	for (auto& attachment : this->weapons) {
		window->draw(*(attachment->getSprite()));;
	}
}

void Player::move()
{
	this->getSprite()->move(this->get_velocity_x(), this->get_velocity_y());
	for(size_t i = 0; i < this->get_weapons().size(); i++) {
		Entity* attachment = (this->get_weapons())[i];
		attachment->move();
	}
}

std::vector<Weapon*> Player::get_weapons() const
{
	return this->weapons;
}