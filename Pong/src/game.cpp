#include <stack>

#include "game.h"
#include "game_state.h"
#include "paddle.h"

void Game::pushState(GameState* state)
{
	this->states.push(state);
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();

	pushState(state);

	return;
}

GameState* Game::checkState()
{
	if (this->states.empty())
		return nullptr;

	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time timeElapsed = clock.restart();
		float deltaTime = timeElapsed.asSeconds();

		if (checkState() == nullptr)
			continue;

		checkState()->HandleEvents(deltaTime);
		checkState()->Update(deltaTime);
		this->window.clear(this->windowColor);
		checkState()->Render(deltaTime);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
	this->window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
	while (!this->states.empty())
		popState();
}
