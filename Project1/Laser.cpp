#include "Laser.h"

Laser::Laser(
	float start_x,
	float start_y, 
	std::string fileName, 
	float speed_mult,
	float damage_mult,
	float velocity_x,
	float velocity_y,
	float lifetime
): Entity(start_x, start_y, fileName, speed_mult)
{
	this->damage_mult = damage_mult;
	this->velocity_y = velocity_y;
	this->velocity_x = velocity_x;
	this->lifetime = lifetime;
	// Brings laser to position of the weapon
	this->loadSprite()->setOrigin(start_x  + -13,start_y + 70);
}

float Laser::get_time_alive() const {
	return this->clock.getElapsedTime().asSeconds();
}

float Laser::get_time_to_live() const {
	return this->lifetime;
}