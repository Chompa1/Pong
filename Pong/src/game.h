#pragma once

#include <stack>
#include <SFML\Graphics.hpp>

class GameState;

class Game
{

public:

	std::stack<GameState*> states;

	sf::RenderWindow window;
	sf::Clock clock;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* checkState();

	void gameLoop();

	sf::Color windowColor;

	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT = 600;

	Game();
	~Game();

};