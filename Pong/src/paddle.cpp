#include "paddle.h"

Paddle::Paddle(sf::Color fillColour, sf::Vector2f position)
{
	paddle.setSize(getSize());
	paddle.setFillColor(sf::Color(0.0f, 100.0f, 150.0f, 255.0f));
	paddle.setOutlineThickness(-3.0f);
	paddle.setPosition(position);
	paddle.setFillColor(fillColour);
	paddle.setOutlineColor(sf::Color::Black);
}

void Paddle::move(float deltaTime, Direction direction)
{
	switch (direction)
	{
	case UP:
		paddle.move(sf::Vector2f(0.0f, -m_paddleSpeed * deltaTime));
		break;

	case DOWN:
		paddle.move(sf::Vector2f(0.0f, m_paddleSpeed * deltaTime));
		break;
	}
}

void Paddle::setPosition(float posX, float posY)
{
	paddle.setPosition(sf::Vector2f(posX, posY));
}

void Paddle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(paddle);
}

sf::FloatRect Paddle::getGlobalBounds()
{
	return paddle.getGlobalBounds();
}

sf::Vector2f Paddle::getSize()
{
	return sf::Vector2f(25.0f, 100.0f);
}

sf::Vector2f Paddle::getPosition()
{
	return paddle.getPosition();
}
