#include "menu_state.h"
#include <iostream>

MenuState::MenuState(Game* game)
{
	this->game = game;
	game->windowColor = sf::Color(0, 0, 0);

	if (!font.loadFromFile("resource/fonts/DINPro-Black.otf"))
	{
		std::cout << "Could not load font!";
	}

	title.setFont(font);
	title.setString("Pong!");
	title.setCharacterSize(90.0f);
	title.setFillColor(sf::Color(200, 200, 200));
	title.setPosition(sf::Vector2f(game->SCREEN_WIDTH / 2 - (title.getLocalBounds().width / 2), game->SCREEN_HEIGHT / 2 - 150.0f));

	instruction.setFont(font);
	instruction.setString("Press SPACE to begin");
	instruction.setCharacterSize(45.0f);
	instruction.setFillColor(sf::Color(200, 200, 200));
	instruction.setPosition(sf::Vector2f(game->SCREEN_WIDTH / 2 - (instruction.getLocalBounds().width / 2), game->SCREEN_HEIGHT / 2 + 50.0f));

	clock.restart();
}

void MenuState::Render(const float deltaTime)
{
	this->game->window.draw(title);
	this->game->window.draw(instruction);
}

void MenuState::flashText(sf::Text &text)
{
	if (alpha == 255)
		visible = true;

	else if (alpha == 0)
		visible = false;

	if (visible)
	{
		alpha -= 3;
	}
	else
	{
		alpha += 3;
	}

	std::cout << alpha << std::endl;

	text.setFillColor(sf::Color(200, 200, 200, alpha));
}

void MenuState::Update(const float deltaTime)
{
	if (clock.getElapsedTime().asMilliseconds() >= 25)
	{
		flashText(instruction);
		flashText(title);

		clock.restart();
	}
}

void MenuState::HandleEvents(const float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->game->changeState(new PlayState(this->game));
	}
}