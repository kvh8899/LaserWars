#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include "Weapon.h"
#include "Laser.h"

class Player: public Entity
{
public:
	Player(float start_x, float start_y, int health, std::string fileName, float speed_mult, Weapon * weapon);

	~Player();

	void setHealth(int damage);

	int getHealth() const;

	bool get_is_faint() const;

	void set_is_faint(bool is_faint);

	void handleControls(sf::Event event);

	void shoot_primary_weapon(sf::Event event, std::vector<Laser*>* global_lasers);

	void set_velocity_x(float velocity_x) override;

	void set_velocity_y(float velocity_y) override;

	void draw_entity(sf::RenderWindow* window) override;

	void move() override;

	std::vector<Weapon *> get_weapons() const;

private:
	char* name;

	int health = 100;

	float position_x;

	bool is_faint = false;

	Weapon* weapon;

	std::vector<Weapon *> weapons;

	void handleMovement(sf::Event event);

};

