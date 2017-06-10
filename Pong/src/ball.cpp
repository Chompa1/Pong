#include "ball.h"
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

Ball::Ball(sf::Color fillColour, sf::Vector2f position)
{
	ball.setRadius(m_ballRadius);
	ball.setFillColor(sf::Color(0.0f, 100.0f, 150.0f, 255.0f));
	ball.setOutlineThickness(-3.0f);
	ball.setPosition(position);
	ball.setFillColor(fillColour);
	ball.setOutlineColor(sf::Color::Black);
	ball.setOrigin(ball.getScale() / 2.0f);

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> randAng(130, 230);

	//m_ballAngle = randAng(eng) * (M_PI / 180);
	m_ballAngle = 180 * (M_PI / 180);
}

void Ball::move(float deltaTime)
{
	float factor = m_ballSpeed * deltaTime;
	ball.move(std::cos(m_ballAngle) * factor, std::sin(m_ballAngle) * factor);
}

void Ball::changeAngle()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> randAng(-25, 25);

	m_ballAngle += randAng(eng) * (M_PI / 180);
}

void Ball::invertAngle(bool invertX)
{
	if (invertX == false)
		m_ballAngle = -m_ballAngle;
	else
		m_ballAngle = (180 - (m_ballAngle * (180 / M_PI))) * (M_PI / 180); // Convert to degrees, minus 180, then convert back to radians
}

void Ball::setPosition(float posX, float posY)
{
	ball.setPosition(sf::Vector2f(posX, posY));
}

void Ball::setAngle(float angle)
{
	m_ballAngle = angle * (M_PI / 180);
}

sf::FloatRect Ball::getGlobalBounds()
{
	return ball.getGlobalBounds();
}

sf::Vector2f Ball::getPosition()
{
	return ball.getPosition();
}

float Ball::getRadius()
{
	return m_ballRadius;
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(ball);
}
