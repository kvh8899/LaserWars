#include "Renderer.h"
#include <iostream>


Renderer::~Renderer() {
	std::cout << "Exiting Game" << std::endl;
	for (auto& laser : *this->global_lasers) {
		delete laser;
	}
	delete this->window_obj;
	delete this->global_lasers;
	delete this->global_lasers_to_remove;
}
sf::RenderWindow* Renderer::renderGame()
{
	sf::VideoMode video = sf::VideoMode(this->getWindowWidth(), this->getWindowHeight());

	std::string window_title = "Laser Wars";
	
	this->window_obj = new sf::RenderWindow();
	this->window_obj->create(video, window_title, sf::Style::Close);
	this->global_lasers = new std::vector<Laser*>();
	this->global_lasers_to_remove = new std::vector<std::vector<Laser*>::const_iterator>();

	return this->window_obj;
}

void Renderer::loadMusic(char* music_file_name)
{
	sf::Music music;
	if (!music.openFromFile(music_file_name)) {
		// Handle file opening error
		std::cout << "Music was not able to play" << std::endl;
	}
	music.play();
}

void Renderer::setWindowHeight(int height) {
	this->w_height = height;
}

int Renderer::getWindowHeight() const {
	return this->w_height;
}

void Renderer::setWindowWidth(int width) {
	this->w_width = width;
}

int Renderer::getWindowWidth() const {
	return this->w_width;
}

Renderer* Renderer::set_global_lasers(std::vector<Laser*>* lasers) {
	this->global_lasers = global_lasers;
	return this;
}

std::vector<Laser*>* Renderer::get_global_lasers()
{
	return this->global_lasers;
}

void Renderer::render_entity_movement(std::vector<Entity*> entities, sf::RenderWindow* window)
{
	for (size_t i = 0; i < entities.size(); i++) {
		Entity* entity = entities[i];

		if (entity->getIsMovingLeft() == true && entity->getIsMovingRight()) {
			entity->set_velocity_x(0);
		}
		else if (entity->getIsMovingLeft() == true) {
			entity->set_velocity_x(-0.1 * entity->get_speed_mult());
		}
		else if (entity->getIsMovingRight() == true) {
			entity->set_velocity_x(0.1 * entity->get_speed_mult());
		}
		else {
			entity->set_velocity_x(0);
		}

		if (entity->getIsMovingDown() == true && entity->getIsMovingUp() == true)
		{
			entity->set_velocity_y(0);
		}
		else if (entity->getIsMovingDown() == true)
		{
			entity->set_velocity_y(0.1 * entity->get_speed_mult());
		}
		else if (entity->getIsMovingUp() == true)
		{
			entity->set_velocity_y(-0.1 * entity->get_speed_mult());
		}
		else {
			entity->set_velocity_y(0);
		}
		
		entity->move();
		entity->draw_entity(window);
	}
}

void Renderer::process_player_movement_event(std::vector<Player*> entities, sf::Event event, sf::RenderWindow * window) {

	for (size_t i = 0; i < entities.size(); i++) {
		Player* entity = entities[i];
		entity->handleControls(event);
	}

}

void Renderer::process_weapon_events(std::vector<Weapon*> *weapons, sf::RenderWindow* window) {
	for (const auto& weapon : *weapons) {
		if (weapon->get_is_firing() == true) {
			weapon->fire_weapon(this->global_lasers, 0, -0.1);
		}
	}
}

void Renderer::process_projectile_events(sf::RenderWindow* window) {

	// Handle laser ttl
	for (const auto& it : (*this->global_lasers)) {
		if (it->get_time_alive() >= it->get_time_to_live()) {
			this->global_lasers_to_remove->push_back(
				std::find(this->global_lasers->begin(), 
				this->global_lasers->end(), it)
			);
			continue;
		}
		it->move();
		it->draw_entity(window);
	}

	// Handle laser collision

	// Remove lasers from the world
	for (const auto& it : *this->global_lasers_to_remove) {
		delete* it;
		this->global_lasers->erase(it);
	}
	this->global_lasers_to_remove->clear();
}

