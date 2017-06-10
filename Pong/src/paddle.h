#pragma once

#include <SFML\Graphics.hpp>

class Paddle : public sf::Drawable
{

private:

	sf::RectangleShape paddle;
	float m_paddleSpeed = 400.0f;

public:

	enum Direction { UP, DOWN, AI };

	Paddle(sf::Color fillColour, sf::Vector2f position);

	void move(float deltaTime, Direction direction);
	void setPosition(float posX, float posY);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	sf::FloatRect getGlobalBounds();
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
};