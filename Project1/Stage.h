#pragma once
#include <SFML/Graphics.hpp>
class Stage
{
public:
	Stage(std::string file_name);

	~Stage();

	void draw_background(sf::RenderWindow* window);

	void destroy();



protected:
	sf::Sprite* stage_background;
	sf::Texture* stage_texture;
	std::string stage_file;
};

