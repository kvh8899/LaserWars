#include <iostream>
#include <vector>
#include "Renderer.h"
#include "Player.h"
#include "Stage.h"
#include "CollisionSystem.h"
using namespace std;

int main()
{

	Renderer * gameRenderer = new Renderer();
	sf::RenderWindow *window = gameRenderer->renderGame();


	Player * playerOne = new Player(1.0, 1.0, 100, "C:/Users/kylev/source/repos/Project1/ship.png", 30, NULL);
	// Load stage
	Stage* stage = new Stage("C:/Users/kylev/source/repos/Project1/space.jpg");

	// Todo: load enemies
	vector<Player *> players = {};
	vector<Entity*> entities = {};
	vector<Weapon*> *weapons = new std::vector<Weapon*>();

	players.push_back(playerOne);
	entities.push_back(playerOne);

	for (size_t i = 0; i < players.size(); i++) {
		players[i]->loadSprite()->setOrigin(1, 1);

		for (size_t j = 0; j < players[i]->get_weapons().size(); j++) {
			sf::Sprite * weapon = players[i]->get_weapons()[j]->loadSprite();
			weapon->setOrigin(60, -18);
			weapon->rotate(-90.f);
			weapon->setScale(.75, .75);
		}

		for (auto& weapon : players[i]->get_weapons()) {
			weapons->push_back(weapon);
		}
	}
	
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed){
				window->close();
			}
			gameRenderer->process_player_movement_event(players, event, window);
			
		}
		CollisionSystem::detect_stage_collision(entities, gameRenderer);

		window->clear();
		stage->draw_background(window);
		gameRenderer->render_entity_movement(entities, window);
		gameRenderer->process_weapon_events(weapons, window);
		gameRenderer->process_projectile_events(window);
		window->display();
	}

	for (size_t i = 0; i < players.size(); i++) {
		players[i]->destroy();
	}
	stage->destroy();
	delete window;
	delete gameRenderer;
	return EXIT_SUCCESS;
}