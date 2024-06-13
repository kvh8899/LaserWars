#include "Entity.h"
#include <iostream>

// This class has a lot of methods, will switch to component based architecture later
Entity::Entity(float start_x, float start_y, std::string fileName, float speed_mult) {
	set_velocity_x(0);
	set_velocity_y(0);
	this->speed_mult = speed_mult;
	this->fileName = fileName;
	std::cout << "Creating Entity" + this->fileName << std::endl;
}

Entity::~Entity() {
	std::cout << "Removing Entity" + this->fileName << std::endl;
	delete this->texture;
	delete this->sprite;
}

void Entity::moveLeft()
{
	this->isMovingLeft = true;
}

void Entity::stopMovingLeft()
{
	this->isMovingLeft = false;
}

void Entity::moveRight()
{
	this->isMovingRight = true;
}

bool Entity::getIsMovingLeft() const
{
	return this->isMovingLeft;
}

bool Entity::getIsMovingRight() const
{
	return this->isMovingRight;
}

void Entity::stopMovingRight()
{
	this->isMovingRight = false;
}

void Entity::moveDown()
{
	this->isMovingDown = true;
}

void Entity::moveUp()
{
	this->isMovingUp = true;
}

void Entity::stopMovingDown()
{
	this->isMovingDown = false;
}

void Entity::stopMovingUp()
{
	this->isMovingUp = false;
}

bool Entity::getIsMovingDown() const
{
	return this->isMovingDown;
}

bool Entity::getIsMovingUp() const
{
	return this->isMovingUp;
}

std::vector<float> Entity::getPosition() const
{
	return { this->position_x, this->position_y };
}

sf::Sprite* Entity::loadSprite()
{
	this->texture = new sf::Texture();
	if (this->texture->loadFromFile(this->fileName)) {
		this->isLoaded = true;
	}
	else {
		this->isLoaded = false;
		std::cout << "There was a problem loading" + this->fileName << std::endl;
	}
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*(this->texture));
	return this->sprite;
}

sf::Sprite* Entity::getSprite() const
{
	return this->sprite;
}

bool Entity::getIsLoaded() const
{
	return this->isLoaded;
}

float Entity::get_speed_mult() const
{
	return this->speed_mult;
}

float Entity::get_pos_x() const
{
	return this->position_x;
}

float Entity::get_pos_y() const
{
	return this->position_y;
}

std::string Entity::get_entity_type() const
{
	return this->entity_type;
}

float Entity::get_velocity_y() const
{
	return this->velocity_y;
}

void Entity::set_velocity_y(float velocity_y) {
	this->velocity_y = velocity_y;
}

float Entity::get_velocity_x() const
{
	return this->velocity_x;
}

void Entity::set_velocity_x(float velocity_x) {
	this->velocity_x = velocity_x;
}

void Entity::draw_entity(sf::RenderWindow* window)
{
	window->draw(*(this->getSprite()));
}

void Entity::move() 
{
	this->getSprite()->move(this->get_velocity_x(), this->get_velocity_y());
}

void Entity::destroy()
{
	this->~Entity();
}