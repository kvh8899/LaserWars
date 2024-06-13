#include "CollisionSystem.h"

void CollisionSystem::detect_stage_collision(std::vector<Entity *> entities, Renderer * renderer)
{
	for (auto& entity : entities)
	{
		sf::Vector2f entity_pos = entity->getSprite()->getPosition();
		sf::Vector2u entity_size = entity->getSprite()->getTexture()->getSize();

		// Detect collision with left and right border
		if (entity_pos.x >= (renderer->getWindowWidth() - entity_size.x)) {
			entity->stopMovingRight();
		}else if (entity_pos.x <= 0) {
			entity->stopMovingLeft();
		}

		if (entity_pos.y >= (renderer->getWindowHeight() - entity_size.y)){
			entity->stopMovingDown();
		}
		else if (entity_pos.y <= 0) {
			entity->stopMovingUp();
		}
	}
}