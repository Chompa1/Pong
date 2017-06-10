#include "play_state.h"

#include <SFML/Graphics.hpp>
#include <iostream>

PlayState::PlayState(Game* game)
{
	this->game = game;
	player1 = new Paddle(sf::Color(255, 75, 75), sf::Vector2f(0.0f, 0.0f));
	paddleAI = new PaddleAI(sf::Color(75, 75, 255), sf::Vector2f(0.0f, 0.0f));
	ball = new Ball(sf::Color(255, 255, 255), sf::Vector2f(0, 0));

	resetPositions();

	float separatorLength = 15.0f;
	separator.setSize(sf::Vector2f(separatorLength, (float)this->game->SCREEN_HEIGHT));
	separator.setPosition(sf::Vector2f(((float)this->game->SCREEN_WIDTH / 2) - (separatorLength / 2), 0.0f));
	separator.setFillColor(sf::Color(175, 175, 175));

	if (!font.loadFromFile("resource/fonts/DINPro-Black.otf"))
	{
		std::cout << "Could not load font!";
	}
		
	leftText.setFont(font);
	leftText.setPosition(sf::Vector2f(separator.getPosition().x - 100.0f - (fontSize / 2), separator.getSize().y / 2 - fontSize / 1.5));
	leftText.setString(std::to_string(leftScore));
	leftText.setCharacterSize(fontSize);
	leftText.setFillColor(sf::Color(175, 175, 175));

	rightText.setFont(font);
	rightText.setPosition(sf::Vector2f(separator.getPosition().x + 100.0f + separator.getSize().x, separator.getSize().y / 2 - fontSize / 1.5));
	rightText.setString(std::to_string(rightScore));
	rightText.setCharacterSize(fontSize);
	rightText.setFillColor(sf::Color(175, 175, 175));
}

void PlayState::Render(const float deltaTime)
{
	/* Render objects to the game's window */

	this->game->window.draw(separator);
	this->game->window.draw(leftText);
	this->game->window.draw(rightText);

	this->game->window.draw(*player1);
	this->game->window.draw(*paddleAI);
	this->game->window.draw(*ball);
}

void PlayState::resetPositions()
{
	// Cannot be done in the constructor as this is called multiple times

	ball->setPosition(this->game->SCREEN_WIDTH / 2 - ball->getRadius(), this->game->SCREEN_HEIGHT / 2 - ball->getRadius());
	paddleAI->setPosition(this->game->SCREEN_WIDTH - paddleAI->getSize().x - 20.0f, this->game->SCREEN_HEIGHT / 2);
	player1->setPosition(20.0f, this->game->SCREEN_HEIGHT / 2 - player1->getSize().y / 2);
}

void PlayState::checkVerticalCollisions()
{
	/* Check if ball hits the vertical sides */

	if (ball->getPosition().y - ball->getRadius() < 0.0f)
	{
		ball->invertAngle();
		ball->setPosition(ball->getPosition().x, ball->getPosition().y + 0.1f);
	}

	else if (ball->getPosition().y + ball->getRadius() > this->game->SCREEN_HEIGHT - ball->getRadius())
	{
		ball->invertAngle();
		ball->setPosition(ball->getPosition().x, ball->getPosition().y - 0.1f);
	}
}

void PlayState::checkBallPaddleCollisions()
{
	/* Check collisions between the paddles and the ball */
	
	if (ball->getGlobalBounds().intersects(player1->getGlobalBounds())
		&& ball->getPosition().x > player1->getPosition().x)
	{
		ball->setPosition(ball->getPosition().x + 0.5f, ball->getPosition().y);
		ball->invertAngle(true);
		ball->changeAngle();
	}

	else if (ball->getGlobalBounds().intersects(paddleAI->getGlobalBounds())
		&& ball->getPosition().x < paddleAI->getPosition().x)
	{
		ball->setPosition(ball->getPosition().x - 0.5f, ball->getPosition().y);
		ball->invertAngle(true);
		ball->changeAngle();
	}
}

void PlayState::checkExitScreen()
{
	/* Check if ball exits the horizontal sides */

	if (ball->getPosition().x + ball->getRadius() < 0)
	{
		rightScore++;
		rightText.setString(std::to_string(rightScore));
		ball->setAngle(0.0f);
		resetPositions();
		playing = false;
	}

	else if (ball->getPosition().x + ball->getRadius() > this->game->SCREEN_WIDTH)
	{
		leftScore++;
		leftText.setString(std::to_string(leftScore));
		ball->setAngle(180.0f);
		resetPositions();
		playing = false;
	}
}

void PlayState::HandleEvents(const float deltaTime)
{
	checkVerticalCollisions();
	checkBallPaddleCollisions();
	checkExitScreen();
}

void PlayState::Update(const float deltaTime)
{
	/* Check for player input */

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !playing)
	{
		playing = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player1->getPosition().y > 12.5f && playing)
	{
		player1->move(deltaTime, player1->UP);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& player1->getPosition().y < this->game->SCREEN_HEIGHT - (12.5f + player1->getSize().y) && playing)
	{
		player1->move(deltaTime, player1->DOWN);
	}

	/* Set the AI path to follow the ball
	   TODO: Create a randomized AI */

	if (ball->getPosition().y < paddleAI->getPosition().y && ball->getPosition().y > paddleAI->getSize().y / 2 + 12.5f && playing)
	{
		paddleAI->followBall(deltaTime, *ball);
	}

	if (ball->getPosition().y > paddleAI->getPosition().y && 
		ball->getPosition().y + paddleAI->getSize().y / 2 < this->game->SCREEN_HEIGHT - 12.5f && playing)
	{
		paddleAI->followBall(deltaTime, *ball);
	}

	if (playing)
	{
		ball->move(deltaTime);
	}
}
