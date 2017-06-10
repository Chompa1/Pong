#pragma once

#include <SFML\Graphics.hpp>

class Ball : public sf::Drawable
{

private:

	sf::CircleShape ball;
	float m_ballSpeed = 600.0f;
	float m_ballRadius = 10.0f;

public:

	Ball(sf::Color fillColour, sf::Vector2f position);

	float m_ballAngle = 120.0f;

	void move(float deltaTime);
	void changeAngle();
	void invertAngle(bool invertX = false);
	void setPosition(float posX, float posY);
	void setAngle(float angle);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();
	float getRadius();
};