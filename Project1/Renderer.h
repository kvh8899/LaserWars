#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Weapon.h"

class Renderer
{
public:

	~Renderer();

	sf::RenderWindow *renderGame();

	void loadMusic(char* music_file_name);

	void setWindowHeight(int height);

	int getWindowHeight() const;
	
	void setWindowWidth(int width);

	int getWindowWidth() const;

	Renderer* set_global_lasers(std::vector<Laser*>* lasers);

	std::vector<Laser*>* get_global_lasers();

	void render_entity_movement(std::vector<Entity*> entities, sf::RenderWindow* window);

	void process_player_movement_event(std::vector<Player*> entities, sf::Event event, sf::RenderWindow* window);

	void process_weapon_events(std::vector<Weapon*> * weapons, sf::RenderWindow* window);

	void process_projectile_events(sf::RenderWindow* window);
private:
	 int w_height = 600;
	 int w_width = 600;
	 sf::RenderWindow* window_obj;

	 std::vector<Laser*>* global_lasers;
	 std::vector<std::vector<Laser*>::const_iterator>* global_lasers_to_remove;
	 
};

