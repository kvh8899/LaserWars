#pragma once
#include "Entity.h"
#include "WeaponTypes.h"
#include "Laser.h"
class Weapon: public Entity
{
public:
	Weapon(float start_x, float start_y, std::string fileName, float speed_mult,float fire_rate, WeaponTypes::WeaponTypesEnum weaponType);

	~Weapon();

	void fire_weapon(std::vector<Laser*>* global_lasers, float direction_x, float direction_y);

	Weapon* set_is_firing(bool is_firing);

	bool get_is_firing() const;

	Weapon* set_is_on_cooldown(bool is_on_cd);

	bool get_is_on_cooldown() const;

	float get_time_last_fired() const;

	Weapon* set_time_last_fired(float time_last_fired);

private:
	WeaponTypes::WeaponTypesEnum weaponType;

	std::string LaserFile = "C:/Users/kylev/source/repos/Project1/primary_laser.png";

	bool is_firing;

	bool is_on_cooldown;

	float fire_rate;

	float time_last_fired;

	sf::Clock clock;


};

