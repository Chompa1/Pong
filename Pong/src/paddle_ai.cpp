#include "paddle_ai.h"

PaddleAI::PaddleAI(sf::Color fillColour, sf::Vector2f position)
{
	paddle_ai.setSize(getSize());
	paddle_ai.setOrigin(sf::Vector2f(paddle_ai.getSize().x / 2, paddle_ai.getSize().y / 2));
	paddle_ai.setFillColor(sf::Color(0.0f, 100.0f, 150.0f, 255.0f));
	paddle_ai.setOutlineThickness(-3.0f);
	paddle_ai.setPosition(position);
	paddle_ai.setFillColor(fillColour);
	paddle_ai.setOutlineColor(sf::Color(125, 125, 125));
}

void PaddleAI::followBall(float deltaTime, Ball ball)
{
	paddle_ai.setPosition(paddle_ai.getPosition().x, ball.getPosition().y);
}

void PaddleAI::move(float deltaTime, float posX, float posY)
{
	paddle_ai.move(sf::Vector2f(posX, posY));
}

void PaddleAI::setPosition(float posX, float posY)
{
	paddle_ai.setPosition(sf::Vector2f(posX, posY));
}

void PaddleAI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(paddle_ai);
}

sf::FloatRect PaddleAI::getGlobalBounds()
{
	return paddle_ai.getGlobalBounds();
}

sf::Vector2f PaddleAI::getSize()
{
	return sf::Vector2f(25.0f, 100.0f);
}

sf::Vector2f PaddleAI::getPosition()
{
	return paddle_ai.getPosition();
}
