#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(float start_x, float start_y, std::string fileName, float speed_mult);

	~Entity();

	void moveLeft();

	void moveRight();

	void moveDown();

	void moveUp();

	void stopMovingLeft();

	void stopMovingRight();

	void stopMovingDown();

	void stopMovingUp();

	bool getIsMovingLeft() const;

	bool getIsMovingRight() const;

	bool getIsMovingDown() const;

	bool getIsMovingUp() const;

	float get_pos_x() const;

	float get_pos_y() const;

	std::vector<float> getPosition() const;

	float get_speed_mult() const;

	virtual void set_velocity_y(float velocity_y);

	float get_velocity_y() const;

	virtual void set_velocity_x(float velocity_x);

	float get_velocity_x() const;

	bool getIsLoaded() const;

	sf::Sprite* loadSprite();

	sf::Sprite* getSprite() const;

	std::string get_entity_type() const;
	
	virtual void draw_entity(sf::RenderWindow* window);

	virtual void move();

	void destroy();

protected:
	char* name;

	float position_x;

	float position_y;

	float speed;

	float velocity_x;

	float velocity_y;

	float speed_mult;

	bool isLoaded;

	bool isMovingRight;

	bool isMovingLeft;

	bool isMovingDown;

	bool isMovingUp;

	sf::Sprite* sprite;

	sf::Texture* texture;

	std::string fileName;

	std::string entity_type;

};

