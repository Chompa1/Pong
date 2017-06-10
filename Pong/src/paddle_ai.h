#pragma once

#include "game.h"
#include "ball.h"

#include <SFML\Graphics.hpp>

class PaddleAI : public sf::Drawable
{

private:

	sf::RectangleShape paddle_ai;
	float m_paddleSpeed = 400.0f;

public:

	enum Direction { UP, DOWN, AI };

	PaddleAI(sf::Color fillColour, sf::Vector2f position);

	void followBall(float deltaTime, Ball ball);
	void move(float deltaTime, float posX, float posY);
	void setPosition(float posX, float posY);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	sf::FloatRect getGlobalBounds();
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
};