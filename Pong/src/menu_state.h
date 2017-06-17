#pragma once

#include "play_state.h"

class MenuState : public GameState
{

public:

	void Render(const float deltaTime);
	void Update(const float deltaTime);
	void HandleEvents(const float deltaTime);

	MenuState(Game* game);

private:

	bool visible = true;
	int alpha = 0;
	void flashText(sf::Text &text);

	sf::Clock clock;

	sf::Font font;
	sf::Text title;
	sf::Text instruction;
};