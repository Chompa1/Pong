#pragma once

#include "game_state.h"
#include "paddle.h"
#include "paddle_ai.h"
#include "ball.h"

class PlayState : public GameState
{

public:

	void Render(const float deltaTime);
	void Update(const float deltaTime);
	void HandleEvents(const float deltaTime);

	PlayState(Game* game);

private:

	bool playing = false;

	int leftScore = 0;
	int rightScore = 0;

	void checkVerticalCollisions();
	void checkBallPaddleCollisions();
	void checkExitScreen();
	void resetPositions();

	sf::RectangleShape separator;

	sf::Font font;
	float fontSize = 72.0f;
	sf::Text leftText;
	sf::Text rightText;

	Paddle* player1;
	PaddleAI* paddleAI;
	Ball* ball;
};

