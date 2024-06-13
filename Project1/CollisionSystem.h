#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Player.h"
#include <vector>
class CollisionSystem
{
public:
	static void detect_stage_collision(std::vector<Entity*> entities, Renderer* renderer);
};

