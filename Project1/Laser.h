#pragma once
#include "Entity.h"

class Laser: public Entity
{
public:
	Laser(
		float start_x,
		float start_y,
		std::string fileName,
		float speed_mult,
		float damage_mult,
		float velocity_x,
		float velocity_y,
		float lifetime
	);

	float get_time_alive() const;

	float get_time_to_live() const;

private:
	float damage_mult;
	float lifetime; // this will affect bullet range
	sf::Clock clock;
};

