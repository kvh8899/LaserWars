#include "Stage.h"
#include <iostream>
Stage::Stage(std::string file_name)
{
	this->stage_file = file_name;
	this->stage_background = new sf::Sprite();
	this->stage_texture = new sf::Texture();
}

Stage::~Stage() {
	std::cout << "Removing Stage" << std::endl;
	delete this->stage_texture;
	delete this->stage_background;
}

void Stage::draw_background(sf::RenderWindow * window)
{
	if (this->stage_texture->loadFromFile(this->stage_file))
	{
		this->stage_background->setTexture(*(this->stage_texture));
	}
	else {
		std::cout << "Failed to load stage: " + this->stage_file << std::endl;
		return;
	}
	window->draw(*(this->stage_background));
}

void Stage::destroy()
{
	this->~Stage();
}