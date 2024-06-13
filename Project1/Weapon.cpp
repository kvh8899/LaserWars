#include "Weapon.h"
#include <iostream>

Weapon::Weapon(
	float start_x,
	float start_y,
	std::string fileName,
	float speed_mult,
	float fire_rate,
	WeaponTypes::WeaponTypesEnum weaponType
) : Entity(start_x, start_y, fileName, speed_mult)
{
	this->weaponType = weaponType;
	this->fire_rate = fire_rate;
	this->is_firing = false;
	this->is_on_cooldown = false;
	this->time_last_fired = fire_rate;
}

Weapon::~Weapon()
{
	std::cout << "removing attachment" << std::endl;
};

void Weapon::fire_weapon(std::vector<Laser*> * global_lasers,float direction_x, float direction_y)
{

	if (this->weaponType == WeaponTypes::WeaponTypesEnum::Cannon && this->get_time_last_fired() >= this->fire_rate) {
		float x = this->getSprite()->getPosition().x;
		float y = this->getSprite()->getPosition().y;
		Laser* laser_to_shoot = new Laser(-x, -y, this->LaserFile, this->speed_mult, 1, direction_x, direction_y * this->speed_mult * 2,1.5);

		global_lasers->push_back(laser_to_shoot);
		this->clock.restart();
	}
	set_time_last_fired(this->clock.getElapsedTime().asSeconds());
}

Weapon* Weapon::set_is_firing(bool is_firing) {
	this->is_firing = is_firing;
	return this;
}

bool Weapon::get_is_firing() const {
	return this->is_firing;
}

Weapon* Weapon::set_is_on_cooldown(bool is_on_cd) {
	this->is_on_cooldown = is_on_cd;
	return this;
}

bool Weapon::get_is_on_cooldown() const {
	return this->is_on_cooldown;
}

float Weapon::get_time_last_fired() const {
	return this->time_last_fired;
}

Weapon* Weapon::set_time_last_fired(float time_last_fired) {
	this->time_last_fired = time_last_fired;
	return this;
}